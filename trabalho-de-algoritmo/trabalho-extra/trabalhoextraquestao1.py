pessoas = []  # Cria uma lista vazia para armazenar os dicionários de pessoas.
while True:  # Inicia um loop infinito.
    nome = "pessoa" + str(len(pessoas) + 1)  # Cria uma string com o nome da pessoa.
    salario = input("Digite o salário de " + nome + ": ")  # Solicita o salário da pessoa ao usuário.

    if float(salario) < 0:  # Verifica se o salário é negativo.
        print("Salário inválido. Saindo do programa.")  # Imprime uma mensagem de erro.
        break  # Sai do loop.
    filhos = input("Digite o número de filhos de " + nome + ": ")  # Solicita o número de filhos da pessoa ao usuário.
    pessoas.append({"nome": nome, "salario": salario, "filhos": filhos})  # Adiciona um dicionário com as informações da pessoa à lista.

salarios = [float(pessoa["salario"]) for pessoa in pessoas]  # Cria uma lista com os salários das pessoas.
media_salarios = sum(salarios) / len(salarios)  # Calcula a média dos salários.

filhos = [int(pessoa["filhos"]) for pessoa in pessoas]  # Cria uma lista com o número de filhos das pessoas.
media_filhos = sum(filhos) / len(filhos)  # Calcula a média do número de filhos.

maior_salario = max(salarios)  # Encontra o maior salário da lista.
percentual_salario_ate_100 = len([s for s in salarios if s <= 100]) / len(salarios) * 100  # Calcula o percentual de pessoas com salário até R$100.

print("A média dos salários é:", media_salarios)  # Imprime a média dos salários na tela.
print("A média do número de filhos é:", media_filhos)  # Imprime a média do número de filhos na tela.
print("O maior salário é:", maior_salario)  # Imprime o maior salário na tela.
print(f"O percentual de pessoas com salário até R$100 é: {percentual_salario_ate_100:.2f}%")  # Imprime o percentual de pessoas com salário até R$100 na tela.
