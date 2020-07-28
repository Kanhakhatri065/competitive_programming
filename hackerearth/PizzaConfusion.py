N = int(input())

u = ""
v = -1

for _ in range(N):
    a, b = input().split()
    b = int(b)
    if b > v or (b == v and a < u):
        u, v = a, b

print(u)