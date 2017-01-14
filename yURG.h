/*===[[ START HDOC ]]=========================================================*/


/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YURG_HGUARD
#define YURG_HGUARD loaded


/* rapidly evolving version number to aid with visual change confirmation     */
#define YURG_VER_NUM   "0.2c"
#define YURG_VER_TXT   "added yURG_abbr logic to set normal when setting mas"



#define        LEN_LABEL        20
#define        LEN_DESC         80
#define        LEN_STR         200
#define        MAX_URGS        500


typedef     struct   cDEBUG       tDEBUG;

/*===[[ DEBUGGING SETUP ]]====================================================*/
/* this is my latest standard format, vars, and urgents                       */
/* v3.0b : added signal handling                                (2014-feb-01) */
struct cDEBUG
{
   /*---(handle)-------------------------*/
   int         logger;                 /* log file so that we don't close it  */
   /*---(overall)------------------------*/  /* abcdefghi_kl__opq_stu__x__    */
   /* f = full urgents turns on all standard urgents                          */
   /* k = kitchen sink and turns everything, i mean everything on             */
   /* q = quiet turns all urgents off including the log itself                */
   char        tops;                   /* t) broad structure and context      */
   char        summ;                   /* r) statistics and analytical output */
   /*---(startup/shutdown)---------------*/
   char        args;                   /* a) command line args and urgents    */
   char        args_mas;               /* A) command line args and urgents    */
   char        conf;                   /* c) configuration handling           */
   char        conf_mas;               /* C) configuration handling           */
   char        prog;                   /* p) program setup and teardown       */
   char        prog_mas;               /* P) program setup and teardown       */
   /*---(file processing)----------------*/
   char        inpt;                   /* i) text and data file input         */
   char        inpt_mas;               /* I) text/data file input   (mas/more)*/
   char        outp;                   /* o) text and data file output        */
   char        outp_mas;               /* O) text/data file output  (mas/more)*/
   char        sqls;                   /* q) sql and database accesses        */
   char        sqls_mas;               /* Q) sql and database accesses        */
   /*---(event handling)-----------------*/
   char        loop;                   /* l) main program event loop          */
   char        loop_mas;               /* L) main program event loop          */
   char        user;                   /* u) user input and handling          */
   char        user_mas;               /* U) user input and handling          */
   char        apis;                   /* z) interprocess communication       */
   char        apis_mas;               /* Z) interprocess communication       */
   char        sign;                   /* x) os signal handling               */
   char        sign_mas;               /* X) os signal handling               */
   char        scrp;                   /* b) scripts and batch operations     */
   char        scrp_mas;               /* B) scripts and batch operations     */
   char        hist;                   /* h) history, undo, redo              */
   char        hist_mas;               /* H) history, undo, redo              */
   /*---(program)------------------------*/
   char        graf;                   /* g) grahpics, drawing, and display   */
   char        graf_mas;               /* G) grahpics, drawing, and display   */
   char        data;                   /* d) complex data structure handling  */
   char        data_mas;               /* D) complex data structure handling  */
   char        envi;                   /* e) environment processing           */
   char        envi_mas;               /* E) environment processing (mas/more)*/
   /*---(sorting)------------------------*/
   char        sort;
   char        sort_mas;
   /*---(spreadsheet)--------------------*/
   char        rpn;
   char        calc;
   char        calc_mas;
   char        exec;
   char        exec_mas;
   char        loc;
   char        cell;
   char        cell_mas;
   /*---(dependencies)-------------------*/
   char        deps;
   char        deps_mas;
   /*---(selections)---------------------*/
   char        visu;                   /* gyges_visu : visual selection       */
   char        ssel;                   /* gyges_visu : source selection       */
   char        mark;                   /* gyges_visu : location/object marks  */
   /*---(registers)----------------------*/
   char        regs;                   /* s_sel  : copy and paste registers   */
   /*---(other)--------------------------*/
   char        s;
   char        sylk;
   char        gnome;
   char        dtree;          /* displays the dependency tree and exits      */
   char        ystr;                   /* s_file : ystr functions             */
};
tDEBUG      yURG_debug;



/*---(standard)--------------------------*/
#define     DEBUG_TOPS          if (yURG_debug.tops      == 'y')
#define     DEBUG_SUMM          if (yURG_debug.summ      == 'y')
#define     DEBUG_ARGS          if (yURG_debug.args      == 'y')
#define     DEBUG_CONF          if (yURG_debug.conf      == 'y')
#define     DEBUG_CONF_M        if (yURG_debug.conf_mas  == 'y')
#define     DEBUG_PROG          if (yURG_debug.prog      == 'y')
#define     DEBUG_PROG_M        if (yURG_debug.prog_mas  == 'y')
#define     DEBUG_INPT          if (yURG_debug.inpt      == 'y')
#define     DEBUG_INPT_M        if (yURG_debug.inpt_mas  == 'y')
#define     DEBUG_OUTP          if (yURG_debug.outp      == 'y')
#define     DEBUG_OUTP_M        if (yURG_debug.outp_mas  == 'y')
#define     DEBUG_LOOP          if (yURG_debug.loop      == 'y')
#define     DEBUG_LOOP_M        if (yURG_debug.loop_mas  == 'y')
#define     DEBUG_USER          if (yURG_debug.user      == 'y')
#define     DEBUG_USER_M        if (yURG_debug.user_mas  == 'y')
#define     DEBUG_APIS          if (yURG_debug.apis      == 'y')
#define     DEBUG_APIS_M        if (yURG_debug.apis_mas  == 'y')
#define     DEBUG_SIGN          if (yURG_debug.sign      == 'y')
#define     DEBUG_SIGN_M        if (yURG_debug.sign_mas  == 'y')
#define     DEBUG_SCRP          if (yURG_debug.scrp      == 'y')
#define     DEBUG_SCRP_M        if (yURG_debug.scrp_mas  == 'y')
#define     DEBUG_HIST          if (yURG_debug.hist      == 'y')
#define     DEBUG_HIST_M        if (yURG_debug.hist_mas  == 'y')
#define     DEBUG_GRAF          if (yURG_debug.graf      == 'y')
#define     DEBUG_GRAF_M        if (yURG_debug.graf_mas  == 'y')
#define     DEBUG_DATA          if (yURG_debug.data      == 'y')
#define     DEBUG_DATA_M        if (yURG_debug.data_mas  == 'y')
#define     DEBUG_ENVI          if (yURG_debug.envi      == 'y')
#define     DEBUG_ENVI_M        if (yURG_debug.envi_mas  == 'y')
/*---(dependencies)----------------------*/
#define     DEBUG_DEPS          if (yURG_debug.deps      == 'y')
#define     DEBUG_DEPS_M        if (yURG_debug.deps_mas  == 'y')
#define     DEBUG_GNOME         if (yURG_debug.gnome     == 'y')
/*---(cells)-----------------------------*/
#define     DEBUG_LOC           if (yURG_debug.loc       == 'y')
#define     DEBUG_CELL          if (yURG_debug.cell      == 'y')
#define     DEBUG_CELL_M        if (yURG_debug.cell_mas  == 'y')
/*---(formulas)--------------------------*/
#define     DEBUG_S             if (yURG_debug.s         == 'y')
#define     DEBUG_RPN           if (yURG_debug.rpn       == 'y')
#define     DEBUG_CALC          if (yURG_debug.calc      == 'y')
#define     DEBUG_CALC_M        if (yURG_debug.calc_mas  == 'y')
#define     DEBUG_EXEC          if (yURG_debug.exec      == 'y')
#define     DEBUG_EXEC_M        if (yURG_debug.exec_mas  == 'y')
/*---(visual)----------------------------*/
#define     DEBUG_VISU          if (yURG_debug.visu      == 'y')
#define     DEBUG_SSEL          if (yURG_debug.ssel      == 'y')
#define     DEBUG_MARK          if (yURG_debug.mark      == 'y')
/*---(registers)-------------------------*/
#define     DEBUG_REGS          if (dyURG_ebug.regs      == 'y')
/*---(ySTR)------------------------------*/
#define     DEBUG_YSTR          if (yURG_debug.ystr      == 'y')



char        yURG_list          (void);
char        yURG_abbr          (char  a_abbr);
char        yURG_set           (char  a_name);
char        yURG_mass          (char  a_set , char a_extra);
char        yURG_parse         (int   a_argc, char *a_argv[]);





#endif
/*===[[ END ]]================================================================*/
