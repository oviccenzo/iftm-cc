numero_a = int(input("Digite o número A: "))
numero_b = int(input("Digite o número B: "))

contador = numero_a
resultado = numero_a

while (contador <= numero_b):
    if (contador == numero_a):
        contador = contador + 1
    else:  
        resultado = resultado + contador
        contador = contador + 1
    
print("Resultado: ", resultado)