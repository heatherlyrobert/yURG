/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"

tURG_DEBUG      yURG_debug;

char        s_lower     [30] = "";
char        s_upper     [30] = "";

int         s_curr      = -1;

char        s_origs     [LEN_RECD];      /* original urgs from yURG_urgs   */
char        s_nows      [LEN_RECD];      /* current state of urgs          */
int         s_ntry      = 0;
int         s_norig     = 0;
int         s_nnow      = 0;

tYURG_TYPE  yURG_type [MAX_URGS] = {
   {   'u' , '-' , "univeral"                },
   {   'u' , 'o' , "overall"                 },
   {   'u' , 's' , "startup/teardown"        },
   {   'u' , 'd' , "data and text files"     },
   {   'u' , 'e' , "event handling"          },
   {   'u' , 'p' , "special processing"      },
   {   's' , '-' , "specific"                },
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
   /*---(compound)-----------------------*/
   {  '-' , "quiet"          , "turn absolutely everything off"        , '-', '-', NULL                           },
   {  '-' , "full"           , "turn all universals on"                , '-', '-', NULL                           },
   {  '-' , "mas"            , "turn all universals and their mas on"  , '-', '-', NULL                           },
   {  '-' , "kitchen"        , "turn all universals/specific (no mas)" , '-', '-', NULL                           },
   {  '-' , "omniscient"     , "turn absolutely everything on"         , '-', '-', NULL                           },
   {  '-' , "urgents"        , "list all urgents available in program" , 'u', '-', NULL                           },
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
   {  'l' , "loop"           , "main program event loop"               , 'u', 'e', &yURG_debug.loop               },
   {  'u' , "user"           , "user input and handling"               , 'u', 'e', &yURG_debug.user               },
   {  'z' , "apis"           , "interprocess communication"            , 'u', 'e', &yURG_debug.apis               },
   {  'x' , "sign"           , "o/s signal handling"                   , 'u', 'e', &yURG_debug.sign               },
   {  'b' , "scrp"           , "scripts and batch handling"            , 'u', 'e', &yURG_debug.scrp               },
   {  'h' , "hist"           , "history, undo, redo"                   , 'u', 'e', &yURG_debug.hist               },
   /*---(deeper program)-----------------*/
   {  'g' , "graf"           , "graphics, drawing, and display"        , 'u', 'p', &yURG_debug.graf               },
   {  'w' , "wind"           , "window drawing and looping"            , 'u', 'p', &yURG_debug.wind               },
   {  'd' , "data"           , "complex data structure handling"       , 'u', 'p', &yURG_debug.data               },
   {  'e' , "envi"           , "environmental processing"              , 'u', 'p', &yURG_debug.envi               },
   {  's' , "sort"           , "data sorting and ordering"             , 'u', 'p', &yURG_debug.sort               },
   /*---(gregg)--------------------------*/
   {  '-' , "touch"          , "touch interface"                       , 's', '-', &yURG_debug.touch              },
   {  '-' , "raw"            , "data point -- raw collection"          , 's', '-', &yURG_debug.raw                },
   {  '-' , "simple"         , "data point -- simplification"          , 's', '-', &yURG_debug.simple             },
   {  '-' , "average"        , "data point -- averaging"               , 's', '-', &yURG_debug.average            },
   {  '-' , "critical"       , "data point -- critical points"         , 's', '-', &yURG_debug.critical           },
   {  '-' , "circle"         , "data point -- circle marking"          , 's', '-', &yURG_debug.circle             },
   {  '-' , "curve"          , "data point -- curve marking"           , 's', '-', &yURG_debug.curve              },
   {  '-' , "line"           , "data point -- line straightening"      , 's', '-', &yURG_debug.line               },
   {  '-' , "dict"           , "dictionary processing"                 , 's', '-', &yURG_debug.dict               },
   /*---(hermes)-------------------------*/
   {  '-' , "dirs"           , "hermes location tracking"              , 's', '-', &yURG_debug.dirs               },
   {  '-' , "pkgs"           , "hermes package tracking"               , 's', '-', &yURG_debug.pkgs               },
   {  '-' , "cmds"           , "hermes command tracking"               , 's', '-', &yURG_debug.cmds               },
   {  '-' , "gentoo"         , "hermes gentoo/portage access"          , 's', '-', &yURG_debug.gentoo             },
   {  '-' , "cache"          , "hermes cached database"                , 's', '-', &yURG_debug.cache              },
   /*---(spreadsheet)--------------------*/
   {  '-' , "locs"           , "spreadsheet location parsing and use"  , 's', '-', &yURG_debug.locs               },
   {  '-' , "cell"           , "spreadsheet cell creation and mtce"    , 's', '-', &yURG_debug.cell               },
   /*---(calculations)-------------------*/
   {  '-' , "rpn"            , "calculation conversion infix to rpn"   , 's', '-', &yURG_debug.rpn                },
   {  '-' , "calc"           , "calculation building from rpn"         , 's', '-', &yURG_debug.calc               },
   {  '-' , "exec"           , "calculation execution"                 , 's', '-', &yURG_debug.exec               },
   {  '-' , "adjs"           , "small, config adjustments in measures" , 's', '-', &yURG_debug.adjs               },
   /*---(dependencies)-------------------*/
   {  '-' , "deps"           , "dependency creation and maintenance"   , 's', '-', &yURG_debug.deps               },
   /*---(visual)-------------------------*/
   {  '-' , "visu"           , "visual selection of objects"           , 's', '-', &yURG_debug.visu               },
   {  '-' , "ssel"           , "visual selection of text strings"      , 's', '-', &yURG_debug.ssel               },
   /*---(yVIKEYS-searching)--------------*/
   {  '-' , "mark"           , "yVIKEYS location/object marks"         , 's', '-', &yURG_debug.mark               },
   {  '-' , "hint"           , "yVIKEYS location/object hinting"       , 's', '-', &yURG_debug.hint               },
   {  '-' , "srch"           , "yVIKEYS location/object searching"     , 's', '-', &yURG_debug.srch               },
   /*---(yVIKEYS-handling)---------------*/
   {  '-' , "map"            , "yVIKEYS screen mapping"                , 'l', 'v', &yURG_debug.map                },
   {  '-' , "mode"           , "yVIKEYS mode handling"                 , 'l', 'v', &yURG_debug.mode               },
   {  '-' , "edit"           , "yVIKEYS source editing"                , 'l', 'v', &yURG_debug.edit               },
   {  '-' , "yvikeys_mode"   , "yVIKEYS vi-keys handling library"      , 'l', 'v', &yURG_debug.yvikeys_mode       },
   /*---(registers)----------------------*/
   {  '-' , "regs"           , "copy and paste registers"              , 's', '-', &yURG_debug.regs               },
   /*---(libraries)----------------------*/
   {  '-' , "ylogs"          , "heatherly yLOG process monitoring"     , 'l', 's', &yURG_debug.ylogs              },
   {  '-' , "ystr"           , "heatherly ySTR string library"         , 'l', 's', &yURG_debug.ystr               },
   {  '-' , "ydlst"          , "yDLST quad-double linked list lib"     , 'l', 's', &yURG_debug.ydlst              },
   {  '-' , "ysched"         , "ySCHED kernighan sched grammar"        , 'l', 's', &yURG_debug.ysched             },
   {  '-' , "yparse"         , "heatherly yPARSE parsing queue"        , 'l', 's', &yURG_debug.yparse             },
   {  '-' , "yexec"          , "yEXEC process dispatch and control"    , 'l', 's', &yURG_debug.yexec              },
   {  '-' , "ygolem"         , "heatherly yGOLEM robotics controller"  , 'l', 's', &yURG_debug.ygolem             },
   {  '-' , "yregex"         , "heatherly yREGEX library"              , 'l', 's', &yURG_debug.yregex             },
   {  '-' , "ykine_calc"     , "yKINE kinematics calculations"         , 'l', 'k', &yURG_debug.ykine_calc         },
   {  '-' , "ykine_data"     , "yKINE kinematics common data"          , 'l', 'k', &yURG_debug.ykine_data         },
   {  '-' , "ykine_scrp"     , "yKINE kinematics script interpretation", 'l', 'k', &yURG_debug.ykine_scrp         },
   {  '-' , "yvikeys"        , "yVIKEYS vi-keys handling library"      , 'l', 'v', &yURG_debug.yvikeys            },
   {  '-' , "yvikeys_keys"   , "yVIKEYS vi-keys handling library"      , 'l', 'v', &yURG_debug.yvikeys_keys       },
   {  '-' , "yvikeys_scale"  , "yVIKEYS vi-keys handling library"      , 'l', 'v', &yURG_debug.yvikeys_scale      },
   {  '-' , "yfont"          , "yFONT texturn mapped font library"     , 'l', 'g', &yURG_debug.yfont              },
   {  '-' , "yfont_file"     , "yFONT file creation and access"        , 'l', 'g', &yURG_debug.yfont_file         },
   {  '-' , "yfont_calc"     , "yFONT layout and vertex calculation"   , 'l', 'g', &yURG_debug.yfont_calc         },
   {  '-' , "yfont_map"      , "yFONT texture mapping and access"      , 'l', 'g', &yURG_debug.yfont_map          },
   {  '-' , "ygltex"         , "yGLTEX opengl texture handling"        , 'l', 'g', &yURG_debug.ygltex             },
   {  '-' , "ycolor"         , "yGLTEX opengl color handling"          , 'l', 'g', &yURG_debug.ycolor             },
   {  '-' , "yrpn"           , "yRPN reverse polish notation"          , 'l', 'g', &yURG_debug.yrpn               },
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
yURG__count        (void)
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
      if (*(yURG_info [i].point) == '-')      continue;
      /*---(append)----------------------*/
      ++c;
   }
   /*---(complete)-----------------------*/
   return c;
}

char         /*--> put lower letters in a string ---------[ ------ [ ------ ]-*/
yURG__strings      (void)
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
      if (*(yURG_info [i].point) == '-')      continue;
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

char         /*--> display all urgents and status --------[ ------ [ ------ ]-*/
yURG_help          (char *a_progname)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   int         j           = 0;
   int         k           = 0;
   char        x_type      = ' ';
   char        x_subsave   = ' ';
   int         x_count     = 0;
   int         x_countmas  = 0;
   int         x_total     = 0;
   int         x_totalmas  = 0;
   char        x_upper     [LEN_LABEL] = "";
   char        x_mas       = ' ';
   int         x_len       = 0;
   char        x_header    [LEN_FULL  ] = "";
   /*---(list universals)----------------*/
   printf ("yURG : urgent inventory report\n\n");
   if (yURG_debug.loud != 'y') {
      printf ("YOU ARE NOT RUNNING IN DEBUG MODE\n");
      printf ("urgents are only active if debug version of program is used (except @v).\n");
      printf ("to run %s in debug mode, use %s_debug\n\n", a_progname, a_progname);
   }
   /*---(cycle types)--------------------*/
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(filter)----------------------*/
      if (yURG_type [i].type     == '\0')                            break;
      if (yURG_type [i].sub      != '-' )                            continue;
      x_type = yURG_type [i].type;
      sprintf (x_header, "%s --------------------------", yURG_type [i].desc);
      printf ("%-21.21s mas ---description----------------------------\n", x_header);
      x_subsave  = '?';
      /*---(cycle urgents)---------------*/
      for (j = 0; j < MAX_URGS; ++j) {
         /*---(filter)-------------------*/
         if (yURG_info [j].abbr  == '\0')                            break;
         if (yURG_info [j].type  != x_type)                          continue;
         /*---(find mas version)---------*/
         x_mas = '-';
         strlcpy (x_upper, yURG_info [j].full, LEN_LABEL);
         x_len = strllen (x_upper, LEN_LABEL);
         for (k = 0; k < x_len; ++k)  x_upper [k] = toupper (x_upper [k]);
         for (k = 0; k < MAX_URGS; ++k) {
            if (yURG_info [k].abbr  == '\0')                         break;
            if (yURG_info [k].full[0] != x_upper [0])                continue;
            if (strcmp (yURG_info [k].full, x_upper) != 0)           continue;
            x_mas = 'y';
            break;
         }
         /*---(print)--------------------*/
         if (yURG_info [j].sub != x_subsave && yURG_info [j].sub != '-') {
            for (k = 0; k < MAX_URGS; ++k) {
               /*---(filter)----------------------*/
               if (yURG_type [k].type    == '\0')                    break;
               if (yURG_type [k].type    != x_type)                  continue;
               if (yURG_type [k].sub != yURG_info [j].sub)   continue;
               sprintf (x_header, "---%s---------------------------", yURG_type [k].desc);
               printf  ("   %-30.30s\n", x_header);
               break;
            }
            x_subsave = yURG_info [j].sub;
         }
         if (yURG_info [j].abbr  != '-')
            printf ("   @%c,@@%-14.14s %c  %-40.40s\n",
                  yURG_info [j].abbr , yURG_info [j].full , x_mas, yURG_info [j].desc );
         else
            printf ("   @@%-14.14s    %c  %-40.40s\n",
                  yURG_info [j].full , x_mas, yURG_info [j].desc );
         /*---(totals)-------------------*/
         ++x_count;
         if (x_mas == 'y')  ++x_countmas;
         /*---(done)---------------------*/
      }
      /*---(sub-totals)------------------*/
      printf ("   ---count = %d (%d mas)\n\n", x_count, x_countmas);
      x_total     += x_count;
      x_totalmas  += x_countmas;
      x_count      = x_countmas = 0;
   }
   /*---(grand totals)-------------------*/
   printf ("grand total count = %d (%d mas), %d overall\n\n", x_total, x_totalmas, x_total + x_totalmas);
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> display all urgents and status --------[ ------ [ ------ ]-*/
yURG_list          (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   /*---(list)---------------------------*/
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].type  == '-')      continue;
      /*---(show)------------------------*/
      printf ("%3d %c %-15.15s %-40.40s %c %10p %c\n", i,
            yURG_info [i].abbr , yURG_info [i].full ,
            yURG_info [i].desc , yURG_info [i].type ,
            yURG_info [i].point, *(yURG_info [i].point));
   }
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> display all urgents and status --------[ ------ [ ------ ]-*/
yURG_summ          (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   /*---(list)---------------------------*/
   DEBUG_ARGS   yLOG_note   ("summarization of urgent processing");
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].type  == '-')      continue;
      if (yURG_info [i].point == NULL)     continue;
      /*---(show)------------------------*/
      DEBUG_ARGS   yLOG_char   (yURG_info [i].full, *(yURG_info [i].point));
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
yurg__flip         (int i, cchar a_lower, cchar a_on)
{
   /*---(set)-------------------------*/
   if (a_on == YURG_ON) {
      DEBUG_ARGS_M   yLOG_note    ("set on");
      if (*(yURG_info [i].point) == YURG_OFF) {
         *(yURG_info [i].point) = YURG_ON;
      }
      if (!a_lower) *(yURG_info [i].point) = YURG_MAS;
   }
   /*---(unset)-----------------------*/
   if (a_on == YURG_OFF) {
      DEBUG_ARGS_M   yLOG_note    ("set off");
      if (*(yURG_info [i].point) == YURG_MAS)  {
         if (!a_lower) *(yURG_info [i].point) = YURG_ON;
      }
      if (a_lower) *(yURG_info [i].point) = YURG_OFF;
   }
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
      yurg__flip (i, a_abbr == x_lower, a_on);
      /*---(done)------------------------*/
      s_curr = i;
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
         else if (strcmp (a_name, "omniscient") == 0)   yURG_mass  ('y', 'E');
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
      yurg__flip (i, a_name [0] == x_lower [0], a_on);
      /*---(done)------------------------*/
      s_curr = i;
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

char         /*--: evaluate logger needs early -----------[ leaf   [ ------ ]-*/
yURG_logger        (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   int         i           = 0;
   char       *a           = NULL;
   int         x_len       = 0;
   char       *p           = NULL;
   int         t           [LEN_FULL];
   char        x_progname  [LEN_FULL] = "";
   char        x_basename  [LEN_FULL] = "";
   char        x_log       = '-';
   char        x_type      = '-';
   char        x_args      = '-';
   char        x_prog      = '-';
   char        x_verb      = '-';
   /*---(default urgents)----------------*/
   yURG_debug.logger   =  -1;
   yURG_debug.loud     = '-';
   yURG_mass    ('-', 'E');   /* turn everything off */
   p = strrchr (a_argv [0], '/');
   if (p == NULL)  strlcpy (x_progname, a_argv [0], LEN_FULL);
   else            strlcpy (x_progname, p + 1     , LEN_FULL);
   strlcpy (x_basename, x_progname, LEN_FULL);
   x_len  = strllen (x_basename, LEN_LABEL);
   /*---(test for normal version)--------*/
   if (x_len >= 6) {
      if (strstr (x_basename, "_debug") != 0)  x_type = 'd';
      if (strstr (x_basename, "_unit" ) != 0)  x_type = 'u';
      if (x_type != '-')   yURG_debug.loud   = 'y';
   }
   /*---(fix program name)---------------*/
   if (x_type == 'd') {
      x_basename [x_len - 6] = '\0';
      strlcpy (x_progname, x_basename, LEN_FULL);
   }
   if (x_type == 'u') {
      x_basename [x_len - 5] = '\0';
   }
   x_len  = strllen (x_progname, LEN_LABEL);
   /*---(process)------------------------*/
   for (i = 1; i < a_argc; ++i) {
      /*---(prepare)---------------------*/
      a = a_argv[i];
      /*---(filter)----------------------*/
      if (a[0] != '@')   continue;
      /*---(non-logging)-----------------*/
      if      (strcmp (a, "@v"           ) == 0) { x_verb = 'v'; continue; }
      else if (strcmp (a, "@@verbose"    ) == 0) { x_verb = 'v'; continue; }
      else if (strcmp (a, "@V"           ) == 0) { x_verb = 'V'; continue; }
      else if (strcmp (a, "@@VERBOSE"    ) == 0) { x_verb = 'V'; continue; }
      /*---(logging)---------------------*/
      if (x_log == '-') x_log = yLOG_SYSTEM;
      /*---(locations)-------------------*/
      if      (strcmp (a, "@q"           ) == 0)   x_log  = yLOG_QUIET;
      else if (strcmp (a, "@@quiet"      ) == 0)   x_log  = yLOG_QUIET;
      else if (strcmp (a, "@@ylog"       ) == 0)   x_log  = yLOG_SYSTEM;
      else if (strcmp (a, "@@ylogh"      ) == 0)   x_log  = yLOG_HISTORICAL;
      else if (strcmp (a, "@@stdout"     ) == 0)   x_log  = yLOG_STDOUT;
      else if (strcmp (a, "@@root"       ) == 0)   x_log  = yLOG_ROOT;
      else if (strcmp (a, "@@usb"        ) == 0)   x_log  = yLOG_USB;
      /*---(singles)---------------------*/
      else if (strcmp (a, "@a"           ) == 0)   x_args = 'a';
      else if (strcmp (a, "@@args"       ) == 0)   x_args = 'a';
      else if (strcmp (a, "@A"           ) == 0)   x_args = 'A';
      else if (strcmp (a, "@@ARGS"       ) == 0)   x_args = 'A';
      else if (strcmp (a, "@p"           ) == 0)   x_prog = 'p';
      else if (strcmp (a, "@@prog"       ) == 0)   x_prog = 'p';
      else if (strcmp (a, "@P"           ) == 0)   x_prog = 'P';
      else if (strcmp (a, "@@PROG"       ) == 0)   x_prog = 'P';
      /*---(compounds)-------------------*/
      else if (strcmp (a, "@@full"       ) == 0) { if (x_args != 'A')  x_args = 'a'; if (x_prog != 'P') x_prog = 'p'; }
      else if (strcmp (a, "@@mas"        ) == 0) { x_args = 'A'; x_prog = 'P'; }
      else if (strcmp (a, "@@kitchen"    ) == 0) { if (x_args != 'A')  x_args = 'a'; if (x_prog != 'P') x_prog = 'p'; }
      else if (strcmp (a, "@@omniscient" ) == 0) { x_args = 'A'; x_prog = 'P'; }
      else if (strcmp (a, "@@urgents"    ) == 0) { yURG_help (x_basename); exit (0); }
      else if (strcmp (a, "@@help"       ) == 0) { yURG_help (x_basename); exit (0); }
   }
   /*---(hande verbose flag)-------------*/
   if      (x_verb == 'v')    yURG_debug.view = YURG_ON;
   else if (x_verb == 'V')    yURG_debug.view = YURG_MAS;
   /*---(startup logging)----------------*/
   if (yURG_debug.loud != 'y')                                  return 0;
   switch (x_log) {
   case yLOG_SYSTEM     :
      yURG_debug.logger = yLOG_begin (x_progname, yLOG_SYSTEM    , yLOG_NOISE);
      break;
   case yLOG_HISTORICAL :
      yURG_debug.logger = yLOG_begin (x_progname, yLOG_HISTORICAL, yLOG_NOISE);
      break;
   case yLOG_STDOUT     :
      yURG_debug.logger = yLOG_begin (x_progname, yLOG_STDOUT    , yLOG_NOISE);
      break;
   case yLOG_ROOT       :
      yURG_debug.logger = yLOG_begin (x_progname, yLOG_ROOT      , yLOG_NOISE);
      break;
   case yLOG_USB        :
      rc = mount ("/dev/sdb1", "/mnt/usb1", "vfat", MS_NOSUID | MS_NODEV | MS_NOEXEC | MS_NOATIME, NULL);
      yURG_debug.logger = yLOG_begin (x_progname, yLOG_USB       , yLOG_NOISE);
      break;
   case yLOG_QUIET : default  :
      yURG_debug.logger = yLOG_begin (x_progname, yLOG_SYSTEM    , yLOG_QUIET);
      break;
   }
   if (yURG_debug.logger < 0) {
      return yURG_debug.logger;
   }
   /*---(fast update)--------------------*/
   yURG_debug.tops = YURG_ON;
   if (x_args == 'a')    yURG_debug.args = YURG_ON;
   if (x_args == 'A')    yURG_debug.args = YURG_MAS;
   if (x_prog == 'p')    yURG_debug.prog = YURG_ON;
   if (x_prog == 'P')    yURG_debug.prog = YURG_MAS;;
   DEBUG_TOPS    yLOG_enter   (__FUNCTION__);
   DEBUG_TOPS    yLOG_note    ("@@tops turned on in yURG_logger()");
   DEBUG_ARGS    yLOG_note    ("@@args turned on in yURG_logger()");
   DEBUG_ARGS_M  yLOG_note    ("@@ARGS turned on in yURG_logger()");
   DEBUG_PROG    yLOG_note    ("@@prog turned on in yURG_logger()");
   DEBUG_PROG_M  yLOG_note    ("@@PROG turned on in yURG_logger()");
   DEBUG_TOPS    yLOG_exit    (__FUNCTION__);
   /*---(complete)-----------------------*/
   return 0;
}

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
   /*---(process)------------------------*/
   for (i = 1; i < a_argc; ++i) {
      /*---(filter args)-----------------*/
      a = a_argv[i];
      DEBUG_ARGS   yLOG_info    ("option"    , a);
      ++x_total;
      if (a[0] != '@')  continue;
      DEBUG_ARGS   yLOG_note    ("idenfified urgent");
      x_len  = strlen (a);
      ++s_ntry;
      /*---(process)---------------------*/
      rc     =  0;
      s_curr = -1;
      /*---(single abbrev)---------------*/
      if (a [0] == '@' && x_len == 2) {
         rc = yURG_abbr  (a[1] , YURG_ON);
      }
      /*---(multi abbrev)----------------*/
      else if (a [0] == '@' && a [1] != '@' && x_len > 2) {
         rc = yurg__multi (a + 1, YURG_ON);
      }
      /*---(long form)-------------------*/
      else if (a [0] == '@' && x_len >= 5) {
         rc = yURG_name  (a + 2, YURG_ON);
         if (rc < 0 && (strncmp (a + 2, "NO", 2) == 0 || strncmp (a + 2, "no", 2) == 0)) {
            rc = yURG_name  (a + 4, YURG_OFF);
         }
      }
      /*---(unknown)---------------------*/
      else {
         DEBUG_ARGS   yLOG_note    ("could not process");
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

#define       LEN_TEXT  2000
char          unit_answer [ LEN_TEXT ];

char*            /* [------] unit test accessor ------------------------------*/
yURG__unit         (char *a_question, int a_num)
{
   int         c           = 0;
   /*---(initialize)---------------------*/
   strlcpy (unit_answer, "yURG_unit, unknown request", 100);
   /*---(string testing)-----------------*/
   if      (strncmp(a_question, "lower"     , 20)  == 0) {
      yURG__strings ();
      snprintf (unit_answer, LEN_TEXT, "yURG lower       : [%s]", s_lower);
   } else if (strncmp(a_question, "upper"     , 20)  == 0) {
      yURG__strings ();
      snprintf (unit_answer, LEN_TEXT, "yURG upper       : [%s]", s_upper);
   } else if (strncmp(a_question, "count"     , 20)  == 0) {
      c = yURG__count ();
      snprintf (unit_answer, LEN_TEXT, "yURG count       : %d"  , c);
   } else if (strncmp(a_question, "curr"      , 20)  == 0) {
      if (s_curr < 0) {
         snprintf (unit_answer, LEN_TEXT, "yURG curr   (%2d) : %c %s"  , s_curr, '-', "n/a");
      } else {
         snprintf (unit_answer, LEN_TEXT, "yURG curr   (%2d) : %c %s"  , s_curr, yURG_info [s_curr].abbr, yURG_info [s_curr].full);
      }
   } else if (strncmp(a_question, "orig"      , 20)  == 0) {
      snprintf (unit_answer, LEN_TEXT, "yURG orig   (%2d) : [%s]"  , s_norig, s_origs);
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}



char       /*----: set up programgents/debugging -----------------------------*/
yURG__testquiet     (void)
{
   char       *x_args [2]  = { "yURG_debug","@@quiet" };
   yURG_logger (2, x_args);
   return 0;
}

char       /*----: set up programgents/debugging -----------------------------*/
yURG__testloud      (void)
{
   char       *x_args [2]  = { "yURG_debug","@@kitchen" };
   yURG_logger (2, x_args);
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
yURG__testend       (void)
{
   DEBUG_TOPS   yLOG_end     ();
   return 0;
}

/*===[[ END ]]================================================================*/
