LDLIBS = -lfl -lm -pthread -lreadline

all: uffsdb

uffsdb: interface/y.tab.c interface/y.tab.h interface/lex.yy.c *.c *.h
	gcc *.c interface/*.c -Iinclude -Wall -g $(LDLIBS) -o uffsdb 

interface/y.tab.c interface/y.tab.h: interface/lex.l interface/yacc.y
	lex -o interface/lex.yy.c interface/lex.l
	yacc -d -o interface/y.tab.c interface/yacc.y

clean:
	rm uffsdb -f
	rm data/ -RIf
	rm interface/y.tab.c interface/y.tab.h interface/lex.yy.c
