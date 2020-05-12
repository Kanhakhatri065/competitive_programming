n, t =  input().split()

n = int(n)
t = int(t)

output = 0

if(n == 1 and t <= 10):
    output = t
elif(n == 1 and t == 10):
    output = -1
else:
    left = 1
    for i in range(n):
        left *= 10
    
    while(True):
        if(left % t == 0):
            output = t
            break
        left += 1

print(output)
