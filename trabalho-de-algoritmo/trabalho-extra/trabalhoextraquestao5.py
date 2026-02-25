# Lê 20 valores para n
for i in range(20):
    n = int(input(f"Digite o valor {i+1} de n: "))
    print(f"\nTabuada do número {n}:")

    for j in range(1, n + 1):
        for k in range(1, 11):  # Tabuada do 1 ao 10 (padrão)
            print(f"{j} x {k} = {j * k}")
        print()  # Linha em branco entre tabuadas