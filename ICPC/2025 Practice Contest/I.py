n, m = [int(x) for x in input().split()]
cnt = 0
for i in range(n):
    s = input()
    rem = m - len(s)
    l = rem // 2
    r = rem - l
    if l != r:
        if cnt % 2 == 1:
            temp = l
            l = r
            r = temp
        cnt += 1
    res = "." * l + s + "." * r
    print(res)
