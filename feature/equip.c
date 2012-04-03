//	equip.c

#include <dbase.h>
#include <weapon.h>

int wear()
{
	object owner;
	mapping armor_prop, applied_prop;
	string *apply, type;
	int exp;
	
    if(!environment()) return 0;
	// Only character object can wear armors.
	if( !(owner = environment())->is_character() ) return 0;

	// If already worn, just recognize it.
	if( query("equipped") ) return 1;

	// Check if we have "armor_prop" defined.
	if( !mapp(armor_prop = query("armor_prop")) )
		return notify_fail("��ֻ�ܴ����ɵ������ߵĶ�����\n");

	type = query("armor_type");

        if( file_size("/std/armor/"+type+".c") < 0 )
		return notify_fail("������ߵĸ�ʽ�趨����, ���æ post ֪ͨ��ʦ��\n");

	if( owner->query_temp("armor/" + type) )
		return notify_fail("���Ѿ�������ͬ���͵Ļ����ˡ�\n");
	exp = (int)query("need_exp");
	if( (int)owner->query("combat_exp")<exp)
	    return notify_fail("��ľ���ֵ�����Դ����˷��ߡ�\n");
	if (query("rain_cover"))
	  if (!owner->query_temp("rain_cover"))
	    owner->set_temp("rain_cover",1);
	  else return notify_fail ("��ֻ�ܴ���һ����ߡ�\n");
	if (query("need_class"))
	{
	  if (owner->query("class")!=query("need_class"))
	    return notify_fail("���ְҵ�޷������˷��ߡ�\n");
	}
	if (query("thunder"))
	  if (!owner->query_temp("thunder"))
	    owner->set_temp("thunder",query("thunder"));
	  else return notify_fail ("��ֻ�ܴ���һ��ɢ������\n");

	owner->set_temp("armor/" + type, this_object());
	apply = keys(armor_prop);
	applied_prop = owner->query_temp("apply");
	if( !mapp(applied_prop) ) applied_prop = ([]);
	for(int i = 0; i<sizeof(apply); i++)
		if( undefinedp(applied_prop[apply[i]]) )
			applied_prop[apply[i]] = armor_prop[apply[i]];
		else
			applied_prop[apply[i]] += armor_prop[apply[i]];
	owner->set_temp("apply", applied_prop);
	set("equipped", "worn");
	return 1;
}

int wield()
{
	object owner, old_weapon;
	mapping weapon_prop;
	string *apply, type;
	int flag,exp;

	// Only character object can wear armors.
	if( !(owner = environment())->is_character() ) return 0;

	// If already wielded, just recognize it.
	if( query("equipped") ) return 1;

	// Check if we have "weapon_prop" defined.
	if( !mapp(weapon_prop = query("weapon_prop")) )
		return notify_fail("��ֻ��װ���ɵ��������Ķ�����\n");
	exp = (int)query("need_exp");
	if( (int)owner->query("combat_exp")<exp)
	    return notify_fail("��ľ���ֵ������װ����������\n");
	if (query("need_class"))
	{
	  if (owner->query("class")!=query("need_class"))
	    return notify_fail("���ְҵ�޷�װ����������\n");
	}

	flag = query("flag");

	if( flag & TWO_HANDED ) {
		if( owner->query_temp("weapon")
		||	owner->query_temp("secondary_weapon")
		||	owner->query_temp("armor/shield") )
			return notify_fail("�����ճ�˫�ֲ���װ��˫��������\n");
		owner->set_temp("weapon", this_object());
	} else {

		// If we are are using any weapon?
		if( !(old_weapon = owner->query_temp("weapon")) )
			owner->set_temp("weapon", this_object());

		else // If we still have a free hand? 
		if( !owner->query_temp("secondary_weapon")
		&&	!owner->query_temp("armor/shield") ) {

			// If we can wield this as secondary weapon?
			if(flag & SECONDARY) {
				owner->set_temp("secondary_weapon", this_object());

			// If we can switch our old weapon to secondary weapon ?
			} else if( (int)old_weapon->query("flag") & SECONDARY ) {
				old_weapon->unequip();
				owner->set_temp("weapon", this_object());
				old_weapon->wield();

			// We need unwield our old weapon before we can use this one.
			} else
				return notify_fail("������ȷ�����Ŀǰװ����������\n");

		// We have both hands wearing something.
		} else
			return notify_fail("�����ճ�һֻ����ʹ��������\n");
	}

	apply = keys(weapon_prop);
	for(int i = 0; i<sizeof(apply); i++)
		owner->add_temp("apply/" + apply[i], weapon_prop[apply[i]]);

	owner->reset_action();
	set("equipped", "wielded");
	return 1;
}

int unequip()
{
	object owner;
	mapping prop, applied_prop;
	string *apply, equipped;

    if(!environment()) return 0;
	if( !(owner = environment())->is_character() ) return 0;

	if( !stringp(equipped = query("equipped")) )
		return notify_fail("��Ŀǰ��û��װ������������\n");

	if( equipped=="wielded" ) {
		if( (object)owner->query_temp("weapon") == this_object() )
			owner->delete_temp("weapon");
		else if( (object)owner->query_temp("secondary_weapon") == this_object() )
			owner->delete_temp("secondary_weapon");
		prop = query("weapon_prop");
		owner->reset_action();
	} else if ( equipped=="worn" ) {
		owner->delete_temp("armor/" + query("armor_type") );
		prop = query("armor_prop");
	}
	if (query("rain_cover"))
	  owner->delete_temp("rain_cover");
	if (query("thunder"))
	  owner->delete_temp("thunder");

	apply = keys(prop);
	applied_prop = owner->query_temp("apply");
	for(int i = 0; i<sizeof(apply); i++)
		// To support array apply, we cannot add_temp() here.
		applied_prop[apply[i]] -= prop[apply[i]];
	delete("equipped");
	return 1;
}