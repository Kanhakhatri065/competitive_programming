from decimal import Decimal
from math import asin, pi

testcases = int(input())
for tt in range(1, testcases + 1):
    v, d = map(Decimal, input().split())
    angle = 90 * asin(Decimal(9.8) * d / (v * v)) / pi
    print(f"Case #{tt}: {angle:.7f}", flush = True)