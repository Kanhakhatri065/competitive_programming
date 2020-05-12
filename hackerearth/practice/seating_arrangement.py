testcases = int(input())

for i in range(testcases):
    number = int(input())

    if number % 12 == 0:
        print(f"{number-11} WS")
    elif number% 12 == 1:
        print(f"{number + 11} WS")
    elif number% 12 == 2:
        print(f"{number + 9} MS")
    elif number % 12 == 3:
        print(f"{number + 7} AS")
    elif number % 12 == 4:
        print(f"{nubmer + 5} AS")
    elif number % 12 == 5:
        print(f"{number + 3} MS")
    elif number % 12 == 6:
        print(f"{number + 1} WS")
    elif number % 12 == 7:
        print(f"{number - 1} WS")
    elif number % 12 == 8:
        print(f"{number - 3} MS")
    elif number % 12 == 9:
        print(f"{number - 5} AS")
    elif number % 12 == 10:
        print(f"{number - 7} AS")
    elif number % 12 == 11:
        number(f"{number - 9} MS")