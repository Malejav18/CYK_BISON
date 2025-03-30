%{
    #include "cyk.tab.h"
%}

%%

b  return B;
a  return C;

[ \t\n]  ;  // Ignorar espacios y saltos de línea

.   { return yytext[0]; }  // Cualquier otro carácter

%%

int yywrap() {
    return 1;
}
