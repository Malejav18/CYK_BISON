%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int yyparse(void);
    int yylex(void);
    void yyerror(const char *s);

    #define MAX_LEN 100

    int table[MAX_LEN][MAX_LEN]; // Tabla CYK
    char input[MAX_LEN]; // Cadena de entrada
    int length; // Longitud de la cadena

    // Función para inicializar la tabla CYK
    void initialize_table() {
        for (int i = 0; i < MAX_LEN; i++)
            for (int j = 0; j < MAX_LEN; j++)
                table[i][j] = 0;
    }

    // Función para imprimir la tabla CYK
    void print_table() {
        printf("\nTabla CYK final:\n");
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - i; j++) {
                printf("%d ", table[i][j]);
            }
            printf("\n");
        }
    }

%}

// Definición de tokens
%token B C

%%

// Regla inicial
S: A B { table[length - 1][0] = 1; } ;

A: B C { table[length - 1][0] = 1; } ;

%%

int main() {
    printf("Ingrese una cadena (ejemplo: 'bab'):\n");
    scanf("%s", input);
    length = strlen(input);

    initialize_table(); // Inicializamos la tabla CYK

    if (yyparse() == 0) {
        print_table();
        printf("\nLa cadena pertenece al lenguaje.\n");
    } else {
        printf("\nLa cadena NO pertenece al lenguaje.\n");
    }

    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
