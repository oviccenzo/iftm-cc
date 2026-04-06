# Entrada da altura
altura_metros = float(input("Digite sua altura em metros: ")) 

# Entrada do sexo
sexo = input("Digite o sexo por favor: (M-Masculino, F-Feminino: ) ") 

# Inicialização da variável
resultado = 0 

# Condição para Masculino
if (sexo == 'M'): 
    resultado = (72.7 * altura_metros) - 58 

# Condição para Feminino
if (sexo == 'F'): 
    resultado = (62.1 * altura_metros) - 44.7 

# Exibição do resultado
print("Resultado: ", resultado)
