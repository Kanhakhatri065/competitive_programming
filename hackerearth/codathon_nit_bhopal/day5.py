from sys import stdin,stdout

testcases = int(stdin.readline())

for i in range(testcases):
    total_coins = int(stdin.readline())

    chance = 0
    j = 1
    
    while total_coins != 0:
        if((j >=1 and j<= total_coins) and (j & total_coins == 0)):
            total_coins -= j
            j = 0
            chance += 1

        if((j == total_coins) and (j & total_coins != 0)):
            break
        j += 1

    if(chance % 2 == 0):
        print("Pranshu")
    else:
        print("Jatin")