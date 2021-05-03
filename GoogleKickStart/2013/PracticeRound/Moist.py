testcases = int(input())
for tt in range(1, testcases+1):
    n = int(input())
    names = [input() for index in range(n)]

    cnt = 0
    tmp = names[0]
    for name in names[1:]:
        if(name < tmp):
            cnt += 1
        else:
            tmp = name
    
    print(f"Case #{tt}: {cnt}", flush = True)