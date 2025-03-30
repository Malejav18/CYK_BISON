def cyk_parser(grammar, start_symbol, string):
    n = len(string)
    if n == 0:
        return False
    
    table = [[set() for _ in range(n - i)] for i in range(n)]
    
    print("Inicializando tabla CYK:")
    for row in table:
        print(row)
    
    # Llenar la tabla para los caracteres individuales
    print("\nProcesando caracteres individuales:")
    for i, char in enumerate(string):
        for lhs, rhs in grammar.items():
            if (char,) in rhs:
                table[0][i].add(lhs)
                print(f"Caracter '{char}' en posición {i} se deriva de {lhs}")
    
    # Llenar la tabla para substrings más largas
    print("\nProcesando substrings más largas:")
    for length in range(2, n + 1):  # Longitud de la subcadena
        print(f"\nSubcadenas de longitud {length}:")
        for i in range(n - length + 1):  # Inicio de la subcadena
            for split in range(1, length):  # Punto de división
                left_cell = table[split - 1][i]
                right_cell = table[length - split - 1][i + split]
                print(f"Evaluando división en {i}-{i+split}: {left_cell} | {right_cell}")
                
                for lhs, rhs in grammar.items():
                    for rule in rhs:
                        if len(rule) == 2 and rule[0] in left_cell and rule[1] in right_cell:
                            table[length - 1][i].add(lhs)
                            print(f"Regla {lhs} -> {rule} aplicada en posición ({i}, {length - 1})")
    
    print("\nTabla CYK final:")
    for row in table:
        print(row)
    
    return start_symbol in table[-1][0]

# Definir la gramática en forma normal de Chomsky
cnf_grammar = {
    'S': [('A', 'B')],
    'A': [('B', 'C')],
    'B': [('b',)],
    'C': [('a',)]
}

# Cadena a evaluar
string = "bab"

# Ejecutar el algoritmo CYK
does_belong = cyk_parser(cnf_grammar, 'S', string)
print("\nLa cadena pertenece al lenguaje:", does_belong)
# Output esperado: True o False dependiendo de si la cadena pertenece al lenguaje definido por la gramática
