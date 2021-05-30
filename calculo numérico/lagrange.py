def L(k, val, x, y):
    up = 1
    down = 1
    n = len(x)
    for i in range(n):
        if i != k:
            up *= (val - x[i])
    for i in range(n):
        if i != k:
            down *= (x[k] - x[i])
    return up/down


def main():
    x = [float(i) for i in input().split(' ')]
    y = [float(i) for i in input().split(' ')]
    n = len(x)
    Px = float(input())
    ans = 0.0
    for i in range(n):
        ans += y[i] * L(i, Px, x, y)
    print(ans)


main()
