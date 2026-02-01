r, c = [int(x) for x in input().split()]
cnt = 0
for i in range(r):
    s = input()
    rem = c - len(s)
    line = ""
    if rem % 2 == 0:
        line = s.center(c, ".")
    else:
        if cnt % 2 == 0:
            line = "." * (rem // 2) + s + "." * (rem - rem // 2)
        else:
            line = "." * (rem - rem // 2) + s + "." * (rem // 2)
        cnt += 1
    print(line)
