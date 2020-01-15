yacc -d limbaj.y
lex limbaj.l
g++ lex.yy.c y.tab.c -ll -ly -w -o sursa.exe
./sursa.exe limbaj.txt