def same_signal(a, b):
    if a > 0 and b > 0:
        return True
    if a < 0 and b < 0:
        return True
    return False


def f(x):
    return x*x*x - 9*x + 3


a, b = [float(x) for x in input().split(' ')]
while True:
    m = (a+b)/2
    print("$a = {}$, $b = {}$, $\overline(x) = {}$, $f(\overline(x)) = {}$".format(
        a, b, m, f(m)))
    print()
    if abs(f(m)) < 0.002:
        print("Raiz aproximada = {}".format(m))
        break
    if same_signal(f(m), f(a)):
        a = m
    else:
        b = m
