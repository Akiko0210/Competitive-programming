t = int(input())

while t > 0:
    s = int(input())
    n = int(input())
    ans = 0
    while n > 0: 
        ans += n
        n //= 10

    print(ans)

    t -= 1