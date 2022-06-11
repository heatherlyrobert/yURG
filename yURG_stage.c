/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"


char
yurg_stage_clear        (void)
{
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   strncpy (myURG.stage, "--- -----", LEN_LABEL);
   DEBUG_ARGS   yLOG_info    ("stage"     , myURG.stage);
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yurg_stage_prep         (void)
{
   int         i           =    0;
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   DEBUG_ARGS   yLOG_info    ("stage beg" , myURG.stage);
   if (strcmp (myURG.stage, "--- -----") == 0) {
      strncpy (myURG.stage, "yyy yyyyy", LEN_LABEL);
      DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   DEBUG_ARGS   yLOG_info    ("stage mid" , myURG.stage);
   if (myURG.stage [YURG_MID] == 'y') {
      myURG.stage [YURG_ONE] = 'y';
      myURG.stage [YURG_TWO] = 'y';
      myURG.stage [YURG_THR] = 'y';
      myURG.stage [YURG_FOU] = 'y';
      myURG.stage [YURG_FIV] = 'y';
      DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   for (i = YURG_ONE; i <= YURG_FIV; ++i) {
      if (myURG.stage [i] == 'y') myURG.stage [YURG_MID] = 'y';
   }
   DEBUG_ARGS   yLOG_info    ("stage end" , myURG.stage);
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yURG_stage_check        (char a_stage)
{
   char        rc          =   -1;
   char        s           [LEN_RECD];
   char        t           [LEN_RECD];
   if (myURG.mute != 'y')  yLOGS_unmute ();
   sprintf (t, "%s : %s, checking %d, ", __FUNCTION__, myURG.stage, a_stage);
   switch (a_stage) {
   case YURG_BEG  :  myURG.cstage = 'ù'; strncpy (s, "start-up"        , LEN_RECD);   break;
   case YURG_MID  :  myURG.cstage = 'ò'; strncpy (s, "main loop"       , LEN_RECD);   break;
   case YURG_END  :  myURG.cstage = 'ÿ'; strncpy (s, "wrap-up"         , LEN_RECD);   break;
   case YURG_ONE  :  myURG.cstage = 'è'; strncpy (s, "user block 1"    , LEN_RECD);   break;
   case YURG_TWO  :  myURG.cstage = 'é'; strncpy (s, "user block 2"    , LEN_RECD);   break;
   case YURG_THR  :  myURG.cstage = 'ê'; strncpy (s, "user block 3"    , LEN_RECD);   break;
   case YURG_FOU  :  myURG.cstage = 'ë'; strncpy (s, "user block 4"    , LEN_RECD);   break;
   case YURG_FIV  :  myURG.cstage = 'ì'; strncpy (s, "user block 5"    , LEN_RECD);   break;
   default        :  myURG.cstage = '·'; strncpy (s, "UNKNOWN stage"   , LEN_RECD);   break;
   }
   strncat (t, s, LEN_RECD);
   if (myURG.stage [a_stage] == 'y') {
      strncat (t, ", UNMUTING", LEN_RECD);
      yLOG_note (t);
      rc = 1;
   } else {
      strncat (t, ", MUTING", LEN_RECD);
      yLOG_note (t);
      if (myURG.mute != 'y')  yLOGS_mute   ();
      rc = 0;
   }
   return rc;
}



/*====================------------------------------------====================*/
/*===----                    unit testing accessor                     ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;}

char*            /* [------] unit test accessor ------------------------------*/
yurg_stage__unit        (char *a_question, int a_num)
{
   char        t           [LEN_RECD];
   int         c           = 0;
   /*---(initialize)---------------------*/
   snprintf (unit_answer, LEN_RECD, "STAGE            : request not understood");
   /*---(string testing)-----------------*/
   if      (strncmp (a_question, "settings"  , 20)  == 0) {
      snprintf (unit_answer, LEN_RECD, "STAGE settings   : [%s]", myURG.stage);
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}


