st = input()

lst = []

count = 1
for i in range(len(st) - 1):
    if(st[i] != st[i+1]):
        count += 1
    else:
        lst.append(count)
        count=1
        continue
    lst.append(count)
print(max(lst))
