
n,t,k,d = map(int,input().split())
    
    
tempo = 0
bolos = 0
tempo2 = 0
bolos2 = 0
    
while bolos < n:
    tempo += t
    bolos += k
    
tempo2 += d
    
bolos2 += (d//t) * k
    
k += k
    
while bolos2 < n:
    tempo2 += t
    bolos2 += k
    
if tempo2 >= tempo:
    print("NO")
    
else:
    print("YES")