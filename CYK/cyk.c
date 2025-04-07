#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 2000
#define MAX_NONTERMINALS 10
#define MAX_RULES 50

typedef struct {
    int parent;
    int left;
    int right;
} BinaryProduction;

typedef struct {
    int nonTerminal;
    char terminal;
} TerminalProduction;

int table[MAX_LEN][MAX_LEN][MAX_NONTERMINALS];

BinaryProduction binaryRules[MAX_RULES];
int binaryRuleCount = 0;

TerminalProduction terminalRules[MAX_RULES];
int terminalRuleCount = 0;

int numNonTerminals = 0;
char nonTerminalNames[MAX_NONTERMINALS];

int getNonTerminalIndex(char c) {
    for (int i = 0; i < numNonTerminals; ++i) {
        if (nonTerminalNames[i] == c) return i;
    }
    nonTerminalNames[numNonTerminals] = c;
    return numNonTerminals++;
}

void addBinaryRule(char parent, char left, char right) {
    binaryRules[binaryRuleCount++] = (BinaryProduction){
        .parent = getNonTerminalIndex(parent),
        .left = getNonTerminalIndex(left),
        .right = getNonTerminalIndex(right)
    };
}

void addTerminalRule(char nonTerminal, char terminal) {
    terminalRules[terminalRuleCount++] = (TerminalProduction){
        .nonTerminal = getNonTerminalIndex(nonTerminal),
        .terminal = terminal
    };
}

int cyk(const char* input) {
    int n = strlen(input);
    memset(table, 0, sizeof(table));

    for (int i = 0; i < n; ++i) {
        for (int r = 0; r < terminalRuleCount; ++r) {
            if (terminalRules[r].terminal == input[i]) {
                table[i][0][terminalRules[r].nonTerminal] = 1;
            }
        }
    }

    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i <= n - l; ++i) {
            for (int k = 1; k < l; ++k) {
                for (int r = 0; r < binaryRuleCount; ++r) {
                    int p = binaryRules[r].parent;
                    int left = binaryRules[r].left;
                    int right = binaryRules[r].right;
                    if (table[i][k-1][left] && table[i+k][l-k-1][right]) {
                        table[i][l-1][p] = 1;
                    }
                }
            }
        }
    }

    int startSymbol = getNonTerminalIndex('S');
    return table[0][n-1][startSymbol];
}

void evaluate(int n) {
    char* input = malloc(2 * n + 1);
    for (int i = 0; i < n; i++) input[i] = 'a';
    for (int i = n; i < 2 * n; i++) input[i] = 'b';
    input[2 * n] = '\0';

    printf("\nEvaluando cadena con %d a's y %d b's (longitud %d)...\n", n, n, 2 * n);

    clock_t start = clock();
    int result = cyk(input);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Resultado: %s\n", result ? "✅ Válida" : "❌ Inválida");
    printf("Tiempo de ejecución: %.6f segundos\n", time_spent);

    free(input);
}

int main() {
    // Definir la gramática para L = { aⁿbⁿ | n ≥ 1 }
    addBinaryRule('S', 'A', 'X');
    addBinaryRule('S', 'A', 'B');
    addBinaryRule('X', 'S', 'B');
    addTerminalRule('A', 'a');
    addTerminalRule('B', 'b');

    // Ejecutar pruebas con diferentes longitudes
    evaluate(50);
    evaluate(100);
    evaluate(200);
    evaluate(400);
    evaluate(600);
    evaluate(800);
    evaluate(1000);
    return 0;
}
