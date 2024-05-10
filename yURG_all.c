/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"




/*====================------------------------------------====================*/
/*===----                     message and error                        ----===*/
/*====================------------------------------------====================*/
static void  o___ALL_____________o () { return; }

char
yURG_all_clear          (void)
{
   yURG_msg_clear ();
   yURG_err_clear ();
   return 0;
}

char
yURG_all_tmp            (void)
{
   yURG_msg_tmp ();
   yURG_msg_clear ();
   yURG_err_tmp ();
   yURG_err_clear ();
   return 0;
}

char
yURG_all_live           (void)
{
   yURG_msg_live ();
   yURG_err_live ();
   return 0;
}

char
yURG_all_none           (void)
{
   yURG_msg_none ();
   yURG_err_none ();
   return 0;
}

char
yURG_all_mute           (void)
{
   yURG_msg_mute ();
   yURG_err_mute ();
   return 0;
}

char
yURG_all_off            (void)
{
   yURG_all_mute ();
   yURG_all_none ();
   return 0;
}

char
yURG_all_tmplive        (void)
{
   yURG_msg_tmp   ();
   yURG_msg_live  ();
   yURG_msg_clear ();
   yURG_err_tmp   ();
   yURG_err_live  ();
   yURG_err_clear ();
   return 0;
}
