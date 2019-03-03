/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YURG_priv_hguard
#define YURG_priv_hguard loaded



/*===[[ HEADER ]]=============================================================*/
/*345678901-12345678901-123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/

#define     P_FOCUS     "RS (run-time support)"
#define     P_NICHE     "de (debugging/logging control)"
#define     P_PURPOSE   "simple, clean, incremental debugging and logging control"

#define     P_NAMESAKE  "zelus-daimon (enforcer)
#define     P_HERITAGE  "zelus, sibling of strength (kratos), force (bia), and victory (nike)"
#define     P_IMAGERY   "angel-like being, represents zeal and dedication, enforcer of zeus"

#define     P_SYSTEM    "gnu/linux   (powerful, ubiquitous, technical, and hackable)"
#define     P_LANGUAGE  "ansi-c      (wicked, limitless, universal, and everlasting)"
#define     P_CODESIZE  "small       (appoximately 1,000 slocl)"

#define     P_AUTHOR    "heatherlyrobert"
#define     P_CREATED   "2014-10"
#define     P_DEPENDS   "none"

#define     P_VERNUM    "0.4b"
#define     P_VERTXT    "added debug macro for yLOG to unit test"
#define     P_PRIORITY  "direct, simple, brief, vigorous, and lucid (h.w. fowler)"

/*345678901-12345678901-123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/

#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <string.h>       /* C_ANSI : printf, snprintf, fgets, fopen, ...  */
#include    <stdlib.h>       /* C_ANSI : exit                                 */
#include    <ctype.h>        /* C_ANSI : tolower, toupper, ...                */
#include    <sys/mount.h>    /* C_ANSI : mount                                */

#include    <yLOG.h>         /* CUSTOM : heatherly program logging            */
#include    <ySTR.h>         /* CUSTOM : heatherly string handling            */

#include    "yURG.h"


#define        LEN_LABEL        20
#define        LEN_DESC         80
#define        LEN_STR         200
#define        MAX_URGS        500

typedef   struct  cYURG_TYPE   tYURG_TYPE;
struct cYURG_TYPE
{
   char        type;                        /* matches urgent types           */
   char        subtype;                     /* matches urgent sub-types;      */
   char        desc        [LEN_LABEL];     /* description of type            */
};

typedef   struct  cYURG_INFO   tYURG_INFO;
struct cYURG_INFO
{
   char        abbr;                        /* single letter name             */
   char        fast;                        /* must evaluate with logging     */
   char        full        [LEN_LABEL];     /* full name                      */
   char        desc        [LEN_DESC ];     /* explanation                    */
   char        type;                        /* universal, mas, special        */
   char        subtype;                     /* universal, mas, special        */
   char       *point;                       /* universal, mas, special        */
};




char*       yURG__unit         (char *a_question, int a_num);
char        yURG__testquiet    (void);
char        yURG__testloud     (void);
char        yURG__testend      (void);


#endif
