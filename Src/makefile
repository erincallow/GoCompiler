#Version 3.0

GoCompiler: lex.yy.c y.tab.c GoTree.o GoWeed.o GoPretty.o GoSymbol.o GoType.o memory.o error.o GoCode.o main.o
	gcc lex.yy.c y.tab.c GoTree.o GoWeed.o GoPretty.o GoSymbol.o GoType.o memory.o error.o GoCode.o -o GoCompiler main.o -ll

lex.yy.c: GoScanner.l
	flex GoScanner.l

y.tab.c: GoParser.y 
	bison --yacc --defines GoParser.y

GoTree.o: GoTree.c GoTree.h GoSymbol.h
	gcc -c -g GoTree.c GoTree.h GoSymbol.h

GoWeed.o: GoWeed.c GoWeed.h GoTree.h error.h
	gcc -c -g GoWeed.c GoWeed.h GoTree.h error.h

GoPretty.o : GoPretty.c GoPretty.h GoTree.h
	gcc -c -g GoPretty.c GoPretty.h GoTree.h

GoSymbol.o : GoSymbol.c GoSymbol.h memory.h GoTree.h error.h
	gcc -c -g GoSymbol.c GoSymbol.h memory.h GoTree.h error.h

GoType.o : GoType.c GoSymbol.h GoTree.h memory.h
	gcc -c -g GoType.c GoSymbol.h GoTree.h memory.h

memory.o: memory.c memory.h
	gcc -c -g memory.c memory.h

error.o: error.c error.h
	gcc -c -g error.c error.h

GoCode.o: GoCode.c GoCode.h GoTree.h
	gcc -c -g GoCode.c GoCode.h GoTree.h

main.o: main.c GoTree.h GoPretty.h GoCode.h
	gcc -c -g main.c GoTree.h GoPretty.h GoCode.h

clean:
	rm -f *.o lex.* y.tab.*

