def newton(x, y, z):
    m = len(x)
    dely = []
    for i in range(m):
        dely.append(y[i])

    for k in range(m - 1):
        for i in range(m-1, k, -1):
            dely[i] = (dely[i] - dely[i-1])/(x[i]-x[i-k-1])
    r = dely[m-1]
    for i in range(m-2, -1, -1):
        r = r*(z-x[i])+dely[i]
    return r


def main():
    x = [float(i) for i in input().split(' ')]
    y = [float(i) for i in input().split(' ')]
    n = len(x)
    val = float(input())
    print(newton(x, y, val))


main()
