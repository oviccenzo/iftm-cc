altura_metros = float(input("Digite sua altura em metros: "))
sexo = input("Digite o sexo por favor: (M-Masculino, F-Feminino) ")
resultado = 0
if (sexo == 'M'):
    resultado = (72.7 * altura_metros) - 58 
if (sexo == 'F'):
    resultado = (62.1 * altura_metros) - 44.7 


print("Resultado: ", resultado)
