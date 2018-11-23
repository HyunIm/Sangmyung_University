# ======================================================================

DIR = symbol
FILES = Makefile parser.y scanner.l symbol.c

# ======================================================================

symbol:	parser.o scanner.o
	gcc -O -o symbol parser.o scanner.o -lfl

parser.o:	parser.c
	gcc -O -c parser.c

parser.c:	parser.y symbol.c
	bison -d parser.y
	mv parser.tab.c parser.c
	mv parser.tab.h parser.h

scanner.o:	scanner.c
	gcc -O -c scanner.c

scanner.c:	scanner.l
	flex scanner.l
	mv lex.yy.c scanner.c

# ======================================================================

install:	symbol
	install symbol /usr/local/bin

# ======================================================================
clean:
	@rm -rf .*~ *~ symbol parser.c parser.h scanner.c *.o *.ps *.pdf

# ======================================================================
