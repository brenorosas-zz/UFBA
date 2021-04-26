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
if b - a < precisao:
    print("Raiz aproximada = {}".format((a + b)/2))
else:
    it = 1
    ant = 1
    while True:
        x = (a+b)/2
        print("$a = {:.9f}$, $b = {:.9f}$, $X_{}{}{} = {:.9f}$, $f(X_{}{}{}) = {:.9f}$".format(a, b, '{', it, '}', x, '{', it, '}', f(x)))
        print()
        # print("$a = {}$, $b = {}$, $\overline(x) = {}$, $f(\overline(x)) = {}$".format(a, b, m, f(m)))
        if abs(f(x)) < precisao:
            print("$\overline{}X{} = {}$".format('{', '}', x))
            print()
            print("$f(\overline{}X{}) = {:.10f}$".format('{', '}', f(x)))
            print()
            ans = abs((f(ant) - f(x))/f(x))
            print("Erro em $x = {:.10f}$".format(ans))
            break
        if same_signal(f(x), f(a)):
            a = x
        else:
            b = x
        ant = x
        it += 1
print()
print(it, "iterações")