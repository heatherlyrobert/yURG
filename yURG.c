/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"

tURG_DEBUG      yURG_debug;

char        s_lower     [30] = "";
char        s_upper     [30] = "";
char        s_digit     [30] = "";

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
   /* abbr  fast  full--------   desc------------------------------------  type */
   /*---(compound)-----------------------*/
   {   '-' , 'y' , "quiet"          , "turn absolutely everything off"        , '-', '-', NULL                           },
   {   '-' , 'y' , "full"           , "turn all universals on"                , '-', '-', NULL                           },
   {   '-' , 'y' , "mas"            , "turn all universals and their mas on"  , '-', '-', NULL                           },
   {   '-' , 'y' , "kitchen"        , "turn all universals/specific (no mas)" , '-', '-', NULL                           },
   {   '-' , 'y' , "omniscient"     , "turn absolutely everything on"         , '-', '-', NULL                           },
   {   '-' , 'y' , "urgents"        , "list all urgents available in program" , 'u', '-', NULL                           },
   /*---(overall)------------------------*/
   {   't' , '-' , "tops"           , "broad structure and context"           , 'u', 'o', &yURG_debug.tops               },
   {   'T' , '-' , "TOPS"           , "broad structure and context"           , '#', 'o', &yURG_debug.tops_mas           },
   {   'r' , '-' , "summ"           , "runtime statistics/analytical output"  , 'u', 'o', &yURG_debug.summ               },
   {   'R' , '-' , "SUMM"           , "runtime statistics/analytical output"  , '#', 'o', &yURG_debug.summ_mas           },
   {   'v' , '-' , "verbose"        , "provide alternate terminal output"     , 'u', 'o', &yURG_debug.verb               },
   {   'V' , '-' , "VERBOSE"        , "provide alternate terminal output"     , '#', 'o', &yURG_debug.verb_mas           },
   /*---(startup/shutdown)---------------*/
   {   'a' , 'y' , "args"           , "command-line args and urgent handling" , 'u', 's', &yURG_debug.args               },
   {   'A' , 'y' , "ARGS"           , "command-line args and urgent handling" , '#', 's', &yURG_debug.args_mas           },
   {   'c' , '-' , "conf"           , "configuration handling"                , 'u', 's', &yURG_debug.conf               },
   {   'C' , '-' , "CONF"           , "configuration handling"                , '#', 's', &yURG_debug.conf_mas           },
   {   'p' , 'y' , "prog"           , "program setup and shutdown"            , 'u', 's', &yURG_debug.prog               },
   {   'P' , 'y' , "PROG"           , "program setup and shutdown"            , '#', 's', &yURG_debug.prog_mas           },
   /*---(file processing)----------------*/
   {   'i' , '-' , "inpt"           , "text and data file input"              , 'u', 'd', &yURG_debug.inpt               },
   {   'I' , '-' , "INPT"           , "text and data file input"              , '#', 'd', &yURG_debug.inpt_mas           },
   {   'o' , '-' , "outp"           , "text and data file output"             , 'u', 'd', &yURG_debug.outp               },
   {   'O' , '-' , "OUTP"           , "text and data file output"             , '#', 'd', &yURG_debug.outp_mas           },
   {   'q' , '-' , "sqls"           , "database and sql interaction"          , 'u', 'd', &yURG_debug.sqls               },
   {   'Q' , '-' , "SQLS"           , "database and sql interaction"          , '#', 'd', &yURG_debug.sqls_mas           },
   /*---(event handling)-----------------*/
   {   'l' , '-' , "loop"           , "main program event loop"               , 'u', 'e', &yURG_debug.loop               },
   {   'L' , '-' , "LOOP"           , "main program event loop"               , '#', 'e', &yURG_debug.loop_mas           },
   {   'u' , '-' , "user"           , "user input and handling"               , 'u', 'e', &yURG_debug.user               },
   {   'U' , '-' , "USER"           , "user input and handling"               , '#', 'e', &yURG_debug.user_mas           },
   {   'z' , '-' , "apis"           , "interprocess communication"            , 'u', 'e', &yURG_debug.apis               },
   {   'Z' , '-' , "APIS"           , "interprocess communication"            , '#', 'e', &yURG_debug.apis_mas           },
   {   'x' , '-' , "sign"           , "o/s signal handling"                   , 'u', 'e', &yURG_debug.sign               },
   {   'X' , '-' , "SIGN"           , "o/s signal handling"                   , '#', 'e', &yURG_debug.sign_mas           },
   {   'b' , '-' , "scrp"           , "scripts and batch handling"            , 'u', 'e', &yURG_debug.scrp               },
   {   'B' , '-' , "SCRP"           , "scripts and batch handling"            , '#', 'e', &yURG_debug.scrp_mas           },
   {   'h' , '-' , "hist"           , "history, undo, redo"                   , 'u', 'e', &yURG_debug.hist               },
   {   'H' , '-' , "HIST"           , "history, undo, redo"                   , '#', 'e', &yURG_debug.hist_mas           },
   /*---(deeper program)-----------------*/
   {   'g' , '-' , "graf"           , "graphics, drawing, and display"        , 'u', 'p', &yURG_debug.graf               },
   {   'G' , '-' , "GRAF"           , "graphics, drawing, and display"        , '#', 'p', &yURG_debug.graf_mas           },
   {   'd' , '-' , "data"           , "complex data structure handling"       , 'u', 'p', &yURG_debug.data               },
   {   'D' , '-' , "DATA"           , "complex data structure handling"       , '#', 'p', &yURG_debug.data_mas           },
   {   'e' , '-' , "envi"           , "environmental processing"              , 'u', 'p', &yURG_debug.envi               },
   {   'E' , '-' , "ENVI"           , "environmental processing"              , '#', 'p', &yURG_debug.envi_mas           },
   {   's' , '-' , "sort"           , "data sorting and ordering"             , 'u', 'p', &yURG_debug.sort               },
   {   'S' , '-' , "SORT"           , "data sorting and ordering"             , '#', 'p', &yURG_debug.sort_mas           },
   /*---(hermes)-------------------------*/
   {   '-' , '-' , "dirs"           , "hermes location tracking"              , 's', '-', &yURG_debug.dirs               },
   {   '-' , '-' , "DIRS"           , "hermes location tracking"              , 'M', '-', &yURG_debug.dirs_mas           },
   {   '-' , '-' , "pkgs"           , "hermes package tracking"               , 's', '-', &yURG_debug.cell               },
   {   '-' , '-' , "PKGS"           , "hermes package tracking"               , 'M', '-', &yURG_debug.cell_mas           },
   {   '-' , '-' , "cmds"           , "hermes command tracking"               , 's', '-', &yURG_debug.cell               },
   {   '-' , '-' , "CMDS"           , "hermes command tracking"               , 'M', '-', &yURG_debug.cell_mas           },
   {   '-' , '-' , "gentoo"         , "hermes gentoo/portage access"          , 's', '-', &yURG_debug.cell               },
   {   '-' , '-' , "GENTOO"         , "hermes gentoo/portage access"          , 'M', '-', &yURG_debug.cell_mas           },
   {   '-' , '-' , "cache"          , "hermes cached database"                , 's', '-', &yURG_debug.cell               },
   {   '-' , '-' , "CACHE"          , "hermes cached database"                , 'M', '-', &yURG_debug.cell_mas           },
   /*---(spreadsheet)--------------------*/
   {   '-' , '-' , "locs"           , "spreadsheet location parsing and use"  , 's', '-', &yURG_debug.locs               },
   {   '-' , '-' , "LOCS"           , "spreadsheet location parsing and use"  , 'M', '-', &yURG_debug.locs_mas           },
   {   '-' , '-' , "cell"           , "spreadsheet cell creation and mtce"    , 's', '-', &yURG_debug.cell               },
   {   '-' , '-' , "CELL"           , "spreadsheet cell creation and mtce"    , 'M', '-', &yURG_debug.cell_mas           },
   /*---(calculations)-------------------*/
   {   '-' , '-' , "rpn"            , "calculation conversion infix to rpn"   , 's', '-', &yURG_debug.rpn                },
   {   '-' , '-' , "RPN"            , "calculation conversion infix to rpn"   , 'M', '-', &yURG_debug.rpn_mas            },
   {   '-' , '-' , "calc"           , "calculation building from rpn"         , 's', '-', &yURG_debug.calc               },
   {   '-' , '-' , "CALC"           , "calculation building from rpn"         , 'M', '-', &yURG_debug.calc_mas           },
   {   '-' , '-' , "exec"           , "calculation execution"                 , 's', '-', &yURG_debug.exec               },
   {   '-' , '-' , "EXEC"           , "calculation execution"                 , 'M', '-', &yURG_debug.exec_mas           },
   {   '-' , '-' , "adjs"           , "small, config adjustments in measures" , 's', '-', &yURG_debug.adjs               },
   {   '-' , '-' , "ADJS"           , "small, config adjustments in measures" , 'M', '-', &yURG_debug.adjs_mas           },
   /*---(dependencies)-------------------*/
   {   '-' , '-' , "deps"           , "dependency creation and maintenance"   , 's', '-', &yURG_debug.deps               },
   {   '-' , '-' , "DEPS"           , "dependency creation and maintenance"   , 'M', '-', &yURG_debug.deps_mas           },
   /*---(visual)-------------------------*/
   {   '-' , '-' , "visu"           , "visual selection of objects"           , 's', '-', &yURG_debug.visu               },
   {   '-' , '-' , "VISU"           , "visual selection of objects"           , 'M', '-', &yURG_debug.visu_mas           },
   {   '-' , '-' , "ssel"           , "visual selection of text strings"      , 's', '-', &yURG_debug.ssel               },
   {   '-' , '-' , "SSEL"           , "visual selection of text strings"      , 'M', '-', &yURG_debug.ssel_mas           },
   {   '-' , '-' , "mark"           , "location and object marks"             , 's', '-', &yURG_debug.mark               },
   {   '-' , '-' , "MARK"           , "location and object marks"             , 'M', '-', &yURG_debug.mark_mas           },
   /*---(registers)----------------------*/
   {   '-' , '-' , "regs"           , "copy and paste registers"              , 's', '-', &yURG_debug.regs               },
   {   '-' , '-' , "REGS"           , "copy and paste registers"              , 'M', '-', &yURG_debug.regs_mas           },
   /*---(libraries)----------------------*/
   {   '-' , '-' , "ystr"           , "heatherly ySTR string library"         , 'l', 's', &yURG_debug.ystr               },
   {   '-' , '-' , "YSTR"           , "heatherly ySTR string library"         , 'M', 's', &yURG_debug.ystr_mas           },
   {   '-' , '-' , "ykine_calc"     , "yKINE kinematics calculations"         , 'l', 'k', &yURG_debug.ykine_calc         },
   {   '-' , '-' , "YKINE_CALC"     , "yKINE kinematics calculations"         , 'M', 'k', &yURG_debug.ykine_calc_mas     },
   {   '-' , '-' , "ykine_data"     , "yKINE kinematics common data"          , 'l', 'k', &yURG_debug.ykine_data         },
   {   '-' , '-' , "YKINE_DATA"     , "yKINE kinematics common data"          , 'M', 'k', &yURG_debug.ykine_data_mas     },
   {   '-' , '-' , "ykine_scrp"     , "yKINE kinematics script interpretation", 'l', 'k', &yURG_debug.ykine_scrp         },
   {   '-' , '-' , "YKINE_SCRP"     , "yKINE kinematics script interpretation", 'M', 'k', &yURG_debug.ykine_scrp_mas     },
   {   '-' , '-' , "yvikeys_keys"   , "yVIKEYS vi-keys handling library"      , 'l', 'v', &yURG_debug.yvikeys_keys       },
   {   '-' , '-' , "YVIKEYS_KEYS"   , "yVIKEYS vi-keys handling library"      , 'M', 'v', &yURG_debug.yvikeys_keys_mas   },
   {   '-' , '-' , "yvikeys_mode"   , "yVIKEYS vi-keys handling library"      , 'l', 'v', &yURG_debug.yvikeys_mode       },
   {   '-' , '-' , "YVIKEYS_MODE"   , "yVIKEYS vi-keys handling library"      , 'M', 'v', &yURG_debug.yvikeys_mode_mas   },
   {   '-' , '-' , "yvikeys_scale"  , "yVIKEYS vi-keys handling library"      , 'l', 'v', &yURG_debug.yvikeys_scale      },
   {   '-' , '-' , "YVIKEYS_SCALE"  , "yVIKEYS vi-keys handling library"      , 'M', 'v', &yURG_debug.yvikeys_scale_mas  },
   {   '-' , '-' , "yfont"          , "yFONT texturn mapped font library"     , 'l', 'g', &yURG_debug.yfont              },
   {   '-' , '-' , "YFONT"          , "yFONT texturn mapped font library"     , 'M', 'g', &yURG_debug.yfont_mas          },
   {   '-' , '-' , "yfont_file"     , "yFONT file creation and access"        , 'l', 'g', &yURG_debug.yfont_file         },
   {   '-' , '-' , "yfont_calc"     , "yFONT layout and vertex calculation"   , 'l', 'g', &yURG_debug.yfont_calc         },
   {   '-' , '-' , "yfont_map"      , "yFONT texture mapping and access"      , 'l', 'g', &yURG_debug.yfont_map          },
   {   '-' , '-' , "ygltex"         , "yGLTEX opengl texture handling"        , 'l', 'g', &yURG_debug.ygltex             },
   {   '-' , '-' , "YGLTEX"         , "yGLTEX opengl texture handling"        , 'M', 'g', &yURG_debug.ygltex_mas         },
   {   '-' , '-' , "ycolor"         , "yGLTEX opengl color handling"          , 'l', 'g', &yURG_debug.ycolor             },
   {   '-' , '-' , "YCOLOR"         , "yGLTEX opengl color handling"          , 'M', 'g', &yURG_debug.ycolor_mas         },
   /*---(end-of-list)--------------------*/
   {   '\0', '-' , "END-OF-LIST", "end of list"                           , ' ', ' ', NULL                  },

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
   snprintf (yURG_ver, 100, "%s   %s : %s", t, YURG_VER_NUM, YURG_VER_TXT);
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
      if (*(yURG_info [i].point) != 'y')      continue;
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
   strlcpy  (s_lower, "--------------------------", LEN_STR);
   strlcpy  (s_upper, "--------------------------", LEN_STR);
   strlcpy  (s_digit, "----------"                , LEN_STR);
   /*---(list)---------------------------*/
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr     == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].abbr     == '-')      continue;
      if (yURG_info [i].type     == '-')      continue;
      if (  yURG_info [i].point  == NULL)     continue;
      if (*(yURG_info [i].point) != 'y')      continue;
      /*---(append)----------------------*/
      c = yURG_info [i].abbr;
      if (c >= 'a' && c <= 'z')  s_lower [c - 'a'] = c;
      if (c >= 'A' && c <= 'Z')  s_upper [c - 'A'] = c;
      if (c >= '0' && c <= '9')  s_digit [c - '0'] = c;
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
   char        x_header    [LEN_STR  ] = "";
   /*---(list universals)----------------*/
   printf ("yURG : urgent inventory report\n\n");
   if (yURG_debug.mode != 'y') {
      printf ("YOU ARE NOT RUNNING IN DEBUG MODE\n");
      printf ("urgents are only active if debug version of program is used (except @v).\n");
      printf ("to run %s in debug mode, use %s_debug\n\n", a_progname, a_progname);
   }
   /*---(cycle types)--------------------*/
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(filter)----------------------*/
      if (yURG_type [i].type     == '\0')                            break;
      if (yURG_type [i].subtype  != '-' )                            continue;
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
         if (yURG_info [j].subtype != x_subsave && yURG_info [j].subtype != '-') {
            for (k = 0; k < MAX_URGS; ++k) {
               /*---(filter)----------------------*/
               if (yURG_type [k].type    == '\0')                    break;
               if (yURG_type [k].type    != x_type)                  continue;
               if (yURG_type [k].subtype != yURG_info [j].subtype)   continue;
               sprintf (x_header, "---%s---------------------------", yURG_type [k].desc);
               printf  ("   %-30.30s\n", x_header);
               break;
            }
            x_subsave = yURG_info [j].subtype;
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

char         /*--> set a single urgent by abbr -----------[ ------ [ ------ ]-*/
yURG_abbr          (cchar a_abbr, cchar a_on)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;
   int         i           = 0;
   int         x_count     = 0;
   char       *x_valid     = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
   /*---(header)-------------------------*/
   DEBUG_ARGS_M   yLOG_enter   (__FUNCTION__);
   DEBUG_ARGS_M   yLOG_value   ("a_abbr"    , a_abbr);
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
      if (yURG_info [i].abbr  != a_abbr)              continue;
      DEBUG_ARGS_M   yLOG_note    ("MATCH");
      if (yURG_info [i].point == NULL) {
         DEBUG_ARGS_M   yLOG_note    ("bad pointer on record");
         DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
         return rce;
      }
      /*---(set)-------------------------*/
      DEBUG_ARGS_M   yLOG_note    ("set on and increment counter");
      ++x_count;
      *(yURG_info [i].point) = YURG_ON;
      /*---(check mas)-------------------*/
      if (yURG_info [i].type  == '#' && a_abbr >= 'A' && a_abbr <= 'Z') {
         DEBUG_ARGS_M   yLOG_note    ("attemp to set non-mas version");
         yURG_abbr (tolower (a_abbr), a_on);
      }
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
   DEBUG_ARGS_M   yLOG_info    ("a_name"    , a_name);
   /*---(defense)------------------------*/
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
      if (yURG_info [i].full[0] != a_name [0])        continue;
      if (strcmp (yURG_info [i].full, a_name) != 0)   continue;
      DEBUG_ARGS_M   yLOG_note    ("MATCH");
      /*---(compound)--------------------*/
      if (yURG_info [i].type == '-') {
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
      *(yURG_info [i].point) = a_on;
      /*---(check mas)-------------------*/
      if ((yURG_info [i].type  == '#' || yURG_info [i].type  == 'M') && strcmp (x_lower, a_name) != 0) {
         yURG_name (x_lower, a_on);
      }
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
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   char       *a           = NULL;
   int         x_len       = 0;
   char        x_progname  [LEN_STR] = "";
   char        x_basename  [LEN_STR] = "";
   char        x_log       = '-';
   char        x_type      = '-';
   char        x_args      = '-';
   char        x_prog      = '-';
   char        x_verb      = '-';
   /*---(default urgents)----------------*/
   yURG_debug.logger   =  -1;
   yURG_debug.mode     = '-';
   yURG_mass    ('-', 'E');   /* turn everything off */
   strlcpy (x_progname, a_argv [0], LEN_STR);
   strlcpy (x_basename, a_argv [0], LEN_STR);
   x_len  = strllen (x_progname, LEN_LABEL);
   /*> printf ("%3d:%s\n", x_len, x_progname);                                        <* 
    *> printf ("   :%s\n",        x_progname + x_len - 6);                            <* 
    *> printf ("   :%s\n",        x_progname + x_len - 5);                            <*/
   /*---(test for normal version)--------*/
   if (x_len >= 6) {
      if (strcmp (a_argv[0] + x_len - 6, "_debug") == 0)  x_type = 'd';
      if (strcmp (a_argv[0] + x_len - 5, "_unit" ) == 0)  x_type = 'u';
      /*> printf ("type = %c\n", x_type);                                                <*/
      if (x_type != '-')   yURG_debug.mode   = 'y';
   }
   /*---(fix program name)---------------*/
   if (x_type == 'd') {
      x_basename [x_len - 6] = '\0';
      strlcpy (x_progname, x_basename, LEN_STR);
   }
   if (x_type == 'u') {
      x_basename [x_len - 5] = '\0';
   }
   x_len  = strllen (x_progname, LEN_LABEL);
   /*> printf ("%3d:%s\n", x_len, x_progname);                                        <*/
   /*---(process)------------------------*/
   for (i = 1; i < a_argc; ++i) {
      /*---(prepare)---------------------*/
      a = a_argv[i];
      /*> printf ("evaluating %2d:%s\n", i, a);                                       <*/
      /*---(filter)----------------------*/
      if (a[0] != '@')   continue;
      /*---(non-logging)-----------------*/
      if      (strcmp (a, "@v"           ) == 0) { x_verb = 'v'; continue; }
      else if (strcmp (a, "@@verbose"    ) == 0) { x_verb = 'V'; continue; }
      else if (strcmp (a, "@V"           ) == 0) { x_verb = 'v'; continue; }
      else if (strcmp (a, "@@VERBOSE"    ) == 0) { x_verb = 'V'; continue; }
      /*---(logging)---------------------*/
      if (x_log == '-') x_log = 'y';
      /*---(singles)---------------------*/
      if      (strcmp (a, "@q"           ) == 0)   x_log  = 'q';
      else if (strcmp (a, "@@quiet"      ) == 0)   x_log  = 'q';
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
      /*> printf ("done, ready for next\n");                                          <*/
   }
   /*> printf ("log  = %c\n", x_log);                                                 <*/
   /*---(hande verbose flag)-------------*/
   if (x_verb == 'v')    yURG_debug.verb = 'y';
   if (x_args == 'V')  { yURG_debug.verb = 'y'; yURG_debug.verb_mas = 'y'; }
   /*---(startup logging)----------------*/
   if (yURG_debug.mode != 'y')                                  return 0;
   switch (x_log) {
   case 'y' :
      yURG_debug.logger = yLOG_begin (x_progname, yLOG_SYSTEM    , yLOG_NOISE);
      break;
   case 'q' :
   case '-' :
   default  :
      yURG_debug.logger = yLOG_begin (x_progname, yLOG_SYSTEM    , yLOG_QUIET);
      break;
   }
   /*> printf ("debugger = %d\n", yURG_debug.logger);                                 <*/
   /*---(fast update)--------------------*/
   yURG_debug.tops = YURG_ON;
   if (x_args == 'a')    yURG_debug.args = YURG_ON;
   if (x_args == 'A')    yURG_debug.args = yURG_debug.args_mas = YURG_ON;
   if (x_prog == 'p')    yURG_debug.prog = YURG_ON;
   if (x_prog == 'P')    yURG_debug.prog = yURG_debug.prog_mas = YURG_ON;
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
   int         x_urgs      = 0;
   int         x_bad       = 0;
   int         x_good      = 0;
   /*---(defense)------------------------*/
   if (yURG_debug.mode != 'y')   return 0;
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(process)------------------------*/
   for (i = 1; i < a_argc; ++i) {
      a = a_argv[i];
      DEBUG_ARGS   yLOG_info    ("option"    , a);
      ++x_total;
      if (a[0] != '@')  continue;
      DEBUG_ARGS   yLOG_note    ("idenfified urgent");
      x_len  = strlen (a);
      ++x_urgs;
      rc = 0;
      if      (x_len == 2)  rc = yURG_abbr  (a[1] , YURG_ON);
      else if (x_len >= 5)  rc = yURG_name  (a + 2, YURG_ON);
      else {
         DEBUG_ARGS   yLOG_note    ("could not process");
         ++x_bad;
      }
      DEBUG_ARGS   yLOG_value   ("rc"        , rc);
      if (rc < 0) ++x_bad;
      else        ++x_good;
   }
   DEBUG_ARGS   yLOG_value   ("x_good"    , x_good);
   DEBUG_ARGS   yLOG_value   ("x_bad"     , x_bad);
   yURG_summ   ();
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return x_good;
}



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
   } else if (strncmp(a_question, "digit"     , 20)  == 0) {
      yURG__strings ();
      snprintf (unit_answer, LEN_TEXT, "yURG digit       : [%s]", s_digit);
   } else if (strncmp(a_question, "count"     , 20)  == 0) {
      c = yURG__count ();
      snprintf (unit_answer, LEN_TEXT, "yURG count       : %d"  , c);
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
