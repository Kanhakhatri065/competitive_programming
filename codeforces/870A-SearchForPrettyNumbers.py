##*** I came, I saw, I conquered. ***
import sys

n, m = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

for i in range(1, 10):
    if i in a and i in b:
        print(i)
        exit(0)

x = min(a)
y = min(b)

sys.stdout.write("%d%d"%(min(x, y), max(x, y)))
