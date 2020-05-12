n = int(input())

matrix = [[None for y in range(n)] for x in range(n)]

for i in range(n):
    lst = [int(j) for j in input().split()]
    for j in range(n):
        matrix[i][j] = lst[j]

query = int(input())

for i in range(query):
    lst = [int(j) for j in input().split()]
    type = lst[0]
    a = lst[1]
    b = lst[2]
    c = lst[3]

    for j in range(a-1,b):
        matrix[j][j] = matrix[j][k] ^ c

    if type == 2:
            for k in range(a-1,b):
                matrix[j][k] = matrix[j][k] ^ c

sum = 0

for i in range(n):
    sum += matrix[i][i]

print(sum)