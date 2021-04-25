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
    ant = 1
    while(True):
        x = att(xa, xb)
        if abs(f(x)) < precisao:
            print("{:.10f}".format(f(x)))
            print("Raiz aproximada = {}".format(x))
            ans = abs((f(ant) - f(x))/f(x))
            print("Erro em x = {:.10f}".format(ans))
            break
        xa = xb
        xb = x
        ant = x
        it += 1
print(it, "iterações")