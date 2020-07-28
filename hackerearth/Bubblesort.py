
N = int(input())
arr = [int(s) for s in input().split()]



swaps = 0
for i in range(N):
    for j in range(0, N - i - 1):
        if arr[j] > arr[j + 1]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]
            swaps += 1

print(swaps)