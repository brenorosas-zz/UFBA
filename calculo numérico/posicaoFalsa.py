def same_signal(a, b):
    if a > 0 and b > 0:
        return True
    if a < 0 and b < 0:
        return True
    return False

def f(x):
    #Lembrar de mudar a função para cada questão
    return x*x*x - x - 1

a, b = [float(x) for x in input().split(' ')]
precisao = input()
precisao = float(precisao)
it = 0
if abs(f(a)) < precisao:
    print("Raiz aproximada = {}".format(a))
elif abs(f(b)) < precisao:
    print("Raiz aproximada = {}".format(b))
else:
    it = 1
    while True:
        x = (a*f(b) - b*f(a))/(f(b) - f(a))
        # print("$a = {}$, f(a) = {}, $b = {}$, f(b) = {}, $\overline(x) = {}$, $f(\overline(x)) = {}$".format(a, f(a), b, f(b), m, f(m)))
        if abs(f(x)) < precisao:
            print("{:.10f}".format(f(x)))
            print("Raiz aproximada = {}".format(x))
            erro = abs(1.3247179572447 - x)
            print("Erro: {:.10f}".format(erro))
            break
        if same_signal(f(x), f(a)):
            a = x
        else:
            b = x
        it = it + 1
print(it, "iterações")
