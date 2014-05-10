# $Id: Makefile,v 1.7 2012-11-14 18:30:13-08 - - $
MKFILE    = Makefile
DEPSFILE  = ${MKFILE}.deps
NOINCLUDE = ci clean spotless
NEEDINCL  = ${filter ${NOINCLUDE}, ${MAKECMDGOALS}}
SUBMAKE   = ${MAKE} --no-print-directory

GCC       = gcc -g -O0 -Wall -Wextra -std=gnu99
MAKEDEPS  = cc -MM

CHEADER   = List.h 
CSOURCE   = Listdr.c ${CHEADER:.h=.c}
CSOURCE2  = store.c ${CHEADER:.h=.c}
OBJECTS   = ${CSOURCE:.c=.o}
OBJECTS2   = ${CSOURCE2:.c=.o}
EXECBIN   = Listdr
EXECBIN2  = store
SOURCES   = ${CHEADER} ${CSOURCE} ${MKFILE}
SOURCES2  = ${CHEADER} ${CSOURCE2} ${MKFILE}

all : ${EXECBIN} ${EXECBIN2}
			
${EXECBIN} : ${OBJECTS}
	${GCC} -o $@ ${OBJECTS}

${EXECBIN2} : ${OBJECTS2}
	${GCC} -o $@ ${OBJECTS2}
%.o : %.c
	${GCC} -c $<


lis : ${SOURCES}
	mkpspdf ${LISTING} ${SOURCES} ${DEPSFILE}

	${SOURCES2}
	mkpspdf ${LISTING} ${SOURCES2} ${DEPSFILE}
	
clean :
	- rm ${OBJECTS} ${DEPSFILE} core

spotless : clean
	- rm ${EXECBIN}

deps : ${CSOURCE} ${CHEADER}
	@ echo "# ${DEPSFILE} created `date`" >${DEPSFILE}
	${MAKEDEPS} ${CSOURCE} | sort | uniq >>${DEPSFILE}

${DEPSFILE} :
	@ touch ${DEPSFILE}
	${SUBMAKE} deps

again :
	${MAKE} --no-print-directory spotless deps ci all lis

ifeq "${NEEDINCL}" ""
include ${DEPSFILE}
endif
