## Ejecución:
```
bison -d parser.y
flex lexer.l
gcc -o reconocedor parser.tab.c lex.yy.c -lfl
./reconocedor
```
