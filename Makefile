#*============================----beg-of-source---============================*#

#*---(current variables)--------------*#
BASE    = yURG
DEBUG   = yURG_debug
UNIT    = yURG_unit
DIR     = /home/system/yURG.urgent_handling
#*---(compilier variables)------------*#
# must have "-x c" on gcc line so stripped files work with alternate extensions
COMP    = gcc -c -std=gnu89 -x c -g -pg -Wall -Wextra
INCS    = -I/usr/local/include 
LINK    = gcc
LIBDIR  = -L/usr/local/lib
LIBS    = ${LIBDIR} -lySTR -lyLOG
LIBD    = ${LIBDIR} -lySTR -lyLOG
LIBU    = ${LIBDIR} -lySTR -lyLOG -lyUNIT -lyVAR
#*---(file lists)---------------------*#
HEADS   = ${BASE}.h   ${BASE}_priv.h
OBJS    = ${BASE}.os
OBJD    = ${BASE}.o
OBJU    = ${BASE}.o   ${UNIT}.o
#*---(make variables)-----------------*#
COPY    = cp -f
CLEAN   = rm -f
PRINT   = @printf
STRIP   = @grep -v -e " DEBUG_" -e " yLOG_" 



#*---(executables)--------------------*#
all                : ${DEBUG} ${BASE} ${UNIT}

${BASE}            : ${OBJS}
	${LINK}  -shared -Wl,-soname,lib${BASE}.so.1   ${LIBS}  -o lib${BASE}.so.1.0   ${OBJS}
	ar       rcs  lib${BASE}.a   ${OBJS}

${DEBUG}           : ${OBJD}
	${LINK}  -shared -Wl,-soname,lib${DEBUG}.so.1  ${LIBD}  -o lib${DEBUG}.so.1.0  ${OBJD}
	ar       rcs  lib${DEBUG}.a  ${OBJD}

${UNIT}            : ${OBJU}
	${LINK}  -o ${UNIT}        ${OBJU}   ${LIBU}



#*---(components)---------------------*#
${BASE}.o          : ${HEADS} ${BASE}.c
	${COMP}  -fPIC  ${BASE}.c        -o ${BASE}.o         ${INCS}
	${STRIP}        ${BASE}.c         > ${BASE}.cs      
	${COMP}  -fPIC  ${BASE}.cs       -o ${BASE}.os        ${INCS}

${UNIT}.o          : ${HEADS} ${BASE}.unit
	uUNIT    ${BASE}
	mv ${UNIT}.code ${UNIT}.c
	${COMP}  ${UNIT}.c  ${INCS}



#*---(housecleaning)------------------*#
clean              :
	${PRINT}  "\n--------------------------------------\n"
	${PRINT}  "cleaning out local object, backup, and temp files\n"
	${CLEAN} lib${BASE}.so.1
	${CLEAN} lib${BASE}.so.1.0
	${CLEAN} lib${DEBUG}.so.1
	${CLEAN} lib${DEBUG}.so.1.0
	${CLEAN} *.o
	${CLEAN} *.cs
	${CLEAN} *.os
	${CLEAN} *~
	${CLEAN} temp*
	${CLEAN} ${BASE}_unit.c

bigclean           :
	${PRINT}  "\n--------------------------------------\n"
	${PRINT}  "clean out local swap files\n"
	${CLEAN}  '.'*.sw?

remove             :
	${PRINT}  "\n--------------------------------------\n"
	${PRINT}  "remove ${BASE} from production\n"
	_lib      -d  ${BASE}
	_lib      -d  ${DEBUG}
	ldconfig

install            :
	#---(production version)--------------#
	sha1sum   lib${BASE}.so.1.0
	_lib      -s ${BASE}
	ldconfig
	sha1sum   lib${BASE}.a
	_lib      -a ${BASE}
	ldconfig
	#---(debug version)-------------------#
	sha1sum   lib${DEBUG}.so.1.0
	_lib      -S ${DEBUG}
	ldconfig
	sha1sum   lib${DEBUG}.a
	_lib      -A ${DEBUG}
	ldconfig
	#---(documentation)-------------------#
	rm -f     /usr/share/man/man3/${BASE}.3.bz2
	cp -f     ${BASE}.3    /usr/share/man/man3/
	bzip2     /usr/share/man/man3/${BASE}.3
	chmod     0644  /usr/share/man/man3/${BASE}.3.bz2

#*============================----end-of-source---============================*#
