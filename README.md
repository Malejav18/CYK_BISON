# CYK_BISON

En el contexto de las Gramáticas Independientes del Contexto (GIC), una gramática se considera que está en la forma normal de Chomsky (CNF) si presenta la siguiente estructura:

- **Producción binaria:**  
  \( A \rightarrow BC \)  
  donde \(A\), \(B\) y \(C\) son variables (no terminales) y \(B, C\) no pueden ser el símbolo inicial.
  
- **Producción terminal:**  
  \( A \rightarrow a \)  
  donde \(a\) es un símbolo terminal.

- **Producción especial para la cadena vacía:**  
  \( S \rightarrow \epsilon \)  
  Esta regla se permite únicamente para el símbolo inicial \(S\) si el lenguaje incluye la cadena vacía.
