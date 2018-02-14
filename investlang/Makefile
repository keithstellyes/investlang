all: lexerstd testbins

lexerstd: tokens.o lex.yy.o lexerstd.o 
	gcc -lfl lex.yy.o tokens.o lexerstd.o -o lexerstd
lexerstd.o: lexerstd.c
	gcc lexerstd.c -c
lex.yy.o: tokens.h lexer.l
	flex --header-file=lex.yy.h lexer.l
	gcc lex.yy.c -c

tokens.o: tokens.h tokens.c
	gcc tokens.c -c

clean:
	rm lex.yy.h lex.yy.c lex.yy.o lexerstd.o

do-tests: testbins
	./tests/helloworld
	./tests/quotestuff

testbins: tests/common.o tests/helloworld tests/quotestuff

tests/common.o: tests/common.c tests/common.h
	gcc -I. tests/common.c -c -o tests/common.o

tests/helloworld: lex.yy.o tokens.o tests/helloworld.o
	gcc -lfl tests/common.o lex.yy.o tokens.o tests/helloworld.o -o tests/helloworld

tests/helloworld.o: tests/helloworld.c
	gcc -I. tests/helloworld.c -c -o tests/helloworld.o

tests/quotestuff: lex.yy.o tokens.o tests/quotestuff.o
	gcc -lfl tests/common.o lex.yy.o tokens.o tests/helloworld.o -o tests/quotestuff

tests/quotestuff.o: tests/quotestuff.c
	gcc -I. tests/quotestuff.c -c -o tests/quotestuff.o
