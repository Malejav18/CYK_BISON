%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void yyerror(const char *s);
int yylex();

clock_t start_time, end_time;
%}

%token A B NEWLINE

%%
input:
      /* vacío */
    | input linea
    ;

linea:
    S NEWLINE { 
        end_time = clock();
        printf("Cadena válida.\n"); 
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Tiempo de análisis: %.6f segundos\n\n", time_taken);
    }
  | NEWLINE { 
        end_time = clock();
        printf("Cadena vacía.\n"); 
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Tiempo de análisis: %.6f segundos\n\n", time_taken);
    }
  ;

S:
    A { start_time = clock(); } X
  | A { start_time = clock(); } B
  ;

X:
    S B
  ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    printf("Ingresa una cadena por línea (Ctrl+D para salir):\n");
    yyparse();
    return 0;
}

