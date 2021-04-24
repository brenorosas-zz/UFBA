def f(x):
    return x**3 - x - 1

def att(xa, xb):
    return xb - (f(xb)*(xb - xa))/(f(xb) - f(xa))

xa, xb = [float(x) for x in input().split(' ')]
precisao = input()
precisao = float(precisao)
it = 0
if abs(f(xa)) < precisao:
    print("Raiz aproximada = {}".format(xa))
elif abs(f(xb)) < precisao:
    print("Raiz aproximada = {}".format(xb))
else:
    it = 1
    while(True):
        x = att(xa, xb)
        if abs(f(x)) < precisao:
            print("{:.10f}".format(f(x)))
            print("Raiz aproximada = {}".format(x))
            erro = abs(1.3247179572447 - x)
            print("Erro: {:.10f}".format(erro))
            break
        xa = xb
        xb = x
        it += 1
print(it, "iterações")