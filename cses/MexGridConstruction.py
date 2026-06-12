n = int(input())

ans = [[0] * n for _ in range(n)]

for i in range(n):
    for j in range(n):
        s = set()
        for k in range(i):
            s.add(ans[k][j])

        for k in range(j):
            s.add(ans[i][k])

        for k in range(2 * n):
            if k not in s:
                ans[i][j] = k
                break

for row in ans:
    print(*row)
