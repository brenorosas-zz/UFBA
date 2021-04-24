def f(x):
    #Lembrar de mudar a função para cada questão
    return x**3 - x - 1

def phi(x):
    return (x+1)**(1/3)

x = float(input())
#Chute inicial = valor médio
precisao = input()
precisao = float(precisao)
it = 0
if abs(f(x)) < precisao:
    print("Raiz aproximada = {}".format(x))
else:
    it = 1
    while True:
        x = phi(x)
        if abs(f(x)) < precisao:
            print("{:.10f}".format(f(x)))
            print("Raiz aproximada = {}".format(x))
            erro = abs(1.3247179572447 - x)
            print("Erro: {:.10f}".format(erro))
            break 
        it += 1
print(it, "iterações")
    
