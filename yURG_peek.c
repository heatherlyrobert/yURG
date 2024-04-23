/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"



static char  s_peek    [LEN_RECD] = "";
static char  s_pprint  [LEN_RECD] = "";


#define     MAX_PERM         50
typedef     struct cPERM    tPERM;
struct cPERM {
   char        name        [LEN_LABEL];
   char        desc        [LEN_HUND];
   int         value;
   char        disp        [LEN_TERSE];
};
const tPERM s_perms [MAX_PERM] = {
   /* 123456789012345    12345678901234567890123456789012345678901234567890123456789012345678901234567890   12345    123456789  */
   /* ---name--------    ---description------------------------------------------------------------------   perms    -display-  */
   { "g_only"         , "only the group can see, access, or modify"                                       , 00070 , "---rwx---"},
   { "g_share"        , "only the group can modify, but all others can see and access"                    , 00075 , "---rwxr-x"},
   /*---(directories)-------------*/
   { "d_open"         , "everyone can access directory, then list, read, create, and delete files"        , 00777 , "rwxrwxrwx"},
   { "d_group"        , "owner and group can do anything, others can read"                                , 00775 , "rwxrwxr-x"},
   { "d_control"      , "owner and group can do anything, everyone else can do nothing"                   , 00770 , "rwxrwx---"},
   { "d_normal"       , "everyone can access directory, group and other can list and read files only"     , 00755 , "rwxr-xr-x"},
   { "d_normals"      , "everyone can access directory, group and other can list and read files only"     , 01755 , "rwxr-xr-t"},
   { "d_sgroup"       , "same as d_normal, but new files get directories group id"                        , 02755 , "rwxr-sr-x"},
   { "d_secure"       , "owner can do anything,  group can list and read files only, all others nothing"  , 00750 , "rwxw-x---"},
   { "d_tight"        , "owner can do anything, all others nothing"                                       , 00700 , "rwx------"},
   { "d_tights"       , "everyone can see, access, and modify, but only owner can delete"                 , 01700 , "rwx-----T"},
   /*---(root)--------------------*/
   { "r_share"        , "only root specifically can modify; but all others can see and access"            , 00555 , "r-xr-xr-x"},
   { "r_only"         , "only root specifically can sse, access, or modify; even root group can not"      , 00000 , "---------"},
   /*---(regular files)-----------*/
   { "f_open"         , "everyone can read and write"                                                     , 00666 , "rw-rw-rw-"},
   { "f_control"      , "owner and group can read and write, everyone else gets nothing"                  , 00660 , "rw-rw----"},
   { "f_hidev"        , "owner and group can read and write, everyone else read-only"                     , 00664 , "rw-rw-r--"},
   { "f_usb"          , "owner and group can read and write, everyone else read-only"                     , 00662 , "rw-rw--w-"},
   { "f_normal"       , "owner can read and write, everyone else can read only"                           , 00644 , "rw-r--r--"},
   { "f_secure"       , "owner can read and write, group can read only, everyone else gets nothing"       , 00640 , "rw-r-----"},
   { "f_tty"          , "owner can read and write, group can write only, everyone else gets nothing"      , 00620 , "rw--w----"},
   { "f_tight"        , "owner can read and write, everyone else gets nothing"                            , 00600 , "rw-------"},
   { "f_nodel"        , "everyone can see, access, and modify, but only owner can delete"                 , 01777 , "rwxrwxrwt"},
   /*---(end)---------------------*/
   { "end-of-entries" , "---marker---"                                                                    , 00000 , "---------"},
};



/*====================------------------------------------====================*/
/*===----                    files and directories                     ----===*/
/*====================------------------------------------====================*/
static void      o___FILE_______________o (void) {;}

char
yURG_touchier           (char a_type, cchar a_name [LEN_PATH], cchar a_own [LEN_LABEL], cchar a_grp [LEN_LABEL], cchar a_perms [LEN_LABEL], int a_major, int a_minor, char a_link [LEN_PATH])
{
   char        rce         =  -10;
   char        rc          =    0;
   char        x_type      =  '-';
   FILE       *f           = NULL;
   tPASSWD    *x_owner     = NULL;
   tGROUP     *x_group     = NULL;
   int         x_uid       =   -1;
   int         x_gid       =   -1;
   uint        x_perms     =   -1;
   int         i, l, x_euid, x_egid, x_eperm, x_emaj, x_emin;
   char        x_link      [LEN_PATH];
   /*---(defense)------------------------*/
   --rce;  if (a_name  == NULL)                  return rce;
   --rce;  if (strcmp (a_name, "") == 0)         return rce;
   --rce;  if (a_own   == NULL)                  return rce;
   --rce;  if (a_grp   == NULL)                  return rce;
   --rce;  if (a_perms == NULL)                  return rce;
   /*---(check on file)------------------*/
   x_type = yURG_exists (a_name);
   --rce;  if (x_type < 0)                       return rce;
   --rce;  if (x_type > '-' && x_type != a_type) return rce;
   /*---(pre-work ownership)-------------*/
   x_owner = getpwnam (a_own);
   --rce;  if (x_owner == NULL)                  return rce;
   x_uid   = x_owner->pw_uid;
   x_group = getgrnam (a_grp);
   --rce;  if (x_group == NULL)                  return rce;
   x_gid   = x_group->gr_gid;
   /*---(pre-work permissions)-----------*/
   l = strlen (a_perms);
   --rce;
   if      (a_perms [0] == '0')   sscanf (a_perms, "%o", &x_perms);
   else if (l >= 5 && a_perms [1] == '_') {
      for (i = 0; i < MAX_PERM; ++i) {
         if (strcmp (s_perms [i].name, a_perms) != 0)  continue;
         x_perms = s_perms [i].value;
         break;
      }
      if (x_perms == -1)                         return rce;
   }
   else if (l == 9) {
      x_perms = 0;
      if      (a_perms [0] == '-')  ;
      else if (a_perms [0] == 'r')  x_perms += 00400;
      else                          return rce;
      if      (a_perms [1] == '-')  ;
      else if (a_perms [1] == 'w')  x_perms += 00200;
      else                          return rce;
      if      (a_perms [2] == '-')  ;
      else if (a_perms [2] == 'x')  x_perms += 00100;
      else if (a_perms [2] == 's')  x_perms += 04100;
      else if (a_perms [2] == 'S')  x_perms += 04000;
      else                          return rce;
      if      (a_perms [3] == '-')  ;
      else if (a_perms [3] == 'r')  x_perms += 00040;
      else                          return rce;
      if      (a_perms [4] == '-')  ;
      else if (a_perms [4] == 'w')  x_perms += 00020;
      else                          return rce;
      if      (a_perms [5] == '-')  ;
      else if (a_perms [5] == 'x')  x_perms += 00010;
      else if (a_perms [5] == 's')  x_perms += 02010;
      else if (a_perms [5] == 'S')  x_perms += 02000;
      else                          return rce;
      if      (a_perms [6] == '-')  ;
      else if (a_perms [6] == 'r')  x_perms += 00004;
      else                          return rce;
      if      (a_perms [7] == '-')  ;
      else if (a_perms [7] == 'w')  x_perms += 00002;
      else                          return rce;
      if      (a_perms [8] == '-')  ;
      else if (a_perms [8] == 'x')  x_perms += 00001;
      else if (a_perms [8] == 't')  x_perms += 01001;
      else if (a_perms [8] == 'T')  x_perms += 01000;
      else                          return rce;
   }
   else  return rce;
   /*---(create, if needed)--------------*/
   --rce;  if (x_type == '-') {
      --rce;  switch (a_type) {
      case 'b' :
         rc = mknod   (a_name, S_IFBLK, makedev (a_major, a_minor));
         break;
      case 'c' :
         rc = mknod   (a_name, S_IFCHR, makedev (a_major, a_minor));
         break;
      case 'd' : 
         rc = mkdir   (a_name, 00000);
         break;
      case 'r' : 
         f  = fopen   (a_name, "wt");
         if (f == NULL)  return rce;
         fflush (f);
         fclose (f);
         f == NULL;
         break;
      case 'h' : 
         rc = link    (a_link, a_name);
         break;
      case 's' : 
         rc = symlink (a_link, a_name);
         break;
      }
   }
   /*---(ownership)----------------------*/
   rc = chown (a_name, x_uid, x_gid);
   --rce;  if (rc < 0)            return rce;
   /*---(permissions)--------------------*/
   rc = chmod (a_name, x_perms);
   --rce;  if (rc < 0)            return rce;
   /*---(verify)-------------------------*/
   x_type = yURG_detail (a_name, &x_euid, NULL, &x_egid, NULL, &x_eperm, NULL, NULL, NULL, NULL, &x_emaj, &x_emin, x_link);
   --rce;  if (x_type == '-')                      return '-';
   --rce;  if (x_type <  0)                        return rce;
   --rce;  if (x_type >  '-' && x_type != a_type)  return rce;
   --rce;  if (x_uid   != x_euid)                  return rce;
   --rce;  if (x_gid   != x_egid)                  return rce;
   --rce;  if (x_type != 's') {
      --rce;  if (x_perms != x_eperm)              return rce;
   }
   --rce;  if (strchr ("bc", x_type) != NULL) {
      if (a_major != x_emaj)                       return rce;
      if (a_minor != x_emin)                       return rce;
   }
   --rce;  if (x_type == 's') {
      if (strcmp (a_link, x_link) != 0)            return rce;
   }
   /*---(complete)-----------------------*/
   return x_type;
}

char yURG_touch              (cchar a_name [LEN_PATH], cchar a_own [LEN_LABEL], cchar a_grp [LEN_LABEL], cchar a_perms [LEN_LABEL]) { return yURG_touchier ('r', a_name, a_own, a_grp, a_perms, 0, 0, ""); }

char
yURG_rm                 (cchar a_name [LEN_PATH])
{
   char        rce         =  -10;
   char        rc          =    0;
   /*---(defense)------------------------*/
   --rce;  if (a_name == NULL)                    return rce;
   --rce;  if (strcmp (a_name, "") == 0)          return rce;
   rc = unlink (a_name);
   --rce;  if (rc != 0)                           return '-';
   return yURG_exists (a_name);
}

char
yURG_mkdir              (cchar a_name [LEN_PATH], cchar a_own [LEN_LABEL], cchar a_grp [LEN_LABEL], cchar a_perms [LEN_LABEL])
{
   char        x_cmd       [LEN_RECD]  = "";
   sprintf (x_cmd, "mkdir %s       > /dev/null  2>&1", a_name);
   system  (x_cmd);
   sprintf (x_cmd, "chown %s:%s %s > /dev/null  2>&1", a_own  , a_grp  , a_name);
   system  (x_cmd);
   sprintf (x_cmd, "chmod %s %s    > /dev/null  2>&1", a_perms, a_name  );
   system  (x_cmd);
   return 0;
}

char
yURG_rmdir              (cchar a_name [LEN_PATH])
{
   char        x_cmd       [LEN_RECD];
   sprintf (x_cmd, "rm    -fr %s   > /dev/null  2>&1", a_name);
   system  (x_cmd);
   return 0;
}

char 
yURG_detail             (cchar a_name [LEN_PATH], int *r_uid, char r_own [LEN_LABEL], int *r_gid, char r_grp [LEN_LABEL], int *r_perms, char r_pname [LEN_LABEL], char r_pdisp [LEN_TERSE], long *r_bytes, int *r_epoch, int *r_major, int *r_minor, char r_link [LEN_PATH])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   tSTAT       s;
   tPASSWD    *x_owner     = NULL;
   tGROUP     *x_group     = NULL;
   char        x_type      =  '-';
   int         x_perms     =    0;
   int         i           =    0;
   /*---(default)------------------------*/
   if (r_uid   != NULL)  *r_uid   = -1;
   if (r_own   != NULL)  strcpy (r_own  , "");
   if (r_gid   != NULL)  *r_gid   = -1;
   if (r_grp   != NULL)  strcpy (r_grp  , "");
   if (r_perms != NULL)  *r_perms = -1;
   if (r_pname != NULL)  strcpy (r_pname, "");
   if (r_pdisp != NULL)  strcpy (r_pdisp, "");
   if (r_bytes != NULL)  *r_bytes = -1;
   if (r_epoch != NULL)  *r_epoch = -1;
   if (r_major != NULL)  *r_major = -1;
   if (r_minor != NULL)  *r_minor = -1;
   if (r_link  != NULL)  strcpy (r_link , "");
   /*---(defense)------------------------*/
   --rce;  if (a_name == NULL)            return rce;
   --rce;  if (strcmp (a_name, "") == 0)  return rce;
   /*---(check existance)----------------*/
   rc = lstat (a_name, &s);
   if (rc < 0)   return '-';
   /*---(normal types)-------------------*/
   if      (S_ISBLK  (s.st_mode))   x_type = 'b';
   else if (S_ISCHR  (s.st_mode))   x_type = 'c';
   else if (S_ISDIR  (s.st_mode))   x_type = 'd';
   else if (S_ISREG  (s.st_mode))   x_type = 'r';
   else if (S_ISSOCK (s.st_mode))   x_type = 'i';
   else if (S_ISFIFO (s.st_mode))   x_type = 'p';
   else if (S_ISLNK  (s.st_mode))   x_type = 's';
   else                             x_type = '?';
   /*---(check hard link)----------------*/
   if (x_type == 'r' && s.st_nlink > 1) x_type = 'h';
   /*---(ownership)----------------------*/
   if (r_uid != NULL || r_own != NULL) {
      x_owner = getpwuid (s.st_uid);
      if (x_owner != NULL)  {
         if (r_uid != NULL)  *r_uid   = x_owner->pw_uid;
         if (r_own != NULL)  strlcpy (r_own, x_owner->pw_name, LEN_LABEL);
      }
   }
   if (r_gid != NULL || r_grp != NULL) {
      x_group = getgrgid (s.st_gid);
      if (x_group != NULL)  {
         if (r_gid != NULL)  *r_gid   = x_group->gr_gid;
         if (r_grp != NULL)  strlcpy (r_grp, x_group->gr_name, LEN_LABEL);
      }
   }
   /*---(permissions)--------------------*/
   x_perms = s.st_mode & 007777;
   if (r_perms != NULL)      *r_perms = x_perms;
   if (r_pname != NULL || r_pdisp != NULL) {
      for (i = 0; i < MAX_PERM; ++i) {
         if (s_perms [i].value != x_perms)  continue;
         if (r_pname != NULL)   strlcpy (r_pname, s_perms [i].name, LEN_LABEL);
         if (r_pdisp != NULL)   strlcpy (r_pdisp, s_perms [i].disp, LEN_TERSE);
         break;
      }
   }
   /*---(size)---------------------------*/
   if (r_bytes != NULL)      *r_bytes = s.st_size;
   /*---(update)-------------------------*/
   if (r_epoch != NULL)      *r_epoch = s.st_mtime;
   /*---(device)-------------------------*/
   if (strchr ("bc", x_type) != NULL) {
      if (r_major != NULL)   *r_major = major (s.st_rdev);
      if (r_minor != NULL)   *r_minor = minor (s.st_rdev);
   }
   /*---(symlink)------------------------*/
   if (x_type == 's') {
      if (r_link  != NULL)  readlink (a_name, r_link, LEN_PATH);
   }
   /*---(complete)-----------------------*/
   return x_type;
}

char yURG_exists  (cchar a_name [LEN_PATH]) { return yURG_detail (a_name, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL); }



/*====================------------------------------------====================*/
/*===----                      file contents                           ----===*/
/*====================------------------------------------====================*/
static void      o___CONTENT____________o (void) {;}

char*
yurg_peek               (cchar *a_name, int n, int *a_count)
{
   char        t           [LEN_RECD]  = "";
   FILE       *f           = NULL;
   int         c           =    0;
   int         x_len       =    0;
   static int  x_last      =    0;
   if (a_count != NULL)  *a_count = -1;
   if (a_name == NULL)            return "(null name)";
   if (strcmp (a_name, "") == 0)  return "(empty name)";
   if (a_count != NULL)  *a_count = 0;
   strcpy (s_peek, "");
   f = fopen (a_name, "rt");
   if (f == NULL) {
      if (a_count != NULL)  *a_count = -1;
      return "(not found)";
   }
   switch (n) {
   case -1 :
      fclose (f);
      return "(found)";
      break;
   case 'º' :
      n = x_last = 0;
      break;
   case '»' :
      n = x_last = 999;
      break;
   case '´' :
      n = x_last;
      break;
   case 'Ö' : case '·' :  /* · means default */
      n = ++x_last;
      break;
   case '×' :
      n = --x_last;
      break;
   default :
      x_last = n;
      break;
   }
   if (n < 0)  n = x_last = 0;
   while (1) {
      fgets (t, LEN_RECD, f);
      if (feof (f))  break;
      if (c == x_last)    strcpy (s_peek, t);
      if (x_last == 999)  strcpy (s_peek, t);
      ++c;
   }
   x_len = strlen (s_peek);
   if (x_len > 0 && s_peek [x_len - 1] == '\n')  s_peek [--x_len] = '\0';
   fclose (f);
   if (a_count != NULL)  *a_count = c;
   return s_peek;
}

int
yURG_peek_count         (cchar *a_name)
{
   int         c           =    0;
   yurg_peek (a_name, 0, &c);
   return c;
}

char*
yURG_peek               (cchar *a_name, int n)
{
   return yurg_peek (a_name, n, NULL);
}

char*
yURG_peek_clear         (cchar *a_name, int n)
{
   int         l           =    0;
   int         i           =    0;
   yurg_peek (a_name, n, NULL);
   l = strlen (s_peek);
   for (i = 0; i < l; ++i) {
      switch (s_peek [i]) {
      case  10 :  s_peek [i] = '¦';  break;
      case  13 :  s_peek [i] = '¦';  break;
      case  27 :  s_peek [i] = '¥';  break;
      case  29 :  s_peek [i] = '¨';  break;
      case  31 :  s_peek [i] = '§';  break;
      case  32 :  s_peek [i] = '²';  break;
      }
   }
   return s_peek;
}

char*
yURG_peek_fill          (cchar *a_name, int n)
{
   int         i           =    0;
   int         l           =    0;
   strcpy (s_pprint, yurg_peek (a_name, n, NULL));
   l = strlen (s_pprint);
   if (l == 0)  return "n/a";
   for (i = 0; i < l; ++i) {
      if (s_pprint [i] == ' ')   s_pprint [i] = '²';
      if (s_pprint [i] == '')  s_pprint [i] = '§';
      if (s_pprint [i] == '\t')  s_pprint [i] = 'Ú';
   }
   return s_pprint;
}

char*
yURG_peek_field         (cchar *a_name, int n)
{
   int         i           =    0;
   int         l           =    0;
   strcpy (s_pprint, yurg_peek (a_name, n, NULL));
   l = strlen (s_pprint);
   for (i = 0; i < l; ++i) {
      if (s_pprint [i] == '')  s_pprint [i] = '§';
   }
   return s_pprint;
}



/*====================------------------------------------====================*/
/*===----                      file comparision                        ----===*/
/*====================------------------------------------====================*/
static void      o___COMPLEX____________o (void) {;}

char
yURG_diff               (cchar *a_actual, cchar *a_expect)
{
   char        rce         =  -10;
   char        rc          =    0;
   char       *x_diff      = "/tmp/yurg_diff.txt";
   char        x_cmd       [LEN_RECD]  = "";
   int         c           =    0;
   rc = yURG_exists (a_actual);
   --rce;  if (rc < 0)  return rce;
   rc = yURG_exists (a_expect);
   --rce;  if (rc < 0)  return rce;
   sprintf (x_cmd, "diff %s %s > %s", a_actual, a_expect, x_diff);
   system  (x_cmd);
   rc = yURG_exists (x_diff);
   --rce;  if (rc < 0 || rc == '-')  return rce;
   c = yURG_peek_count (x_diff);
   if (c > 0)  return 0;
   return 1;
}


