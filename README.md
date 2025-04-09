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

# Prueba 1: Complejidad Computacional

Una de las diferencias más importantes entre el algoritmo CYK y un parser generado con Bison es la **eficiencia en tiempo de ejecución**, especialmente al procesar cadenas largas.

### 🧮 CYK (Cocke–Younger–Kasami)

- **Tipo de algoritmo:** Bottom-up mediante programación dinámica.
- **Requisitos:** Gramática en Forma Normal de Chomsky (CNF).
- **Complejidad temporal:**  
  **O(n³ × |G|)** donde:
  - *n* es la longitud de la cadena de entrada.
  - *|G|* es el número de reglas en la gramática.

Esto significa que su rendimiento cae significativamente con cadenas largas, pero es robusto y versátil, ideal para validadores generales y demostraciones teóricas.

---

### ⚙️ Bison (LALR(1))

- **Tipo de parser:** Bottom-up por desplazamiento/reducción (shift-reduce).
- **Requisitos:** Gramática en forma BNF o EBNF (no necesita CNF).
- **Complejidad temporal:**  
  **O(n)** en la mayoría de los casos (tiempo lineal en la longitud de la cadena).

Gracias a su análisis previo en tiempo de compilación (generación de tablas LALR), Bison puede analizar cadenas largas de forma muy eficiente. Es el estándar de facto en compiladores reales.

---

## Resultados CYK:
```
Evaluando cadena con 100 a's y 100 b's (longitud 200)...
Resultado: ✅ Válida
Tiempo de ejecución: 0.053141 segundos

Evaluando cadena con 200 a's y 200 b's (longitud 400)...
Resultado: ✅ Válida
Tiempo de ejecución: 0.198244 segundos

Evaluando cadena con 400 a's y 400 b's (longitud 800)...
Resultado: ✅ Válida
Tiempo de ejecución: 1.613016 segundos

Evaluando cadena con 600 a's y 600 b's (longitud 1200)...
Resultado: ✅ Válida
Tiempo de ejecución: 5.528667 segundos

Evaluando cadena con 800 a's y 800 b's (longitud 1600)...
Resultado: ✅ Válida
Tiempo de ejecución: 18.200996 segundos

Evaluando cadena con 1000 a's y 1000 b's (longitud 2000)...
Resultado: ✅ Válida
Tiempo de ejecución: 35.805268 segundos
```

![Image](https://github.com/user-attachments/assets/7cc310e0-3b5a-41f2-b63a-ac3e8c394ac0)

- La gráfica evidencia que el tiempo de ejecución del algoritmo crece de forma cúbica a medida que aumenta la longitud de la cadena, lo cual concuerda con su complejidad teórica.

- En cadenas de menor tamaño, el algoritmo se comporta de manera eficiente. Sin embargo, al incrementar la longitud, el tiempo de ejecución se incrementa drásticamente, lo que refleja su limitada escalabilidad.

- Esta tendencia sugiere que, si bien CYK es preciso y confiable, no es ideal para procesar grandes volúmenes de texto o aplicaciones que requieren respuestas en tiempo real sin aplicar optimizaciones.

## Resultados Bison:
Evaluando cadena con 100 a's y 100 b's
```
Cadena válida
Tiempo de ejecución: 0.000005 segundos
```
Evaluando cadena con 200 a's y 200 b's
```
Cadena válida
Tiempo de ejecución: 0.000011 segundos
```
Evaluando cadena con 400 a's y 400 b's
```
Cadena válida
Tiempo de ejecución: 0.000021 segundos
```
Evaluando cadena con 600 a's y 600 b's
```
Cadena válida
Tiempo de ejecución: 0.000026 segundos
```
Evaluando cadena con 800 a's y 800 b's
```
Cadena válida
Tiempo de ejecución: 0.000036 segundos
```
Evaluando cadena con 1000 a's y 1000 b's
```
Cadena válida
Tiempo de ejecución: 0.000048 segundos
```

![Image](https://github.com/user-attachments/assets/ce5a1e48-b19e-4e9d-b86e-b382db742393)

- El análisis con Bison es extraordinariamente rápido, con tiempos que apenas alcanzan milésimas de segundo incluso en cadenas largas. En comparación con CYK, Bison presenta un rendimiento varios órdenes de magnitud superior.

- La relación entre la longitud de la cadena y el tiempo de ejecución parece casi lineal, lo que es indicativo de una eficiencia mucho mayor en términos de complejidad computacional. Esto se debe a que Bison genera analizadores LL(1), LALR(1) u otros, según la gramática, permitiendo una ejecución optimizada en tiempo constante o casi lineal en muchos casos.

![Image](https://github.com/user-attachments/assets/e3a806c1-43d8-427a-9c4e-b8700de3046e)

- CYK presenta una curva ascendente pronunciada, con un crecimiento cercano al cúbico en el tiempo de ejecución. Esto concuerda con su complejidad teórica O(n^3), y se traduce en una ejecución que llega hasta los 35 segundos para cadenas de longitud 2000.

- Bison, en cambio, muestra un rendimiento sorprendentemente eficiente. Su tiempo de ejecución se mantiene en el orden de milisegundos, con un crecimiento prácticamente lineal respecto al tamaño de la entrada.

- El algoritmo CYK es útil en escenarios donde se necesita validar cualquier gramática libre de contexto sin restricciones.

- Por otro lado, Bison requiere una gramática más estructurada, pero ofrece un rendimiento enorme gracias a la generación de analizadores eficientes como LALR(1).

# Prueba 2: Manejo de Ambiguedades

Una gran diferencia entre ambos enfoques es el tratamiento de ambigüedad. Bison no permite ambigüedades directamente: al encontrar conflictos shift/reduce o reduce/reduce, obliga al programador a resolverlos con reglas de precedencia o reestructuración de la gramática. En cambio, CYK puede detectar y representar múltiples derivaciones válidas para una cadena ambigua.


# Otras Comparaciones

## Soporte Gramatical:
Bison admite gramáticas LALR(1), lo que significa que puede manejar una amplia gama de estructuras sintácticas sin requerir transformaciones específicas. Esto permite escribir reglas en notación BNF bastante natural. En cambio, CYK solo funciona con gramáticas en Forma Normal de Chomsky (CNF), lo que obliga a transformar la gramática original a una forma muy restringida (producciones binarias o terminales). Esta limitación puede hacer que el diseño de gramáticas para CYK sea más complejo y menos legible.

## Uso y Escalabilidad
Bison, en conjunto con Flex, ofrece una interfaz de desarrollo muy accesible. Solo es necesario describir la gramática y las acciones semánticas; el compilador genera automáticamente el parser. Bison escala bien en aplicaciones reales. Es utilizado en compiladores, intérpretes y analizadores, y puede manejar archivos de código fuente de miles de líneas sin problemas, gracias a su enfoque determinista y su ejecución lineal. CYK, al ser un algoritmo de fuerza bruta con complejidad cúbica respecto al tamaño de la entrada, no escala bien. Además, el algoritmo CYK requiere programación manual del parser, incluyendo estructuras para representar reglas, manejo de la tabla dinámica y lógica de evaluación
