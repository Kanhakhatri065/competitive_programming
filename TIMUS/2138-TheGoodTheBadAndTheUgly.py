from math import modf, pow

comp = input()
x = int(input())

def process():
    global x
    r = []
    if(x >= 256):
        while(x >= 256):
            x /= 256
            b, a = modf(x)
            x = a
            remainder = b * 256
            r.append(remainder)
        r.append(a)
    else:
        r.append(x)
    return r

out = 0
r = process()

if len(r) < 4:
    for i in range(4 - len(r)):
        r.append(0)

for i in range(len(r)):
    out = out + r[i] * pow(256, len(r) - (i + 1))

print(int(out))
