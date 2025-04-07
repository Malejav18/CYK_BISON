%{
#include "parser.tab.h"
%}

%%
a       return A;
b       return B;
\n      return NEWLINE;
.       return yytext[0];
%%

int yywrap() {
    return 1;
}
