/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"

tURG_DEBUG      myURG;
tYURG_priv      myURG_priv;

/*
 *  standard a-z urgents are for a application, not libraries.
 *
 *  libraries should be separable from application as they are
 *  debugged separately.  but, to create a debugging path that may
 *  include both, base library urgents can include...
 *
 *     @@ymap      ymap, base
 *     @@YMAP      ymap, base with more detail
 *     @@ymap_g    ymap, plus graf
 *     @@ymap_u    ymap, plus user
 *
 *     @+ymap      ymap, everything that starts with ymap
 *
 *
 *
 *
 *
 */

/*> char        s_lower     [30] = "";                                                <*/
/*> char        s_upper     [30] = "";                                                <*/

/*> int         s_curr      = -1;                                                     <*/

/*> char        s_origs     [LEN_RECD];      /+ original urgs from yURG_urgs   +/     <*/
/*> int         s_norig     = 0;                                                      <*/
/*> char        s_nows      [LEN_RECD];      /+ current state of urgs          +/     <*/
/*> int         s_nnow      = 0;                                                      <*/
/*> int         s_ntry      = 0;                                                      <*/

tYURG_TYPE  yURG_type [MAX_URGS] = {
   {   'h' , '-' , "help by categories"      },
   {   'u' , '-' , "univerals"               },
   {   'u' , 'o' , "overall"                 },
   {   'u' , 's' , "startup/teardown"        },
   {   'u' , 'd' , "data and text files"     },
   {   'u' , 'e' , "event handling"          },
   {   'u' , 'p' , "special processing"      },
   {   'p' , '-' , "program-specific"        },
   {   'l' , '-' , "library-related"         },
   {   'l' , 's' , "safe strings"            },
   {   'l' , 'k' , "kinematics"              },
   {   'l' , 'v' , "vi-keys"                 },
   {   'l' , 'g' , "graphics"                },
   {   '-' , '-' , "compound"                },
   {   '\0', '\0', "end-of-list"             },
};


/*> {  'p' , "prog"           , "program setup, main, and shutdown"     , 'u', 's', &myURG.prog               },   <* 
 *> /+---(startup/shutdown)---------------+/                                                                       <* 
 *> {  'a' , "args"           , "command-line args and urgent handling" , 'u', 's', &myURG.args               },   <* 
 *> {  'c' , "conf"           , "configuration handling"                , 'u', 's', &myURG.conf               },   <* 
 *> /+---(file processing)----------------+/                                                                       <* 
 *> {  'f' , "file"           , "shared file handling"                  , 'u', 'd', &myURG.inpt               },   <* 
 *> {  'i' , "inpt"           , "text and data file input"              , 'u', 'd', &myURG.inpt               },   <* 
 *> {  'o' , "outp"           , "text and data file output"             , 'u', 'd', &myURG.outp               },   <* 
 *> {  'x' , "apis"           , "db, sigs, env, api"                    , 'u', 'e', &myURG.sign               },   <*/

/*> {  't' , "tops"           , "broad structure and context"           , 'u', 'o', &myURG.tops               },   <* 
 *> {  'r' , "rptg"           , "reports/dump, analysis, runtime stats" , 'u', 'o', &myURG.rptg               },   <* 
 *> {  'v' , "view"           , "provide alternate terminal output"     , 'u', 'o', &myURG.view               },   <*/

/*> /+---(event handling)-----------------+/                                                                                 <* 
 *> {  'l' , "loop"           , "major program event loops"             , 'u', 'e', &myURG.loop               },             <* 
 *> {  'u' , "user"           , "user input and handling"               , 'u', 'e', &myURG.user               },             <* 
 *> {  'b' , "scrp"           , "scripts and batch handling"            , 'u', 'e', &myURG.scrp               },             <* 
 *> /+> {  'n' , "norm"           , "normal execution flow (catch-all)"     , 'u', 'e', &myURG.norm               },   <+/   <* 
 *> {  'h' , "hist"           , "history, undo, redo"                   , 'u', 'e', &myURG.hist               },             <* 
 *> /+---(deeper program)-----------------+/                                                                                 <* 
 *> {  'd' , "data"           , "complex data structure handling"       , 'u', 'p', &myURG.data               },             <* 
 *> {  's' , "sort"           , "data sorting and ordering"             , 'u', 'p', &myURG.sort               },             <* 
 *> {  'g' , "graf"           , "graphics, drawing, and display"        , 'u', 'p', &myURG.graf               },             <* 
 *> {  'w' , "wind"           , "repeated windows, drawing and looping" , 'u', 'p', &myURG.wind               },             <* 
 *> /+> {  'y' , "trav"           , "data searching and traversal"          , 'u', 'p', &myURG.trav               },   <+/   <* 
 *> /+> {  'm' , "mems"           , "data registers, memory, saving"        , 'u', 'p', &myURG.mems               },   <+/   <*/

/*> char   g_stage  [ 30] = "ииииииииииииииииииииииии";                                                                                                                                                                                                                                           <* 
 *> char   g_urgs   [300] = "ииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии";   <* 
 *>                                                                                                                                                                                                                                                                                               <* 
 *> char   g_lower  [ 30] = "ииииииииииииииииииииииииии";                                                                                                                                                                                                                                         <* 
 *> char   g_upper  [ 30] = "ииииииииииииииииииииииииии";                                                                                                                                                                                                                                         <* 
 *> char   g_greek  [ 30] = "ииииииииииииииииииииииии";                                                                                                                                                                                                                                           <* 
 *> char   g_number [ 30] = "ииииииииии";                                                                                                                                                                                                                                                         <*/

const tYURG_INFO  yURG_info [MAX_URGS] = {
   /* abbr   ---full----------  ---desc--------------------------------  typ  sub  ---base---   ---mas----   pointer------------------ */
   {  '-' , "urgents"        , "list every urgent available"           , 'h', '-', ""         , ""         , NULL                      },
   {  '-' , "universal"      , "list universal urgents"                , 'h', '-', ""         , ""         , NULL                      },
   {  '-' , "program"        , "list program urgents"                  , 'h', '-', ""         , ""         , NULL                      },
   {  '-' , "library"        , "list library urgents"                  , 'h', '-', ""         , ""         , NULL                      },
   /*---(compound)-----------------------*/
   {  '-' , "quiet"          , "turn absolutely everything off"        , '-', '-', ""         , ""         , NULL                      },
   {  '-' , "full"           , "turn all universals on"                , '-', '-', ""         , ""         , NULL                      },
   {  '-' , "mas"            , "turn all universals and their mas on"  , '-', '-', ""         , ""         , NULL                      },
   {  '-' , "kitchen"        , "turn all universals/specific (no mas)" , '-', '-', ""         , ""         , NULL                      },
   {  '-' , "omni"           , "turn absolutely everything on"         , '-', '-', ""         , ""         , NULL                      },
   /*---(stages)-------------------------*/
   {  '-' , "mute"           , "start muted/silent"                    , '-', '-', ""         , ""         , &myURG.mute               },
   {  'щ' , "beg"            , "only active during startup"            , '-', '-', ""         , ""         , &(myURG.stage[0])         },
   {  'Ы' , "mid"            , "only active during normal/main"        , '-', '-', ""         , ""         , &(myURG.stage[1])         },
   {  ' ' , "end"            , "only active during shutdown "          , '-', '-', ""         , ""         , &(myURG.stage[2])         },
   {  'У' , "one"            , "during main, user-defined block 1"     , '-', '-', ""         , ""         , &(myURG.stage[4])         },
   {  'ж' , "two"            , "during main, user-defined block 2"     , '-', '-', ""         , ""         , &(myURG.stage[5])         },
   {  'в' , "thr"            , "during main, user-defined block 3"     , '-', '-', ""         , ""         , &(myURG.stage[6])         },
   {  'Ж' , "fou"            , "during main, user-defined block 4"     , '-', '-', ""         , ""         , &(myURG.stage[7])         },
   {  'В' , "fiv"            , "during main, user-defined block 5"     , '-', '-', ""         , ""         , &(myURG.stage[8])         },
   /*---(overall)------------------------*/
   {  'v' , "view"           , "provide alternate terminal output"     , 'u', 'o', "VIEW"     , "VIEW_M"   , &myURG.view               },
   /*---(startup/shutdown)---------------*/
   {  'p' , "prog"           , "general program setup and shutdown"    , 'u', 's', "PROG"     , "PROG_M"   , &myURG.prog               },
   {  'a' , "args"           , "command-line args and urgent handling" , 'u', 's', "ARGS"     , "ARGS_M"   , &myURG.args               },
   /*---(file processing)----------------*/
   {  '+' , "file"           , "combination of inpt/outp"              , '-', '-', "FILE"     , "FILE_M"   , NULL                      },
   {  'i' , "inpt"           , "data source files/db (non-conf/rptg)"  , 'u', 'd', "INPT"     , "INPT_M"   , &myURG.inpt               },
   {  'o' , "outp"           , "data output files/db (non-conf/rptg)"  , 'u', 'd', "OUTP"     , "OUTP_M"   , &myURG.outp               },
   {  'c' , "conf"           , "configuration handling and updating"   , 'u', 's', "CONF"     , "CONF_M"   , &myURG.conf               },
   {  'r' , "rptg"           , "reporting, import and export"          , 'u', 'o', "RPTG"     , "RPTG_M"   , &myURG.rptg               },
   /*---(event/volume)-------------------*/
   {  'l' , "loop"           , "main looping, highly repetitive"       , 'u', 'e', "LOOP"     , "LOOP_M"   , &myURG.loop               },
   {  'u' , "user"           , "user input and handling"               , 'u', 'e', "USER"     , "USER_M"   , &myURG.user               },
   {  'g' , "graf"           , "graphics, drawing, and display"        , 'u', 'p', "GRAF"     , "GRAF_M"   , &myURG.graf               },
   {  'e' , "envi"           , "apis, signals, os, shell"              , 'u', 'p', "ENVI"     , "ENVI_M"   , &myURG.envi               },
   /*---(deeper program)-----------------*/
   {  's' , "sort"           , "sorting and ordering data structures"  , 'u', 'p', "SORT"     , "SORT_M"   , &myURG.sort               },
   {  'f' , "find"           , "searching for matches in data struct"  , 'u', 'p', "FIND"     , "FIND_M"   , &myURG.find               },
   {  'w' , "walk"           , "walking data structures"               , 'u', 'p', "WALK"     , "WALK_M"   , &myURG.walk               },
   {  't' , "tabl"           , "data table input, update, searching"   , 'u', 'p', "TABL"     , "TABL_M"   , &myURG.tabl               },
   {  'd' , "data"           , "pure data chewing, reviewing, gather"  , 'u', 'p', "DATA"     , "DATA_M"   , &myURG.data               },
   /*---(critical)-----------------------*/
   {  ' ' , "ystr"           , "heatherly ySTR string library"         , 'l', 's', "YSTR"     , "YSTR_M"   , &myURG.ystr               },
   {  '-' , "yenv"           , "heatherly yENV system library"         , 'l', 's', "YENV"     , "YENV_M"   , &myURG.yenv               },
   {  'т' , "yscore"         , "heatherly ySCORE transaction scoring"  , 'l', 's', "YSCORE"   , "YSCORE_M" , &myURG.yscore             },
   /*---(spreadsheet)--------------------*/
   {  '-' , "locs"           , "spreadsheet location parsing and use"  , 'p', '-', ""         , ""         , &myURG.locs               },
   {  '-' , "cell"           , "spreadsheet cell creation and mtce"    , 'p', '-', ""         , ""         , &myURG.cell               },
   /*---(calculations)-------------------*/
   {  '-' , "calc"           , "calculation building from rpn"         , 'p', '-', ""         , ""         , &myURG.calc               },
   {  '-' , "exec"           , "calculation execution"                 , 'p', '-', ""         , ""         , &myURG.exec               },
   {  '-' , "adjs"           , "small, config adjustments in measures" , 'p', '-', ""         , ""         , &myURG.adjs               },
   /*---(dependencies)-------------------*/
   {  '-' , "deps"           , "dependency creation and maintenance"   , 'p', '-', ""         , ""         , &myURG.deps               },
   /*---(visual)-------------------------*/
   {  '-' , "visu"           , "visual selection of objects"           , 'p', '-', ""         , ""         , &myURG.visu               },
   {  '-' , "ssel"           , "visual selection of text strings"      , 'p', '-', ""         , ""         , &myURG.ssel               },
   /*---(yVIKEYS-searching)--------------*/
   {  '-' , "mark"           , "yVIKEYS location/object marks"         , 'p', '-', ""         , ""         , &myURG.mark               },
   {  '-' , "hint"           , "yVIKEYS location/object hinting"       , 'p', '-', ""         , ""         , &myURG.hint               },
   {  '-' , "srch"           , "yVIKEYS location/object searching"     , 'p', '-', ""         , ""         , &myURG.srch               },
   /*---(yVIKEYS-handling)---------------*/
   {  '-' , "map"            , "yVIKEYS screen mapping"                , 'l', 'v', ""         , ""         , &myURG.map                },
   {  '-' , "mode"           , "yVIKEYS mode handling"                 , 'l', 'v', ""         , ""         , &myURG.mode               },
   {  '-' , "keys"           , "yVIKEYS key handling"                  , 'l', 'v', ""         , ""         , &myURG.keys               },
   {  '-' , "edit"           , "yVIKEYS source editing"                , 'l', 'v', ""         , ""         , &myURG.edit               },
   {  '-' , "yvikeys_mode"   , "yVIKEYS vi-keys handling library"      , 'l', 'v', ""         , ""         , &myURG.yvikeys_mode       },
   /*---(vi-keys special)----------------*/
   {  'U' , "yvihub"         , "yVIHUB vi-keys coordination"           , 'l', 'v', "YVIHUB"   , ""         , &myURG.yvihub             },
   /*---(vi-keys fundamental)------------*/
   {  'O' , "ymode"          , "yMODE  vi-keys mode processing"        , 'l', 'v', "YMODE"    , "YMODE_M"  , &myURG.ymode              },
   {  'K' , "ykeys"          , "yKEYS  vi-keys keyboard handling"      , 'l', 'v', "YKEYS"    , "YKEYS_M"  , &myURG.ykeys              },
   {  'F' , "yfile"          , "yFILE  vi-keys file management"        , 'l', 'v', "YFILE"    , "YFILE_M"  , &myURG.yfile              },
   {  'V' , "yview"          , "yVIEW  vi-keys layout manageent"       , 'l', 'v', "YVIEW"    , "YVIEW_M"  , &myURG.yview              },
   /*---(vi-keys extended)---------------*/
   {  'P' , "ymap"           , "yMAP   vi-keys map mode handling"      , 'l', 'v', "YMAP"     , "YMAP_M"   , &myURG.ymap               },
   {  '-' , "ymap_u"         , "yMAP   user/mode details"              , 'l', 'v', "YMAP_U"   , ""         , &myURG.ymap_user          },
   {  '-' , "ymap_g"         , "yMAP   draw/refresh details"           , 'l', 'v', "YMAP_G"   , ""         , &myURG.ymap_graf          },
   {  'C' , "ycmd"           , "yCMD   vi-keys command processor"      , 'l', 'v', "YCMD"     , "YCMD_M"   , &myURG.ycmd               },
   {  'B' , "ymacro"         , "yMACRO vi-keys script handling"        , 'l', 'v', "YMACRO"   , "YMACRO_M" , &myURG.ymacro             },
   {  'S' , "ysrc"           , "ySRC   vi-keys content handling"       , 'l', 'v', "YSRC"     , "YSRC_M"   , &myURG.ysrc               },
   {  '-' , "ysrc_u"         , "ySRC   user/mode details"              , 'l', 'v', "YSRC_U"   , ""         , &myURG.ysrc_user          },
   {  'M' , "ymark"          , "yMARK  vi-keys search and mark"        , 'l', 'v', "YMARK"    , "YMARK_M"  , &myURG.ycmd               },
   /*---(vi-keys graph)------------------*/
   {  'G' , "ygod"           , "yGOD   3d viewing library"             , 'l', 'v', "YGOD"     , ""         , NULL                      },
   {  'Y' , "yvicu"          , "yVICU  vi-keys ncurses support"        , 'l', 'v', "YVICU"    , ""         , NULL                      },
   {  'Y' , "yviop"          , "yVIOP  vi-keys opengl support"         , 'l', 'v', "YVIOP"    , ""         , NULL                      },
   /*---(registers)----------------------*/
   {  '-' , "regs"           , "copy and paste registers"              , 'p', '-', ""         , ""         , &myURG.regs               },
   /*---(libraries)----------------------*/
   {  '§' , "ycalc"          , "yCALC calculation engine"              , 'l', 's', "YCALC"    , ""         , &myURG.ycalc              },
   {  'Ы' , "ycolor"         , "yGLTEX opengl color handling"          , 'l', 'g', "YCOLOR"   , ""         , &myURG.ycolor             },
   {  'в' , "ydlst"          , "yDLST quad-double linked list lib"     , 'l', 's', "YDLST"    , ""         , &myURG.ydlst              },
   {  'В' , "yexec"          , "yEXEC process dispatch and control"    , 'l', 's', "YEXEC"    , ""         , &myURG.yexec              },
   {  'Ч' , "yfont"          , "yFONT texture mapped font library"     , 'l', 'g', "YFONT"    , "YFONT_M"  , &myURG.yfont              },
   {  '-' , "yfont_file"     , "yFONT file creation and access"        , 'l', 'g', ""         , ""         , &myURG.yfont_file         },
   {  '-' , "yfont_calc"     , "yFONT layout and vertex calculation"   , 'l', 'g', ""         , ""         , &myURG.yfont_calc         },
   {  '-' , "yfont_map"      , "yFONT texture mapping and access"      , 'l', 'g', ""         , ""         , &myURG.yfont_map          },
   {  'Ж' , "ygltex"         , "yGLTEX opengl texture handling"        , 'l', 'g', "YGLTEX"   , "YGLTEX_M" , &myURG.ygltex             },
   {  'ч' , "ygolem"         , "heatherly yGOLEM robotics controller"  , 'l', 's', "YGOLEM"   , ""         , &myURG.ygolem             },
   {  'Ш' , "yjobs"          , "yJOBS job execution and control"       , 'l', 's', "YJOBS"    , "YJOBS_M"  , &myURG.yjobs              },
   {  'ы' , "ykine"          , "yKINE kinematics main"                 , 'l', 'k', "YKINE"    , "YKINE_M"  , &myURG.ykine              },
   {  '-' , "ykine_calc"     , "yKINE kinematics calculations"         , 'l', 'k', ""         , ""         , &myURG.ykine_calc         },
   {  '-' , "ykine_tick"     , "yKINE kinematics exact timing/ticks"   , 'l', 'k', ""         , ""         , &myURG.ykine_tick         },
   {  '-' , "ykine_data"     , "yKINE kinematics common data"          , 'l', 'k', ""         , ""         , &myURG.ykine_data         },
   {  '-' , "ykine_scrp"     , "yKINE kinematics script interpretation", 'l', 'k', ""         , ""         , &myURG.ykine_scrp         },
   {  '-' , "ykine_move"     , "yKINE kinematics move creation"        , 'l', 'k', ""         , ""         , &myURG.ykine_move         },
   {  '-' , "ykine_exact"    , "yKINE kinematics loading of progress"  , 'l', 'k', ""         , ""         , &myURG.ykine_exact        },
   {  'э' , "yparse"         , "heatherly yPARSE parsing queue"        , 'l', 's', "YPARSE"   , ""         , &myURG.yparse             },
   {  'Э' , "yregex"         , "heatherly yREGEX library"              , 'l', 's', "YREGEX"   , ""         , &myURG.yregex             },
   {  'З' , "yrpn"           , "yRPN conversion infix to rpn"          , 'p', '-', "YRPN"     , ""         , &myURG.yrpn               },
   {  'щ' , "ysched"         , "ySCHED kernighan sched grammar"        , 'l', 's', "YSCHED"   , ""         , &myURG.ysched             },
   {  'У' , "ysec"           , "ySEC system access logging"            , 'l', 's', "YSEC"     , ""         , &myURG.ysec               },
   {  'Щ' , "ysort"          , "ySORT  vi-keys data ordering"          , 'l', 'v', "YSORT"    , ""         , &myURG.ysort              },
   {  'ш' , "ydesk"          , "yX11 window management"                , 'l', 'v', "YDESK"    , ""         , &myURG.desk               },
   {  '­' , "yascii"         , "yASCII font and art"                   , 'l', 'g', "YASCII"   , ""         , &myURG.yascii             },
   /*---(other)--------------------------*/
   {  '-' , "yxwin"          , "yX11 window management"                , 'l', 'v', ""         , ""         , &myURG.yxwin              },
   {  '-' , "yvikeys"        , "yVIKEYS vi-keys handling library"      , 'l', 'v', ""         , ""         , &myURG.yvikeys            },
   {  '-' , "yvikeys_keys"   , "yVIKEYS vi-keys handling library"      , 'l', 'v', ""         , ""         , &myURG.yvikeys_keys       },
   {  '-' , "yvikeys_scale"  , "yVIKEYS vi-keys handling library"      , 'l', 'v', ""         , ""         , &myURG.yvikeys_scale      },
   {  '-' , "format"         , "hyleoroi formatting options"           , 'M', 'g', ""         , ""         , &myURG.format             },
   {  '-' , "color"          , "hyleoroi color usage and setup"        , 'M', 'g', ""         , ""         , &myURG.color              },
   /*---(gregg)--------------------------*/
   {  '-' , "touch"          , "touch interface"                       , 'p', '-', ""         , ""         , &myURG.touch              },
   {  '-' , "raw"            , "data point -- raw collection"          , 'p', '-', ""         , ""         , &myURG.raw                },
   {  '-' , "simple"         , "data point -- simplification"          , 'p', '-', ""         , ""         , &myURG.simple             },
   {  '-' , "avg"            , "data point -- averaging"               , 'p', '-', ""         , ""         , &myURG.average            },
   {  '-' , "crit"           , "data point -- critical points"         , 'p', '-', ""         , ""         , &myURG.critical           },
   {  '-' , "circ"           , "data point -- circle marking"          , 'p', '-', ""         , ""         , &myURG.circle             },
   {  '-' , "curv"           , "data point -- curve marking"           , 'p', '-', ""         , ""         , &myURG.curve              },
   {  '-' , "line"           , "data point -- line straightening"      , 'p', '-', ""         , ""         , &myURG.line               },
   {  '-' , "match"          , "data point -- match processing"        , 'p', '-', ""         , ""         , &myURG.match              },
   {  '-' , "dict"           , "dictionary processing"                 , 'p', '-', ""         , ""         , &myURG.dict               },
   /*---(graph/helios)-------------------*/
   {  '-' , "mass"           , "group of nodes"                        , 'p', '-', ""         , ""         , &myURG.mass               },
   {  '-' , "node"           , "node or vertex"                        , 'p', '-', ""         , ""         , &myURG.node               },
   {  '-' , "edge"           , "edge or connection"                    , 'p', '-', ""         , ""         , &myURG.edge               },
   {  '-' , "stats"          , "statistics and grouping"               , 'p', '-', ""         , ""         , &myURG.stats              },
   /*---(hermes)-------------------------*/
   {  '-' , "dirs"           , "hermes location tracking"              , 'p', '-', ""         , ""         , &myURG.dirs               },
   {  '-' , "pkgs"           , "hermes package tracking"               , 'p', '-', ""         , ""         , &myURG.pkgs               },
   {  '-' , "cmds"           , "hermes command tracking"               , 'p', '-', ""         , ""         , &myURG.cmds               },
   {  '-' , "gentoo"         , "hermes gentoo/portage access"          , 'p', '-', ""         , ""         , &myURG.gentoo             },
   {  '-' , "cache"          , "hermes cached database"                , 'p', '-', ""         , ""         , &myURG.cache              },
   /*---(tools)--------------------------*/
   {  '-' , "hfix"           , "VIM/IDE tool HFIX"                     , 'p', '-', ""         , ""         , &myURG.hfix               },
   /*---(end-of-list)--------------------*/
   {  '\0', "END-OF-LIST"    , "end of list"                           , ' ', ' ', ""         , ""         , NULL                      },
};

char         /*--> count number of set urgents -----------[ ------ [ ------ ]-*/
yurg__count        (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   int         c           = 0;
   /*---(list)---------------------------*/
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr     == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].type     == '-')      continue;
      if (  yURG_info [i].point  == NULL)     continue;
      if (*(yURG_info [i].point) == YURG_OFF) continue;
      /*---(append)----------------------*/
      ++c;
   }
   /*---(complete)-----------------------*/
   return c;
}

char         /*--> create a string of current ------------[ ------ [ ------ ]-*/
yURG_orig          (char *a_orig)
{
   if (a_orig != NULL)  strncpy (a_orig, myURG_priv.origs, LEN_RECD);
   return myURG_priv.norig;
}

char         /*--> create a string of current ------------[ ------ [ ------ ]-*/
yURG_curr          (char *a_curr)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   int         k           = 0;
   int         c           = 0;
   char        t           [LEN_LABEL];
   char        x_join      = 0;
   /*---(list)---------------------------*/
   strncpy (myURG_priv.nows, "", LEN_RECD);
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr     == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].type     == '-')      continue;
      if (  yURG_info [i].point  == NULL)     continue;
      if (*(yURG_info [i].point) == YURG_OFF) continue;
      /*---(append)----------------------*/
      if (yURG_info [i].abbr != '-')  {
         if (*(yURG_info [i].point) == YURG_ON )  sprintf (t, "%c", yURG_info [i].abbr);
         else                                     sprintf (t, "%c", toupper (yURG_info [i].abbr));
         if (!x_join)  strncat (myURG_priv.nows, " @", LEN_RECD);
         strncat (myURG_priv.nows, t, LEN_RECD);
         x_join = 1;
      } else {
         strncat (myURG_priv.nows, " @@", LEN_RECD);
         strcpy (t, yURG_info [i].full);
         for (k = 0; k < strlen (t); ++k)  t [k] = toupper (t [k]);
         if (*(yURG_info [i].point) == YURG_ON )  strncat (myURG_priv.nows, yURG_info [i].full, LEN_RECD);
         else                                     strncat (myURG_priv.nows, t, LEN_RECD);
         x_join = 0;
      }
      ++c;
   }
   strncat (myURG_priv.nows, " ", LEN_RECD);
   /*---(save)---------------------------*/
   if (a_curr != NULL)  strncpy (a_curr, myURG_priv.nows, LEN_RECD);
   myURG_priv.nnow = c;
   /*---(complete)-----------------------*/
   return c;
}

char         /*--> put lower letters in a string ---------[ ------ [ ------ ]-*/
yurg__strings      (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   char        c           = ' ';
   /*---(initialize)---------------------*/
   strncpy  (myURG_priv.lower, "--------------------------", LEN_FULL);
   strncpy  (myURG_priv.upper, "--------------------------", LEN_FULL);
   /*---(list)---------------------------*/
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr     == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].abbr     == '-')      continue;
      if (yURG_info [i].type     == '-')      continue;
      if (  yURG_info [i].point  == NULL)     continue;
      if (*(yURG_info [i].point) == YURG_OFF) continue;
      /*---(append)----------------------*/
      c = yURG_info [i].abbr;
      if (c >= 'a' && c <= 'z') {
         myURG_priv.lower [c - 'a'] = c;
         if (*(yURG_info [i].point) == 'Y')  myURG_priv.upper [c - 'a'] = toupper (c);
      }
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
yURG_by_debug      (cchar *a_name, char *r_abbr)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;
   char        rc          =    0;
   int         i           = 0;
   int         x_len       = 0;
   char        x_end       [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_ARGS_M   yLOG_enter   (__FUNCTION__);
   /*---(prepare)------------------------*/
   if (r_abbr != NULL)  *r_abbr = 'и';
   /*---(defense)------------------------*/
   DEBUG_ARGS_M   yLOG_point   ("a_name"    , a_name);
   --rce;  if (a_name == NULL) {
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_ARGS_M   yLOG_info    ("a_name"    , a_name);
   x_len = strlen (a_name);
   DEBUG_ARGS_M   yLOG_value   ("x_len"     , x_len);
   --rce;  if (x_len <  7) {
      DEBUG_ARGS_M   yLOG_note    ("a_name too short (< 3 chars)");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   --rce;  if (x_len > 15) {
      DEBUG_ARGS_M   yLOG_note    ("a_name too long (> 15 chars)");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   --rce;  if (strncmp ("DEBUG_", a_name, 6) != 0) {
      DEBUG_ARGS_M   yLOG_note    ("a_name does not start with DEBUG_");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(prepare)------------------------*/
   strcpy (x_end, a_name + 6);
   DEBUG_ARGS_M   yLOG_info    ("x_end"     , x_end);
   /*---(find)---------------------------*/
   for (i = 0; i < MAX_URGS; ++i) {
      DEBUG_ARGS_M  yLOG_info    ("checking"  , yURG_info [i].full);
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0') {
         DEBUG_ARGS_M   yLOG_note    ("hit end of table");
         break;
      }
      /*---(filter)----------------------*/
      if (yURG_info [i].base [0] == '\0')             continue;
      if (yURG_info [i].base [0] != x_end [0])        continue;
      if (yURG_info [i].base [1] != x_end [1])        continue;
      /*---(check)-----------------------*/
      if (strcmp (yURG_info [i].base, x_end) != 0 &&
            strcmp (yURG_info [i].mas , x_end) != 0)    continue;
      /*---(handle)----------------------*/
      DEBUG_ARGS_M   yLOG_note    ("MATCH");
      if (r_abbr != NULL)  *r_abbr = yURG_info [i].abbr;
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return 1;
   }
   /*---(fall-out)-----------------------*/
   --rce;
   DEBUG_ARGS_M yLOG_exitr   (__FUNCTION__, rce);
   return rce;
}



/*====================------------------------------------====================*/
/*===----                          normal                              ----===*/
/*====================------------------------------------====================*/
static void      o___NORMAL________o (void) {;}

char
yurg__flip         (int i, cchar a_lower, cchar a_on)
{
   /*---(set)-------------------------*/
   if (a_on == YURG_ON) {
      /*---(note)---------------------*/
      DEBUG_ARGS_M   yLOG_note    ("set on");
      /*---(defense)------------------*/
      if (a_lower  && *(yURG_info [i].point) == YURG_ON ) {
         DEBUG_ARGS_M   yLOG_note    ("already on, no need to double set");
         return -1;
      }
      if (a_lower  && *(yURG_info [i].point) == YURG_MAS) {
         DEBUG_ARGS_M   yLOG_note    ("already mas, normal of no use");
         return -2;
      }
      if (!a_lower && *(yURG_info [i].point) == YURG_MAS) {
         DEBUG_ARGS_M   yLOG_note    ("already mas, no need to double set");
         return -3;
      }
      /*---(setting)------------------*/
      if (*(yURG_info [i].point) == YURG_OFF) {
         *(yURG_info [i].point) = YURG_ON;
      }
      if (!a_lower) *(yURG_info [i].point) = YURG_MAS;
      /*---(done)---------------------*/
   }
   /*---(unset)-----------------------*/
   if (a_on == YURG_OFF) {
      /*---(note)---------------------*/
      DEBUG_ARGS_M   yLOG_note    ("set off");
      /*---(defense)------------------*/
      if (a_lower  && *(yURG_info [i].point) == YURG_OFF) {
         DEBUG_ARGS_M   yLOG_note    ("already off, no need to double unset");
         return -6;
      }
      if (!a_lower && *(yURG_info [i].point) == YURG_OFF) {
         DEBUG_ARGS_M   yLOG_note    ("already off, no need to turn off mas");
         return -7;
      }
      if (!a_lower && *(yURG_info [i].point) == YURG_ON ) {
         DEBUG_ARGS_M   yLOG_note    ("already normal, no need to unset mas");
         return -8;
      }
      /*---(setting)------------------*/
      if (*(yURG_info [i].point) == YURG_MAS)  {
         if (!a_lower) *(yURG_info [i].point) = YURG_ON;
      }
      if (a_lower) *(yURG_info [i].point) = YURG_OFF;
      /*---(done)---------------------*/
   }
   /*---(complete)--------------------*/
   return 0;
}

char
yurg__multi        (cchar *a_string, cchar a_on)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         x_len       =    0;
   int         i           =    0;
   /*---(header)-------------------------*/
   DEBUG_ARGS_M   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_ARGS_M   yLOG_point   ("a_string"  , a_string);
   --rce;  if (a_string == NULL) {
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_ARGS_M   yLOG_info    ("a_string"  , a_string);
   x_len = strlen (a_string);
   DEBUG_ARGS_M   yLOG_value   ("x_len"     , x_len);
   for (i = 0; i < x_len; ++i) {
      yURG_by_abbr (a_string [i], a_on);
   }
   /*---(complete)-----------------------*/
   DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> set a single urgent by abbr -----------[ ------ [ ------ ]-*/
yURG_by_abbr       (cchar a_abbr, cchar a_on)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
   int         x_count     =    0;
   char       *x_valid     = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
   char        x_lower     =  '-';
   /*---(header)-------------------------*/
   DEBUG_ARGS_M   yLOG_enter   (__FUNCTION__);
   DEBUG_ARGS_M   yLOG_value   ("a_abbr"    , a_abbr);
   /*---(prepare)------------------------*/
   myURG_priv.curr = -1;
   /*---(defense)------------------------*/
   --rce;  if (a_abbr <=  32) {
      DEBUG_ARGS_M   yLOG_note    ("a_abbr is control character");
      DEBUG_ARGS_M   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (strchr (x_valid, a_abbr) == NULL) {
      DEBUG_ARGS_M   yLOG_note    ("a_abbr not alphabetic");
      DEBUG_ARGS_M   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_lower = tolower (a_abbr);
   /*---(find)---------------------------*/
   --rce;
   DEBUG_ARGS_M  yLOG_note    ("start search");
   for (i = 0; i < MAX_URGS; ++i) {
      DEBUG_ARGS_M  yLOG_info    ("checking"  , yURG_info [i].full);
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0') {
         DEBUG_ARGS_M   yLOG_note    ("hit end of table");
         break;
      }
      /*---(filter)----------------------*/
      if (yURG_info [i].type  == '-')                 continue;
      if (yURG_info [i].abbr  != x_lower)             continue;
      DEBUG_ARGS_M   yLOG_note    ("MATCH");
      if (yURG_info [i].point == NULL) {
         DEBUG_ARGS_M   yLOG_note    ("bad pointer on record");
         DEBUG_ARGS_M   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      /*---(set)-------------------------*/
      ++x_count;
      myURG_priv.curr = i;
      rc = yurg__flip (i, a_abbr == x_lower, a_on);
      if (rc < 0) {
         DEBUG_ARGS_M   yLOG_exitr   (__FUNCTION__, rc);
         return rc;
      }
      break;
   }
   /*---(check)--------------------------*/
   DEBUG_ARGS_M   yLOG_value   ("count"     , x_count);
   --rce;  if (x_count < 1  ) {
      DEBUG_ARGS_M   yLOG_note    ("did not find any urgents matching name");
      DEBUG_ARGS_M   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (x_count > 1  ) {
      DEBUG_ARGS_M   yLOG_note    ("found more than one urgent matching name");
      DEBUG_ARGS_M   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> set a single urgent by name -----------[ ------ [ ------ ]-*/
yURG_by_name       (cchar *a_name, cchar a_on)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;
   char        rc          =    0;
   int         i           = 0;
   int         x_len       = 0;
   int         x_count     = 0;
   char       *x_valid     = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
   char        x_lower     [LEN_LABEL] = "";
   /*---(header)-------------------------*/
   DEBUG_ARGS_M   yLOG_enter   (__FUNCTION__);
   /*---(prepare)------------------------*/
   myURG_priv.curr = -1;
   /*---(defense)------------------------*/
   DEBUG_ARGS_M   yLOG_point   ("a_name"    , a_name);
   --rce;  if (a_name == NULL) {
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_ARGS_M   yLOG_info    ("a_name"    , a_name);
   x_len = strlen (a_name);
   DEBUG_ARGS_M   yLOG_value   ("x_len"     , x_len);
   --rce;  if (x_len <  3) {
      DEBUG_ARGS_M   yLOG_note    ("a_name too short (< 3 chars)");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   --rce;  if (x_len > 15) {
      DEBUG_ARGS_M   yLOG_note    ("a_name too long (> 15 chars)");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   strncpy (x_lower, a_name, LEN_LABEL);
   --rce;  for (i = 0; i < x_len; ++i) {
      DEBUG_ARGS_M   yLOG_char    ("check"     , a_name [i]);
      if (strchr (x_valid, a_name [i]) == NULL)  {
         DEBUG_ARGS_M   yLOG_note    ("a_abbr not alphabetic");
         DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
         return rce;
      }
      x_lower [i] = tolower (a_name [i]);
   }
   x_lower [x_len] = '\0';
   DEBUG_ARGS_M   yLOG_info    ("x_lower"   , x_lower);
   /*---(find)---------------------------*/
   --rce;
   for (i = 0; i < MAX_URGS; ++i) {
      DEBUG_ARGS_M  yLOG_info    ("checking"  , yURG_info [i].full);
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0') {
         DEBUG_ARGS_M   yLOG_note    ("hit end of table");
         break;
      }
      /*---(filter)----------------------*/
      if (yURG_info [i].full[0] != x_lower [0])       continue;
      if (strcmp (yURG_info [i].full, x_lower) != 0)  continue;
      DEBUG_ARGS_M   yLOG_note    ("MATCH");
      /*---(compound)--------------------*/
      if (yURG_info [i].point == NULL) {
         DEBUG_ARGS_M   yLOG_note    ("compound urgent");
         if      (strcmp (a_name, "quiet"     ) == 0)   yurg_mass  ('-', 'E');
         else if (strcmp (a_name, "full"      ) == 0)   yurg_mass  ('y', '-');
         else if (strcmp (a_name, "mas"       ) == 0)   yurg_mass  ('y', 'M');
         else if (strcmp (a_name, "kitchen"   ) == 0)   yurg_mass  ('y', 'y');
         else if (strcmp (a_name, "omni"      ) == 0)   yurg_mass  ('y', 'E');
         ++x_count;
         break;
      }
      /*---(check)-----------------------*/
      if (yURG_info [i].point == NULL) {
         DEBUG_ARGS_M   yLOG_note    ("bad pointer on record");
         DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
         return rce;
      }
      /*---(set)-------------------------*/
      ++x_count;
      myURG_priv.curr = i;
      rc = yurg__flip (i, a_name [0] == x_lower [0], a_on);
      if (rc < 0) {
         DEBUG_ARGS_M yLOG_exit    (__FUNCTION__);
         return rc;
      }
      /*---(muting)----------------------*/
      if (strcmp (a_name, "mute"      ) == 0) {
         if (myURG.mute == 'y') yLOGS_mute   ();
      }
      /*---(done)------------------------*/
      break;
   }
   /*---(check)--------------------------*/
   DEBUG_ARGS_M   yLOG_value   ("count"     , x_count);
   --rce;  if (x_count < 1  ) {
      DEBUG_ARGS_M   yLOG_note    ("did not find any urgents matching name");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   --rce;  if (x_count > 1  ) {
      DEBUG_ARGS_M   yLOG_note    ("found more than one urgent matching name");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_ARGS_M yLOG_exit    (__FUNCTION__);
   return 0;
}

char  yURG_name (cchar *a_name, cchar a_on) { return yURG_by_name (a_name, a_on); }

char       /*----: process the urgents/debugging -----------------------------*/
yurg__wild         (cchar *a_string, cchar a_on)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   int         x_len       =    0;
   int         c           =    0;
   x_len = strlen (a_string);
   for (i = 0; i < MAX_URGS; ++i) {
      if (a_string [0] != yURG_info [i].full [0])              continue;
      if (strncmp (a_string, yURG_info [i].full, x_len) != 0)  continue;
      yURG_by_name (yURG_info [i].full, a_on);
      ++c;
   }
   return c;
}

char
yurg__mass_one     (char *a_var, char a_set)
{
   switch (a_set) {
   case 'Y'  :
      if (*a_var != 'Y')  *a_var = a_set;
      break;
   case 'y'  :
      if (*a_var == '-')  *a_var = a_set;
      break;
   default   :
      *a_var = a_set;
      break;
   }
   return 0;
}

char       /*----: process the urgents/debugging -----------------------------*/
yurg_mass          (cchar a_set, cchar a_extra)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   /*---(walk table)---------------------*/
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0')     break;
      if (strcmp (yURG_info [i].full, "mute") == 0)  continue;
      /*---(filter)----------------------*/
      if (yURG_info [i].point == NULL)     continue;
      if (yURG_info [i].type  == '-')      continue;
      /*---(everything)------------------*/
      if (a_extra == 'E' ) {
         yurg__mass_one (yURG_info [i].point, a_set);
         continue;
      }
      /*---(universal)-------------------*/
      if (yURG_info [i].type  == 'u') {
         yurg__mass_one (yURG_info [i].point, a_set);
         continue;
      }
      /*---(mas)-------------------------*/
      if (yURG_info [i].type  == '#' && a_extra == 'M' ) {
         yurg__mass_one (yURG_info [i].point, a_set);
         continue;
      }
      /*---(specialty)-------------------*/
      if (yURG_info [i].type  == 's' && a_extra == 'y' ) {
         yurg__mass_one (yURG_info [i].point, a_set);
         continue;
      }
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                           drivers                            ----===*/
/*====================------------------------------------====================*/
static void      o___DRIVERS_______o (void) {;}

char       /*----: process the urgents/debugging -----------------------------*/
yURG_urgs          (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   char        rc          = 0;
   char       *a           = NULL;
   int         x_len       = 0;
   int         x_total     = 0;
   /*---(defense)------------------------*/
   if (myURG.loud != 'y')   return 0;
   /*---(header)-------------------------*/
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   /*---(prepare)------------------------*/
   myURG_priv.ntry  = 0;
   strncpy (myURG_priv.origs, "", LEN_RECD);
   myURG_priv.norig = 0;
   strncpy (myURG_priv.nows , "", LEN_RECD);
   myURG_priv.nnow  = 0;
   myURG.mute = '-';
   yurg_stage_clear ();
   /*---(process)------------------------*/
   for (i = 1; i < a_argc; ++i) {
      /*---(filter args)-----------------*/
      a = a_argv[i];
      DEBUG_ARGS   yLOG_complex ("option"    , "%2d, %s", i, a);
      ++x_total;
      if (a[0] != '@')  continue;
      x_len  = strlen (a);
      ++myURG_priv.ntry;
      /*---(process)---------------------*/
      rc     =  0;
      myURG_priv.curr = -1;
      /*---(single abbrev)---------------*/
      if (a [0] == '@' && x_len == 2) {
         DEBUG_ARGS   yLOG_note    ("single abbreviated version");
         rc = yURG_by_abbr  (a[1] , YURG_ON);
      }
      /*---(multi abbrev)----------------*/
      else if (a [0] == '@' && a [1] != '@' && a [1] == '-' && x_len > 2) {
         DEBUG_ARGS   yLOG_note    ("multiple abbreviated OFF version");
         rc = yurg__multi (a + 1, YURG_OFF);
      }
      /*---(multi abbrev)----------------*/
      else if (a [0] == '@' && a [1] != '@' && a [1] != '+' && x_len > 2) {
         DEBUG_ARGS   yLOG_note    ("multiple abbreviated ON version");
         rc = yurg__multi (a + 1, YURG_ON);
      }
      /*---(long form)-------------------*/
      else if (a [0] == '@' && x_len >= 5) {
         if (a [1] == '@') {
            DEBUG_ARGS   yLOG_note    ("long form ON version");
            rc = yURG_by_name  (a + 2, YURG_ON);
            if (rc < 0 && (strncmp (a + 2, "NO", 2) == 0 || strncmp (a + 2, "no", 2) == 0)) {
               DEBUG_ARGS   yLOG_note    ("long form OFF version");
               rc = yURG_by_name  (a + 4, YURG_OFF);
            }
         } else if (a [1] == '+') {
            DEBUG_ARGS   yLOG_note    ("wild card form ON version");
            rc = yurg__wild  (a + 2, YURG_ON);
         }
      }
      /*---(unknown)---------------------*/
      else {
         DEBUG_ARGS   yLOG_note    ("could not identify version");
         ++myURG_priv.ntry;
      }
      /*---(report)----------------------*/
      DEBUG_ARGS   yLOG_value   ("rc"        , rc);
      if (rc >= 0) {
         ++myURG_priv.norig;
         strncat (myURG_priv.origs, " ", LEN_RECD);
         strncat (myURG_priv.origs, a  , LEN_RECD);
      }
      /*---(done)------------------------*/
   }
   strncat (myURG_priv.origs, " ", LEN_RECD);
   DEBUG_ARGS   yLOG_value   ("ntry"      , myURG_priv.ntry);
   DEBUG_ARGS   yLOG_value   ("norig"     , myURG_priv.norig);
   DEBUG_ARGS   yLOG_info    ("origs"     , myURG_priv.origs);
   yurg_stage_prep ();
   yURG_summ   ();
   /*---(complete)-----------------------*/
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return myURG_priv.norig;
}

char yURG_lognum             (void) { return myURG.logger; }

/*===[[ END ]]================================================================*/
