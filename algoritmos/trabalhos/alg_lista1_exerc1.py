horas_trabalhadas = int(input("quantas horas trabalhada: ")) 
salario = 0 

if (horas_trabalhadas <= 40):
    salario = horas_trabalhadas * 8
else:
    salario = 320 + (horas_trabalhadas * 12)

print("Número de horas trabalhadas: ", horas_trabalhadas)
print("Salário semanal: ", salario)
# https://playground.ai.cloudflare.com/
