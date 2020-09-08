/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"

tURG_DEBUG      yURG_debug;

char        s_lower     [30] = "";
char        s_upper     [30] = "";

int         s_curr      = -1;

char        s_origs     [LEN_RECD];      /* original urgs from yURG_urgs   */
int         s_norig     = 0;
char        s_nows      [LEN_RECD];      /* current state of urgs          */
int         s_nnow      = 0;
int         s_ntry      = 0;

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

tYURG_INFO  yURG_info [MAX_URGS] = {
   /* abbr   ---full----------  ---desc--------------------------------  typ  sub  pointer---------------------- */
   {  '-' , "urgents"        , "list every urgent available"           , 'h', '-', NULL                           },
   {  '-' , "universal"      , "list universal urgents"                , 'h', '-', NULL                           },
   {  '-' , "program"        , "list program urgents"                  , 'h', '-', NULL                           },
   {  '-' , "library"        , "list library urgents"                  , 'h', '-', NULL                           },
   /*---(compound)-----------------------*/
   {  '-' , "quiet"          , "turn absolutely everything off"        , '-', '-', NULL                           },
   {  '-' , "full"           , "turn all universals on"                , '-', '-', NULL                           },
   {  '-' , "mas"            , "turn all universals and their mas on"  , '-', '-', NULL                           },
   {  '-' , "kitchen"        , "turn all universals/specific (no mas)" , '-', '-', NULL                           },
   {  '-' , "omni"           , "turn absolutely everything on"         , '-', '-', NULL                           },
   /*---(stages)-------------------------*/
   {  '-' , "only_init"      , "only active during startup"            , '-', '-', &(yURG_debug.stage[0])         },
   {  '-' , "only_inpt"      , "only active during file input"         , '-', '-', &(yURG_debug.stage[1])         },
   {  '-' , "only_main"      , "only active during normal/main"        , '-', '-', &(yURG_debug.stage[2])         },
   {  '-' , "only_outp"      , "only active during file output"        , '-', '-', &(yURG_debug.stage[3])         },
   {  '-' , "only_wrap"      , "only active during shutdown "          , '-', '-', &(yURG_debug.stage[4])         },
   {  '-' , "only_one"       , "during main, user-defined stage 1"     , '-', '-', &(yURG_debug.stage[6])         },
   {  '-' , "only_two"       , "during main, user-defined stage 2"     , '-', '-', &(yURG_debug.stage[7])         },
   {  '-' , "only_thr"       , "during main, user-defined stage 3"     , '-', '-', &(yURG_debug.stage[8])         },
   {  '-' , "only_fou"       , "during main, user-defined stage 4"     , '-', '-', &(yURG_debug.stage[9])         },
   {  '-' , "only_fiv"       , "during main, user-defined stage 5"     , '-', '-', &(yURG_debug.stage[10])        },
   /*---(overall)------------------------*/
   {  't' , "tops"           , "broad structure and context"           , 'u', 'o', &yURG_debug.tops               },
   {  'r' , "rptg"           , "reports/dump, analysis, runtime stats" , 'u', 'o', &yURG_debug.rptg               },
   {  'v' , "view"           , "provide alternate terminal output"     , 'u', 'o', &yURG_debug.view               },
   /*---(startup/shutdown)---------------*/
   {  'a' , "args"           , "command-line args and urgent handling" , 'u', 's', &yURG_debug.args               },
   {  'c' , "conf"           , "configuration handling"                , 'u', 's', &yURG_debug.conf               },
   {  'p' , "prog"           , "program setup and shutdown"            , 'u', 's', &yURG_debug.prog               },
   /*---(file processing)----------------*/
   {  'i' , "inpt"           , "text and data file input"              , 'u', 'd', &yURG_debug.inpt               },
   {  'o' , "outp"           , "text and data file output"             , 'u', 'd', &yURG_debug.outp               },
   {  'q' , "sqls"           , "database and sql interaction"          , 'u', 'd', &yURG_debug.sqls               },
   /*---(event handling)-----------------*/
   {  'l' , "loop"           , "major program event loops"             , 'u', 'e', &yURG_debug.loop               },
   {  'n' , "norm"           , "normal execution flow (catch-all)"     , 'u', 'e', &yURG_debug.norm               },
   {  'u' , "user"           , "user input and handling"               , 'u', 'e', &yURG_debug.user               },
   {  'z' , "apis"           , "interprocess communication"            , 'u', 'e', &yURG_debug.apis               },
   {  'x' , "sign"           , "o/s signal handling"                   , 'u', 'e', &yURG_debug.sign               },
   {  'b' , "scrp"           , "scripts and batch handling"            , 'u', 'e', &yURG_debug.scrp               },
   {  'h' , "hist"           , "history, undo, redo"                   , 'u', 'e', &yURG_debug.hist               },
   /*---(deeper program)-----------------*/
   {  'g' , "graf"           , "graphics, drawing, and display"        , 'u', 'p', &yURG_debug.graf               },
   {  'w' , "wind"           , "repeated windows, drawing and looping" , 'u', 'p', &yURG_debug.wind               },
   {  'e' , "envi"           , "environmental processing"              , 'u', 'p', &yURG_debug.envi               },
   {  'd' , "data"           , "complex data structure handling"       , 'u', 'p', &yURG_debug.data               },
   {  's' , "sort"           , "data sorting and ordering"             , 'u', 'p', &yURG_debug.sort               },
   {  'y' , "trav"           , "data searching and traversal"          , 'u', 'p', &yURG_debug.trav               },
   {  'm' , "mems"           , "data registers, memory, saving"        , 'u', 'p', &yURG_debug.mems               },
   /*---(gregg)--------------------------*/
   {  '-' , "touch"          , "touch interface"                       , 'p', '-', &yURG_debug.touch              },
   {  '-' , "raw"            , "data point -- raw collection"          , 'p', '-', &yURG_debug.raw                },
   {  '-' , "simple"         , "data point -- simplification"          , 'p', '-', &yURG_debug.simple             },
   {  '-' , "avg"            , "data point -- averaging"               , 'p', '-', &yURG_debug.average            },
   {  '-' , "crit"           , "data point -- critical points"         , 'p', '-', &yURG_debug.critical           },
   {  '-' , "circ"           , "data point -- circle marking"          , 'p', '-', &yURG_debug.circle             },
   {  '-' , "curv"           , "data point -- curve marking"           , 'p', '-', &yURG_debug.curve              },
   {  '-' , "line"           , "data point -- line straightening"      , 'p', '-', &yURG_debug.line               },
   {  '-' , "match"          , "data point -- match processing"        , 'p', '-', &yURG_debug.match              },
   {  '-' , "dict"           , "dictionary processing"                 , 'p', '-', &yURG_debug.dict               },
   /*---(graph/helios)-------------------*/
   {  '-' , "mass"           , "group of nodes"                        , 'p', '-', &yURG_debug.mass               },
   {  '-' , "node"           , "node or vertex"                        , 'p', '-', &yURG_debug.node               },
   {  '-' , "edge"           , "edge or connection"                    , 'p', '-', &yURG_debug.edge               },
   {  '-' , "stats"          , "statistics and grouping"               , 'p', '-', &yURG_debug.stats              },
   /*---(hermes)-------------------------*/
   {  '-' , "dirs"           , "hermes location tracking"              , 'p', '-', &yURG_debug.dirs               },
   {  '-' , "pkgs"           , "hermes package tracking"               , 'p', '-', &yURG_debug.pkgs               },
   {  '-' , "cmds"           , "hermes command tracking"               , 'p', '-', &yURG_debug.cmds               },
   {  '-' , "gentoo"         , "hermes gentoo/portage access"          , 'p', '-', &yURG_debug.gentoo             },
   {  '-' , "cache"          , "hermes cached database"                , 'p', '-', &yURG_debug.cache              },
   /*---(spreadsheet)--------------------*/
   {  '-' , "locs"           , "spreadsheet location parsing and use"  , 'p', '-', &yURG_debug.locs               },
   {  '-' , "cell"           , "spreadsheet cell creation and mtce"    , 'p', '-', &yURG_debug.cell               },
   /*---(calculations)-------------------*/
   {  '-' , "rpn"            , "calculation conversion infix to rpn"   , 'p', '-', &yURG_debug.rpn                },
   {  '-' , "calc"           , "calculation building from rpn"         , 'p', '-', &yURG_debug.calc               },
   {  '-' , "exec"           , "calculation execution"                 , 'p', '-', &yURG_debug.exec               },
   {  '-' , "adjs"           , "small, config adjustments in measures" , 'p', '-', &yURG_debug.adjs               },
   /*---(dependencies)-------------------*/
   {  '-' , "deps"           , "dependency creation and maintenance"   , 'p', '-', &yURG_debug.deps               },
   /*---(visual)-------------------------*/
   {  '-' , "visu"           , "visual selection of objects"           , 'p', '-', &yURG_debug.visu               },
   {  '-' , "ssel"           , "visual selection of text strings"      , 'p', '-', &yURG_debug.ssel               },
   /*---(yVIKEYS-searching)--------------*/
   {  '-' , "mark"           , "yVIKEYS location/object marks"         , 'p', '-', &yURG_debug.mark               },
   {  '-' , "hint"           , "yVIKEYS location/object hinting"       , 'p', '-', &yURG_debug.hint               },
   {  '-' , "srch"           , "yVIKEYS location/object searching"     , 'p', '-', &yURG_debug.srch               },
   /*---(yVIKEYS-handling)---------------*/
   {  '-' , "map"            , "yVIKEYS screen mapping"                , 'l', 'v', &yURG_debug.map                },
   {  '-' , "mode"           , "yVIKEYS mode handling"                 , 'l', 'v', &yURG_debug.mode               },
   {  '-' , "edit"           , "yVIKEYS source editing"                , 'l', 'v', &yURG_debug.edit               },
   {  '-' , "yvikeys_mode"   , "yVIKEYS vi-keys handling library"      , 'l', 'v', &yURG_debug.yvikeys_mode       },
   /*---(registers)----------------------*/
   {  '-' , "regs"           , "copy and paste registers"              , 'p', '-', &yURG_debug.regs               },
   /*---(libraries)----------------------*/
   {  '-' , "ylogs"          , "heatherly yLOG process monitoring"     , 'l', 's', &yURG_debug.ylogs              },
   {  '-' , "ystr"           , "heatherly ySTR string library"         , 'l', 's', &yURG_debug.ystr               },
   {  '-' , "ydlst"          , "yDLST quad-double linked list lib"     , 'l', 's', &yURG_debug.ydlst              },
   {  '-' , "ysched"         , "ySCHED kernighan sched grammar"        , 'l', 's', &yURG_debug.ysched             },
   {  '-' , "yparse"         , "heatherly yPARSE parsing queue"        , 'l', 's', &yURG_debug.yparse             },
   {  '-' , "yexec"          , "yEXEC process dispatch and control"    , 'l', 's', &yURG_debug.yexec              },
   {  '-' , "ygolem"         , "heatherly yGOLEM robotics controller"  , 'l', 's', &yURG_debug.ygolem             },
   {  '-' , "yregex"         , "heatherly yREGEX library"              , 'l', 's', &yURG_debug.yregex             },
   {  '-' , "ykine"          , "yKINE kinematics main"                 , 'l', 'k', &yURG_debug.ykine              },
   {  '-' , "ykine_calc"     , "yKINE kinematics calculations"         , 'l', 'k', &yURG_debug.ykine_calc         },
   {  '-' , "ykine_tick"     , "yKINE kinematics exact timing/ticks"   , 'l', 'k', &yURG_debug.ykine_tick         },
   {  '-' , "ykine_data"     , "yKINE kinematics common data"          , 'l', 'k', &yURG_debug.ykine_data         },
   {  '-' , "ykine_scrp"     , "yKINE kinematics script interpretation", 'l', 'k', &yURG_debug.ykine_scrp         },
   {  '-' , "ykine_move"     , "yKINE kinematics move creation"        , 'l', 'k', &yURG_debug.ykine_move         },
   {  '-' , "ykine_exact"    , "yKINE kinematics loading of progress"  , 'l', 'k', &yURG_debug.ykine_exact        },
   {  '-' , "desk"           , "yX11 window management"                , 'l', 'v', &yURG_debug.desk               },
   {  '-' , "yvikeys"        , "yVIKEYS vi-keys handling library"      , 'l', 'v', &yURG_debug.yvikeys            },
   {  '-' , "yvikeys_keys"   , "yVIKEYS vi-keys handling library"      , 'l', 'v', &yURG_debug.yvikeys_keys       },
   {  '-' , "yvikeys_scale"  , "yVIKEYS vi-keys handling library"      , 'l', 'v', &yURG_debug.yvikeys_scale      },
   {  '-' , "yfont"          , "yFONT texture mapped font library"     , 'l', 'g', &yURG_debug.yfont              },
   {  '-' , "yfont_file"     , "yFONT file creation and access"        , 'l', 'g', &yURG_debug.yfont_file         },
   {  '-' , "yfont_calc"     , "yFONT layout and vertex calculation"   , 'l', 'g', &yURG_debug.yfont_calc         },
   {  '-' , "yfont_map"      , "yFONT texture mapping and access"      , 'l', 'g', &yURG_debug.yfont_map          },
   {  '-' , "ygltex"         , "yGLTEX opengl texture handling"        , 'l', 'g', &yURG_debug.ygltex             },
   {  '-' , "ycolor"         , "yGLTEX opengl color handling"          , 'l', 'g', &yURG_debug.ycolor             },
   {  '-' , "format"         , "hyleoroi formatting options"           , 'M', 'g', &yURG_debug.format             },
   {  '-' , "color"          , "hyleoroi color usage and setup"        , 'M', 'g', &yURG_debug.color              },
   /*---(end-of-list)--------------------*/
   {  '\0', "END-OF-LIST"    , "end of list"                           , ' ', ' ', NULL                           },
};



/*====================------------------------------------====================*/
/*===----                        utility functions                     ----===*/
/*====================------------------------------------====================*/
static void      o___UTILITY_________________o (void) {;}

char        yURG_ver     [500];

char*      /* ---- : return library versioning information -------------------*/
yURG_version       (void)
{
   char    t [20] = "";
#if    __TINYC__ > 0
   strlcpy (t, "[tcc built  ]", 15);
#elif  __GNUC__  > 0
   strlcpy (t, "[gnu gcc    ]", 15);
#elif  __HEPH__  > 0
   strncpy (t, "[hephaestus ]", 15);
#else
   strlcpy (t, "[unknown    ]", 15);
#endif
   snprintf (yURG_ver, 100, "%s   %s : %s", t, P_VERNUM, P_VERTXT);
   return yURG_ver;
}

char         /*--> return status of debug ----------------[ ------ [ ------ ]-*/
yURG_debugmode     (void)
{
   if (yURG_debug.logger < 0)   return '-';
   return 'y';
}

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
   if (a_orig != NULL)  strlcpy (a_orig, s_origs, LEN_RECD);
   return s_norig;
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
   strlcpy (s_nows, "", LEN_RECD);
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
         if (!x_join)  strlcat (s_nows, " @", LEN_RECD);
         strlcat (s_nows, t, LEN_RECD);
         x_join = 1;
      } else {
         strlcat (s_nows, " @@", LEN_RECD);
         strcpy (t, yURG_info [i].full);
         for (k = 0; k < strlen (t); ++k)  t [k] = toupper (t [k]);
         if (*(yURG_info [i].point) == YURG_ON )  strlcat (s_nows, yURG_info [i].full, LEN_RECD);
         else                                     strlcat (s_nows, t, LEN_RECD);
         x_join = 0;
      }
      ++c;
   }
   strlcat (s_nows, " ", LEN_RECD);
   /*---(save)---------------------------*/
   if (a_curr != NULL)  strlcpy (a_curr, s_nows, LEN_RECD);
   s_nnow = c;
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
   strlcpy  (s_lower, "--------------------------", LEN_FULL);
   strlcpy  (s_upper, "--------------------------", LEN_FULL);
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
         s_lower [c - 'a'] = c;
         if (*(yURG_info [i].point) == 'Y')  s_upper [c - 'a'] = toupper (c);
      }
   }
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                          normal                              ----===*/
/*====================------------------------------------====================*/
static void      o___NORMAL__________________o (void) {;}

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
   x_len = strllen (a_string, LEN_LABEL);
   DEBUG_ARGS_M   yLOG_value   ("x_len"     , x_len);
   for (i = 0; i < x_len; ++i) {
      yURG_abbr (a_string [i], a_on);
   }
   /*---(complete)-----------------------*/
   DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> set a single urgent by abbr -----------[ ------ [ ------ ]-*/
yURG_abbr          (cchar a_abbr, cchar a_on)
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
   s_curr = -1;
   /*---(defense)------------------------*/
   --rce;  if (a_abbr <=  32) {
      DEBUG_ARGS_M   yLOG_note    ("a_abbr is control character");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   --rce;  if (strchr (x_valid, a_abbr) == NULL) {
      DEBUG_ARGS_M   yLOG_note    ("a_abbr not alphabetic");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
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
         DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
         return rce;
      }
      /*---(set)-------------------------*/
      ++x_count;
      s_curr = i;
      rc = yurg__flip (i, a_abbr == x_lower, a_on);
      if (rc < 0)  return rc;
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
   DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> set a single urgent by name -----------[ ------ [ ------ ]-*/
yURG_name          (cchar *a_name, cchar a_on)
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
   s_curr = -1;
   /*---(defense)------------------------*/
   DEBUG_ARGS_M   yLOG_point   ("a_name"    , a_name);
   --rce;  if (a_name == NULL) {
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   DEBUG_ARGS_M   yLOG_info    ("a_name"    , a_name);
   x_len = strllen (a_name, LEN_LABEL);
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
   strlcpy (x_lower, a_name, LEN_LABEL);
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
         if      (strcmp (a_name, "quiet"     ) == 0)   yURG_mass  ('-', 'E');
         else if (strcmp (a_name, "full"      ) == 0)   yURG_mass  ('y', '-');
         else if (strcmp (a_name, "mas"       ) == 0)   yURG_mass  ('y', 'M');
         else if (strcmp (a_name, "kitchen"   ) == 0)   yURG_mass  ('y', 'y');
         else if (strcmp (a_name, "omni"      ) == 0)   yURG_mass  ('y', 'E');
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
      s_curr = i;
      rc = yurg__flip (i, a_name [0] == x_lower [0], a_on);
      if (rc < 0)  return rc;
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
      yURG_name (yURG_info [i].full, a_on);
      ++c;
   }
   return c;
}

char       /*----: process the urgents/debugging -----------------------------*/
yURG_mass          (cchar a_set, cchar a_extra)
{
   int         i           = 0;
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].point == NULL)     continue;
      if (yURG_info [i].type  == '-')      continue;
      /*---(everything)------------------*/
      if (a_extra == 'E' ) {
         *(yURG_info [i].point) = a_set;
         continue;
      }
      /*---(universal)-------------------*/
      if (yURG_info [i].type  == 'u') {
         *(yURG_info [i].point) = a_set;
         continue;
      }
      /*---(mas)-------------------------*/
      if (yURG_info [i].type  == '#' && a_extra == 'M' ) {
         *(yURG_info [i].point) = a_set;
         continue;
      }
      /*---(specialty)-------------------*/
      if (yURG_info [i].type  == 's' && a_extra == 'y' ) {
         *(yURG_info [i].point) = a_set;
         continue;
      }
      /*---(done)------------------------*/
   }
   return 0;
}



/*====================------------------------------------====================*/
/*===----                           drivers                            ----===*/
/*====================------------------------------------====================*/
static void      o___DRIVERS_________________o (void) {;}

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
   if (yURG_debug.loud != 'y')   return 0;
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(prepare)------------------------*/
   s_ntry  = 0;
   strlcpy (s_origs, "", LEN_RECD);
   s_norig = 0;
   strlcpy (s_nows , "", LEN_RECD);
   s_nnow  = 0;
   yurg_stage_clear ();
   /*---(process)------------------------*/
   for (i = 1; i < a_argc; ++i) {
      /*---(filter args)-----------------*/
      a = a_argv[i];
      DEBUG_ARGS   yLOG_complex ("option"    , "%2d, %s", i, a);
      ++x_total;
      if (a[0] != '@')  continue;
      x_len  = strlen (a);
      ++s_ntry;
      /*---(process)---------------------*/
      rc     =  0;
      s_curr = -1;
      /*---(single abbrev)---------------*/
      if (a [0] == '@' && x_len == 2) {
         DEBUG_ARGS   yLOG_note    ("single abbreviated version");
         rc = yURG_abbr  (a[1] , YURG_ON);
      }
      /*---(multi abbrev)----------------*/
      else if (a [0] == '@' && a [1] == '-' && x_len > 2) {
         DEBUG_ARGS   yLOG_note    ("multiple abbreviated OFF version");
         rc = yurg__multi (a + 1, YURG_OFF);
      }
      /*---(multi abbrev)----------------*/
      else if (a [0] == '@' && a [1] != '@'  && a [1] != '+' && x_len > 2) {
         DEBUG_ARGS   yLOG_note    ("multiple abbreviated ON version");
         rc = yurg__multi (a + 1, YURG_ON);
      }
      /*---(long form)-------------------*/
      else if (a [0] == '@' && x_len >= 5) {
         if (a [1] == '@') {
            DEBUG_ARGS   yLOG_note    ("long form ON version");
            rc = yURG_name  (a + 2, YURG_ON);
            if (rc < 0 && (strncmp (a + 2, "NO", 2) == 0 || strncmp (a + 2, "no", 2) == 0)) {
               DEBUG_ARGS   yLOG_note    ("long form OFF version");
               rc = yURG_name  (a + 4, YURG_OFF);
            }
         } else if (a [1] == '+') {
            DEBUG_ARGS   yLOG_note    ("wild card form ON version");
            rc = yurg__wild  (a + 2, YURG_ON);
         }
      }
      /*---(unknown)---------------------*/
      else {
         DEBUG_ARGS   yLOG_note    ("could not identify version");
         ++s_ntry;
      }
      /*---(report)----------------------*/
      DEBUG_ARGS   yLOG_value   ("rc"        , rc);
      if (rc >= 0) {
         ++s_norig;
         strlcat (s_origs, " ", LEN_RECD);
         strlcat (s_origs, a  , LEN_RECD);
      }
      /*---(done)------------------------*/
   }
   strlcat (s_origs, " ", LEN_RECD);
   DEBUG_ARGS   yLOG_value   ("s_ntry"    , s_ntry);
   DEBUG_ARGS   yLOG_value   ("s_norig"   , s_norig);
   DEBUG_ARGS   yLOG_info    ("s_origs"   , s_origs);
   yurg_stage_prep ();
   yURG_summ   ();
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return s_norig;
}

char yURG_lognum             (void) { return yURG_debug.logger; }



/*====================------------------------------------====================*/
/*===----                    unit testing accessor                     ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;}

char          unit_answer [LEN_RECD];

char*            /* [------] unit test accessor ------------------------------*/
yURG__unit         (char *a_question, int a_num)
{
   char        t           [LEN_RECD];
   int         c           = 0;
   /*---(initialize)---------------------*/
   strlcpy (unit_answer, "yURG_unit, unknown request", 100);
   /*---(string testing)-----------------*/
   if      (strncmp(a_question, "lower"     , 20)  == 0) {
      yurg__strings ();
      snprintf (unit_answer, LEN_RECD, "yURG lower       : [%s]", s_lower);
   } else if (strncmp(a_question, "upper"     , 20)  == 0) {
      yurg__strings ();
      snprintf (unit_answer, LEN_RECD, "yURG upper       : [%s]", s_upper);
   } else if (strncmp(a_question, "count"     , 20)  == 0) {
      c = yurg__count ();
      snprintf (unit_answer, LEN_RECD, "yURG count       : %d"  , c);
   } else if (strncmp(a_question, "curr"      , 20)  == 0) {
      if (s_curr < 0) {
         snprintf (unit_answer, LEN_RECD, "yURG curr   (%2d) : %c %s"  , s_curr, '-', "n/a");
      } else {
         snprintf (unit_answer, LEN_RECD, "yURG curr   (%2d) : %c %s"  , s_curr, yURG_info [s_curr].abbr, yURG_info [s_curr].full);
      }
   } else if (strncmp(a_question, "orig"      , 20)  == 0) {
      c = yURG_orig (t);
      snprintf (unit_answer, LEN_RECD, "yURG orig   (%2d) : [%s]"  , c, t);
   } else if (strncmp(a_question, "now"       , 20)  == 0) {
      c = yURG_curr (t);
      snprintf (unit_answer, LEN_RECD, "yURG now    (%2d) : [%s]"  , c, t);
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}



char       /*----: set up programgents/debugging -----------------------------*/
yURG__testquiet     (void)
{
   char       *x_args [2]  = { "yURG_debug","@@quiet" };
   s_curr = -1;   
   yURG_logger (2, x_args);
   return 0;
}

char       /*----: set up programgents/debugging -----------------------------*/
yURG__testloud      (void)
{
   char       *x_args [2]  = { "yURG_debug","@@kitchen" };
   s_curr = -1;   
   yURG_logger (2, x_args);
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
yURG__testend       (void)
{
   DEBUG_TOPS   yLOGS_end     ();
   return 0;
}

/*===[[ END ]]================================================================*/
