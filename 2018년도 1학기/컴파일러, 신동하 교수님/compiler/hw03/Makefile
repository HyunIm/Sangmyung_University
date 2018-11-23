# ======================================================================

scanner:	scanner.c
	gcc -O -o scanner scanner.c -lfl

scanner.c:	scanner.l
	flex scanner.l
	mv lex.yy.c scanner.c

# ======================================================================

clean:
	@rm -rf .*~ *~ scanner scanner.c *.o *.ps *.pdf

# ======================================================================
