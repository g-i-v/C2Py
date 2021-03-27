Tutorial per l'esecuzione dei test mediante i seguenti comandi linux 


+++ Generazione del Traduttore +++

Nella directory con i file 	lexer.l		parser.y	AST.h 		compiler.c eseguo i seguenti comandi per ottenere il traduttore: 

bison -d parser.y
flex -l lexer.l 
gcc -o a.out parser.tab.c lex.yy.c compiler.c -lfl

A questo punto avrò ottenuto un file "a.out" che è il vero e proprio traduttore: un file eseguibile da riga di comando.




+++ Traduzione C -> Python +++

./a.out < test1_GOOD.txt  -> genera "out.py" (rinominato in "test1_good.py")

./a.out < test2_GOOD.txt  -> genera "out.py" (rinominato in "test2_good.py")

./a.out < test1_WRONG.txt -> genera messaggi d'errore su standard output

./a.out < test2_WRONG.txt -> genera "out.py" (rinominato in "test1_good.py")



+++ Esecuzione programmi C +++

gcc test1.c 	-> genera "a.out" eseguibile da riga di comando 
./a.out 	: ESECUZIONE PROGRAMMA SOURCE	

gcc test2.c     -> genera "a.out" eseguibile da riga di comando
./a.out 	: ESECUZIONE PROGRAMMA SOURCE



+++ Esecuzione programmi Python +++ 

python3 test1_good.py 		: ESECUZIONE PROGRAMMA TARGET	

python3 test2_good.py		: ESECUZIONE PROGRAMMA TARGET	


