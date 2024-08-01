import random
import string as sst

def main():
    n = int(input())
    for _ in range(n):
        t = int(input())
        string = input()
        removed = 0
        i = 0

        while i < t - 2:

            if i < t - 4 and string[i:i+5] == "mapie":
                removed += 1
                i += 5
                continue

            q = string[i:i+3]
            # print(q)
            if q == "map" or q == "pie":
                removed += 1
                i += 3
                continue
            i += 1
        print(removed)

main()