/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"



/*====================------------------------------------====================*/
/*===----                        utility functions                     ----===*/
/*====================------------------------------------====================*/
static void      o___UTILITY_______o (void) {;}

char        yURG_ver     [500];

char*      /* ---- : return library versioning information -------------------*/
yURG_version       (void)
{
   char    t [20] = "";
#if    __TINYC__ > 0
   strncpy (t, "[tcc built  ]", 15);
#elif  __GNUC__  > 0
   strncpy (t, "[gnu gcc    ]", 15);
#elif  __HEPH__  > 0
   strncpy (t, "[hephaestus ]", 15);
#else
   strncpy (t, "[unknown    ]", 15);
#endif
   snprintf (yURG_ver, 100, "%s   %s : %s", t, P_VERNUM, P_VERTXT);
   return yURG_ver;
}

char         /*--> return status of debug ----------------[ ------ [ ------ ]-*/
yURG_debugmode     (void)
{
   if (myURG.logger < 0)   return '-';
   return 'y';
}



/*====================------------------------------------====================*/
/*===----                    unit testing accessor                     ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST______o (void) {;}

char          unit_answer [LEN_RECD];

char*            /* [------] unit test accessor ------------------------------*/
yURG__unit         (char *a_question, int a_num)
{
   char        t           [LEN_RECD];
   int         c           = 0;
   /*---(initialize)---------------------*/
   strncpy (unit_answer, "yURG_unit, unknown request", 100);
   /*---(string testing)-----------------*/
   if      (strncmp(a_question, "lower"     , 20)  == 0) {
      yurg__strings ();
      snprintf (unit_answer, LEN_RECD, "yURG lower       : [%s]", myURG_priv.lower);
   } else if (strncmp(a_question, "upper"     , 20)  == 0) {
      yurg__strings ();
      snprintf (unit_answer, LEN_RECD, "yURG upper       : [%s]", myURG_priv.upper);
   } else if (strncmp(a_question, "count"     , 20)  == 0) {
      c = yurg__count ();
      snprintf (unit_answer, LEN_RECD, "yURG count       : %d"  , c);
   } else if (strncmp(a_question, "curr"      , 20)  == 0) {
      if (myURG_priv.curr < 0) {
         snprintf (unit_answer, LEN_RECD, "yURG curr   (%2d) : %c %s"  , myURG_priv.curr, '-', "n/a");
      } else {
         snprintf (unit_answer, LEN_RECD, "yURG curr   (%2d) : %c %s"  , myURG_priv.curr, yURG_info [myURG_priv.curr].abbr, yURG_info [myURG_priv.curr].full);
      }
   } else if (strncmp(a_question, "orig"      , 20)  == 0) {
      c = yURG_orig (t);
      snprintf (unit_answer, LEN_RECD, "yURG orig   (%2d) : [%s]"  , c, t);
   } else if (strncmp(a_question, "now"       , 20)  == 0) {
      c = yURG_curr (t);
      snprintf (unit_answer, LEN_RECD, "yURG now    (%2d) : [%s]"  , c, t);
   } else if (strncmp(a_question, "muting"    , 20)  == 0) {
      c = yURG_curr (t);
      snprintf (unit_answer, LEN_RECD, "yURG muting      : %c å%-25.25sæ  %c å%-25.25sæ"  , myURG_priv.mlive, t);
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}

char*
yURG_mute_status        (void)
{
   char        s           [LEN_DESC]  = "";
   char        t           [LEN_DESC]  = "";
   sprintf (s, "%c %-10.10p å%-.20sæ", myURG_priv.mlive, myURG_priv.mfile, myURG_priv.mname);
   sprintf (t, "%c %-10.10p å%-.20sæ", myURG_priv.elive, myURG_priv.efile, myURG_priv.ename);
   sprintf (unit_answer, "msg %-35.35s, err %s");
   return unit_answer;
}



char       /*----: set up programgents/debugging -----------------------------*/
yURG__unit_quiet        (void)
{
   char       *x_args [2]  = { "yURG_unit","@@quiet" };
   myURG_priv.curr = -1;   
   yURG_logger (2, x_args);
   return 0;
}

char       /*----: set up programgents/debugging -----------------------------*/
yURG__unit_loud         (void)
{
   char       *x_args [2]  = { "yURG_unit","@@kitchen" };
   myURG_priv.curr = -1;   
   yURG_logger (2, x_args);
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
yURG__unit_end          (void)
{
   DEBUG_ARGS   yLOGS_end     ();
   return 0;
}
