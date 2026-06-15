import sys

n = int(sys.stdin.readline())


def dist(i, j):
    a, b = min(i, j), max(i, j)

    # Special case for 4x4 board
    if n == 4 and a == 0 and b == 3:
        return 5

    # Small-board / corner special cases
    if a == 0 and b == 0:
        return 0
    if a == 0 and b == 1:
        return 3
    if a == 1 and b == 1:
        return 4
    if a == 2 and b == 2:
        return 4

    moves = max((b + 1) // 2, (a + b + 2) // 3)  # ceil(b / 2)  # ceil((a + b) / 3)

    # Fix parity
    if (moves + a + b) % 2 == 1:
        moves += 1

    return moves


# Precompute strings to avoid calling str() 1,000,000 times
strs = [str(x) for x in range(2 * n + 10)]

out = []
for i in range(n):
    row = []
    for j in range(n):
        row.append(strs[dist(i, j)])
    out.append(" ".join(row))

sys.stdout.write("\n".join(out))
