n = int(input())
k = int(input())

k -= 1
pure_nums = k * k
defaulter_nums = k

for i in range(3, n + 1):
    tmp = pure_nums
    tmp1 = defaulter_nums * k
    pure_nums = pure_nums * k + tmp1
    defaulter_nums = tmp

pure_nums += defaulter_nums
print(pure_nums)