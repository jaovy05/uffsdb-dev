LDLIBS = -lfl -lm -pthread -lreadline

all: uffsdb

debug: interface/y.tab.c interface/y.tab.h interface/lex.yy.c *.c *.h
	gcc -DDEBUG *.c interface/*.c $(LDLIBS) -o uffsdb -Wall -g

uffsdb: interface/y.tab.c interface/y.tab.h interface/lex.yy.c *.c *.h
	gcc *.c interface/*.c $(LDLIBS) -o uffsdb -Wall -g

interface/y.tab.c interface/y.tab.h: interface/lex.l interface/yacc.y
	lex -o interface/lex.yy.c interface/lex.l
	yacc -d -o interface/y.tab.c interface/yacc.y

clean:
	rm uffsdb -f
	rm data/ -RIf
	rm interface/y.tab.c interface/y.tab.h interface/lex.yy.c

