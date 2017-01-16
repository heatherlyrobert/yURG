/*===[[ START HDOC ]]=========================================================*/


/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YURG_HGUARD
#define YURG_HGUARD loaded


/* rapidly evolving version number to aid with visual change confirmation     */
#define YURG_VER_NUM   "0.2n"
#define YURG_VER_TXT   "library urgents required underscores in names"



#define        LEN_LABEL        20
#define        LEN_DESC         80
#define        LEN_STR         200
#define        MAX_URGS        500


typedef     struct   cURG_DEBUG       tURG_DEBUG;

/*===[[ DEBUGGING SETUP ]]====================================================*/
/* this is my latest standard format, vars, and urgents                       */
/* v3.0b : added signal handling                                (2014-feb-01) */
struct cURG_DEBUG
{
   /*---(handle)-------------------------*/
   int         logger;                 /* log file so that we don't close it  */
   int         mode;                   /* quiet '-' vs logging 'y'            */
   /*---(overall)------------------------*/  /* abcdefghi_kl__opq_stu__x__    */
   /* f = full urgents turns on all standard urgents                          */
   /* k = kitchen sink and turns everything, i mean everything on             */
   /* q = quiet turns all urgents off including the log itself                */
   char        tops;                   /* t) broad structure and context      */
   char        tops_mas;               /* t) broad structure and context      */
   char        summ;                   /* r) statistics and analytical output */
   char        summ_mas;               /* r) statistics and analytical output */
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
   char        sort;                   /* s) data sorting and ordering        */
   char        sort_mas;               /* S) data sorting and ordering        */
   /*---(spreadsheet)--------------------*/
   char        locs;
   char        locs_mas;
   char        cell;
   char        cell_mas;
   /*---(calculations)-------------------*/
   char        rpn;
   char        rpn_mas;
   char        calc;
   char        calc_mas;
   char        exec;
   char        exec_mas;
   /*---(dependencies)-------------------*/
   char        deps;
   char        deps_mas;
   /*---(selections)---------------------*/
   char        visu;                   /* gyges_visu : visual selection       */
   char        visu_mas;               /* gyges_visu : visual selection       */
   char        ssel;                   /* gyges_visu : source selection       */
   char        ssel_mas;               /* gyges_visu : source selection       */
   char        mark;                   /* gyges_visu : location/object marks  */
   char        mark_mas;               /* gyges_visu : location/object marks  */
   /*---(registers)----------------------*/
   char        regs;                   /* s_sel  : copy and paste registers   */
   char        regs_mas;               /* s_sel  : copy and paste registers   */
   /*---(other)--------------------------*/
   char        adjs;                   /* small, configurable adjustments     */
   char        adjs_mas;               /* small, configurable adjustments     */
   char        s;
   char        sylk;
   char        gnome;
   char        dtree;          /* displays the dependency tree and exits      */
   char        ystr;                   /* ySTR string library                 */
   char        ystr_mas;               /* ySTR string library                 */
   char        ykine_calc;                  /* yKINE kinematics library            */
   char        ykine_calc_mas;              /* yKINE kinematics library            */
   char        ykine_data;                  /* yKINE kinematics library            */
   char        ykine_data_mas;              /* yKINE kinematics library            */
   char        ykine_scrp;                  /* yKINE kinematics library            */
   char        ykine_scrp_mas;              /* yKINE kinematics library            */
   char        yvikeys_keys;                /* yVIKEYS vi-keys library        */
   char        yvikeys_keys_mas;            /* yVIKEYS vi-keys library        */
   char        yvikeys_mode;                /* yVIKEYS vi-keys library        */
   char        yvikeys_mode_mas;            /* yVIKEYS vi-keys library        */
   char        yvikeys_scale;               /* yVIKEYS vi-keys library        */
   char        yvikeys_scale_mas;           /* yVIKEYS vi-keys library        */
};
extern    tURG_DEBUG      yURG_debug;



/*---(standard)--------------------------*/
#define     DEBUG_TOPS             if (yURG_debug.tops               == 'y')
#define     DEBUG_TOPS_M           if (yURG_debug.tops_mas           == 'y')
#define     DEBUG_SUMM             if (yURG_debug.summ               == 'y')
#define     DEBUG_SUMM_M           if (yURG_debug.summ_mas           == 'y')
#define     DEBUG_ARGS             if (yURG_debug.args               == 'y')
#define     DEBUG_ARGS_M           if (yURG_debug.args_mas           == 'y')
#define     DEBUG_CONF             if (yURG_debug.conf               == 'y')
#define     DEBUG_CONF_M           if (yURG_debug.conf_mas           == 'y')
#define     DEBUG_PROG             if (yURG_debug.prog               == 'y')
#define     DEBUG_PROG_M           if (yURG_debug.prog_mas           == 'y')
#define     DEBUG_INPT             if (yURG_debug.inpt               == 'y')
#define     DEBUG_INPT_M           if (yURG_debug.inpt_mas           == 'y')
#define     DEBUG_OUTP             if (yURG_debug.outp               == 'y')
#define     DEBUG_OUTP_M           if (yURG_debug.outp_mas           == 'y')
#define     DEBUG_LOOP             if (yURG_debug.loop               == 'y')
#define     DEBUG_LOOP_M           if (yURG_debug.loop_mas           == 'y')
#define     DEBUG_USER             if (yURG_debug.user               == 'y')
#define     DEBUG_USER_M           if (yURG_debug.user_mas           == 'y')
#define     DEBUG_APIS             if (yURG_debug.apis               == 'y')
#define     DEBUG_APIS_M           if (yURG_debug.apis_mas           == 'y')
#define     DEBUG_SIGN             if (yURG_debug.sign               == 'y')
#define     DEBUG_SIGN_M           if (yURG_debug.sign_mas           == 'y')
#define     DEBUG_SCRP             if (yURG_debug.scrp               == 'y')
#define     DEBUG_SCRP_M           if (yURG_debug.scrp_mas           == 'y')
#define     DEBUG_HIST             if (yURG_debug.hist               == 'y')
#define     DEBUG_HIST_M           if (yURG_debug.hist_mas           == 'y')
#define     DEBUG_GRAF             if (yURG_debug.graf               == 'y')
#define     DEBUG_GRAF_M           if (yURG_debug.graf_mas           == 'y')
#define     DEBUG_DATA             if (yURG_debug.data               == 'y')
#define     DEBUG_DATA_M           if (yURG_debug.data_mas           == 'y')
#define     DEBUG_ENVI             if (yURG_debug.envi               == 'y')
#define     DEBUG_ENVI_M           if (yURG_debug.envi_mas           == 'y')
#define     DEBUG_SORT             if (yURG_debug.sort               == 'y')
#define     DEBUG_SORT_M           if (yURG_debug.sort_mas           == 'y')
/*---(dependencies)----------------------*/
#define     DEBUG_DEPS             if (yURG_debug.deps               == 'y')
#define     DEBUG_DEPS_M           if (yURG_debug.deps_mas           == 'y')
/*---(cells)-----------------------------*/
#define     DEBUG_LOCS             if (yURG_debug.locs               == 'y')
#define     DEBUG_LOCS_M           if (yURG_debug.locs_mas           == 'y')
#define     DEBUG_CELL             if (yURG_debug.cell               == 'y')
#define     DEBUG_CELL_M           if (yURG_debug.cell_mas           == 'y')
/*---(formulas)--------------------------*/
#define     DEBUG_RPN              if (yURG_debug.rpn                == 'y')
#define     DEBUG_RPN_M            if (yURG_debug.rpn_mas            == 'y')
#define     DEBUG_CALC             if (yURG_debug.calc               == 'y')
#define     DEBUG_CALC_M           if (yURG_debug.calc_mas           == 'y')
#define     DEBUG_EXEC             if (yURG_debug.exec               == 'y')
#define     DEBUG_EXEC_M           if (yURG_debug.exec_mas           == 'y')
#define     DEBUG_ADJS             if (yURG_debug.adjs               == 'y')
#define     DEBUG_ADJS_M           if (yURG_debug.adjs_mas           == 'y')
/*---(visual)----------------------------*/
#define     DEBUG_VISU             if (yURG_debug.visu               == 'y')
#define     DEBUG_VISU_M           if (yURG_debug.visu_mas           == 'y')
#define     DEBUG_SSEL             if (yURG_debug.ssel               == 'y')
#define     DEBUG_SSEL_M           if (yURG_debug.ssel_mas           == 'y')
#define     DEBUG_MARK             if (yURG_debug.mark               == 'y')
#define     DEBUG_MARK_M           if (yURG_debug.mark_mas           == 'y')
/*---(registers)-------------------------*/
#define     DEBUG_REGS             if (yURG_debug.regs               == 'y')
#define     DEBUG_REGS_M           if (yURG_debug.regs_mas           == 'y')
/*---(ySTR)------------------------------*/
#define     DEBUG_YSTR             if (yURG_debug.ystr               == 'y')
#define     DEBUG_YSTR_M           if (yURG_debug.ystr_mas           == 'y')
#define     DEBUG_YKINE            if (yURG_debug.ykine              == 'y')
#define     DEBUG_YKINE_M          if (yURG_debug.ykine_mas          == 'y')
#define     DEBUG_YKINE_CALC       if (yURG_debug.ykine_calc         == 'y')
#define     DEBUG_YKINE_CALC_M     if (yURG_debug.ykine_calc_mas     == 'y')
#define     DEBUG_YKINE_DATA       if (yURG_debug.ykine_data         == 'y')
#define     DEBUG_YKINE_DATA_M     if (yURG_debug.ykine_data_mas     == 'y')
#define     DEBUG_YKINE_SCRP       if (yURG_debug.ykine_scrp         == 'y')
#define     DEBUG_YKINE_SCRP_M     if (yURG_debug.ykine_scrp_mas     == 'y')
#define     DEBUG_YVIKEYS_KEYS     if (yURG_debug.yvikeys_keys       == 'y')
#define     DEBUG_YVIKEYS_KEYS_M   if (yURG_debug.yvikeys_keys_mas   == 'y')
#define     DEBUG_YVIKEYS_MODE     if (yURG_debug.yvikeys_mode       == 'y')
#define     DEBUG_YVIKEYS_MODE_M   if (yURG_debug.yvikeys_mode_mas   == 'y')
#define     DEBUG_YVIKEYS_SCALE    if (yURG_debug.yvikeys_scale      == 'y')
#define     DEBUG_YVIKEYS_SCALE_M  if (yURG_debug.yvikeys_scale_mas  == 'y')

typedef     const char         cchar;


char*       yURG_version       (void);
char        yURG_debugmode     (void);

char        yURG_logger        (int    a_argc, char *a_argv[]);
char        yURG_urgs          (int    a_argc, char *a_argv[]);
char        yURG_summ          (void);

char        yURG_list          (void);
char        yURG_abbr          (cchar  a_abbr);
char        yURG_name          (cchar *a_name);
char        yURG_mass          (cchar  a_set , cchar a_extra);




#endif
/*===[[ END ]]================================================================*/
