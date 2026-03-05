/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YURG_priv_hguard
#define YURG_priv_hguard loaded



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



/*===[[ ONE_LINERS ]]=========================================================*/
/*                      ´·········1·········2·········3·········4·········5·········6·········7*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*········· ··········· ´·····························´········································*/
#define     P_FOCUS     "RS (run-time support)"
#define     P_NICHE     "de (debugging/logging control)"
#define     P_SUBJECT   "runtime debugging control"
#define     P_PURPOSE   "simple, clean, incremental debugging and logging control"
/*········· ··········· ´·····························´········································*/
#define     P_NAMESAKE  "zelus-daimon (enforcer)"
#define     P_PRONOUNCE ""
#define     P_HERITAGE  "zeal, sibling of strength (kratos), force (bia), and victory (nike)"
#define     P_BRIEFLY   ""
#define     P_IMAGERY   "angel-like being, represents zeal and dedication, enforcer of zeus"
#define     P_REASON    "daimon of zealousness, dedication, and enforcement"
/*········· ··········· ´·····························´········································*/
#define     P_ONELINE   P_NAMESAKE " " P_SUBJECT
/*········· ··········· ´·····························´········································*/
#define     P_HOMEDIR   "/home/system/yURG.urgent_processing"
#define     P_BASENAME  "yURG"
#define     P_FULLPATH  "/usr/local/lib64/libyURG.so"
#define     P_SUFFIX    "···"
#define     P_CONTENT   "···"
/*········· ··········· ´·····························´········································*/
#define     P_SYSTEM    "gnu/linux   (powerful, ubiquitous, technical, and hackable)"
#define     P_LANGUAGE  "ansi-c      (wicked, limitless, universal, and everlasting)"
#define     P_COMPILER  "gcc 5.3.0"
#define     P_CODESIZE  "small       (appoximately 1,000 slocl)"
/*········· ··········· ´·····························´········································*/
#define     P_AUTHOR    "heatherlyrobert"
#define     P_CREATED   "2014-10"
/*········· ··········· ´·····························´········································*/
#define     P_VERMAJOR  "1.--, production improvements"
#define     P_VERMINOR  "1.2-, catch-up with production use"
#define     P_VERNUM    "1.2a"
#define     P_VERTXT    "minor modifications to unit testing to fully check out"
/*········· ··········· ´·····························´········································*/
#define     P_PRIORITY  "direct, simple, brief, vigorous, and lucid (h.w. fowler)"
#define     P_PRINCIPAL "[grow a set] and build your wings on the way down (r. bradbury)"
#define     P_REMINDER  "there are many better options, but i *own* every byte of this one"
/*········· ··········· ´·····························´········································*/
#define     P_DEPANSI   "stdio,string,stdlib,stdarg,unistd"
#define     P_DEPPOSIX  "ctype,sys/stat,pwd,grp,fcntl,sys/sysmacros,openssl/sha"
#define     P_DEPCORE   ""
#define     P_DEPVIKEY  ""
#define     P_DEPGRAPH  ""
#define     P_DEPOTHER  ""
#define     P_DEPSOLO   "ySTR_solo,yCOLOR_solo,yDLST_solo"
#define     P_DEPALIEN  ""
/*········· ··········· ´·····························´········································*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/



/*===[[ REASONING ]]==========================================================*/
/*345678901-12345678901-12345678901-12345678901-12345678901-12345678901-12345678901-12345678901-*/

#define     P_DEFINE    \
 "process logging and debugging is a method of observing actual program¦" \
 "behavior in order to learn, trace, identify, understand, and repair¦" \
 "non-trivial and emergent (multi-cause) run-time issues¦"
#define     P_CURRENT   \
 "my code base is growing quickly and much of that code executes either¦" \
 "continuously, frequently, or at critical moments -- big code base,¦" \
 "audacious plans, and one programmer to rule it all ;)¦"
#define     P_CONCERN   \
 "the art of logging, messaging, reporting, and creating transparent programs¦" \
 "has been replaced with massive, complex programs and expensive commercial¦" \
 "monitoring with incoherent streams of one-dimentional, ad-hoc messages.¦"
#define     P_ALTERNS   "syslog, systemd, printf, gdb"
#define     P_VALUE     \
 "process logging and debugging is a rapid way to diagnose process issues.¦" \
 "it is a huge time and resource saver in build/testing, recreating prodution¦" \
 "issues, and regaining logic/flow knowledge.¦"
#define     P_USERBASE  \
 "never confuse tailored, technical, super-user systems and general, easy-¦" \
 "to-use, zero effort required systems built to get end-users up and happy¦" \
 "as quickly as possible.  i will always chose power.¦"
#define     P_NEED      \
 "i need something run-time configurable, remain built-in, and ready for¦" \
 "immediate use.  it must include structure/flow logging as well as values¦" \
 "and state messages, and be easy to search, sort, and filter.¦"
#define     P_SUMMARY   \
 "yURG/yLOG are a pair of simple, direct, consistent, and clean libraries¦" \
 "to enable process logging, tracing, and debugging in order to speed issue¦" \
 "detection, identification, repair, and validation in my custom programs.¦"
#define     P_OBJECTIVE \
 "a) allow programs to be observed without significantly altering them¦" \
 "b) provide a forensic trail for programs to aid reproduction of issues¦" \
 "c) keep it simple so that it does not require huge learning curve¦" \
 "d) cleanly incorporated so it can remain permenantly in source code¦" \
 "e) maximize reuse so i don't have to recreate each time¦" \
 "f) standardize so data can be scanned quickly and troubles found fast¦" \
 "g) easy and automatic to remove so as to not hamper production¦" \
 "h) allows programmers to see the true program execution  path¦" \
 "i) cut significant time from tracing, debugging, and maintaining¦" \
 "j) speed education of new maintainers and unit testers (watch flow)¦" \
 "k) re-enforce a disciplined development culture and building-to-last¦" \
 "l) avoid a product that will require me to switch every few years¦"
#define     P_WARNINGS  \
 "a) logging eats up cpu, disk, and other resources¦" \
 "b) is rarely reviewed (only because existing methods are complicated)¦" \
 "c) can distract when nothing needs to be reviewed (configurable)¦" \
 "d) is one more thing that can go wrong (always funny)¦" \
 "e) must be very different for high volume apps¦" \
 "f) has to be built ahead of time and therefore can slow projects¦" \
 "g) since its shared, changes can effect all programs¦" \
 "h) drives a single method of thinking (myopia requires self-review)¦"

/*===[[ END_HEADER ]]=========================================================*/

/*345678901-12345678901-123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/

#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <string.h>       /* C_ANSI : printf, snprintf, fgets, fopen, ...  */
#include    <stdlib.h>       /* C_ANSI : exit                                 */
#include    <stdarg.h>       /* C_ANSI : va_args                              */
#include    <ctype.h>        /* C_ANSI : tolower, toupper, ...                */
#include    <sys/stat.h>          /* fstat, umask                                */
#include    <unistd.h>       /* stat(),crpyt()                      */
#include    <sys/mount.h>    /* C_ANSI : mount                                */
#include    <pwd.h>               /* getpwuid, getpwnam                       */
#include    <grp.h>               /* getgruid, getgrnam                       */
#include    <fcntl.h>             /* creat, open, fcntl                       */
#include    <sys/sysmacros.h>
#include    <openssl/sha.h>       /* openssl implementation of sha1           */

#include    <yLOG.h>         /* CUSTOM : heatherly program logging            */
#include    "yURG.h"
#include    <yCOLOR_solo.h>
#include    <yDLST_solo.h>


typedef struct stat      tSTAT;
typedef struct passwd    tPASSWD;
typedef struct group     tGROUP;



typedef struct cYURG_priv  tYURG_priv;
struct cYURG_priv {
   /*---(urgents)-----------*/
   char        lower       [LEN_TITLE];
   char        upper       [LEN_TITLE];
   int         curr;
   char        origs       [LEN_RECD];      /* original urgs from yURG_urgs   */
   int         norig;
   char        nows        [LEN_RECD];      /* current state of urgs          */
   int         nnow;
   int         ntry;
   /*---(messages)----------*/
   char        mlive;
   char        mname       [LEN_FULL];
   FILE       *mfile;
   char        mlive_save;
   char        mname_save  [LEN_FULL];
   /*---(errors)------------*/
   char        elive;
   char        ename       [LEN_FULL];
   FILE       *efile;
   char        elive_save;
   char        ename_save  [LEN_FULL];
   /*---(done)--------------*/
};
extern tYURG_priv  myURG_priv;


#define        MAX_URGS        500

typedef   struct  cYURG_TYPE   tYURG_TYPE;
struct cYURG_TYPE
{
   char        type;                        /* matches urgent types           */
   char        sub;                         /* matches urgent sub-types;      */
   char        desc        [LEN_LABEL];     /* description of type            */
};
extern  tYURG_TYPE  yURG_type [MAX_URGS];

typedef   struct  cYURG_INFO   tYURG_INFO;
struct cYURG_INFO
{
   uchar       abbr;                        /* single letter name             */
   char        full        [LEN_LABEL];     /* full name                      */
   char        desc        [LEN_DESC ];     /* explanation                    */
   char        type;                        /* main type                      */
   char        sub;                         /* subtype                        */
   char        base        [LEN_TERSE];     /* name for base                  */
   char        mas         [LEN_TERSE];     /* name for mas                   */
   char       *point;                       /* pointer to normal              */
};
extern const tYURG_INFO  yURG_info [MAX_URGS];


extern char unit_answer [LEN_RECD];


/*345678901-12345678901-12345678901-12345678901-12345678901-12345678901-123456*/

char        yurg_mass               (cchar  a_set , cchar a_extra);
char        yurg__flip              (int i, cchar a_lower, cchar a_on);
char        yurg__multi             (cchar *a_string, cchar a_on);
char        yurg__wild              (cchar *a_string, cchar a_on);

char        yurg_category           (cchar *a_prog, cchar a_type);
char        yurg_urgents            (cchar *a_prog);

char        yurg_stage_clear        (void);
char        yurg_stage_prep         (void);
char*       yurg_stage__unit        (char *a_question, int a_num);

char        yurg_rptg__test_clear   (void);
char*       yurg_rptg__unit         (char *a_question, int a_num);



/*===[[ yURG_test.c ]]========================================================*/
/*········· ´······················ ´·········································*/
char*       yURG__unit              (char *a_question, int a_num);
/*········· ´······················ ´·········································*/





#endif
