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

## 🐂 ¿Qué es Bison?

**Bison** es una herramienta de análisis sintáctico que genera un **parser LALR(1)** a partir de una gramática definida por el usuario. Es parte del conjunto de herramientas GNU y se utiliza comúnmente junto con **Flex**, que se encarga del análisis léxico.

---

### 🧠 ¿Para qué se usa Bison?

Bison toma como entrada una gramática y genera un **analizador sintáctico en C/C++** que puede reconocer si una cadena de entrada pertenece al lenguaje descrito por la gramática.

## 🎯 Objetivo

Este proyecto compara dos enfoques para validar cadenas que pertenecen a un lenguaje definido por una **gramática libre de contexto en Forma Normal de Chomsky (CNF)**:

- ✅ Un **algoritmo CYK** (Cocke–Younger–Kasami), implementado manualmente.
- ✅ Un **parser LALR(1)** generado automáticamente con **Bison + Flex**.

---

## 📘 Gramática de prueba: lenguaje aⁿbⁿ

Para realizar una comparación controlada, utilizamos primero una gramática en CNF que reconoce el lenguaje:

> **L = { aⁿbⁿ | n ≥ 1 }**

Este lenguaje incluye cadenas como:

- `ab` ✅  
- `aabb` ✅  
- `aaabbb` ✅  
- `aab` ❌  
- `abb` ❌

## Gramática

- S → A X | A B
- X → S B 
- A → a
- B → b  

