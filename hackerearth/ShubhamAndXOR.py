from itertools import permutations

N = int(input())

a = list(map(int, input().split()))

per = permutations(list(range(N)), 2)

b = []

count = 0

for i in per:
    s = set(i)
    if len(s) < 2 or s in b:
        continue

    b.append(s)
    i, j = list(s)
    if a[i] ^ a[j] == 0:
        count += 1

print(count)