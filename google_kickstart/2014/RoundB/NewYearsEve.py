from math import *
from bisect import *

def wine(b, l, n):
    num = b * 3
    sum = 0

    left = [[750 * b]]
    bis = [0]

    for i in range(1, l):
        tmp = [[0 for ii in range(0, i + 1)] for jj in range(0, i + 1)]
        for j in range(0, i):
            for k in range(0, j + 1):
                tmp[j][k] += max(float((left[j][k] - 250) / 3), 0)
                tmp[j + 1][k] += max(float((left[j][k] - 250) / 3), 0)
                tmp[j + 1][k + 1] += max(float((left[j][k] - 250) / 3), 0)
        
        left = tmp
        bis.append(i * (i + 1) / 2)
    
    addr = bisect(bis, n - 1)
    return min(left[addr - 1][n - 1 - (addr * (addr - 1) // 2)], 250)

testcases = int(input())

for cases in range(1, testcases + 1):
    b, l, n = map(int, input().split())
    res = wine(b, l, n)

    print("Case #%d: %.7f"%(cases, res))
