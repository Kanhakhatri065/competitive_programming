import math
n = int(input())
cnt = 0
for _ in range(n):
    arr = input()
    a = list(map(int, arr.split(' ')))
    x = a[0]
    y = a[1]
    xx = a[2]
    xy = a[3]
    xxx = a[4]
    xxy = a[5]

    p = (x - xx) * (x - xx) + (y - xy)  * (y - xy)
    q = (x - xxx) * (x - xxx) + (y - xxy) * (y - xxy)
    r = (xx - xxx) * (xx - xxx) + (xy - xxy) * (xy - xxy)
    l = []
    l.append(p)
    l.append(q)
    l.append(r)
    l.sort()

    if l[0] + l[1] == l[2]:
        cnt += 1
print(cnt)
