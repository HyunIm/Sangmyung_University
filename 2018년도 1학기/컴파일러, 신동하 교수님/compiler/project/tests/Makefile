# ======================================================================

DIR = compiler
FILES = Makefile parser.y scanner.l symbol.c

# ======================================================================

cm:	parser.o scanner.o
	gcc -O -o cm parser.o scanner.o -lfl

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

clean:
	@rm -rf .*~ *~ cm parser.c parser.h scanner.c *.o *.tm *.ps *.pdf
#	cd tests; make clean

# ======================================================================
