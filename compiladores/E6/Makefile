CC = cc -g
LEX = flex
YACC = bison
CFLAGS = -DYYDEBUG=1 

cminusv2 : cminusv2.tab.o lex.yy.o compiler.o
	${CC} -o cminusv2 cminusv2.tab.o lex.yy.o compiler.o
    
cminusv2.tab.c cminusv2.tab.h : cminusv2.y
	${YACC} -vd cminusv2.y

lex.yy.c : cminusv2.l
	${LEX} $<

.SUFFIXES: .l .y .c
