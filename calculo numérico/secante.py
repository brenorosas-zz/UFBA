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
    print("$X_0 = {:.10f}$, $f(X_0) = {:.10f}$".format(xa, f(xa)))
    print()
    print("$X_1 = {:.10f}$, $f(X_1) = {:.10f}$".format(xb, f(xb)))
    print()
    while(True):
        x = att(xa, xb)
        print("$X_{}{}{} = {:.10f}$, $f(X_{}{}{}) = {:.10f}$".format('{', it+1, '}', x, '{', it+1, '}', f(x)))
        print()
        if abs(f(x)) < precisao:
            print("$\overline{}X{} = {}$".format('{', '}', x))
            print()
            print("$f(\overline{}X{}) = {:.10f}$".format('{', '}', f(x)))
            print()
            ans = abs((f(ant) - f(x))/f(x))
            print("Erro em $x = {:.10f}$".format(ans))
            break
        xa = xb
        xb = x
        ant = x
        it += 1
print()
print(it, "iterações")