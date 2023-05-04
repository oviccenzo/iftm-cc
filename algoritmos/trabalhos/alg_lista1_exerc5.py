numero = int(input("Digite dois número: "))

soma_par = 0
contador_par = 0
soma_impar = 0
contador_impar = 0

while (numero > 0):
  if (numero % 2 == 0):
    soma_par = soma_par + numero
    contador_par = contador_par + 1
  else:
    soma_impar = soma_impar + numero
    contador_impar = contador_impar + 1
  numero = int(input("Digite um número: "))

#print("Resultado: ", soma_par,contador_par,soma_impar,contador_impar)      

print("Média dos números pares: ", soma_par/contador_par)
print("Média dos números ímpares: ", soma_impar/contador_impar)
print("Programa terminou!!!")
