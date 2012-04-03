
#include <ansi.h>                       // ∂®“Â ANSI/VT100 ÷’∂Àª˙µƒ“›Õ—¬Î

// /feature/me.c
//
// Kenny@Eternal.Civilization (2/11/1998)

#pragma optimize
#pragma save_binary


#define ECHO 0                          // ∂¡»° ‰»Î ±“™œ‘ æ◊÷‘™
#define HIDE 1                          // ∂¡»° ‰»Î ±≤ªœ‘ æ◊÷‘™
#define REFRESH 1                       // ∂¡»° ‰»Î∫Û“™÷ÿªÊª≠√Ê

void start_edit(string filename);       // ∫ÙΩ–±‡º≠∆˜£¨ø™ º±‡º≠
private void _append(object pl);        // ‘⁄”Œ±Í∫Û√Êº”◊÷
private void _append_line(object pl);   // ‘⁄”Œ±Íµ◊œ¬º”“ª–¬––
private void _backspace(object pl);     // …æ≥˝”Œ±Í«∞µƒ◊÷
protected void _confirm_save(string str, object pl); // ¿Îø™±‡º≠∆˜«∞»∑»œ¥Êµµ
private void _del_char(object pl, int bs);      // …æ≥˝”Œ±Í…œµƒ◊÷
private void _del_line(object pl);              // …æ≥˝’˚––
private int  _dispatcher(object pl);            // ∑÷≈…÷∏¡ÓµΩ≤ªÕ¨∫Ø Ω
private void _down(object pl);                  // ”Œ±ÍÕ˘œ¬“∆“ª––
private void _end(object pl);                   // Ω´”Œ±Í“∆µΩ––Œ≤
private void _esc(object pl);                   // ¥” ‰»Îƒ£ ΩªÿµΩ√¸¡Óƒ£ Ω
private void _file_end(object pl);              // Ω´”Œ±Í“∆µΩµµŒ≤
private void _file_head(object pl);             // Ω´”Œ±Í“∆µΩµµÕ∑
private void _goto_line(object pl);             // Ã¯µΩÃÿ∂®––»•
protected void _goto_line_done(string str, object pl, int rein); // »°µ√––∫≈
private void _help(object pl);                  // ∏®÷˙ª≠√Ê
private void _home(object pl);                  // Ω´”Œ±Í“∆µΩ–– ◊
protected void _input(string str, object pl, int fresh); // ∂¡µ√ ‰»Î◊÷¥Æ
private void _insert(object pl);                // ‘⁄”Œ±Í«∞√Ê≤Â◊÷
private void _insert_line(object pl);           // ‘⁄”Œ±Í…œ∑Ωº”“ª–¬––
private void _insert_exclam_mark(object pl);    // ‘⁄”Œ±Í«∞√Ê≤Â»Î“ª∏ˆ°∏!°±◊÷‘™
private void _join(object pl);                  // Ω´œ¬––Œƒ◊÷“∆µΩ¥À––∫Û√Ê
private void _keymap(object pl);                // ∂®“Â–¬π¶ƒ‹º¸
protected void _keymap_done(string str, object pl); // »°µ√∂®“Âπ¶ƒ‹º¸
private void _left(object pl);                  // ”Œ±ÍÕ˘◊Û“∆“ª◊÷
// ‘⁄◊¥Ã¨¡–œ‘ æ—∂œ¢
private varargs void _message(object pl, string str, string callback, int hide, mixed arg);
protected void _message_done(string str, object pl); // Ω· ¯—∂œ¢µƒœ‘ æ
private void _next_match(object pl);            // À——∞/ÃÊªªœ¬∏ˆ∑˚∫œ◊÷¥Æ
private void _page_down(object pl);             // Õ˘œ¬æÌ“ª“≥£®22 ––£©
private void _page_up(object pl);               // Õ˘…œæÌ“ª“≥£®22 ––£©
private void _process(object pl);               // ¥¶¿Ì ‰»Îƒ£ Ωµƒ◊÷¥Æ ‰»Î
protected void _quit(mixed unused, mixed pl);   // ¿Îø™±‡º≠∆˜
private void _refresh(object pl);               // ∏¸–¬ª≠√Ê
private void _refresh_cursor(object pl);        // ∏¸–¬”Œ±ÍŒª÷√
// ÷ÿªÊª≠√Ê
private void _refresh_screen(object pl, int s_row, int e_row, int s_col);
private void _refresh_status(object pl);        // ∏¸–¬◊¥Ã¨¡–
private void _replace(object pl);               // ◊÷¥ÆÃÊªª
protected void _replace_done(string str, object pl); // »°µ√ÃÊªª◊÷¥Æ
private void _right(object pl, int col, int extra);  // ”Œ±ÍÕ˘”““∆“ª◊÷
private void _search(object pl);                     // ◊÷¥ÆÀ——∞
protected void _search_done(string str, object pl);  // »°µ√À——∞◊÷¥Æ
private void _tab(object pl);                        // √¸¡Óƒ£ Ωœ¬ TAB º¸µƒ∂®Œª
private void _undef_key(object pl);                  // »°œ˚ƒ≥π¶ƒ‹º¸∂®“Â
protected void _undef_key_done(string str, object pl); // »°µ√÷∏∂®π¶ƒ‹º¸
private void _up(object pl);                           // ”Œ±ÍÕ˘…œ“∆“ª––
private void _write(object pl);                        // »°µ√¥¢¥Êµµ∞∏√˚≥∆
protected void _write_done(string str, object pl, int quit); // ¥¢¥Êµµ∞∏

private mapping EditedFiles=([ ]);              // ±‡º≠÷–µƒµµ∞∏

int iS_Row, iE_Row,                             // ø…º˚ ”¥∞µƒ ºƒ©––∫≈
    iS_Col, iE_Col,                             // ø…º˚ ”¥∞µƒ ºŒ¥¿∏Œª
    iRow,   iCol,                               // ”Œ±ÍŒª÷√
    is_Command_Mode, is_NewFile, is_Modify,     // µµ∞∏◊¥øˆ∆Ï±Í
    is_Substituted;                             // ¥˙ªªƒ⁄¬Î∆Ï±Í
string *sText,                                  // µµ∞∏ƒ⁄»›
       sChar, sOldChar,                         //  ‰»Î◊÷¥Æ£®√¸¡Ó£©
       sCount,                                  // √¸¡Óº∆ ˝
       sFileName,                               // ±‡º≠µµ√˚
       sSearch, sReplace;                       // À——∞/ÃÊªª◊÷¥Æ
mapping keymap;                                 // π¶ƒ‹º¸∂®“Â∂‘’’±Ì


void start_edit(string file)                // ∫ÙΩ–±‡º≠∆˜£¨ø™ º±‡º≠
{
        int  i;
        mapping me;


        if (objectp(EditedFiles[file]))
        {
                write(sprintf("%s "HIR"’˝‘⁄±‡º≠’‚∏ˆµµ∞∏£¨«Î…‘∫Ú‘Ÿ±‡º≠°£\n"NOR,
                        capitalize(EditedFiles[file]->query("id"))));
                return;
        } // if
        this_player()->set_temp("me", ([ ]));
        me = this_player()->query_temp("me");
        me["sFileName"] = file;
        if (file_size(file) <= 0)
        {        // µµ∞∏≥§∂»–°”⁄ 1
                me["sText"] = ({ "" });
                if (file_size(file) < 0)
                {        // –¬µµ
                        me["is_Command_Mode"] = 0;
                        me["is_NewFile"] = 1;
                }
        }
        else
        {
                string content=read_file(file), tabs="        ";

                // µµ∞∏≥§∂»¥Û”⁄ 0
                me["is_Command_Mode"] = 1;
                me["is_NewFile"] = 0;
                if (stringp(content))
                {
                        me["sText"] = explode(read_file(file), "\n");
                        // Ω´ TAB£¨“‘ 8 ∏ˆø’∞◊¥˙ÃÊ£¨“‘∑Ω±„”Œ±ÍŒª÷√µƒº∆À„
                        for (i=sizeof(me["sText"])-1; i>=0; i--)
                        {
                                int len=sizeof(me["sText"][i]);
                                reset_eval_cost();
                                for (int j=0; j<len; j++)
                                        if (me["sText"][i][j] == '\t')
                                                me["sText"][i] = replace_string(me["sText"][i], "\t", tabs[0..7-j%8]);
                        }
                }
                else me["sText"] = ({ "" });
        } // old file

        me["sCount"] = "";
        me["sSearch"] = me["sReplace"] = me["is_Modify"] = 0;
        me["iE_Row"] = 23;
        me["iS_Row"] = me["iS_Col"] = me["iRow"] = me["iCol"] = 1;
        EditedFiles += ([ file: this_player()->link() ]);

        // »°µ√/…Ë∂®π¶ƒ‹º¸∂®“Â∂‘’’±Ì
             if (!mapp(me["keymap"] = this_player()->query("me_keymap")))
                     me["keymap"] = ([ ]);
        if (this_player()->query("me_no_help") ||
            this_player()->query_temp("no_me_help"))
        {        // ∑«µ⁄“ª¥Œ π”√±‡º≠∆˜£¨÷±Ω”Ω¯»Î±‡º≠∆˜
                _refresh_screen(this_player(), 1, 23, 1);
                get_char("_input", HIDE, this_player());
        }
        else
        {        // µ⁄“ª¥Œ π”√±‡º≠∆˜£¨œ»ø¥π¶ƒ‹Àµ√˜
                this_player()->set_temp("no_me_help", 1);
                _help(this_player());
        }
} // start_edit()


private void _refresh_cursor(object pl)        // ∏¸–¬”Œ±ÍŒª÷√
{
        mapping me=pl->query_temp("me");
        printf(ESC "[%d;%df", me["iRow"]+1, me["iCol"]);
} // _refresh_cursor()


private void _refresh_status(object pl)        // ∏¸–¬◊¥Ã¨¡–
{
        mapping me=pl->query_temp("me");

        // “∆∂Ø”Œ±ÍµΩ (1,1)£¨”√∑¥œ‡◊÷‘™œ‘ æ◊¥Ã¨¡–
        printf(HOME + NOR + HIW + BBLU + "¡–:%4d ––:%3d %-43s %10s [√¸¡Óƒ£ Ω]" + NOR,
                me["iS_Row"]+me["iRow"]-1, me["iS_Col"]+me["iCol"]-1,
                sprintf("%s %s", me["sFileName"], (me["is_Modify"]? "(“—–ﬁ∏ƒ)":
                (me["is_NewFile"]? "(–¬µµ)": "")))[0..42],
                (me["is_Command_Mode"]? "?:∏®÷˙ª≠√Ê": "[ ‰»Îƒ£ Ω]"));
        _refresh_cursor(pl);
} // _refresh_status()


// ÷ÿªÊª≠√Ê
private void _refresh_screen(object pl, int s_row, int e_row, int s_col)
{
        int  i, temp;
        mapping me=pl->query_temp("me");


        if (e_row < s_row)                // ºÏ≤È ºƒ©––∫≈µƒœ»∫Û¥Œ–Ú
        {
                temp = e_row;
                e_row = s_row;
                s_row = temp;
        }

        if (s_row < 1) s_row = 1;
        if (s_col < 1) s_col = 1;
        if (e_row > sizeof(me["sText"])) // ≤ªƒ‹≥¨π˝µµŒ≤
                e_row = sizeof(me["sText"]);
        if (e_row-s_row > 22) e_row = s_row+22;

        me["iS_Row"] = s_row;        me["iE_Row"] = e_row;
        me["iS_Col"] = s_col;        me["iE_Col"] = s_col+79;

        printf(REF+NOR);                // «Â≥˝ª≠√Ê£¨“∆∂Ø”Œ±ÍµΩ (1,1)
        for (i=me["iS_Row"]-1; i<me["iE_Row"]; i++)
                printf("\r\n%s", me["sText"][i][me["iS_Col"]-1..me["iE_Col"]-1]);
        for (i=me["iS_Row"]+22-me["iE_Row"]; i>0; i--)
                printf("\r\n~");        // ≤ª◊„––∫≈”√ ~ ±Ì æ
        _refresh_status(pl);
} // _refresh_screen()


protected void _input(string str, object pl, int fresh) // ∂¡µ√ ‰»Î◊÷¥Æ
{
        int    i, size, bs=0;
        string *chars;
        mapping me=pl->query_temp("me");

        if (fresh)
        {        // ÷ÿªÊª≠√Ê
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
                get_char("_input", HIDE, pl);
                return;
        }

        me["is_Substituted"] = 1;       // œ»…Ë∂®¥˙ªªƒ⁄¬Î∆Ï±Í
        if (str == "")                  // ¥˙ªªµÙ Backspace/Ctrl-Backspace
        {
                str = "BACKSPACE";
                bs = 1;
        }
        if (str[0] == 27)
        {
                chars = explode(str, ESC);      // “›Õ—¬Îµƒ◊÷¥Æ£¨“‘ ESC ∂œø™
                for (i=sizeof(chars)-1; i>=0; i--)
                        chars[i] = ESC + chars[i];      // º”ªÿ ESC
                if (sizeof(chars) == 0)                 // »Ù÷ª «µ•“ª◊÷‘™ ESC
                        chars = ({ ESC });
        }
        else    chars = ({ str });

        size = sizeof(chars);
        for (i=0; i<size; i++)
        {        // ◊™ªª“›Õ—¬ÎŒ™±‡º≠∆˜ƒ⁄¬Î
                switch (chars[i])
                {
                case "\t":       me["sChar"] = "TAB";   break;
                case "\r":       me["sChar"] = "ENTER"; break;
                case ESC:        me["sChar"] = "ESC";   break;
                case ESC "OA":
                case ESC "[A":   me["sChar"] = "UP";    break;
                case ESC "OB":
                case ESC "[B":   me["sChar"] = "DOWN";  break;
                case ESC "OC":
                case ESC "[C":   me["sChar"] = "RIGHT"; break;
                case ESC "OD":
                case ESC "[D":   me["sChar"] = "LEFT";  break;
                case ESC "OH":
                case ESC "[H":
                case ESC "1~":
                case ESC "[1~":  me["sChar"] = "HOME";  break;
                case ESC "[2~":  me["sChar"] = "INSERT";break;
                case ESC "[3~":  me["sChar"] = "DELETE";break;
                case ESC "4~":   me["sChar"] = "END";   break;
                case ESC "[4~":  me["sChar"] = "END";   break;
                case ESC "[5~":  me["sChar"] = "PAGEUP";break;
                case ESC "[6~":  me["sChar"] = "PAGEDOWN";break;
                case ESC "OP":   me["sChar"] = "F1";    break;
                case ESC "OQ":   me["sChar"] = "F2";    break;
                case ESC "OR":   me["sChar"] = "F3";    break;
                case ESC "OS":   me["sChar"] = "F4";    break;
                case ESC "m":    me["sChar"] = "F5";    break;
                case ESC "[17~": me["sChar"] = "F6";    break;
                case ESC "[18~": me["sChar"] = "F7";    break;
                case ESC "[19~": me["sChar"] = "F8";    break;
                case ESC "[20~": me["sChar"] = "F9";    break;
                case ESC "[21~": me["sChar"] = "F10";   break;
                case ESC "[23~": me["sChar"] = "F11";   break;
                case ESC "[24~": me["sChar"] = "F12";   break;
                default:
                        if (sizeof(chars[i])==1 &&
                            0<chars[i][0] && chars[i][0]<27)
                                switch (chars[i][0])
                                { // ¥˙ªªƒ⁄¬Î£¨ π‘⁄ ‰»Îƒ£ Ω“≤ƒ‹ π”√÷∏¡Ó
                                case  1: me["sChar"]="Ctrl-A"; break;
                                case  2: me["sChar"]="Ctrl-B"; break;
                                case  4: me["sChar"]="Ctrl-D"; break;
                                case  5: me["sChar"]="Ctrl-E"; break;
                                case  6: me["sChar"]="Ctrl-F"; break;
                                case  7: me["sChar"]="Ctrl-G"; break;
                                case 10: me["sChar"]="Ctrl-J"; break;
                                case 11: me["sChar"]="Ctrl-K"; break;
                                case 12: me["sChar"]="Ctrl-L"; break;
                                case 14: me["sChar"]="Ctrl-N"; break;
                                case 15: me["sChar"]="Ctrl-O"; break;
                                case 16: me["sChar"]="Ctrl-P"; break;
                                case 17: me["sChar"]="Ctrl-Q"; break;
                                case 18: me["sChar"]="Ctrl-R"; break;
                                case 19: me["sChar"]="Ctrl-S"; break;
                                case 20: me["sChar"]="Ctrl-T"; break;
                                case 21: me["sChar"]="Ctrl-U"; break;
                                case 22: me["sChar"]="Ctrl-V"; break;
                                case 23: me["sChar"]="Ctrl-W"; break;
                                case 24: me["sChar"]="Ctrl-X"; break;
                                case 25: me["sChar"]="Ctrl-Y"; break;
                                case 26: me["sChar"]="Ctrl-Z"; break;
                        } // switch
                        else
                        {
                                me["sChar"] = chars[i];            // ¥ÀŒ™∆’Õ®◊÷¥Æ
                                if (!bs) me["is_Substituted"] = 0; // «Â≥˝¥˙ªªƒ⁄¬Î∆Ï±Í
                        } // else
                } // switch
                // Ω´◊™ªª∫Ûµƒ◊÷¥ÆÀÕµΩ∑÷≈…÷∏¡Ó∫Ø Ω¥¶¿Ì£¨≤¢µ»¥˝∂¡»°œ¬∏ˆ ‰»Î
                if (_dispatcher(pl) && i==size-1) get_char("_input", HIDE, pl);
        } // for
} // input()


private int _dispatcher(object pl)                // ∑÷≈…÷∏¡ÓµΩ≤ªÕ¨∫Ø Ω
{
        int  i, count=1;
        mapping me=pl->query_temp("me");


        if ( me["is_Command_Mode"] ||
            (me["is_Substituted"] && // »√ ‰»Îƒ£ Ω“≤ƒ‹ π”√ƒ≥–©÷∏¡Ó
             // ’‚∂˛∏ˆ÷∏¡Ó≤ª‘⁄’‚¥¶¿Ì
             me["sChar"]!="ENTER" && me["sChar"]!="TAB") )
        {        // œ÷‘⁄ «√¸¡Óƒ£ Ω
                if (sizeof(me["sChar"])!=1 && !me["is_Substituted"])
                        return 1;
                // ºÏ≤Èπ¶ƒ‹º¸∂®“Â∂‘’’±Ì£¨÷ÿ–¬∂®“Â√¸¡Ó
                if (!undefinedp(me["keymap"][me["sChar"]]))
                        me["sChar"] =
                        me["keymap"][me["sChar"]];
                if (!stringp(me["sChar"])) return 1; // Type checking...
                // ºÏ≤È « ˝◊÷µƒª∞£¨æÕ «∏Ωº”µΩ√¸¡Óº∆ ˝¿Ô
                if ('0'<=me["sChar"][0] && me["sChar"][0]<='9')
                        me["sCount"] += me["sChar"];
                else
                {
                        sscanf(me["sCount"], "%d", count);
                        me["sCount"] = ""; // º∆ ˝∆˜πÈ¡„
                        // ÷ÿ∏≤…œ∏ˆ÷∏¡Ó
                        if (me["sChar"] == ".")
                                me["sChar"] = me["sOldChar"];
                        else        // º«¬º’‚¥Œµƒ÷∏¡Ó
                                me["sOldChar"] = me["sChar"];
                }

                for (i=0; i<count; i++)
                        switch (me["sChar"]) // ∑÷≈…÷∏¡ÓµΩ≤ªÕ¨∫Ø Ω
                        {
                        case "a":_append(pl);                           break;
                        case "d":
                        case "Ctrl-D": _del_line(pl);                  break;
                        case "f":
                        case "Ctrl-Z": _refresh(pl);                break;
                        case "g":
                        case "Ctrl-G": _goto_line(pl);                break;
                        case "h":
                        case "LEFT":
                        case "Ctrl-J": _left(pl);                   break;
                        case "i":      _insert(pl);                break;
                        case "j":
                        case "DOWN":
                        case "Ctrl-K": _down(pl);                break;
                        case "k":
                        case "UP":
                        case "Ctrl-O": _up(pl);                        break;
                        case "l":
                        case "RIGHT":
                        case "Ctrl-L": _right(pl, 1,
                                                (me["is_Command_Mode"]?0:1));
                                       break;
                        case "m": _keymap(pl);                        break;
                        case "n":
                        case "Ctrl-N": _next_match(pl);                break;
                        case "o": _append_line(pl);                    break;
                        case "q":        // ±Ì æ≤ª‘Ÿ∂¡»°–¬ ‰»Î£¨Ω· ¯±‡º≠
                        case "F4":
                        case "Ctrl-Q": _quit(0, pl);                return 0;
                        case "r":
                        case "Ctrl-R": _replace(pl);                break;
                        case "s":
                        case "Ctrl-S": _search(pl);                   break;
                        case "u": _undef_key(pl);                break;
                        case "w":
                        case "F2":
                        case "Ctrl-W": _write(pl);                      break;
                        case "x":
                        case "DELETE":
                        case "Ctrl-X":   _del_char(pl, 0);        break;
                        case "A":
                        case "HOME":
                        case "Ctrl-A":   _home(pl);        break;
                        case "B":
                        case "PAGEUP":
                        case "Ctrl-B":   _page_up(pl);        break;
                        case "E":
                        case "END":
                        case "Ctrl-E":   _end(pl);        break;
                        case "F":
                        case "PAGEDOWN":
                        case "Ctrl-F":   _page_down(pl);        break;
                        case "J":
                        case "Ctrl-P": _join(pl);         break;
                        case "O": _insert_line(pl);         break;
                        case "U":
                        case "Ctrl-U": _file_head(pl);        break;
                        case "V":
                        case "Ctrl-V": _file_end(pl);        break;
                        case "?":
                        case "F1":
                        case "Ctrl-Y": _help(pl);         break;
                        case "~":
                        case "Ctrl-T": _insert_exclam_mark(pl);        break;
                        case "BACKSPACE": _backspace(pl);          break;
                        case "ESC": _esc(pl);                         break;
                        case "TAB": _tab(pl);                        break;
                        } // switch
        } // if me["is_Command_Mode"]
        else
                _process(pl);                // ¥¶¿Ì ‰»Îƒ£ Ωµƒ◊÷¥Æ ‰»Î

        return 1;                        // ±Ì æºÃ–¯∂¡»°–¬ ‰»Î£¨ºÃ–¯±‡º≠
} // dispatcher()


private void _append(object pl)                // ‘⁄”Œ±Í∫Û√Êº”◊÷
{
        mapping me=pl->query_temp("me");

        if (sizeof(me["sText"]) == 0) return;
        me["is_Command_Mode"] = 0;
        _refresh_status(pl);
        _right(pl, 1, 1);
} // _append()


private void _append_line(object pl)        // ‘⁄”Œ±Íµ◊œ¬º”“ª–¬––
{
        string *text;
        mapping me=pl->query_temp("me");

        me["is_Command_Mode"] = me["is_NewFile"] = 0;
        me["is_Modify"] = 1;
        text = me["sText"][0..me["iS_Row"]+me["iRow"]-2] + ({ "" }) +
                me["sText"][me["iS_Row"]+me["iRow"]-1..<1];
        me["sText"] = text;
        _refresh_screen(pl, me["iS_Row"], sizeof(me["sText"]), 1);
        me["iCol"] = 1;
        _down(pl);
} // _append_line()


private void _backspace(object pl)        // …æ≥˝”Œ±Í«∞µƒ◊÷
{
        mapping me=pl->query_temp("me");

        if (me["iS_Col"] == me["iCol"])        return;
        _left(pl);
        _del_char(pl, 1);
} // _backspace()


protected void _confirm_save(string str, object pl) // ¿Îø™±‡º≠∆˜«∞»∑»œ¥Êµµ
{
        mapping me=pl->query_temp("me");

        if (str=="y" || str=="Y") return _write_done("", pl, 1);
        me["is_Modify"] = 0;                // …Ë∂®°∏Œ¥–ﬁ∏ƒ°±∆Ï±Í
        _quit(0, pl);
} // _confirm_save()


private void _del_char(object pl, int bs)                // …æ≥˝”Œ±Í…œµƒ◊÷
{
        int    go_left=0;                //  «∑Ò‘⁄…æ≥˝∫Û“™◊Û“∆”Œ±Í
        string str;
        mapping me=pl->query_temp("me");


        if (sizeof(me["sText"])==0 ||
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])==0)
             return;
        if (me["is_NewFile"] || !me["is_Modify"])
        {
                me["is_NewFile"] = 0;
                me["is_Modify"] = 1;
                _refresh_status(pl);
        }
        if (me["iS_Col"]+me["iCol"]-2 >=
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]))
                return;
        str = me["sText"][me["iS_Row"]+me["iRow"]-2][0..me["iS_Col"]+
                me["iCol"]-3];
        // ºÏ≤È «∑Ò–Ë“™∏Ωº” £œ¬µƒƒ⁄»›
        if (me["iS_Col"]+me["iCol"]-1 <
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]))
                str += me["sText"][me["iS_Row"]+
                me["iRow"]-2][me["iS_Col"]+me["iCol"]-1..<1];
        else        go_left = 1;                // “ÚŒ™ «…æ≥˝––Œ≤µƒ◊÷£¨À˘“‘“™◊Û“∆”Œ±Í
        me["sText"][me["iS_Row"]+me["iRow"]-2] = str;
        printf(ESC "[%d;1f%-80s", me["iRow"]+1,        me["sText"][me["iS_Row"]+
                me["iRow"]-2][me["iS_Col"]-1..me["iE_Col"]-1]);
        if (go_left && !bs) _left(pl);
        else        _refresh_cursor(pl);
} // _del_char()


private void _del_line(object pl)        // …æ≥˝’˚––
{
        string *text=({ });
        mapping me=pl->query_temp("me");

        me["is_NewFile"] = 0;
        me["is_Modify"] = 1;
        if (me["iS_Row"]+me["iRow"]-2 > 0)
                text = me["sText"][0..me["iS_Row"]+me["iRow"]-3];
        text += me["sText"][me["iS_Row"]+me["iRow"]-1..<1];
        me["sText"] = text;
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
        if (me["iS_Row"]+me["iRow"]-1 > sizeof(me["sText"]))
                _up(pl);                // »Ù «…æ≥˝◊Ó∫Û“ª––£¨æÕ“™…œ“∆”Œ±Í
        // »Ù”Œ±Íµƒ–¬Œª÷√≥¨π˝––Œ≤£¨‘Ú“∆∂Ø”Œ±ÍµΩ––Œ≤
        else if (me["iS_Col"]+me["iCol"]-1 >
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]))
            _end(pl);
} // _del_line()


private void _down(object pl)                // ”Œ±ÍÕ˘œ¬“∆“ª––
{
        int  acc;
        mapping me=pl->query_temp("me");


        // ºÏ≤È «∑Ò“—‘⁄µµŒ≤
        if (me["iS_Row"]+me["iRow"]-1 >= sizeof(me["sText"]))
                // »Ù“—œ‘ æµµŒ≤œ¬“ª––£¨‘Ú≤ª◊ˆ ¬
                if (me["iRow"] < 23) return;
                else
                {        // ∂‡œ‘ ”µµŒ≤œ¬“ª––£¨“‘Õªœ‘µµŒ≤µƒ¥Ê‘⁄
                        me["iS_Row"]++;
                        printf(ESC "[24;1f\r\n~");
                        me["iRow"] = 22;
                }
        else if (++me["iRow"] > 23)
        {        // ª≠√Ê…œæÌ£¨œ‘ æœ¬“ª––
                me["iS_Row"]++;                me["iE_Row"]++;
                printf(ESC "[24;1f\r\n%s", me["sText"][me["iE_Row"]-1]
                        [me["iS_Col"]-1..me["iE_Col"]-1]);
                me["iRow"] = 23;
        }

        // »Ù”Œ±Íµƒ–¬Œª÷√≥¨π˝––Œ≤£¨‘Ú“∆∂Ø”Œ±ÍµΩ––Œ≤
        if (me["iS_Col"]+me["iCol"]-1 >
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]))
                me["iCol"] = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-
                        me["iS_Col"]+(me["is_Command_Mode"]?1:2);
        // »Ù¥À––Œﬁ◊÷£¨‘Ú∂®Œª‘⁄µ⁄“ª¿∏
        if (me["iCol"]==0 && me["iS_Col"]==1) me["iCol"] = 1;
        if (me["iCol"] > 0)_refresh_status(pl);
        else
        {        // ”Œ±Íµƒ–¬Œª÷√‘⁄‘≠ª≠√ÊÕ‚£¨–Ë“™÷ÿªÊª≠√Ê
                acc = me["iCol"];        me["iCol"] = 1;
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"],
                        me["iS_Col"]+acc-1);
        }
} // _down()


private void _end(object pl)                // Ω´”Œ±Í“∆µΩ––Œ≤
{
        mapping me=pl->query_temp("me");

        if (sizeof(me["sText"]) == 0) return;
        // º∆À„––Œ≤µƒŒª÷√
        me["iCol"] = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-
                me["iS_Col"]+(me["is_Command_Mode"]?1:2);
        if (me["iCol"] == 0) me["iCol"] = 1; // »Ù¥À––Œﬁ◊÷£¨‘Ú∂®Œª‘⁄µ⁄“ª¿∏
        if (sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]) < me["iE_Col"])
                    _refresh_status(pl);
        else
        {        // ”Œ±Íµƒ–¬Œª÷√‘⁄‘≠ª≠√ÊÕ‚£¨–Ë“™÷ÿªÊª≠√Ê
                me["iCol"] = 79;
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]+
                        (sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-
                        me["iE_Col"]+1));
        }
} // _end()


private void _esc(object pl)                // ¥” ‰»Îƒ£ ΩªÿµΩ√¸¡Óƒ£ Ω
{
        mapping me=pl->query_temp("me");
        me["is_Command_Mode"] = 1;
        _left(pl);
} // _esc()


private void _file_end(object pl)        // Ω´”Œ±Í“∆µΩµµŒ≤
{
        mapping me=pl->query_temp("me");
        if (sizeof(me["sText"]) == 0) return;
        _goto_line_done(sprintf("%d", sizeof(me["sText"])), pl, 0);
} // _file_end()


private void _file_head(object pl)        // Ω´”Œ±Í“∆µΩµµÕ∑
{
        mapping me=pl->query_temp("me");
        if (sizeof(me["sText"]) == 0) return;
        _goto_line_done("1", pl, 0);
} // _file_head()


private void _goto_line(object pl)        // Ã¯µΩÃÿ∂®––»•
{
        mapping me=pl->query_temp("me");
        _message(pl, sprintf("[1;44m«Î ‰»Î––∫≈°∏÷±Ω”∞¥ ENTER »°œ˚£¨1~%d°±£∫[m",
                sizeof(me["sText"])), "_goto_line_done", ECHO, 1);
} // _goto_line()


protected void _goto_line_done(string str, object pl, int rein) // »°µ√––∫≈
{
        int        no;
        mapping me=pl->query_temp("me");

        if (str == "") return _message_done("", pl);
        if (sscanf(str, "%d", no)!=1 || no<1 || no>sizeof(me["sText"]))
                return _message(pl, "[1;31;5m¥ÌŒÛµƒ––∫≈£°[m", "_message_done", HIDE);

        me["iCol"] = 1;
        if (me["iS_Row"]<=no && no<=me["iE_Row"])
        {        // ÷∏∂®––∫≈‘⁄‘≠ø… ”∑∂Œß÷–
                me["iRow"] = no-me["iS_Row"]+1;
                _refresh_status(pl);
        }
        else
        {        // ÷∏∂®––∫≈≤ª‘⁄‘≠ø… ”∑∂Œß÷–£¨–Ë“™÷ÿªÊª≠√Ê
                me["iS_Row"] = no-11;
                if (me["iS_Row"] < 1)        me["iS_Row"] = 1;
                if (me["iE_Row"] < no+11)        me["iE_Row"] = no+11;
                me["iRow"] = no-me["iS_Row"]+1;
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], 1);
        }
        if (rein) get_char("_input", HIDE, pl); // ºÏ≤È «∑Ò–Ë“™∂¡»°œ¬¥Œ ‰»Î
} // _goto_line_done()


private void _help(object pl)                // ∏®÷˙ª≠√Ê
{
        printf(REF +
"[1;41m°æ LPMud »´”©ƒª±‡º≠∆˜ °ø1.3 ∞Ê 9/28/1997  by –ª≥ÁœÈ(Kenny Hsieh), ∞Ê»®À˘”–.[m

[1;44m                                “ª∞„√¸¡Ó                                   [m
w ^W    ¥¢¥Êµµ∞∏       q ^Q    ¿Îø™±‡º≠∆˜        ? ^Y    ∏®÷˙ª≠√Ê°∏¥Àª≠√Ê°±
f ^Z    ÷ÿªÊª≠√Ê
[1;44m                               ”Œ±Í“∆∂Ø÷∏¡Ó                                [m
k ^O °¸   œÚ…œ     j ^K °˝   œÚœ¬      h ^J °˚   œÚ◊Û      l ^L °˙   œÚ”“
A ^A Home ÷¡–– ◊   E ^E End ÷¡––Œ≤     B ^B PgUp …œ“ª“≥    F ^F PgDn œ¬“ª“≥
U ^U      µµ∞∏ø™Õ∑ V ^V µµ∞∏Ω·Œ≤       s ^S      ◊÷¥ÆÀ——∞  r ^R    ◊÷¥ÆÃÊªª
g ^G      Ã¯µΩÃÿ∂®––»•                 n ^N      À——∞/ÃÊªªœ¬∏ˆ∑˚∫œ◊÷¥Æ
[1;44m                                 …æ≥˝√¸¡Ó                                  [m
d ^D    …æ≥˝’˚––       x ^X    …æ≥˝”Œ±Í…œµƒ◊÷
~ ^T ‘⁄”Œ±Í«∞√Ê≤Â»Î“ª∏ˆ°∏!°±◊÷‘™       J ^P    Ω´œ¬––Œƒ◊÷Ω”µΩ¥À––∫Û√Ê
[1;44m                             √¸¡Óƒ£ ΩÃÿ”√÷∏¡Ó                              [m
a  ‘⁄”Œ±Í∫Û√Êº”◊÷      i  ‘⁄”Œ±Í«∞√Ê≤Â◊÷         m  ∂®“Â–¬π¶ƒ‹º¸\n");
        printf(
"u  »°œ˚ƒ≥π¶ƒ‹º¸∂®“Â    o  ‘⁄”Œ±Íµ◊œ¬º”“ª–¬––     O  ‘⁄”Œ±Í…œ∑Ωº”“ª–¬––
.  ÷ÿ∏≤…œ∏ˆ÷∏¡Ó
[1;31mPS. A ^A Home ÷¡–– ◊ A¥˙±Ì÷∏¡Óƒ£ ΩøÏÀŸº¸£¨^A(º¥Ctrl+A)¥˙±Ì ‰»Îƒ£ Ω π”√£¨Home
¥˙±Ìº¸≈Ã π”√£¨◊Ó∫Û « π”√Àµ√˜°£[m

ª∂”≠¥´≤•¥À±‡º≠∆˜£¨µ´«Î±£¡Ù∞Ê»®–˚∏Ê£¨”–»Œ∫ŒŒ Ã‚∫ÕΩ®“È«Î¡™¬ÁŒ“£∫
kenny@cindy.cis.nctu.edu.tw°£
                           [;1m[∞¥»Œ“‚º¸ªÿµΩ±‡º≠∆˜][m");
        get_char("_input", HIDE, pl, REFRESH); // ∂¡»°∞¥º¸“‘÷ÿªÊª≠√Ê
} // _help()


private void _home(object pl)                // Ω´”Œ±Í“∆µΩ–– ◊
{
        mapping me=pl->query_temp("me");

        me["iCol"] = 1;
        if (me["iS_Col"] == 1)_refresh_status(pl);
        else        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], 1);
} // _home()


private void _insert(object pl)                // ‘⁄”Œ±Í«∞√Ê≤Â◊÷
{
        mapping me=pl->query_temp("me");

        if (sizeof(me["sText"]) == 0) return;
        me["is_Command_Mode"] = 0;
        _refresh_status(pl);
} // _insert()


private void _insert_line(object pl)        // ‘⁄”Œ±Í…œ∑Ωº”“ª–¬––
{
        string *text=({ });
        mapping me=pl->query_temp("me");

        me["is_Command_Mode"] = me["is_NewFile"] = 0;
        me["is_Modify"] = 1;
        // ºÏ≤È «∑Ò”Œ±Í…œ∑Ω «∑Ò”–ƒ⁄»›
        if (me["iS_Row"]+me["iRow"]-3 >= 0)
                text = me["sText"][0..me["iS_Row"]+me["iRow"]-3];
        text += ({ "" });
        text += me["sText"][me["iS_Row"]+me["iRow"]-2..<1];
        me["sText"] = text;
        me["iCol"] = 1;
        _refresh_screen(pl, me["iS_Row"], sizeof(me["sText"]), 1);
} // _insert_line()


private void _insert_exclam_mark(object pl) // ‘⁄”Œ±Í«∞√Ê≤Â»Î“ª∏ˆ°∏!°±◊÷‘™
{
        mapping me=pl->query_temp("me");

        // “ÚŒ™Œﬁ∑®’˝≥£ ‰»Î°∏!°±£¨À˘“‘Ãÿµÿº”¥À∫Ø Ω“‘ ‰»Î°∏!°±°£
        if (sizeof(me["sText"]) == 0) return;
        me["sChar"] = "!";
        _process(pl);
} // _insert_!()


private void _join(object pl)                // Ω´œ¬––Œƒ◊÷“∆µΩ¥À––∫Û√Ê
{
        string *text=({ });
        mapping me=pl->query_temp("me");


        if (me["iS_Row"]+me["iRow"]-1 >= sizeof(me["sText"])) return;

        me["is_NewFile"] = 0;
        me["is_Modify"] = 1;
        _end(pl);                        // œ»Ω´”Œ±Í“∆µΩ––Œ≤
        text = me["sText"][0..me["iS_Row"]+me["iRow"]-2];
        if (sizeof(me["sText"][me["iS_Row"]+me["iRow"]-1]))
        {        // »Ùœ¬––”–ƒ⁄»›∏Ωº”…œ¿¥
                text[me["iS_Row"]+me["iRow"]-2] += (" "+
                        me["sText"][me["iS_Row"]+me["iRow"]-1]);
                _right(pl, 1, 1);
        }
        text += me["sText"][me["iS_Row"]+me["iRow"]..<1];
        me["sText"] = text;
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
} // _join()


private void _keymap(object pl)                // ∂®“Â–¬π¶ƒ‹º¸
{
        _message(pl, "«Î ‰»Î–¬∂®“Âº¸∫Õ‘≠π¶ƒ‹º¸£®÷±Ω”∞¥ ENTER »°œ˚£¨“‘ø’∞◊∏Ùø™)£∫",
                "_keymap_done", ECHO);
} // _keymap()


protected void _keymap_done(string str, object pl) // »°µ√∂®“Âπ¶ƒ‹º¸
{
        string old, _new;
        mapping me=pl->query_temp("me");

        _refresh_status(pl);
        if (str != "")
        {        // »Ù”–◊ ¡œ ‰»Î
                if (sscanf(str, "%s %s", _new, old) != 2)
                        return _message(pl, " ‰»Î∏Ò Ω¥ÌŒÛ°£", "_message_done",
                                HIDE);
                me["keymap"][_new] = old;
                _message(pl, sprintf("∫√¡À£¨¥”¥À“‘∫Û–¬∂®“Âº¸°∏%s°±æÕ”–‘≠π¶ƒ‹º¸°∏%s°±µƒπ¶ƒ‹¡À£°",
                        _new, old), "_message_done", HIDE);
        }
        else        get_char("_input", HIDE, pl); // »°œ˚ ‰»Î£¨ºÃ–¯∂¡»°œ¬∏ˆ ‰»Î
} // _keymap_done()


private void _left(object pl)                // ”Œ±ÍÕ˘◊Û“∆“ª◊÷
{
        mapping me=pl->query_temp("me");

        if (me["iS_Col"]==1 && me["iCol"]==1) return _refresh_status(pl);
        if (--me["iCol"] < 1)
        {        // ”Œ±Íµƒ–¬Œª÷√‘⁄‘≠ª≠√ÊÕ‚£¨–Ë“™÷ÿªÊª≠√Ê
                // »Ù◊Û“∆ 8 ¿∏Ã´∂‡µƒª∞£¨æÕ÷ª◊Û“∆“ª¿∏
                if (me["iS_Col"]-8 < 1)
                        me["iCol"] = me["iS_Col"]-1;
                else        me["iCol"] = 8; // ≤ª»ªæÕ…Ë∂®”Œ±Í‘⁄µ⁄ 8 ¿∏Œª÷√
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"],
                        me["iS_Col"]-me["iCol"]);
                return;
        }
        _refresh_status(pl);
} // _left()


// ‘⁄◊¥Ã¨¡–œ‘ æ—∂œ¢
private varargs void _message(object pl, string str, string callback, int hide, mixed arg)
{
        printf(HOME + NOR + REV);        // “∆∂Ø”Œ±ÍµΩ (1,1)£¨…Ë∂®∑¥œ‡◊÷‘™œ‘ æ
        // «Â≥˝‘≠◊¥Ã¨¡–µƒ—∂œ¢
        printf("                                                                                ");
        printf(HOME + str);                // “∆∂Ø”Œ±ÍµΩ (1,1)£¨‘Ÿœ‘ æ—∂œ¢
        input_to(callback, hide, pl, arg); // ∂¡»° ‰»Î◊ ¡œ
} // _message()


protected void _message_done(string str, object pl) // Ω· ¯—∂œ¢µƒœ‘ æ
{
        _refresh_status(pl);
        get_char("_input", HIDE, pl);        // ºÃ–¯∂¡»° ‰»Î◊÷¥Æ
} // _message_done()


private void _next_match(object pl)                // À——∞/ÃÊªªœ¬∏ˆ∑˚∫œ◊÷¥Æ
{
        mapping me=pl->query_temp("me");
        string str="";
        // …Ë∂®∆ ºÀ——∞Œª÷√Œ™”Œ±Íœ÷‘⁄Œª÷√
        int    j=me["iS_Col"]+me["iCol"]-1,
               i, ofs;


        if (!stringp(me["sSearch"])) return; // »Ù√ªœ»…Ë∂®À——∞◊÷¥Æ£¨≤ª◊ˆ ¬

        for (i=me["iS_Row"]+me["iRow"]-2; i<sizeof(me["sText"]); i++)
        {
                if ((ofs = strsrch(me["sText"][i][j-1..<1], me["sSearch"]))
                    == -1)
                        j = 1; // ’‚––√ª’“µΩµƒª∞£¨…Ë∂®œ¬––¥”µ⁄“ª¿∏ø™ º’“
                else
                {        // ’“µΩ÷∏∂®◊÷¥Æ¡À, “∆∂Ø”Œ±ÍµΩƒøµƒ––
                        _goto_line_done(sprintf("%d", i+1), pl, 0);
                        me["iCol"] = j+ofs; // º∆À„÷∏∂®◊÷¥Æµƒæ¯∂‘Œª÷√
                        // »Ù÷∏∂®◊÷¥Æ¬‰‘⁄‘≠ª≠√ÊÕ‚£¨‘Ú÷ÿªÊª≠√Ê
                        if (me["iCol"]<me["iS_Col"] ||
                            me["iCol"]+strlen(me["sSearch"])>me["iS_Col"]+79)
                                _refresh_screen(pl, me["iS_Row"], me["iE_Row"],
                                        me["iCol"]);
                        if (stringp(me["sReplace"]))
                        {        // –Ë“™ÃÊªª◊÷¥Æ
                                me["is_NewFile"] = 0;
                                me["is_Modify"] = 1;
                                // ∏Ωº””Œ±Í«∞ƒ⁄»›
                                str = me["sText"][i][0..me["iCol"]-2];
                                str += me["sReplace"];
                                str += (me["sText"][i][me["iCol"]+
                                        strlen(me["sSearch"])-1..<1]);
                                me["sText"][i] = str;
                                // »ÙÃÊªª◊÷¥Æ¬‰‘⁄‘≠ª≠√ÊÕ‚£¨‘Ú÷ÿªÊª≠√Ê
                                if (me["iCol"]<me["iS_Col"] ||
                                    me["iCol"]+strlen(me["sReplace"])
                                    > me["iS_Col"]+79)
                                        _refresh_screen(pl, me["iS_Row"],
                                                me["iE_Row"], me["iCol"]);
                                // Ω´”Œ∆Ø“∆µΩÃÊªª◊÷¥Æ∫Û√Ê
                                me["iCol"] = me["iCol"]+strlen(me["sReplace"])-
                                        me["iS_Col"]+1;
                                printf(ESC "[%d;1f%-80s", me["iRow"]+1,
                                        me["sText"][me["iS_Row"]+
                                        me["iRow"]-2][me["iS_Col"]-1
                                        ..me["iE_Col"]-1]);
                        }
                        // Ω´”Œ∆Ø“∆µΩÀ——∞◊÷¥Æ∫Û√Ê
                        else        me["iCol"] = me["iCol"]+strlen(me["sSearch"])-
                                        me["iS_Col"]+1;
                        _refresh_status(pl);
                        break;
                } // if found
        } // for each row
        if (i >= sizeof(me["sText"]))
                _message(pl, "’“≤ªµΩ÷∏∂®◊÷¥Æ£°", "_message_done", HIDE);
        else        get_char("_input", HIDE, pl); // ∂¡»°œ¬∏ˆ ‰»Î◊÷¥Æ
} // _next_match()


private void _page_down(object pl)        // Õ˘œ¬æÌ“ª“≥£®22 ––£©
{
        mapping me=pl->query_temp("me");

        if (me["iS_Row"]+22 > sizeof(me["sText"])) return; // ºÏ≤È «∑Ò≤ªƒ‹‘ŸæÌ¡À
        me["iS_Row"] += 22;        me["iE_Row"] += 22;
        // ºÏ≤È”Œ±Íµƒ–¬Œª÷√ «∑Ò≥¨π˝µµŒ≤
        if (me["iS_Row"]+me["iRow"]-1 > sizeof(me["sText"]))
                me["iRow"] = sizeof(me["sText"])-me["iS_Row"]+1;
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
        // »Ù”Œ±Íµƒ–¬Œª÷√≥¨π˝––Œ≤£¨‘Ú“∆∂Ø”Œ±ÍµΩ––Œ≤
        if (me["iS_Col"]+me["iCol"]-1 > sizeof(me["sText"][me["iS_Row"]+
                me["iRow"]-2]))
                _end(pl);
} // _page_down()


private void _page_up(object pl)        // Õ˘…œæÌ“ª“≥£®22 ––£©
{
        mapping me=pl->query_temp("me");

        if (me["iS_Row"] <= 1) return; // ºÏ≤È «∑Ò≤ªƒ‹‘ŸæÌ¡À
        me["iS_Row"] -= 22;
        if (me["iS_Row"] < 1) me["iS_Row"] = 1; // ◊Ó∂‡÷ªƒ‹∑≠µΩµ⁄“ª¡–
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
        // »Ù”Œ±Íµƒ–¬Œª÷√≥¨π˝––Œ≤£¨‘Ú“∆∂Ø”Œ±ÍµΩ––Œ≤
        if (me["iS_Col"]+me["iCol"]-1 >
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]))
            _end(pl);
} // _page_up()


private void _process(object pl)        // ¥¶¿Ì ‰»Îƒ£ Ωµƒ◊÷¥Æ ‰»Î
{
        int    i, size;
        string str, rest, *input;
        mapping me=pl->query_temp("me");


        if (me["is_Modify"]==0 || me["is_NewFile"]==1)
        {
                me["is_NewFile"] = 0;
                me["is_Modify"] = 1;
                _refresh_status(pl);
        }
        if (!me["is_Substituted"] && (strsrch(me["sChar"], "\r")!=-1 ||
            strsrch(me["sChar"], "\n")!=-1))
                me["is_Substituted"] = 1; // …Ë∂®ƒ⁄¬Î¥˙ªª∆Ï±Í
        me["sChar"] = replace_string(me["sChar"], "\t", "        ");
        me["sChar"] = replace_string(me["sChar"], "\r", "\rENTER\r");
        me["sChar"] = replace_string(me["sChar"], "\n", "\rENTER\r");
        input = explode(me["sChar"], "\r");

        size = sizeof(input);
        for (i=0; i<size; i++)                // “ª¥Œ¥¶¿Ì“ª–– ‰»Î
        {
                if (me["is_Substituted"] && input[i] == "ENTER")
                {        // µ±º¸»Î ENTER  ±£¨“™Ω´”Œ±Í÷Æ∫Ûµƒƒ⁄»›“∆µΩœ¬√Êµƒ–¬––
                        rest = me["sText"][me["iS_Row"]+
                                me["iRow"]-2][me["iS_Col"]+me["iCol"]-2..<1];
                        me["sText"][me["iS_Row"]+me["iRow"]-2] =
                                me["sText"][me["iS_Row"]+
                                me["iRow"]-2][0..me["iS_Col"]+me["iCol"]-3];
                        _append_line(pl); // ‘⁄”Œ±Íµ◊œ¬º”“ª–¬––
                        // –¬––µƒƒ⁄»› «‘≠”Œ±ÍŒª÷√“‘∫Ûµƒƒ⁄»›
                        me["sText"][me["iS_Row"]+me["iRow"]-2] = rest;
                        continue;
                }

                //  ‰»Î◊÷¥Æ≤ª « ENTER  ±, ¥¶¿Ì TAB µƒ∂®Œª
                if (me["is_Substituted"] && input[i] == "TAB")
                        input[i] = "        "[0..7-(me["iCol"]-1)%8];
                str = me["sText"][me["iS_Row"]+me["iRow"]-2][0..me["iS_Col"]+
                        me["iCol"]-3] + input[i] + me["sText"][me["iS_Row"] +
                        me["iRow"]-2][me["iS_Col"]+ me["iCol"]-2..<1];
                me["sText"][me["iS_Row"]+me["iRow"]-2] = str;
                _right(pl, sizeof(input[i]), 1);
        } // for

        printf(ESC "[%d;1f%s", me["iRow"]+1, me["sText"][me["iS_Row"]+
                me["iRow"]-2][me["iS_Col"]-1..me["iE_Col"]-1]);
        _refresh_cursor(pl);
} // _process()


protected void _quit(mixed unused, mixed pl) // ¿Îø™±‡º≠∆˜
{
        mapping me;

        seteuid(geteuid(pl));
        me = pl->query_temp("me");
        if (me["is_Modify"])
                return _message(pl, "[44;1;31m¥Àµµ∞∏“—∏¸∏ƒ£¨«ÎŒ –Ë“™¥Êµµ¬(y/N)£ø[N][m",
                        "_confirm_save", ECHO);
        me["iRow"] = 23;
        _refresh_cursor(pl);                // “∆∂Ø”Œ±ÍµΩ◊Ó∫Û“ª––
        printf(NOR "\r\n");
        // »Ùπ¶ƒ‹º¸∂®“Â∂‘’’±Ì «ø’µƒ£¨æÕ«Â≥˝ÕÊº“…Ì…œµƒº«¬º£¨≤ª»ªæÕº«¬º‘⁄ÕÊº“…Ì…œ
        if (sizeof(me["keymap"]) == 0) pl->delete("me_keymap");
        else pl->set("me_keymap", me["keymap"]);
        map_delete(EditedFiles, pl->query_temp("me/sFileName"));
        pl->delete_temp("me"); // «Â≥˝±‡º≠∆˜”√µΩµƒ‘› ±±‰ ˝
} // _quit()


private void _refresh(object pl)        // ∏¸–¬ª≠√Ê
{
        mapping me=pl->query_temp("me");
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
} // _refresh()


private void _replace(object pl)        // ◊÷¥ÆÃÊªª
{
        _message(pl, "[1;44mÀ——∞/ÃÊªª◊÷¥Æ°∏÷±Ω”∞¥ENTER»°œ˚,“‘ø’∞◊∏Ùø™°±£∫[m",
                "_replace_done", ECHO);
} // _replace()


protected void _replace_done(string str, object pl) // »°µ√ÃÊªª◊÷¥Æ
{
        mapping me=pl->query_temp("me");

        _refresh_status(pl);
        if (str != "")
        {        // ”– ‰»Î◊ ¡œ ±
                if (sscanf(str, "%s %s", me["sSearch"],        me["sReplace"]) != 2)
                {        // ÷ª”–“ª∏ˆ◊÷¥Æ£¨æÕ÷∏∂®Œ™À——∞◊÷¥Æ£¨“‚º¥ƒ√µÙ÷∏∂®◊÷¥Æ
                        me["sSearch"] = str;
                        me["sReplace"] = "";
                }
                _next_match(pl);
        }
        else        get_char("_input", HIDE, pl); // ºÃ–¯∂¡»°œ¬∏ˆ ‰»Î◊÷¥Æ
} // _replace_done()


private void _right(object pl, int col, int extra)        // ”Œ±ÍÕ˘”““∆“ª◊÷
{
        int    acc;
        mapping me=pl->query_temp("me");


        if (sizeof(me["sText"])==0 || me["iS_Col"]+me["iCol"]-1>
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-1+extra)
            return;
        me["iCol"] += col;
        if (me["iS_Col"]+me["iCol"]-1 > sizeof(me["sText"][me["iS_Row"]+
            me["iRow"]-2])+extra)
                me["iCol"] = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-
                        me["iS_Col"]+1+extra;
        if (me["iCol"] > 80)
        {        // ”Œ±Íµƒ–¬Œª÷√≤ª‘⁄ø…º˚ ”¥∞ƒ⁄£¨–Ë“™Õ˘”““∆∂Ø ”¥∞
                // »Ù”““∆ 8 ¿∏Ã´∂‡µƒª∞£¨æÕ÷ª”““∆µΩ––Œ≤
                if (me["iE_Col"]+8 > sizeof(me["sText"][me["iS_Row"]+
                    me["iRow"]-2])+1)
                        acc = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-
                                me["iE_Col"]+1;
                else        acc = 8;
                me["iCol"] = 80-acc+1;         // º∆À„”Œ±Íµƒ–¬Œª÷√
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]+acc);
                return;
        }
        _refresh_status(pl);
} // _right()


private void _search(object pl)                // ◊÷¥ÆÀ——∞
{
        _message(pl, "[1;44m«Î ‰»ÎÀ——∞◊÷¥Æ°∏÷±Ω”∞¥ ENTER »°œ˚°±£∫[m", "_search_done",
                ECHO);
} // _search()


protected void _search_done(string str, object pl) // »°µ√À——∞◊÷¥Æ
{
        mapping me=pl->query_temp("me");

        _refresh_status(pl);
        if (str != "")
        {        // ”– ‰»Î◊ ¡œ ±
                me["sSearch"] = str;        me["sReplace"] = 0;
                _next_match(pl);
        }
        else        get_char("_input", HIDE, pl); // ºÃ–¯∂¡»°œ¬∏ˆ ‰»Î◊÷¥Æ
} // _search_done()


private void _tab(object pl)                 // √¸¡Óƒ£ Ωœ¬ TAB º¸µƒ∂®Œª
{
        mapping me=pl->query_temp("me");
        _right(pl, 8-(me["iCol"]-1)%8, 0);
} // _tab()


private void _undef_key(object pl)        // »°œ˚ƒ≥π¶ƒ‹º¸∂®“Â
{
        _message(pl, "«Î ‰»Î”˚»°œ˚∂®“Â÷Æπ¶ƒ‹º¸£®÷±Ω”∞¥ ENTER »°œ˚)£∫",
                "_undef_key_done", ECHO);
} // undef_key()


protected void _undef_key_done(string str, object pl) // »°µ√÷∏∂®π¶ƒ‹º¸
{
        mapping me=pl->query_temp("me");
        if (str != "")        map_delete(me["keymap"], str);
        _message_done("", pl);
} // undef_key_done()


private void _up(object pl)                // ”Œ±ÍÕ˘…œ“∆“ª––
{
        int  acc;
        mapping me=pl->query_temp("me");


        if (me["iRow"]==1 && me["iS_Row"]==1)        return;
        if (--me["iRow"] < 1)
        {        // ”Œ±Í–¬Œª÷√≤ª‘⁄ø…º˚ ”¥∞ƒ⁄£¨æÕ…œ“∆ ”¥∞
                me["iS_Row"]--;
                me["iE_Row"]=me["iS_Row"]+22;
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
                me["iRow"] = 1;
        }
        // »Ù”Œ±Í–¬Œª÷√≥¨π˝––Œ≤£¨‘Ú“∆µΩ––Œ≤
        if (me["iS_Col"]+me["iCol"]-1 > sizeof(me["sText"][me["iS_Row"]+
            me["iRow"]-2]))
                me["iCol"] = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-
                        me["iS_Col"]+(me["is_Command_Mode"]?1:2);
        // »Ù¥À––Œﬁ◊÷£¨‘Ú∂®Œª‘⁄µ⁄“ª¿∏
        if (me["iCol"]==0 && me["iS_Col"]==1) me["iCol"] = 1;
        if (me["iCol"] > 0) _refresh_status(pl);
        else
        {        // ”Œ±Í–¬Œª÷√≤ª‘⁄ø…º˚ ”¥∞ƒ⁄£¨÷ÿªÊª≠√Ê
                acc = me["iCol"];        me["iCol"] = 1;
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"],
                        me["iS_Col"]+acc-1);
        }
} // _up()


private void _write(object pl)                // »°µ√¥¢¥Êµµ∞∏√˚≥∆
{
        _message(pl, "[44;1m«Î ‰»Î–¬µµ√˚°∏÷±Ω”∞¥ ENTER “‘ π”√æ…µµ√˚°±£∫[m",
                "_write_done", ECHO, 0);
} // _write()


protected void _write_done(string str, object pl, int quit) // ¥¢¥Êµµ∞∏
{
        string callback;
        mapping me=pl->query_temp("me");

        if (str == "") str = me["sFileName"];
        else        // »°µ√µµ√˚
                str = resolve_path(pl->query("cwd"), str);
        if (quit) callback = "_quit";
        else callback = "_message_done";
        if (write_file(str, implode(me["sText"], "\n")+"\n", 1))
        {
                me["is_Modify"] = me["is_NewFile"] = 0;
                me["sFileName"] = str;
                _message(pl, "[44;1;36m¥Êµµ≥…π¶£¨YA£°[m", callback, HIDE);
        }
        else
                _message(pl, "[44;30m¥Êµµ ß∞‹£¨-.- .....°£[m", callback, HIDE);
} // write_done()
