n, m = [int(x) for x in input().split(' ')]
mat = [[0.0 for x in range(m)] for y in range(n)]
for i in range(n):
    j = 0
    for x in input().split():
        mat[i][j] = float(x)
        j += 1
for w in range(m - 1):
    pivot = m-w-2
    # print(pivot)
    # print(mat[pivot][m-w-2])
    for l in range(n-1-w):
        k = mat[l][m-w-2] / mat[pivot][m-w-2]
        for i in range(m):
            mat[l][i] -= k * mat[pivot][i]
    # for x in mat:
    #    print(x)
    # print()
# exit()
res = []
for i in range(n):
    ans = 0.0
    for j in range(0, i):
        ans += mat[i][j] * res[j]
    res.append((mat[i][m-1] - ans) / mat[i][i])
for v in res:
    print("%.6f" % v, end=' ')
print()
