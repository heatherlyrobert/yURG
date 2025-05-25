/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YURG_HGUARD
#define YURG_HGUARD loaded



#include <ySTR_solo.h>


#define        YURG_OFF        '-'
#define        YURG_ON         'y'
#define        YURG_MAS        'Y'

#define        YURG_MSG        "/tmp/console.txt"
#define        YURG_BASE       '>'
#define        YURG_LEVEL0     '>'
#define        YURG_LEVEL1     '-'
#define        YURG_LEVEL2     '+'
#define        YURG_ERR        "/tmp/errors.txt"
#define        YURG_FATAL      'F'
#define        YURG_FATAL0     'F'
#define        YURG_FATAL1     'f'
#define        YURG_FATAL2     'ü'
#define        YURG_WARN       'W'
#define        YURG_WARN0      'W'
#define        YURG_WARN1      'w'
#define        YURG_WARN2      'ÿ'
#define        YURG_LASTLINE   999

/*  real fla   vol
 *
 *    ´  p  prog   -   general program startup and shutdown
 *    ´  a  args   -   evaluating args and urgs
 *
 *    ·  ·  file   -   shared inpt/outp opens, closes, error handling, ...
 *    ´  i  inpt   -   data source files/db (non-conf) and database queries
 *    ´  o  outp   -   data output files/db (non-conf) and database insert, ...
 *    ´  c  conf   -   configuration handling, updating, etc
 *    ´  r  rptg   -   reporting, export, and import handling
 *
 *    ´  l  loop   y   main looping, highly repetitive
 *    ´  u  user   -   user input handling
 *    ´  g  graf   y   graphics handling, highly repetitive, specific
 *    ´  e  envi   -   apis, signals, os, shell
 *
 *    ´  s  sort   y   sorting and ordering data structures
 *    ´  f  find   y   searching for matches in major data structures
 *    ´  w  walk   y   walking major data structures for various purposes
 *    ´  t  tabl   y   data table input, update, searching, and output
 *
 *    ´  d  data   y   pure data chewing, reviewing, gathering
 *
 *    ´  ylog   -   yLOG
 *    ´  yurg   -   yURG
 *    ´  yunit  -   yUNIT
 *    ´  yvar   -   yVAR
 *    ´  ystr   -   ySTR
 *
 *    ´  ymode  0   yMODE
 *    ´  ykeys  L   yKEYS
 *    ´  yfile  F   yFILE
 *    ´  yview  V   yVIEW
 *
 *    ´  ymap   M   yMAP
 *    ´  ymark  '   yMARK
 *    ´  ymacro @   yMACRO
 *    ´  ysrc   S   ySRC
 *    ´  ycmd   :   yCMD
 *
 *    ´  ygod   G   yGOD
 *    ´  yviop  Y   yVIOPENGL
 *    ´  yvicu  Y   yVICURSES
 *
 *    ´  ycalc  ý   yCALC
 *    ´  ycolor ò   yCOLOR
 *    ´  ydlst  ë   yDLST
 *    ´  yexec  ì   yEXEC
 *    ´  yfont  ü   yFONT
 *    ´  ygltex ê   yGLTEX
 *    ´  ygolem ó   yGOLEM
 *    ·  yhub   ·   yHUBLIN
 *    ´  yjobs  ö   yJOBS
 *    ´  ykine  ñ   yKINE
 *    ´  yparse ÷   yPARSE
 *    ´  yregex ø   yREGEX
 *    ´  yrpn   ô   yRPN  
 *    ´  ysced  ù   ySCHED
 *    ´  ysec   è   ySEC    (argus)
 *    ´  ysort  ú   ySORT   (troll)
 *    ´  yx11   õ   yX11
 *
 *
 *    0 - 9   custom for a program (not library)
 *
 */

/*---(base)-----------------*/
#define  YURG_ARGS    'a'     /* command line args/urgs                       */
#define  YURG_PROG    'p'     /* one-time startup/shutdown                    */
/*---(input-output)---------*/
#define  YURG_FILE    '+'    /* shared inpt/outp opens, errors, ...           */
#define  YURG_INPT    'i'    /* data source files/db (non-conf)               */
#define  YURG_OUTP    'o'    /* data output files/db (non-conf)               */
#define  YURG_CONF    'c'    /* configuration handling, updating, etc         */
#define  YURG_RPTG    'r'    /* reporting, export, and import handling        */
/*---(volume)---------------*/
#define  YURG_LOOP    'l'    /* main loop processing, highly repetitve        */
#define  YURG_USER    'u'    /* user input handling                           */
#define  YURG_GRAF    'g'    /* graphics handling, highly repetitve           */
#define  YURG_ENVI    'e'    /* directories, signals, apis, shell, o/s        */
/*---(data)-----------------*/
#define  YURG_SORT    's'    /* sorting and ordering data structures          */
#define  YURG_SRCH    'h'    /* searching in major data structures            */
#define  YURG_WALK    'w'    /* walking major data structures                 */
#define  YURG_DATA    'd'    /* pure data chewing, reviewing, gathering       */
#define  YURG_TABLE   't'    /* data table input, update, and output          */
/*---(vi-keys fund)---------*/
#define  YURG_YMODE   'O'
#define  YURG_YKEYS   'K'
#define  YURG_YFILE   'F'
#define  YURG_YVIEW   'V'
/*---(vi-keys extend)-------*/
#define  YURG_YMAP    'P'
#define  YURG_YCMD    'C'
#define  YURG_YMACRO  'B'
#define  YURG_YSRC    'S'
#define  YURG_YMARK   'M'
/*---(vi-keys graph)--------*/
#define  YURG_YGOD    'G'
#define  YURG_YVICU   'Y'
#define  YURG_YVIOP   'Y'
/*---(other libs)-----------*/
#define  YURG_YENV    'ý'
#define  YURG_YCALC   'ý'
#define  YURG_YCOLOR  'ò'
#define  YURG_YDLST   'ë'
#define  YURG_YEXEC   'ì'
#define  YURG_YFONT   'ü'
#define  YURG_YGLTEX  'ê'
#define  YURG_YGOLEM  'û'
#define  YURG_YJOBS   'ö'
#define  YURG_YKINE   'ñ'
#define  YURG_YPARSE  '÷'
#define  YURG_YREGEX  'ø'
#define  YURG_YRPN    'ô'
#define  YURG_YSCHED  'ù'
#define  YURG_YSEC    'è'
#define  YURG_YSORT   'ú'
#define  YURG_YDESK   'õ'    /* x-windows, w-windows, etc.                    */



typedef     unsigned char             uchar;
typedef     unsigned int              uint;
typedef     struct   cURG_DEBUG       tURG_DEBUG;
/*===[[ DEBUGGING SETUP ]]====================================================*/
/* this is my latest standard format, vars, and urgents                       */
/* v3.0b : added signal handling                                (2014-feb-01) */
struct cURG_DEBUG
{
   /*---(handle)-------------------------*/
   int         logger;                 /* log file so that we don't close it  */
   char        use;                    /* (-) normal, (d)ebug, or (u)nit      */
   char        loud;                   /* quiet '-' vs logging 'y'            */
   uchar       curr;
   char        mute;                   /* silent mode                         */
   /*---(overall)------------------------*/  /* abcde_ghi__lmnopqrstuvwxyz    */
   /* f = full urgents turns on all standard urgents                          */
   /* k = kitchen sink and turns everything on, i mean everything on          */
   /* q = quiet turns all urgents off including the log itself                */
   char        view;                   /* v) view direct to stdout            */
   /*---(startup/shutdown)---------------*/
   char        prog;                   /* p) specific program setup/wrapup    */
   char        args;                   /* a) command line args and urgents    */
   /*---(file processing)----------------*/
   char        inpt;                   /* i) text and data file input         */
   char        outp;                   /* o) text and data file output        */
   char        conf;                   /* c) configuration handling           */
   char        rptg;                   /* r) report/dump, analytics, stats    */
   /*---(event handling)-----------------*/
   char        loop;                   /* l) main program event loop          */
   char        user;                   /* u) user input and handling          */
   char        graf;                   /* g) grahpics setup and config        */
   char        envi;                   /* e) environment processing           */
   /*---(program)------------------------*/
   char        sort;                   /* s) data sorting and ordering        */
   char        find;                   /* y) data searching and traversal     */
   char        walk;                   /* y) data searching and traversal     */
   char        tabl;                   /* y) data searching and traversal     */
   char        data;                   /* d) complex data structure handling  */
   /*---(stages)-------------------------*/
   char        stage    [20];          /* stages for active logging           */
   char        cstage;                 /* current stage                       */
   /*---(data input)---------------------*/
   char        touch;                  /* data point -- touch interface       */
   char        raw;                    /* data point -- raw input             */
   char        simple;                 /* data point -- simplification        */
   char        average;                /* data point -- averaging             */
   char        critical;               /* data point -- critical points       */
   char        circle;                 /* data point -- circle marking        */
   char        curve;                  /* data point -- curve marking         */
   char        line;                   /* data point -- line straightening    */
   char        match;                  /* data point -- match processing      */
   char        dict;                   /* dictionary processssing             */
   /*---(hermes)-------------------------*/
   char        dirs;                   /* hermes locations                    */
   char        pkgs;                   /* hermes packages                     */
   char        cmds;                   /* hermes commands                     */
   char        gentoo;                 /* hermes gentoo/portage access        */
   char        cache;                  /* hermes cached database              */
   /*---(helios)-------------------------*/
   char        mass;                   /* grouging of nodes, like disk drive  */
   char        node;                   /* individual nodes                    */
   char        edge;                   /* connections between nodes           */
   char        stats;                  /* collections of statistics           */
   /*---(spreadsheet)--------------------*/
   char        locs;
   char        cell;
   /*---(calculations)-------------------*/
   char        yrpn;
   char        calc;
   char        exec;
   /*---(dependencies)-------------------*/
   char        deps;
   /*---(yVIKEYS)------------------------*/
   char        visu;                   /* yVIKEYS : visual selection          */
   char        ssel;                   /* yVIKEYS : text selection            */
   char        mark;                   /* yVIKEYS : location marks            */
   char        hint;                   /* yVIKEYS : location hinting          */
   char        srch;                   /* yVIKEYS : searching                 */
   char        map;                    /* yVIKEYS : screen mapping            */
   char        mode;                   /* yVIKEYS : mode handling             */
   char        keys;                   /* yVIKEYS : key handling              */
   char        edit;                   /* yVIKEYS : source editing            */
   /*---(vi-keys libraries)--------------*/
   char        yvihub;                 /* yVIHUB vi-keys coordination         */
   char        ymode;                  /* yMODE  vi-keys mode processing      */
   char        ykeys;                  /* yKEYS  vi-keys keyboard handling    */
   char        ymacro;                 /* yMACRO vi-keys script handling      */
   char        yview;                  /* yVIEW  vi-keys layout management    */
   char        ycmd;                   /* yCMD   vi-keys command processor    */
   char        ymark;                  /* yMARK  vi-keys search and marking   */
   char        ysrc;                   /* ySRC   vi-keys content editing      */
   char        ysrc_user;              /* ySRC   vi-keys content editing      */
   char        yfile;                  /* yFILE  vi-keys file management      */
   char        ymap;                   /* yMAP   vi-keys map mode handling    */
   char        ymap_user;              /* yMAP   vi-keys map mode handling    */
   char        ymap_graf;              /* yMAP   vi-keys map mode handling    */
   /*---(registers)----------------------*/
   char        regs;                   /* s_sel  : copy and paste registers   */
   /*---(other)--------------------------*/
   char        adjs;                   /* small, configurable adjustments     */
   char        s;
   char        sylk;
   char        gnome;
   char        dtree;          /* displays the dependency tree and exits      */
   /*---(safe-strings)-------------------*/
   char        ystr;                   /* ySTR string library                 */
   char        yenv;                   /* ySTR system library                 */
   char        ydlst;                  /* yDLST quad-double linked list       */
   char        ysched;                 /* ySCHED kernighan sched grammar      */
   char        yexec;                  /* yEXEC process dispatch and control  */
   char        yjobs;                  /* yJOBS job execution and control     */
   char        ysec;                   /* ySEC system access logging          */
   char        ycalc;                  /* yCALC calculation engine            */
   char        ysort;                  /* ySORT data ordering                 */
   /*---(record parsing)-----------------*/
   char        yparse;                 /* yPARSE parsing to queue libarary    */
   /*---(robotics)-----------------------*/
   char        ygolem;                 /* yGOLEM robotics controller          */
   /*---(regular expressions)------------*/
   char        yregex;                 /* yREGEX library                      */
   /*---(windows)------------------------*/
   char        desk;                   /* desktop/window control              */
   char        yxwin;                  /* x11 control                         */
   /*---(kinematics)---------------------*/
   char        ykine;                  /* yKINE kinematics library -- main    */
   char        ykine_calc;             /* yKINE kinematics library -- sub     */
   char        ykine_tick;             /* yKINE kinematics library -- sub     */
   char        ykine_data;             /* yKINE kinematics library -- sub     */
   char        ykine_scrp;             /* yKINE kinematics library -- sub     */
   char        ykine_move;             /* yKINE kinematics library -- sub     */
   char        ykine_exact;            /* yKINE kinematics library -- sub     */
   /*---(vi-keys)------------------------*/
   char        yvikeys;                     /* yVIKEYS vi-keys library        */
   char        yvikeys_keys;                /* yVIKEYS vi-keys library        */
   char        yvikeys_mode;                /* yVIKEYS vi-keys library        */
   char        yvikeys_scale;               /* yVIKEYS vi-keys library        */
   /*---(fonts)--------------------------*/
   char        yfont;                  /* yFONT texture mapped font library   */
   char        yfont_file;             /* yFONT file creation and access      */
   char        yfont_calc;             /* yFONT layout and vertex calculation */
   char        yfont_map;              /* yFONT texture mapping and access    */
   /*---(textures)-----------------------*/
   char        ygltex;                 /* yFONT opengl texture handling       */
   /*---(colors)-------------------------*/
   char        ycolor;                 /* yFONT opengl color handling         */
   /*---(hyleoroi)-----------------------*/
   char        format;                 /* formatting options                  */
   char        color;                  /* color formatting options            */
   /*---(ascii)--------------------------*/
   char        yascii;                 /* yASCII font and art                 */
   /*---(done)---------------------------*/
};
extern    tURG_DEBUG      myURG;

/*> /+---(silent)-----------------+/                                                                                  <* 
 *> #define     NOT_DEBUG              if (myURG.use                == '-')                                           <* 
 *> #define     DEBUG_ANY              yLOGS_curr (myURG.cstage, '¢');                                                <* 
 *> #define     DEBUG_UNIT             if (myURG.prog    != '-')                                                      <* 
 *> /+---(overall)----------------+/                                                                                  <* 
 *> #define     DEBUG_VIEW             yLOGS_curr (myURG.cstage, 'v');  if (myURG.view    != '-')                     <* 
 *> #define     DEBUG_VIEW_M           yLOGS_curr (myURG.cstage, 'v');  if (myURG.view    == 'Y')                     <* 
 *> /+---(startup/shutdown)-------+/                                                                                  <* 
 *> #define     DEBUG_PROG             yLOGS_curr (myURG.cstage, 'p');  if (myURG.prog    != '-')                     <* 
 *> #define     DEBUG_PROG_M           yLOGS_curr (myURG.cstage, 'p');  if (myURG.prog    == 'Y')                     <* 
 *> #define     DEBUG_ARGS             yLOGS_curr (myURG.cstage, 'a');  if (myURG.args    != '-')                     <* 
 *> #define     DEBUG_ARGS_M           yLOGS_curr (myURG.cstage, 'a');  if (myURG.args    == 'Y')                     <* 
 *> /+---(input/output)-----------+/                                                                                  <* 
 *> #define     DEBUG_FILE             yLOGS_curr (myURG.cstage, 'f');  if (myURG.inpt != '-' || myURG.outp != '-')   <* 
 *> #define     DEBUG_FILE_M           yLOGS_curr (myURG.cstage, 'f');  if (myURG.inpt == 'Y' || myURG.outp == 'Y')   <* 
 *> #define     DEBUG_INPT             yLOGS_curr (myURG.cstage, 'i');  if (myURG.inpt    != '-')                     <* 
 *> #define     DEBUG_INPT_M           yLOGS_curr (myURG.cstage, 'i');  if (myURG.inpt    == 'Y')                     <* 
 *> #define     DEBUG_OUTP             yLOGS_curr (myURG.cstage, 'o');  if (myURG.outp    != '-')                     <* 
 *> #define     DEBUG_OUTP_M           yLOGS_curr (myURG.cstage, 'o');  if (myURG.outp    == 'Y')                     <* 
 *> #define     DEBUG_CONF             yLOGS_curr (myURG.cstage, 'c');  if (myURG.conf    != '-')                     <* 
 *> #define     DEBUG_CONF_M           yLOGS_curr (myURG.cstage, 'c');  if (myURG.conf    == 'Y')                     <* 
 *> #define     DEBUG_RPTG             yLOGS_curr (myURG.cstage, 'r');  if (myURG.rptg    != '-')                     <* 
 *> #define     DEBUG_RPTG_M           yLOGS_curr (myURG.cstage, 'r');  if (myURG.rptg    == 'Y')                     <* 
 *> /+---(event/volume)-----------+/                                                                                  <* 
 *> #define     DEBUG_LOOP             yLOGS_curr (myURG.cstage, 'l');  if (myURG.loop    != '-')                     <* 
 *> #define     DEBUG_LOOP_M           yLOGS_curr (myURG.cstage, 'l');  if (myURG.loop    == 'Y')                     <* 
 *> #define     DEBUG_USER             yLOGS_curr (myURG.cstage, 'u');  if (myURG.user    != '-')                     <* 
 *> #define     DEBUG_USER_M           yLOGS_curr (myURG.cstage, 'u');  if (myURG.user    == 'Y')                     <* 
 *> #define     DEBUG_GRAF             yLOGS_curr (myURG.cstage, 'g');  if (myURG.graf    != '-')                     <* 
 *> #define     DEBUG_GRAF_M           yLOGS_curr (myURG.cstage, 'g');  if (myURG.graf    == 'Y')                     <* 
 *> #define     DEBUG_ENVI             yLOGS_curr (myURG.cstage, 'e');  if (myURG.envi    != '-')                     <* 
 *> #define     DEBUG_ENVI_M           yLOGS_curr (myURG.cstage, 'e');  if (myURG.envi    == 'Y')                     <*/


/*> /+---(program)----------------+/                                                                           <* 
 *> #define     DEBUG_DATA             yLOGS_curr (myURG.cstage, 'd');  if (myURG.data    != '-')              <* 
 *> #define     DEBUG_DATA_M           yLOGS_curr (myURG.cstage, 'd');  if (myURG.data    == 'Y')              <* 
 *> #define     DEBUG_SORT             yLOGS_curr (myURG.cstage, 's');  if (myURG.sort    != '-')              <* 
 *> #define     DEBUG_SORT_M           yLOGS_curr (myURG.cstage, 's');  if (myURG.sort    == 'Y')              <* 
 *> #define     DEBUG_TRAV             yLOGS_curr (myURG.cstage, 'y');  if (myURG.trav    != '-')              <* 
 *> #define     DEBUG_TRAV_M           yLOGS_curr (myURG.cstage, 'y');  if (myURG.trav    == 'Y')              <* 
 *> /+---(gregg)-----------------------------+/                                                                <* 
 *> #define     DEBUG_TOUCH            yLOGS_curr (myURG.cstage, '¢');  if (myURG.touch              != '-')   <* 
 *> #define     DEBUG_TOUCH_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.touch              == 'Y')   <* 
 *> #define     DEBUG_RAW              yLOGS_curr (myURG.cstage, '¢');  if (myURG.raw                != '-')   <* 
 *> #define     DEBUG_RAW_M            yLOGS_curr (myURG.cstage, '¢');  if (myURG.raw                == 'Y')   <* 
 *> #define     DEBUG_SIMP             yLOGS_curr (myURG.cstage, '¢');  if (myURG.simple             != '-')   <* 
 *> #define     DEBUG_SIMP_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.simple             == 'Y')   <* 
 *> #define     DEBUG_AVG              yLOGS_curr (myURG.cstage, '¢');  if (myURG.average            != '-')   <* 
 *> #define     DEBUG_AVG_M            yLOGS_curr (myURG.cstage, '¢');  if (myURG.average            == 'Y')   <* 
 *> #define     DEBUG_CRIT             yLOGS_curr (myURG.cstage, '¢');  if (myURG.critical           != '-')   <* 
 *> #define     DEBUG_CRIT_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.critical           == 'Y')   <* 
 *> #define     DEBUG_CIRC             yLOGS_curr (myURG.cstage, '¢');  if (myURG.circle             != '-')   <* 
 *> #define     DEBUG_CIRC_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.circle             == 'Y')   <* 
 *> #define     DEBUG_CURV             yLOGS_curr (myURG.cstage, '¢');  if (myURG.curve              != '-')   <* 
 *> #define     DEBUG_CURV_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.curve              == 'Y')   <* 
 *> #define     DEBUG_LINE             yLOGS_curr (myURG.cstage, '¢');  if (myURG.line               != '-')   <* 
 *> #define     DEBUG_LINE_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.line               == 'Y')   <* 
 *> #define     DEBUG_MATCH            yLOGS_curr (myURG.cstage, '¢');  if (myURG.match              != '-')   <* 
 *> #define     DEBUG_MATCH_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.match              == 'Y')   <* 
 *> #define     DEBUG_DICT             yLOGS_curr (myURG.cstage, '¢');  if (myURG.dict               != '-')   <* 
 *> #define     DEBUG_DICT_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.dict               == 'Y')   <* 
 *> /+---(stages)----------------------------+/                                                                <* 
 *> #define     YURG_BEG               0                                                                       <* 
 *> #define     YURG_MID               1                                                                       <* 
 *> #define     YURG_END               2                                                                       <* 
 *> #define     YURG_ONE               4                                                                       <* 
 *> #define     YURG_TWO               5                                                                       <* 
 *> #define     YURG_THR               6                                                                       <* 
 *> #define     YURG_FOU               7                                                                       <* 
 *> #define     YURG_FIV               8                                                                       <* 
 *> /+---(hermes)----------------------------+/                                                                <* 
 *> #define     DEBUG_DIRS             yLOGS_curr (myURG.cstage, '¢');  if (myURG.dirs               != '-')   <* 
 *> #define     DEBUG_DIRS_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.dirs               == 'Y')   <* 
 *> #define     DEBUG_PKGS             yLOGS_curr (myURG.cstage, '¢');  if (myURG.pkgs               != '-')   <* 
 *> #define     DEBUG_PKGS_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.pkgs               == 'Y')   <* 
 *> #define     DEBUG_CMDS             yLOGS_curr (myURG.cstage, '¢');  if (myURG.cmds               != '-')   <* 
 *> #define     DEBUG_CMDS_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.cmds               == 'Y')   <* 
 *> #define     DEBUG_GENTOO           yLOGS_curr (myURG.cstage, '¢');  if (myURG.gentoo             != '-')   <* 
 *> #define     DEBUG_GENTOO_M         yLOGS_curr (myURG.cstage, '¢');  if (myURG.gentoo             == 'Y')   <* 
 *> #define     DEBUG_CACHE            yLOGS_curr (myURG.cstage, '¢');  if (myURG.cache              != '-')   <* 
 *> #define     DEBUG_CACHE_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.cache              == 'Y')   <* 
 *> /+---(graph/helios)----------------------+/                                                                <* 
 *> #define     DEBUG_MASS             yLOGS_curr (myURG.cstage, '¢');  if (myURG.mass               != '-')   <* 
 *> #define     DEBUG_MASS_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.mass               == 'Y')   <* 
 *> #define     DEBUG_NODE             yLOGS_curr (myURG.cstage, '¢');  if (myURG.node               != '-')   <* 
 *> #define     DEBUG_NODE_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.node               == 'Y')   <* 
 *> #define     DEBUG_EDGE             yLOGS_curr (myURG.cstage, '¢');  if (myURG.edge               != '-')   <* 
 *> #define     DEBUG_EDGE_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.edge               == 'Y')   <* 
 *> #define     DEBUG_STATS            yLOGS_curr (myURG.cstage, '¢');  if (myURG.stats              != '-')   <* 
 *> #define     DEBUG_STATS_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.stats              == 'Y')   <* 
 *> /+---(dependencies)----------------------+/                                                                <* 
 *> #define     DEBUG_DEPS             yLOGS_curr (myURG.cstage, '¢');  if (myURG.deps               != '-')   <* 
 *> #define     DEBUG_DEPS_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.deps               == 'Y')   <* 
 *> /+---(cells)-----------------------------+/                                                                <* 
 *> #define     DEBUG_LOCS             yLOGS_curr (myURG.cstage, '¢');  if (myURG.locs               != '-')   <* 
 *> #define     DEBUG_LOCS_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.locs               == 'Y')   <* 
 *> #define     DEBUG_CELL             yLOGS_curr (myURG.cstage, '¢');  if (myURG.cell               != '-')   <* 
 *> #define     DEBUG_CELL_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.cell               == 'Y')   <* 
 *> /+---(formulas)--------------------------+/                                                                <* 
 *> #define     DEBUG_YRPN             yLOGS_curr (myURG.cstage, '¢');  if (myURG.yrpn               != '-')   <* 
 *> #define     DEBUG_YRPN_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.yrpn               == 'Y')   <* 
 *> #define     DEBUG_CALC             yLOGS_curr (myURG.cstage, '¢');  if (myURG.calc               != '-')   <* 
 *> #define     DEBUG_CALC_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.calc               == 'Y')   <* 
 *> #define     DEBUG_EXEC             yLOGS_curr (myURG.cstage, '¢');  if (myURG.exec               != '-')   <* 
 *> #define     DEBUG_EXEC_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.exec               == 'Y')   <* 
 *> #define     DEBUG_ADJS             yLOGS_curr (myURG.cstage, '¢');  if (myURG.adjs               != '-')   <* 
 *> #define     DEBUG_ADJS_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.adjs               == 'Y')   <* 
 *> /+---(yVIKEYS)---------------------------+/                                                                <* 
 *> #define     DEBUG_VISU             yLOGS_curr (myURG.cstage, '¢');  if (myURG.visu               != '-')   <* 
 *> #define     DEBUG_VISU_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.visu               == 'Y')   <* 
 *> #define     DEBUG_SSEL             yLOGS_curr (myURG.cstage, '¢');  if (myURG.ssel               != '-')   <* 
 *> #define     DEBUG_SSEL_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ssel               == 'Y')   <* 
 *> #define     DEBUG_MARK             yLOGS_curr (myURG.cstage, '¢');  if (myURG.mark               != '-')   <* 
 *> #define     DEBUG_MARK_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.mark               == 'Y')   <* 
 *> #define     DEBUG_HINT             yLOGS_curr (myURG.cstage, '¢');  if (myURG.hint               != '-')   <* 
 *> #define     DEBUG_HINT_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.hint               == 'Y')   <* 
 *> #define     DEBUG_MAP              yLOGS_curr (myURG.cstage, '¢');  if (myURG.map                != '-')   <* 
 *> #define     DEBUG_MAP_M            yLOGS_curr (myURG.cstage, '¢');  if (myURG.map                == 'Y')   <* 
 *> #define     DEBUG_MODE             yLOGS_curr (myURG.cstage, '¢');  if (myURG.mode               != '-')   <* 
 *> #define     DEBUG_MODE_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.mode               == 'Y')   <* 
 *> #define     DEBUG_KEYS             yLOGS_curr (myURG.cstage, '¢');  if (myURG.keys               != '-')   <* 
 *> #define     DEBUG_KEYS_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.keys               == 'Y')   <* 
 *> #define     DEBUG_EDIT             yLOGS_curr (myURG.cstage, '¢');  if (myURG.edit               != '-')   <* 
 *> #define     DEBUG_EDIT_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.edit               == 'Y')   <* 
 *> /+---(registers)-------------------------+/                                                                <* 
 *> #define     DEBUG_REGS             yLOGS_curr (myURG.cstage, '¢');  if (myURG.regs               != '-')   <* 
 *> #define     DEBUG_REGS_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.regs               == 'Y')   <* 
 *> #define     DEBUG_TREG             yLOGS_curr (myURG.cstage, '¢');  if (myURG.treg               != '-')   <* 
 *> #define     DEBUG_TREG_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.treg               == 'Y')   <* 
 *> /+---(ySTR)------------------------------+/                                                                <* 
 *> #define     DEBUG_YSTR             yLOGS_curr (myURG.cstage, '¢');  if (myURG.ystr               != '-')   <* 
 *> #define     DEBUG_YSTR_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ystr               == 'Y')   <* 
 *> #define     DEBUG_YDLST            yLOGS_curr (myURG.cstage, '¢');  if (myURG.ydlst              != '-')   <* 
 *> #define     DEBUG_YDLST_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.ydlst              == 'Y')   <* 
 *> #define     DEBUG_YSCHED           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ysched             != '-')   <* 
 *> #define     DEBUG_YSCHED_M         yLOGS_curr (myURG.cstage, '¢');  if (myURG.ysched             == 'Y')   <* 
 *> #define     DEBUG_YEXEC            yLOGS_curr (myURG.cstage, '¢');  if (myURG.yexec              != '-')   <* 
 *> #define     DEBUG_YEXEC_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.yexec              == 'Y')   <* 
 *> #define     DEBUG_YCALC            yLOGS_curr (myURG.cstage, '¢');  if (myURG.ycalc              != '-')   <* 
 *> #define     DEBUG_YCALC_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.ycalc              == 'Y')   <* 
 *> #define     DEBUG_YSORT            yLOGS_curr (myURG.cstage, '¢');  if (myURG.ysort              != '-')   <* 
 *> #define     DEBUG_YSORT_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.ysort              == 'Y')   <* 
 *> #define     DEBUG_YJOBS            yLOGS_curr (myURG.cstage, '¢');  if (myURG.yjobs              != '-')   <* 
 *> #define     DEBUG_YJOBS_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.yjobs              == 'Y')   <* 
 *> #define     DEBUG_YSEC             yLOGS_curr (myURG.cstage, '¢');  if (myURG.ysec               != '-')   <* 
 *> #define     DEBUG_YSEC_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ysec               == 'Y')   <* 
 *> /+---(vi-keys libraries)-----------------+/                                                                <* 
 *> #define     DEBUG_YVIHUB           yLOGS_curr (myURG.cstage, '¢');  if (myURG.yvihub             != '-')   <* 
 *> #define     DEBUG_YVIHUB_M         yLOGS_curr (myURG.cstage, '¢');  if (myURG.yvihub             == 'Y')   <* 
 *> #define     DEBUG_YMODE            yLOGS_curr (myURG.cstage, '¢');  if (myURG.ymode              != '-')   <* 
 *> #define     DEBUG_YMODE_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.ymode              == 'Y')   <* 
 *> #define     DEBUG_YKEYS            yLOGS_curr (myURG.cstage, '¢');  if (myURG.ykeys              != '-')   <* 
 *> #define     DEBUG_YKEYS_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.ykeys              == 'Y')   <* 
 *> #define     DEBUG_YMACRO           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ymacro             != '-')   <* 
 *> #define     DEBUG_YMACRO_M         yLOGS_curr (myURG.cstage, '¢');  if (myURG.ymacro             == 'Y')   <* 
 *> #define     DEBUG_YVIEW            yLOGS_curr (myURG.cstage, '¢');  if (myURG.yview              != '-')   <* 
 *> #define     DEBUG_YVIEW_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.yview              == 'Y')   <* 
 *> #define     DEBUG_YCMD             yLOGS_curr (myURG.cstage, '¢');  if (myURG.ycmd               != '-')   <* 
 *> #define     DEBUG_YCMD_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ycmd               == 'Y')   <* 
 *> #define     DEBUG_YMARK            yLOGS_curr (myURG.cstage, '¢');  if (myURG.ymark              != '-')   <* 
 *> #define     DEBUG_YMARK_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.ymark              == 'Y')   <* 
 *> #define     DEBUG_YSRC             yLOGS_curr (myURG.cstage, '¢');  if (myURG.ysrc               != '-')   <* 
 *> #define     DEBUG_YSRC_U           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ysrc_user          != '-')   <* 
 *> #define     DEBUG_YSRC_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ysrc               == 'Y')   <* 
 *> #define     DEBUG_YMAP             yLOGS_curr (myURG.cstage, '¢');  if (myURG.ymap               != '-')   <* 
 *> #define     DEBUG_YMAP_U           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ymap_user          != '-')   <* 
 *> #define     DEBUG_YMAP_G           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ymap_graf          != '-')   <* 
 *> #define     DEBUG_YMAP_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ymap               == 'Y')   <* 
 *> #define     DEBUG_YFILE            yLOGS_curr (myURG.cstage, '¢');  if (myURG.yfile              != '-')   <* 
 *> #define     DEBUG_YFILE_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.yfile              == 'Y')   <* 
 *> /+---(yPARSE)----------------------------+/                                                                <* 
 *> #define     DEBUG_YPARSE           yLOGS_curr (myURG.cstage, '¢');  if (myURG.yparse             == 'y')   <* 
 *> /+---(yGOLEM)----------------------------+/                                                                <* 
 *> #define     DEBUG_YGOLEM           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ygolem             == 'y')   <* 
 *> /+---(yREGEX)----------------------------+/                                                                <* 
 *> #define     DEBUG_YREGEX           yLOGS_curr (myURG.cstage, '¢');  if (myURG.yregex             != '-')   <* 
 *> #define     DEBUG_YREGEX_M         yLOGS_curr (myURG.cstage, '¢');  if (myURG.yregex             == 'Y')   <* 
 *> /+---(windows)---------------------------+/                                                                <* 
 *> #define     DEBUG_DESK             yLOGS_curr (myURG.cstage, '¢');  if (myURG.desk               != '-')   <* 
 *> #define     DEBUG_DESK_M           yLOGS_curr (myURG.cstage, '¢');  if (myURG.desk               != 'Y')   <* 
 *> #define     DEBUG_YXWIN            yLOGS_curr (myURG.cstage, '¢');  if (myURG.yxwin              != '-')   <* 
 *> #define     DEBUG_YXWIN_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.yxwin              != 'Y')   <* 
 *> /+---(kinematics)------------------------+/                                                                <* 
 *> #define     DEBUG_YKINE            yLOGS_curr (myURG.cstage, '¢');  if (myURG.ykine              != '-')   <* 
 *> #define     DEBUG_YKINE_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.ykine              == 'Y')   <* 
 *> #define     DEBUG_YKINE_CALC       yLOGS_curr (myURG.cstage, '¢');  if (myURG.ykine_calc         != '-')   <* 
 *> #define     DEBUG_YKINE_TICK       yLOGS_curr (myURG.cstage, '¢');  if (myURG.ykine_tick         != '-')   <* 
 *> #define     DEBUG_YKINE_MOVE       yLOGS_curr (myURG.cstage, '¢');  if (myURG.ykine_move         != '-')   <* 
 *> #define     DEBUG_YKINE_DATA       yLOGS_curr (myURG.cstage, '¢');  if (myURG.ykine_data         != '-')   <* 
 *> #define     DEBUG_YKINE_SCRP       yLOGS_curr (myURG.cstage, '¢');  if (myURG.ykine_scrp         != '-')   <* 
 *> #define     DEBUG_YKINE_EXACT      yLOGS_curr (myURG.cstage, '¢');  if (myURG.ykine_exact        != '-')   <* 
 *> /+---(vi-keys)---------------------------+/                                                                <* 
 *> #define     DEBUG_YVIKEYS          yLOGS_curr (myURG.cstage, '¢');  if (myURG.yvikeys            == 'y')   <* 
 *> #define     DEBUG_YVIKEYS_KEYS     yLOGS_curr (myURG.cstage, '¢');  if (myURG.yvikeys_keys       != '-')   <* 
 *> #define     DEBUG_YVIKEYS_KEYS_M   yLOGS_curr (myURG.cstage, '¢');  if (myURG.yvikeys_keys       == 'Y')   <* 
 *> #define     DEBUG_YVIKEYS_MODE     yLOGS_curr (myURG.cstage, '¢');  if (myURG.yvikeys_mode       != '-')   <* 
 *> #define     DEBUG_YVIKEYS_MODE_M   yLOGS_curr (myURG.cstage, '¢');  if (myURG.yvikeys_mode       == 'Y')   <* 
 *> #define     DEBUG_YVIKEYS_SCALE    yLOGS_curr (myURG.cstage, '¢');  if (myURG.yvikeys_scale      != '-')   <* 
 *> #define     DEBUG_YVIKEYS_SCALE_M  yLOGS_curr (myURG.cstage, '¢');  if (myURG.yvikeys_scale      == 'Y')   <* 
 *> /+---(yFONT)-----------------------------+/                                                                <* 
 *> #define     DEBUG_YFONT            yLOGS_curr (myURG.cstage, '¢');  if (myURG.yfont              != '-')   <* 
 *> #define     DEBUG_YFONT_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.yfont              == 'Y')   <* 
 *> #define     DEBUG_YFONT_FILE       yLOGS_curr (myURG.cstage, '¢');  if (myURG.yfont_file         == 'y')   <* 
 *> #define     DEBUG_YFONT_CALC       yLOGS_curr (myURG.cstage, '¢');  if (myURG.yfont_calc         == 'y')   <* 
 *> #define     DEBUG_YFONT_MAP        yLOGS_curr (myURG.cstage, '¢');  if (myURG.yfont_map          == 'y')   <* 
 *> /+---(yGLTEX)----------------------------+/                                                                <* 
 *> #define     DEBUG_YGLTEX           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ygltex             != '-')   <* 
 *> #define     DEBUG_YGLTEX_M         yLOGS_curr (myURG.cstage, '¢');  if (myURG.ygltex             == 'Y')   <* 
 *> /+---(yCOLOR)----------------------------+/                                                                <* 
 *> #define     DEBUG_YCOLOR           yLOGS_curr (myURG.cstage, '¢');  if (myURG.ycolor             != '-')   <* 
 *> #define     DEBUG_YCOLOR_M         yLOGS_curr (myURG.cstage, '¢');  if (myURG.ycolor             == 'Y')   <* 
 *> /+---(hyleoroi)--------------------------+/                                                                <* 
 *> #define     DEBUG_FORMAT           yLOGS_curr (myURG.cstage, '¢');  if (myURG.format             != '-')   <* 
 *> #define     DEBUG_FORMAT_M         yLOGS_curr (myURG.cstage, '¢');  if (myURG.format             == 'Y')   <* 
 *> #define     DEBUG_COLOR            yLOGS_curr (myURG.cstage, '¢');  if (myURG.color              != '-')   <* 
 *> #define     DEBUG_COLOR_M          yLOGS_curr (myURG.cstage, '¢');  if (myURG.color              == 'Y')   <* 
 *> /+---(yascii)----------------------------+/                                                                <* 
 *> #define     DEBUG_YASCII           yLOGS_curr (myURG.cstage, '¢');  if (myURG.yascii             != '-')   <*/


/*---(silent)-----------------*/
#define     NOT_DEBUG              if (myURG.use     == '-')
#define     DEBUG_ANY              yLOGS_curr (myURG.cstage, '¢');
#define     DEBUG_UNIT             if (myURG.prog    != '-')
/*---(overall)----------------*/
#define     DEBUG_VIEW             if (yURG_check ('v' , '-', &(myURG.view),        NULL))
#define     DEBUG_VIEW_M           if (yURG_check ('v' , 'Y', &(myURG.view),        NULL))
/*---(startup/shutdown)-------*/
#define     DEBUG_PROG             if (yURG_check ('p' , '-', &(myURG.prog),        NULL))
#define     DEBUG_PROG_M           if (yURG_check ('p' , 'Y', &(myURG.prog),        NULL))
#define     DEBUG_ARGS             if (yURG_check ('a' , '-', &(myURG.args),        NULL))
#define     DEBUG_ARGS_M           if (yURG_check ('a' , 'Y', &(myURG.args),        NULL))
/*---(input/output)-----------*/
#define     DEBUG_FILE             if (yURG_check ('f' , '-', &(myURG.inpt), &(myURG.outp)))
#define     DEBUG_FILE_M           if (yURG_check ('f' , 'Y', &(myURG.inpt), &(myURG.outp)))
#define     DEBUG_INPT             if (yURG_check ('i' , '-', &(myURG.inpt),        NULL))
#define     DEBUG_INPT_M           if (yURG_check ('i' , 'Y', &(myURG.inpt),        NULL))
#define     DEBUG_OUTP             if (yURG_check ('o' , '-', &(myURG.outp),        NULL))
#define     DEBUG_OUTP_M           if (yURG_check ('o' , 'Y', &(myURG.outp),        NULL))
#define     DEBUG_CONF             if (yURG_check ('c' , '-', &(myURG.conf),        NULL))
#define     DEBUG_CONF_M           if (yURG_check ('c' , 'Y', &(myURG.conf),        NULL))
#define     DEBUG_RPTG             if (yURG_check ('r' , '-', &(myURG.rptg),        NULL))
#define     DEBUG_RPTG_M           if (yURG_check ('r' , 'Y', &(myURG.rptg),        NULL))
/*---(event/volume)-----------*/
#define     DEBUG_LOOP             if (yURG_check ('l' , '-', &(myURG.loop),        NULL))
#define     DEBUG_LOOP_M           if (yURG_check ('l' , 'Y', &(myURG.loop),        NULL))
#define     DEBUG_USER             if (yURG_check ('u' , '-', &(myURG.user),        NULL))
#define     DEBUG_USER_M           if (yURG_check ('u' , 'Y', &(myURG.user),        NULL))
#define     DEBUG_GRAF             if (yURG_check ('g' , '-', &(myURG.graf),        NULL))
#define     DEBUG_GRAF_M           if (yURG_check ('g' , 'Y', &(myURG.graf),        NULL))
#define     DEBUG_ENVI             if (yURG_check ('e' , '-', &(myURG.envi),        NULL))
#define     DEBUG_ENVI_M           if (yURG_check ('e' , 'Y', &(myURG.envi),        NULL))
/*---(program)----------------*/
#define     DEBUG_DATA             if (yURG_check ('d' , '-', &(myURG.data),        NULL))
#define     DEBUG_DATA_M           if (yURG_check ('d' , 'Y', &(myURG.data),        NULL))
#define     DEBUG_SORT             if (yURG_check ('s' , '-', &(myURG.sort),        NULL))
#define     DEBUG_SORT_M           if (yURG_check ('s' , 'Y', &(myURG.sort),        NULL))
#define     DEBUG_TRAV             if (yURG_check ('y' , '-', &(myURG.trav),        NULL))
#define     DEBUG_TRAV_M           if (yURG_check ('y' , 'Y', &(myURG.trav),        NULL))


/*---(gregg)-----------------------------*/
#define     DEBUG_TOUCH            if (yURG_check ('¢' , '-', &(myURG.touch),       NULL))
#define     DEBUG_TOUCH_M          if (yURG_check ('¢' , 'Y', &(myURG.touch),       NULL))
#define     DEBUG_RAW              if (yURG_check ('¢' , '-', &(myURG.raw),         NULL))
#define     DEBUG_RAW_M            if (yURG_check ('¢' , 'Y', &(myURG.raw),         NULL))
#define     DEBUG_SIMP             if (yURG_check ('¢' , '-', &(myURG.simple),      NULL))
#define     DEBUG_SIMP_M           if (yURG_check ('¢' , 'Y', &(myURG.simple),      NULL))
#define     DEBUG_AVG              if (yURG_check ('¢' , '-', &(myURG.average),     NULL))
#define     DEBUG_AVG_M            if (yURG_check ('¢' , 'Y', &(myURG.average),     NULL))
#define     DEBUG_CRIT             if (yURG_check ('¢' , '-', &(myURG.critical),    NULL))
#define     DEBUG_CRIT_M           if (yURG_check ('¢' , 'Y', &(myURG.critical),    NULL))
#define     DEBUG_CIRC             if (yURG_check ('¢' , '-', &(myURG.circle),      NULL))
#define     DEBUG_CIRC_M           if (yURG_check ('¢' , 'Y', &(myURG.circle),      NULL))
#define     DEBUG_CURV             if (yURG_check ('¢' , '-', &(myURG.curve),       NULL))
#define     DEBUG_CURV_M           if (yURG_check ('¢' , 'Y', &(myURG.curve),       NULL))
#define     DEBUG_LINE             if (yURG_check ('¢' , '-', &(myURG.line),        NULL))
#define     DEBUG_LINE_M           if (yURG_check ('¢' , 'Y', &(myURG.line),        NULL))
#define     DEBUG_MATCH            if (yURG_check ('¢' , '-', &(myURG.match),       NULL))
#define     DEBUG_MATCH_M          if (yURG_check ('¢' , 'Y', &(myURG.match),       NULL))
#define     DEBUG_DICT             if (yURG_check ('¢' , '-', &(myURG.dict),        NULL))
#define     DEBUG_DICT_M           if (yURG_check ('¢' , 'Y', &(myURG.dict),        NULL))
/*---(stages)----------------------------*/
#define     YURG_BEG               0
#define     YURG_MID               1
#define     YURG_END               2
#define     YURG_ONE               4
#define     YURG_TWO               5
#define     YURG_THR               6
#define     YURG_FOU               7
#define     YURG_FIV               8  
/*---(hermes)----------------------------*/
#define     DEBUG_DIRS             if (yURG_check ('¢' , '-', &(myURG.dirs),        NULL))
#define     DEBUG_DIRS_M           if (yURG_check ('¢' , 'Y', &(myURG.dirs),        NULL))
#define     DEBUG_PKGS             if (yURG_check ('¢' , '-', &(myURG.pkgs),        NULL))
#define     DEBUG_PKGS_M           if (yURG_check ('¢' , 'Y', &(myURG.pkgs),        NULL))
#define     DEBUG_CMDS             if (yURG_check ('¢' , '-', &(myURG.cmds),        NULL))
#define     DEBUG_CMDS_M           if (yURG_check ('¢' , 'Y', &(myURG.cmds),        NULL))
#define     DEBUG_GENTOO           if (yURG_check ('¢' , '-', &(myURG.gentoo),        NULL))
#define     DEBUG_GENTOO_M         if (yURG_check ('¢' , 'Y', &(myURG.gentoo),        NULL))
#define     DEBUG_CACHE            if (yURG_check ('¢' , '-', &(myURG.cache),        NULL))
#define     DEBUG_CACHE_M          if (yURG_check ('¢' , 'Y', &(myURG.cache),        NULL))
/*---(graph/helios)----------------------*/
#define     DEBUG_MASS             if (yURG_check ('¢' , '-', &(myURG.mass),        NULL))
#define     DEBUG_MASS_M           if (yURG_check ('¢' , 'Y', &(myURG.mass),        NULL))
#define     DEBUG_NODE             if (yURG_check ('¢' , '-', &(myURG.node),        NULL))
#define     DEBUG_NODE_M           if (yURG_check ('¢' , 'Y', &(myURG.node),        NULL))
#define     DEBUG_EDGE             if (yURG_check ('¢' , '-', &(myURG.edge),        NULL))
#define     DEBUG_EDGE_M           if (yURG_check ('¢' , 'Y', &(myURG.edge),        NULL))
#define     DEBUG_STATS            if (yURG_check ('¢' , '-', &(myURG.stats),        NULL))
#define     DEBUG_STATS_M          if (yURG_check ('¢' , 'Y', &(myURG.stats),        NULL))
/*---(dependencies)----------------------*/
#define     DEBUG_DEPS             if (yURG_check ('¢' , '-', &(myURG.deps),        NULL))
#define     DEBUG_DEPS_M           if (yURG_check ('¢' , 'Y', &(myURG.deps),        NULL))
/*---(cells)-----------------------------*/
#define     DEBUG_LOCS             if (yURG_check ('¢' , '-', &(myURG.locs),        NULL))
#define     DEBUG_LOCS_M           if (yURG_check ('¢' , 'Y', &(myURG.locs),        NULL))
#define     DEBUG_CELL             if (yURG_check ('¢' , '-', &(myURG.cell),        NULL))
#define     DEBUG_CELL_M           if (yURG_check ('¢' , 'Y', &(myURG.cell),        NULL))
/*---(formulas)--------------------------*/
#define     DEBUG_CALC             if (yURG_check ('¢' , '-', &(myURG.calc),        NULL))
#define     DEBUG_CALC_M           if (yURG_check ('¢' , 'Y', &(myURG.calc),        NULL))
#define     DEBUG_EXEC             if (yURG_check ('¢' , '-', &(myURG.exec),        NULL))
#define     DEBUG_EXEC_M           if (yURG_check ('¢' , 'Y', &(myURG.exec),        NULL))
#define     DEBUG_ADJS             if (yURG_check ('¢' , '-', &(myURG.adjs),        NULL))
#define     DEBUG_ADJS_M           if (yURG_check ('¢' , 'Y', &(myURG.adjs),        NULL))
/*---(yVIKEYS)---------------------------*/
#define     DEBUG_VISU             if (yURG_check ('¢' , '-', &(myURG.visu),        NULL))
#define     DEBUG_VISU_M           if (yURG_check ('¢' , 'Y', &(myURG.visu),        NULL))
#define     DEBUG_SSEL             if (yURG_check ('¢' , '-', &(myURG.ssel),        NULL))
#define     DEBUG_SSEL_M           if (yURG_check ('¢' , 'Y', &(myURG.ssel),        NULL))
#define     DEBUG_MARK             if (yURG_check ('¢' , '-', &(myURG.mark),        NULL))
#define     DEBUG_MARK_M           if (yURG_check ('¢' , 'Y', &(myURG.mark),        NULL))
#define     DEBUG_HINT             if (yURG_check ('¢' , '-', &(myURG.hint),        NULL))
#define     DEBUG_HINT_M           if (yURG_check ('¢' , 'Y', &(myURG.hint),        NULL))
#define     DEBUG_MAP              if (yURG_check ('¢' , '-', &(myURG.map),        NULL))
#define     DEBUG_MAP_M            if (yURG_check ('¢' , 'Y', &(myURG.map),        NULL))
#define     DEBUG_MODE             if (yURG_check ('¢' , '-', &(myURG.mode),        NULL))
#define     DEBUG_MODE_M           if (yURG_check ('¢' , 'Y', &(myURG.mode),        NULL))
#define     DEBUG_KEYS             if (yURG_check ('¢' , '-', &(myURG.keys),        NULL))
#define     DEBUG_KEYS_M           if (yURG_check ('¢' , 'Y', &(myURG.keys),        NULL))
#define     DEBUG_EDIT             if (yURG_check ('¢' , '-', &(myURG.edit),        NULL))
#define     DEBUG_EDIT_M           if (yURG_check ('¢' , 'Y', &(myURG.edit),        NULL))
/*---(registers)-------------------------*/
#define     DEBUG_REGS             if (yURG_check ('¢' , '-', &(myURG.regs),        NULL))
#define     DEBUG_REGS_M           if (yURG_check ('¢' , 'Y', &(myURG.regs),        NULL))
#define     DEBUG_TREG             if (yURG_check ('¢' , '-', &(myURG.treg),        NULL))
#define     DEBUG_TREG_M           if (yURG_check ('¢' , 'Y', &(myURG.treg),        NULL))
/*---(ySTR)------------------------------*/
#define     DEBUG_YSTR             if (yURG_check ('¢' , '-', &(myURG.ystr),        NULL))
#define     DEBUG_YSTR_M           if (yURG_check ('¢' , 'Y', &(myURG.ystr),        NULL))
#define     DEBUG_YENV             if (yURG_check ('¢' , '-', &(myURG.yenv),        NULL))
#define     DEBUG_YENV_M           if (yURG_check ('¢' , 'Y', &(myURG.yenv),        NULL))
#define     DEBUG_YDLST            if (yURG_check ('ë' , '-', &(myURG.ydlst),       NULL))
#define     DEBUG_YDLST_M          if (yURG_check ('ë' , 'Y', &(myURG.ydlst),       NULL))
#define     DEBUG_YSCHED           if (yURG_check ('¢' , '-', &(myURG.ysched),      NULL))
#define     DEBUG_YSCHED_M         if (yURG_check ('¢' , 'Y', &(myURG.ysched),      NULL))
#define     DEBUG_YEXEC            if (yURG_check ('ì' , '-', &(myURG.yexec),       NULL))
#define     DEBUG_YEXEC_M          if (yURG_check ('ì' , 'Y', &(myURG.yexec),       NULL))
#define     DEBUG_YRPN             if (yURG_check ('ô' , '-', &(myURG.yrpn),        NULL))
#define     DEBUG_YRPN_M           if (yURG_check ('ô' , 'Y', &(myURG.yrpn),        NULL))
#define     DEBUG_YCALC            if (yURG_check ('ý' , '-', &(myURG.ycalc),       NULL))
#define     DEBUG_YCALC_M          if (yURG_check ('ý' , 'Y', &(myURG.ycalc),       NULL))
#define     DEBUG_YSORT            if (yURG_check ('ú' , '-', &(myURG.ysort),       NULL))
#define     DEBUG_YSORT_M          if (yURG_check ('ú' , 'Y', &(myURG.ysort),       NULL))
#define     DEBUG_YJOBS            if (yURG_check ('ö' , '-', &(myURG.yjobs),       NULL))
#define     DEBUG_YJOBS_M          if (yURG_check ('ö' , 'Y', &(myURG.yjobs),       NULL))
#define     DEBUG_YSEC             if (yURG_check ('è' , '-', &(myURG.ysec),        NULL))
#define     DEBUG_YSEC_M           if (yURG_check ('è' , 'Y', &(myURG.ysec),        NULL))
/*---(core vikeys)-----------------------*/
#define     DEBUG_YVIHUB           if (yURG_check ('¢' , '-', &(myURG.yvihub),      NULL))
#define     DEBUG_YVIHUB_M         if (yURG_check ('¢' , 'Y', &(myURG.yvihub),      NULL))
/*---(foundational vikeys)---------------*/
#define     DEBUG_YMODE            if (yURG_check ('0' , '-', &(myURG.ymode),       NULL))
#define     DEBUG_YMODE_M          if (yURG_check ('0' , 'Y', &(myURG.ymode),       NULL))
#define     DEBUG_YKEYS            if (yURG_check ('L' , '-', &(myURG.ykeys),       NULL))
#define     DEBUG_YKEYS_M          if (yURG_check ('L' , 'Y', &(myURG.ykeys),       NULL))
#define     DEBUG_YFILE            if (yURG_check ('F' , '-', &(myURG.yfile),       NULL))
#define     DEBUG_YFILE_M          if (yURG_check ('F' , 'Y', &(myURG.yfile),       NULL))
#define     DEBUG_YVIEW            if (yURG_check ('V' , '-', &(myURG.yview),       NULL))
#define     DEBUG_YVIEW_M          if (yURG_check ('V' , 'Y', &(myURG.yview),       NULL))
/*---(foundational vikeys)---------------*/
#define     DEBUG_YMAP             if (yURG_check ('M' , '-', &(myURG.ymap),        NULL))
#define     DEBUG_YMAP_M           if (yURG_check ('¢' , 'Y', &(myURG.ymap),        NULL))
#define     DEBUG_YMAP_U           if (yURG_check ('M' , '-', &(myURG.ymap_user),   NULL))
#define     DEBUG_YMAP_G           if (yURG_check ('M' , '-', &(myURG.ymap_graf),   NULL))
#define     DEBUG_YMARK            if (yURG_check ('/' , '-', &(myURG.ymark),       NULL))
#define     DEBUG_YMARK_M          if (yURG_check ('/' , 'Y', &(myURG.ymark),       NULL))
#define     DEBUG_YMACRO           if (yURG_check ('@' , '-', &(myURG.ymacro),      NULL))
#define     DEBUG_YMACRO_M         if (yURG_check ('@' , 'Y', &(myURG.ymacro),      NULL))
#define     DEBUG_YSRC             if (yURG_check ('S' , '-', &(myURG.ysrc),        NULL))
#define     DEBUG_YSRC_U           if (yURG_check ('S' , '-', &(myURG.ysrc_user),   NULL))
#define     DEBUG_YSRC_M           if (yURG_check ('S' , 'Y', &(myURG.ysrc),        NULL))
#define     DEBUG_YCMD             if (yURG_check (':' , '-', &(myURG.ycmd),        NULL))
#define     DEBUG_YCMD_M           if (yURG_check (':' , 'Y', &(myURG.ycmd),        NULL))
/*---(yPARSE)----------------------------*/
#define     DEBUG_YPARSE           if (yURG_check ('÷' , 'y', &(myURG.yparse),      NULL))
/*---(yGOLEM)----------------------------*/
#define     DEBUG_YGOLEM           if (yURG_check ('¢' , 'y', &(myURG.ygolem),      NULL))
/*---(yREGEX)----------------------------*/
#define     DEBUG_YREGEX           if (yURG_check ('ø' , '-', &(myURG.yregex),      NULL))
#define     DEBUG_YREGEX_M         if (yURG_check ('ø' , 'Y', &(myURG.yregex),      NULL))
/*---(windows)---------------------------*/
#define     DEBUG_DESK             if (yURG_check ('õ' , '-', &(myURG.desk),        NULL))
#define     DEBUG_DESK_M           if (yURG_check ('õ' , 'Y', &(myURG.desk),        NULL))
#define     DEBUG_YXWIN            if (yURG_check ('õ' , '-', &(myURG.yxwin),       NULL))
#define     DEBUG_YXWIN_M          if (yURG_check ('õ' , 'Y', &(myURG.yxwin),       NULL))
/*---(kinematics)------------------------*/
#define     DEBUG_YKINE            if (yURG_check ('ñ' , '-', &(myURG.ykine),       NULL))
#define     DEBUG_YKINE_M          if (yURG_check ('ñ' , 'Y', &(myURG.ykine),       NULL))
#define     DEBUG_YKINE_CALC       if (yURG_check ('ñ' , '-', &(myURG.ykine_calc),  NULL))
#define     DEBUG_YKINE_TICK       if (yURG_check ('ñ' , '-', &(myURG.ykine_tick),  NULL))
#define     DEBUG_YKINE_MOVE       if (yURG_check ('ñ' , '-', &(myURG.ykine_move),  NULL))
#define     DEBUG_YKINE_DATA       if (yURG_check ('ñ' , '-', &(myURG.ykine_data),  NULL))
#define     DEBUG_YKINE_SCRP       if (yURG_check ('ñ' , '-', &(myURG.ykine_scrp),  NULL))
#define     DEBUG_YKINE_EXACT      if (yURG_check ('ñ' , '-', &(myURG.ykine_exact), NULL))
/*---(vi-keys)---------------------------*/
#define     DEBUG_YVIKEYS          if (yURG_check ('¢' , 'y', &(myURG.yvikeys),     NULL))
#define     DEBUG_YVIKEYS_KEYS     if (yURG_check ('¢' , '-', &(myURG.yvikeys_keys),NULL))
#define     DEBUG_YVIKEYS_KEYS_M   if (yURG_check ('¢' , 'Y', &(myURG.yvikeys_keys),NULL))
#define     DEBUG_YVIKEYS_MODE     if (yURG_check ('¢' , '-', &(myURG.yvikeys_mode),NULL))
#define     DEBUG_YVIKEYS_MODE_M   if (yURG_check ('¢' , 'Y', &(myURG.yvikeys_mode),  NULL))
#define     DEBUG_YVIKEYS_SCALE    if (yURG_check ('¢' , '-', &(myURG.yvikeys_scale), NULL))
#define     DEBUG_YVIKEYS_SCALE_M  if (yURG_check ('¢' , 'Y', &(myURG.yvikeys_scale), NULL))
/*---(yFONT)-----------------------------*/
#define     DEBUG_YFONT            if (yURG_check ('ü' , '-', &(myURG.yfont),       NULL))
#define     DEBUG_YFONT_M          if (yURG_check ('ü' , 'Y', &(myURG.yfont),       NULL))
#define     DEBUG_YFONT_FILE       if (yURG_check ('ü' , 'y', &(myURG.yfont_file),  NULL))
#define     DEBUG_YFONT_CALC       if (yURG_check ('ü' , 'y', &(myURG.yfont_calc),  NULL))
#define     DEBUG_YFONT_MAP        if (yURG_check ('ü' , 'y', &(myURG.yfont_map),   NULL))
/*---(yGLTEX)----------------------------*/
#define     DEBUG_YGLTEX           if (yURG_check ('ê' , '-', &(myURG.ygltex),      NULL))
#define     DEBUG_YGLTEX_M         if (yURG_check ('ê' , 'Y', &(myURG.ygltex),      NULL))
/*---(yCOLOR)----------------------------*/
#define     DEBUG_YCOLOR           if (yURG_check ('ò' , '-', &(myURG.ycolor),      NULL))
#define     DEBUG_YCOLOR_M         if (yURG_check ('ò' , 'Y', &(myURG.ycolor),      NULL))
/*---(hyleoroi)--------------------------*/
#define     DEBUG_FORMAT           if (yURG_check ('¢' , '-', &(myURG.format),      NULL))
#define     DEBUG_FORMAT_M         if (yURG_check ('¢' , 'Y', &(myURG.format),      NULL))
#define     DEBUG_COLOR            if (yURG_check ('¢' , '-', &(myURG.color),       NULL))
#define     DEBUG_COLOR_M          if (yURG_check ('¢' , 'Y', &(myURG.color),       NULL))
/*---(yascii)----------------------------*/
#define     DEBUG_YASCII           if (yURG_check ('¢' , '-', &(myURG.yascii),      NULL))


typedef     const char         cchar;



/*===[[ yURG_test.c ]]========================================================*/
/*········· ´······················ ´·········································*/
char*       yURG_version            (void);
char        yURG_debugmode          (void);
char*       yURG_mute_status        (void);
/*---(done)-----------------*/



/*===[[ yURG_log.c ]]=========================================================*/
/*········· ´······················ ´·········································*/
/*---(driver)---------------*/
char        yURG_logger             (int    a_argc, char *a_argv[]);
/*---(done)-----------------*/



/*===[[ yURG_urg.c ]]=========================================================*/
/*········· ´······················ ´·········································*/
/*---(recast)---------------*/
char        yURG_orig               (char *a_orig);
char        yURG_curr               (char *a_curr);
/*---(lookup)---------------*/
char        yURG_by_debug           (cchar *a_name, char *r_abbr);
char        yURG_by_abbr            (cchar  a_abbr, cchar a_on);
char        yURG_by_name            (cchar *a_name, cchar a_on);
char        yURG_name               (cchar *a_name, cchar a_on); /* DEPRICATED */
/*---(driver)---------------*/
char        yURG_urgs               (int    a_argc, char *a_argv[]);
char        yURG_lognum             (void);
char        yURG_check              (uchar a_urg, uchar a_mas, char *a_flag, char *a_alt);
/*---(done)-----------------*/




/*===[[ yURG_rptg.c ]]========================================================*/
/*········· ´······················ ´·········································*/
char        yURG_summ               (void);
char        yURG_list               (void);
/*---(done)-----------------*/



/*===[[ yURG_stage.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
char        yURG_stage_check        (char a_stage);
/*---(done)-----------------*/



/*===[[ yURG_msg.c ]]=========================================================*/
/*········· ´······················ ´·········································*/
/*---(file)-----------------*/
char        yurg_msg__open          (char a_type, char a_append, char a_name [LEN_FULL], char **f, char r_save [LEN_FULL]);
char        yurg_msg_open           (char a_name [LEN_FULL]);
char        yurg_msg__close         (char a_type, char **f, char r_save [LEN_FULL]);
char        yurg_msg_close          (void);
/*---(destination)----------*/
char        yurg_msg__dest          (char a_name [LEN_FULL]);
char        yURG_msg_std            (void);
char        yURG_msg_tmp            (void);
char        yURG_msg_none           (void);
char        yURG_msg_custom         (char a_name [LEN_FULL]);
char        yURG_msg_atmp           (void);
/*---(live)-----------------*/
char        yURG_msg_live           (void);
char        yURG_msg_mute           (void);
/*---(driver)---------------*/
char        yURG_msg                (cchar a_type, cchar *a_format, ...);
/*---(history)--------------*/
char*       yURG_msg_last           (void);
char        yURG_msg_clear          (void);
char        yURG_msg_purge          (void);
/*---(unittest)-------------*/
char*       yurg_msg__unit          (char *a_question, int a_num);
/*---(done)-----------------*/



/*===[[ yURG_err.c ]]=========================================================*/
/*········· ´······················ ´·········································*/
/*---(file)-----------------*/
char        yurg_err_open           (char a_name [LEN_FULL]);
char        yurg_err_close          (void);
/*---(destination)----------*/
char        yurg_err__dest          (char a_name [LEN_FULL]);
char        yURG_err_std            (void);
char        yURG_err_tmp            (void);
char        yURG_err_none           (void);
char        yURG_err_custom         (char a_name [LEN_FULL]);
/*---(live)-----------------*/
char        yURG_err_live           (void);
char        yURG_err_mute           (void);
/*---(driver)---------------*/
char        yURG_err                (cchar a_type, cchar *a_format, ...);
/*---(history)--------------*/
char*       yURG_err_last           (void);
char        yURG_err_clear          (void);
char        yURG_err_purge          (void);
/*---(unittest)-------------*/
char*       yurg_err__unit          (char *a_question, int a_num);
/*---(done)-----------------*/



/*===[[ yURG_all.c ]]=========================================================*/
/*········· ´······················ ´·········································*/
/*---(all-versions)---------*/
char        yURG_all_clear          (void);
char        yURG_all_tmp            (void);
char        yURG_all_none           (void);
char        yURG_all_mute           (void);
char        yURG_all_off            (void);
char        yURG_all_live           (void);
char        yURG_all_tmplive        (void);
char        yURG_all_push           (void);
char        yURG_all_pop            (void);
/*---(done)-----------------*/



#endif
/*===[[ END ]]================================================================*/
