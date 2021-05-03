import fractions

def Normalize(p, q):
    r = fractions.Fraction(p, q)
    return r.numerator, r.denominator

def FindElement(n):
    path = bin(n)[3:]
    p = q = 1
    for x in path:
        if x == '0':
            q += p
        else:
            p += q
    return p, q

def FindPosition(p, q):
    p, q = Normalize(p, q)
    b = ''
    while p != q:
        if p > q:
            p -= q
            b = '1' + b
        else: 
            q -= p
            b = '0' + b
    
    b = '1' + b
    return int(b, 2)

if __name__ == "__main__":
    testcases = int(input())
    for tt in range(1, testcases + 1):
        arr = list(map(int, input().split()))
        if len(arr) == 3:
            ans = FindPosition(arr[1], arr[2])
            print(f"Case #{tt}: {ans}", flush = True)
        else:
            p, q = FindElement(arr[1])
            print(f"Case #{tt}: {p} {q}", flush = True)