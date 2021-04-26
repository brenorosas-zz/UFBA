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
    print("$X_0 = 1.0$, $f(X_0) = {}$".format(f(x)))
    print()
    while True:
        x = phi(x)
        print("$X_{} = \ varphi({}X_{}{}) = {}$, $f(X_{}) = {:.10f}$".format(it, '{',it - 1,'}', x, it, f(x)))
        print()
        if abs(f(x)) < precisao:
            print("$\overline{}X{} = {}$".format('{', '}', x))
            print()
            print("$f(\overline{}X{}) = {:.10f}$".format('{', '}', f(x)))
            print()
            ans = abs((f(ant) - f(x))/f(x))
            print("Erro em $x = {:.10f}$".format(ans))
            break 
        ant = x
        it += 1
print()
print(it, "iterações")
    
