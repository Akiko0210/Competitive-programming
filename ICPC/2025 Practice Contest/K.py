s = input()
t = input()
snum = float(s)
tnum = float(t)
s1, s2 = [int(x) for x in s.split(".")]
t1, t2 = [int(x) for x in t.split(".")]
if snum > tnum:
    if s1 > t1 or (s1 == t1 and s2 > t2):
        print(snum)
    else:
        print(-1)
else:
    if s1 < t1 or (s1 == t1 and s2 < t2):
        print(tnum)
    else:
        print(-1)
