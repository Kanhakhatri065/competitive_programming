n,a,b = map(int, input().split())
ar = input().split(' ')
ar = [int(i)for i in ar]
s = sum(ar)
first = ar.pop(0)
ar = sorted(ar)
i = 1
blocked = 0
while((first*a)/s <b):
    s-=ar[-i]
    i+=1
    blocked +=1
    
print(blocked)