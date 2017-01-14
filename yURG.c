/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"

tYURG_INFO  yURG_info [MAX_URGS] = {
   /* abbr   full--------   desc------------------------------------  type */
   /*---(compound)-----------------------*/
   {   '-' , "quiet"      , "turn all universals off"               , '-', NULL                  },
   {   '-' , "full"       , "turn all universals on"                , '-', NULL                  },
   {   '-' , "kitchen"    , "turn all universals and special on"    , '-', NULL                  },
   {   '-' , "omniscient" , "turn absolutely everything on"         , '-', NULL                  },
   /*---(overall)------------------------*/
   {   't' , "tops"       , "broad structure and context"           , 'u', &yURG_debug.tops      },
   {   'r' , "summ"       , "runtime statistics/analytical output"  , 'u', &yURG_debug.tops      },
   /*---(startup/shutdown)---------------*/
   {   'a' , "args"       , "command-line args and urgent handling" , 'u', &yURG_debug.args      },
   {   'A' , "ARGS"       , "command-line args and urgent handling" , '#', &yURG_debug.args_mas  },
   {   'c' , "conf"       , "configuration handling"                , 'u', &yURG_debug.conf      },
   {   'C' , "CONF"       , "configuration handling"                , '#', &yURG_debug.conf_mas  },
   {   'p' , "prog"       , "program setup and shutdown"            , 'u', &yURG_debug.prog      },
   {   'P' , "PROG"       , "program setup and shutdown"            , '#', &yURG_debug.prog_mas  },
   /*---(file processing)----------------*/
   {   'i' , "inpt"       , "text and data file input"              , 'u', &yURG_debug.tops      },
   {   'I' , "INPT"       , "text and data file input"              , '#', &yURG_debug.tops      },
   {   'o' , "outp"       , "text and data file output"             , 'u', &yURG_debug.tops      },
   {   'O' , "OUTP"       , "text and data file output"             , '#', &yURG_debug.tops      },
   {   'q' , "sql"        , "database and sql interaction"          , 'u', &yURG_debug.tops      },
   {   'Q' , "SQL"        , "database and sql interaction"          , '#', &yURG_debug.tops      },
   /*---(event handling)-----------------*/
   {   'l' , "loop"       , "main program event loop"               , 'u', &yURG_debug.tops      },
   {   'L' , "LOOP"       , "main program event loop"               , '#', &yURG_debug.tops      },
   {   'u' , "user"       , "user input and handling"               , 'u', &yURG_debug.tops      },
   {   'U' , "USER"       , "user input and handling"               , '#', &yURG_debug.tops      },
   {   'z' , "apis"       , "interprocess communication"            , 'u', &yURG_debug.tops      },
   {   'Z' , "APIS"       , "interprocess communication"            , '#', &yURG_debug.tops      },
   {   'x' , "sign"       , "o/s signal handling"                   , 'u', &yURG_debug.tops      },
   {   'X' , "SIGN"       , "o/s signal handling"                   , '#', &yURG_debug.tops      },
   {   'b' , "scrp"       , "scripts and batch handling"            , 'u', &yURG_debug.tops      },
   {   'B' , "SCRP"       , "scripts and batch handling"            , '#', &yURG_debug.tops      },
   {   'h' , "hist"       , "history, undo, redo"                   , 'u', &yURG_debug.tops      },
   {   'H' , "HIST"       , "history, undo, redo"                   , '#', &yURG_debug.tops      },
   /*---(deeper program)-----------------*/
   {   'g' , "graf"       , "graphics, drawing, and display"        , 'u', &yURG_debug.tops      },
   {   'G' , "GRAF"       , "graphics, drawing, and display"        , '#', &yURG_debug.tops      },
   {   'd' , "data"       , "complex data structure handling"       , 'u', &yURG_debug.tops      },
   {   'D' , "DATA"       , "complex data structure handling"       , '#', &yURG_debug.tops      },
   {   'e' , "envi"       , "environmental processing"              , 'u', &yURG_debug.tops      },
   {   'E' , "ENVI"       , "environmental processing"              , '#', &yURG_debug.tops      },
   {   's' , "sort"       , "data sorting and ordering"             , 'u', &yURG_debug.tops      },
   {   'S' , "SORT"       , "data sorting and ordering"             , '#', &yURG_debug.tops      },
   /*---(specific)-----------------------*/
   /*---(end-of-list)--------------------*/
   {   '\0', "END-OF-LIST", "end of list"                           , ' ', NULL                  },

};

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
   }
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> set a single urgent by abbr -----------[ ------ [ ------ ]-*/
yURG_abbr          (char a_abbr)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;
   int         i           = 0;
   int         x_count     = 0;
   /*---(defense)------------------------*/
   --rce;  if (a_abbr <=  32)               return rce;
   --rce;  if (a_abbr >= 127)               return rce;
   /*---(find)---------------------------*/
   --rce;
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0')      break;
      /*---(filter)----------------------*/
      if (yURG_info [i].type  == '-')       continue;
      if (yURG_info [i].abbr  != a_abbr)    continue;
      if (yURG_info [i].point == NULL)      return rce;
      /*---(set)-------------------------*/
      ++x_count;
      *(yURG_info [i].point) = 'y';
   }
   /*---(check)--------------------------*/
   --rce;  if (x_count < 1  )               return rce;
   --rce;  if (x_count > 1  )               return rce;
   /*---(complete)-----------------------*/
   return 0;
}

char       /*----: process the urgents/debugging -----------------------------*/
yURG_mass          (char a_set, char a_extra)
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

char       /*----: process the urgents/debugging -----------------------------*/
yURG_parse         (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   char        rc          = 0;
   char       *a           = NULL;
   int         x_len       = 0;
   int         x_total     = 0;
   int         x_urgs      = 0;
   int         x_bad       = 0;
   /*---(process)------------------------*/
   DEBUG_TOPS  yLOG_enter (__FUNCTION__);
   for (i = 1; i < a_argc; ++i) {
      a = a_argv[i];
      ++x_total;
      if (a[0] != '@')  continue;
      DEBUG_ARGS  yLOG_info  ("urgent", a);
      x_len  = strlen (a);
      ++x_urgs;
      rc = 0;
      if      (x_len == 2)  rc = yURG_abbr  (a[1]);
      /*> else if (x_len >= 5)  rc = yURG_set   (a + 2);                              <*/
      else    ++x_bad;
      if (rc < 0) ++x_bad;
   }
   /*---(complete)-----------------------*/
   DEBUG_TOPS  yLOG_exit  (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                    unit testing accessor                     ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;}

#define       LEN_TEXT  2000
char          unit_answer [ LEN_TEXT ];

char*            /* [------] unit test accessor ------------------------------*/
yURG_unit          (char *a_question, int a_num)
{
   /*---(initialize)---------------------*/
   strlcpy (unit_answer, "yURG_unit, unknown request", 100);
   /*---(string testing)-----------------*/
   /*> if      (strncmp(a_question, "string"    , 20)  == 0) {                                                                                <* 
    *>    snprintf (unit_answer, LEN_TEXT, "ySTR string      : [%s]", its.strtest);                                                           <* 
    *> }                                                                                                                                      <* 
    *> /+---(argument testing)---------------+/                                                                                               <* 
    *> else if (strncmp(a_question, "argc"      , 20)  == 0) {                                                                                <* 
    *>    snprintf (unit_answer, LEN_TEXT, "ySTR argc        : %d", its.argc);                                                                <* 
    *> }                                                                                                                                      <* 
    *> else if (strncmp(a_question, "argv"      , 20)  == 0) {                                                                                <* 
    *>    if (a_num < 20 && a_num < its.argc)  {                                                                                              <* 
    *>       snprintf (unit_answer, LEN_TEXT, "ySTR argv (%2d)   : %3d [%-.40s]", a_num, strllen (its.argv[a_num], 2000), its.argv[a_num]);   <* 
    *>    } else {                                                                                                                            <* 
    *>       snprintf (unit_answer, LEN_TEXT, "ySTR argv (%2d)   : index out of range", a_num);                                               <* 
    *>    }                                                                                                                                   <* 
    *> }                                                                                                                                      <*/
   /*---(complete)-----------------------*/
   return unit_answer;
}



char       /*----: set up programgents/debugging -----------------------------*/
yURG_testquiet     (void)
{
   return 0;
}

char       /*----: set up programgents/debugging -----------------------------*/
yURG_testloud      (void)
{
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
yURG_testend       (void)
{
   return 0;
}

/*===[[ END ]]================================================================*/
