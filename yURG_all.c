/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"



/*===[[ GNU GENERAL PUBLIC LICENSE (GPL) ]]===================================*/
/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */

#define  P_COPYRIGHT   \
   "copyright (c) 2014 robert.s.heatherly at balsashrike at gmail dot com"

#define  P_LICENSE     \
   "the only place you could have gotten this code is my github, my website,¦"   \
   "or illegal sharing. given that, you should be aware that this is GPL licensed."

#define  P_COPYLEFT    \
   "the GPL COPYLEFT REQUIREMENT means any modifications or derivative works¦"   \
   "must be released under the same GPL license, i.e, must be free and open."

#define  P_INCLUDE     \
   "the GPL DOCUMENTATION REQUIREMENT means that you must include the original¦" \
   "copyright notice and the full licence text with any resulting anything."

#define  P_AS_IS       \
   "the GPL NO WARRANTY CLAUSE means the software is provided without any¦"      \
   "warranty and the author cannot be held liable for damages."

#define  P_THEFT    \
   "if you knowingly violate the spirit of these ideas, i suspect you might¦"    \
   "find any number of freedom-minded hackers may take it quite personally ;)"

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
/*===[[ GNU GENERAL PUBLIC LICENSE (GPL) ]]===================================*/




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

char
yURG_all_push           (void)
{
   myURG_priv.mlive_save = myURG_priv.mlive;
   strcpy (myURG_priv.mname_save, myURG_priv.mname);
   myURG_priv.elive_save = myURG_priv.elive;
   strcpy (myURG_priv.ename_save, myURG_priv.ename);
   return 0;
}

char
yURG_all_pop            (void)
{
   if (strcmp (myURG_priv.mname_save, YURG_MSG) == 0) yURG_msg_atmp   ();
   else                                               yURG_msg_custom (myURG_priv.mname_save);
   if (myURG_priv.mlive_save == 'y')  yURG_msg_live ();
   else                               yURG_msg_mute ();
   yURG_err_custom (myURG_priv.ename_save);
   if (myURG_priv.elive_save == 'y')  yURG_err_live ();
   else                               yURG_err_mute ();
   return 0;
}


