number = int(input())

count = 0
temp = 0
remainder = 0

length = 0
while(number != 0):
    remainder = number % 10
    temp = temp * 10 + remainder 
    number = number // 10
    length += 1

while(temp != 0):
    remainder = remainder % 10
    temp = temp // 10
    length -= 1
    if(remainder < 6):
        count += 1
    elif(remainder == 6 and length == -1):
        print("-1")
        exit()

print(count)
