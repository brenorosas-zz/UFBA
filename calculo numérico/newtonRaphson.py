def f(x):
    #Lembrar de mudar a função para cada questão
    return x**3 - x - 1

def df(x):
    #derivada da f(x)
    return 3*x**2 - 1

def att(x):
    return x - f(x)/df(x)

x = float(input())
precisao = input()
precisao = float(precisao)
#Chute inicial = valor médio
it = 0
if abs(f(x)) < precisao:
    print("Raiz aproximada = {}".format(x))
else:
    it = 1
    ant = 1
    while True:
        x = att(x)
        print(x)
        if abs(f(x)) < precisao:
            print("{:.10f}".format(f(x)))
            print("Raiz aproximada = {}".format(x))
            ans = abs((f(ant) - f(x))/f(x))
            print("Erro em x = {:.10f}".format(ans))
            break
        ant = x
        it += 1
print(it, "iterações")
    
