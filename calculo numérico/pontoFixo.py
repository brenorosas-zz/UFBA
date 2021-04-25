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
    ant = 1
    while True:
        x = phi(x)
        if abs(f(x)) < precisao:
            print("{:.10f}".format(f(x)))
            print("Raiz aproximada = {}".format(x))
            ans = abs((f(ant) - f(x))/f(x))
            print("Erro em x = {:.10f}".format(ans))
            break 
        ant = x
        it += 1
print(it, "iterações")
    
