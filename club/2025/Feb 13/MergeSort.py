def divide(a):
    m = len(a)
    if m == 1:
        return a

    b, c = [], []
    for i in range(m):
        if i < m // 2:
            b.append(a[i])
        else:
            c.append(a[i])

    b = divide(b)
    c = divide(c)

    return conquer(b, c)


def conquer(a, b):
    p1, p2 = 0, 0
    c = []
    while p1 < len(a) and p2 < len(b):
        if a[p1] < b[p2]:
            c.append(a[p1])
            p1 += 1
        else:
            c.append(b[p2])
            p2 += 1

    while p1 < len(a):
        c.append(a[p1])
        p1 += 1

    while p2 < len(b):
        c.append(b[p2])
        p2 += 1

    return c


# n = int(input())
numbers = list(map(int, input().split()))
print(divide(numbers))
