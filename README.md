# Comparando CYK y Bison...

## 🧠 Forma normal de Chomsky (CNF)
En el contexto de las **Gramáticas Independientes del Contexto (GIC)**, una gramática se considera que está en la **forma normal de Chomsky (CNF)** si todas sus reglas tienen una de estas formas:

- A → B C  (dos variables, no terminales)
- A → a  (un solo terminal)
- S → ε  (el símbolo inicial puede generar la cadena vacía, si es necesario)

## 🧮 Algoritmo CYK (Cocke–Younger–Kasami)

El algoritmo **CYK** es un algoritmo clásico de análisis sintáctico **basado en programación dinámica** que permite determinar si una cadena pertenece al lenguaje generado por una gramática en **Forma Normal de Chomsky (CNF)**.

---

### 🧠 ¿Cómo funciona?

El algoritmo CYK toma como entrada:
- Una cadena de entrada.
- Una gramática en CNF.

Y responde:
> ✅ La cadena **sí** pertenece al lenguaje generado por la gramática.  
> ❌ La cadena **no** pertenece al lenguaje generado por la gramática.

CYK **rellena una tabla triangular** en la que:
- Las filas representan longitudes de subcadenas.
- Las columnas representan posiciones de inicio en la cadena.
- Cada celda contiene los **no terminales** que pueden generar esa subcadena.

Al final, si el símbolo inicial (S) aparece en la celda que representa toda la cadena, entonces la cadena **es válida** según la gramática.
