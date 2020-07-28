n,m = input().split(" ")
n = int(n)
m = int(m)
count = 1
for i in range(1,m+1):
    count = (count * i) % 1000000007
print(count)