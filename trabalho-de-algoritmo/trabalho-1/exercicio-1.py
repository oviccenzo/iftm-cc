# Entrada de dados
horas_trabalhadas = int(input("Quantas horas trabalhadas: "))
salario = 0

# Verificação de horas extras
if horas_trabalhadas <= 40:
    # Pagamento normal: 8 por hora
    salario = horas_trabalhadas * 8
else:
    # 320 é o valor fixo das primeiras 40 horas (40 * 8)
    # Calculamos 12 apenas sobre o que EXCEDER 40 horas
    horas_extras = horas_trabalhadas - 40
    salario = 320 + (horas_extras * 12)

# Exibição dos resultados
print("Número de horas trabalhadas: ", horas_trabalhadas)
print("Salário semanal: R$", salario)
