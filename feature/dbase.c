// dbase.c

//#include <dbase.h>

inherit F_TREEMAP;

mapping dbase;
static mapping tmp_dbase;  // 据说这样可以不存档

//  The default_ob provides the default values of the dbase. It is set to
//  be master copy of an object.
static mixed default_ob;

mixed query_default_object() { return (mixed)default_ob; }
void set_default_object(mixed ob)
{
  if (!geteuid())
    seteuid(getuid());
  default_ob = ob;
  ob->add("no_clean_up", 1);
}

mixed set(string prop, mixed data)
{
  if (!mapp(dbase))
    dbase = ([]);

  if(!prop) return 0;
  if (strsrch(prop, '/') != -1)
    return (mixed)_set (dbase, explode(prop, "/"), data);

  return (mixed)dbase[prop] = data;
}

varargs mixed query(string prop, int raw)
{
  mixed data;

  if (!mapp(dbase))
    return (mixed)0;

  if(!prop) return 0;
  if (undefinedp(dbase[prop]) && strsrch (prop, '/') != -1)
    data = _query(dbase, explode(prop, "/"));
  else
    data = dbase[prop];

  if (undefinedp(data) && default_ob)
    data = default_ob->query(prop, 1);

  if (raw) return (mixed)data;

  return (mixed)evaluate (data, this_object());
}

int delete(string prop)
{
  if (!mapp(dbase)) return (int)0;

  if (strsrch(prop, '/')!=-1)
    return (int)_delete (dbase, explode(prop, "/"));
  else {
    map_delete (dbase, prop);
    return 1;
  }
}

mixed add(string prop, mixed data)
{
  mixed old;

  if( !mapp(dbase) || !(old = query(prop, 1)) )
    return (mixed)set(prop, data);

  if( functionp(old) )
    error("dbase: add() 不能用在函数的型态上.\n");

  return (mixed)set(prop, old + data);
}

mapping query_entire_dbase()
{
  return (mapping)dbase;
}

mixed set_temp(string prop, mixed data)
{
  if (!mapp(tmp_dbase))
    tmp_dbase = ([]);

  if (strsrch(prop, '/') != -1)
    return _set (tmp_dbase, explode(prop, "/"), data);

  return (mixed)tmp_dbase[prop] = data;
}

varargs mixed query_temp(string prop, int raw)
{
  mixed data;

  if (!mapp(tmp_dbase))
    return 0;

  if (strsrch(prop, '/') != -1)
    data = _query (tmp_dbase, explode(prop, "/"));
  else
    data = tmp_dbase[prop];

  if (functionp(data) && !raw)
    return (*data) (this_object());
  else 
    return (mixed)data;
}

int delete_temp(string prop)
{
  if (!mapp(tmp_dbase))
    return 0;

  if (strsrch(prop, '/') != -1)
    return (int)_delete (tmp_dbase, explode (prop, "/"));
  else {
    map_delete (tmp_dbase, prop);
    return 1;
  }
}

mixed add_temp(string prop, mixed data)
{
  mixed old;

  if (!mapp(tmp_dbase) || !(old = query_temp(prop, 1)))
    return (mixed)set_temp (prop, data);

  if (functionp(old))
    error ("dbase: add_temp() - 不能设到函数型态.\n");

  return (mixed)set_temp(prop, old + data);
}

mapping query_entire_temp_dbase()
{
  return (mapping)tmp_dbase;
}

