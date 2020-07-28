number = int(input())

arr = [None] * 10


for i in range(10):
    arr[i] = 0


while(number != 0):
    remainder = number % 10
    arr[remainder] += 1
    number = number // 10

for i in range(10):
    print(f"{i} {arr[i]}")
