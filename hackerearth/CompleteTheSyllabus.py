import sys

t = int(sys.stdin.readline().strip())

days = ["MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY"]


for i in range(t):
    k = int(sys.stdin.readline().strip())
    A = [int(x) for x in sys.stdin.readline().strip().split()]
    p = sum(A)

    if(k%p == 0):
        ans = 6
        while(A[ans] == 0):
            ans -= 1
        sys.stdout.write("%s\n"%(days[ans]))
        continue
    k = k%p
    kk = 0
    while True:
        k = k-A[kk]
        if(k<=0):
            sys.stdout.write("%s\n"%(days[kk]))
            break
        kk+=1