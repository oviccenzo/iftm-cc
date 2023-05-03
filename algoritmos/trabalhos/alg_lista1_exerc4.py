nota = float(input("Digite a nota final: "))

while (nota >= 0.0 and nota <= 10.0):
    if (nota >= 7.0):
        print("Aprovado")
    elif (nota >= 4.0 and nota < 7.0):
        print("Em exame")
    elif (nota < 4.0):
        print("Reprovado")
    nota = float(input("Digite a nota final: "))          