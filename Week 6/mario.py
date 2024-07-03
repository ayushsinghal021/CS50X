def get_int():
    while True:
        try:
            return int(input("Height: "))
        except ValueError:
            pass

while True:
    x = get_int()
    if x > 0 and x < 9:
        break


for i in range(x):
    print(" " * (x-i-1), end="")
    print("#" * (i+1), end="")
    print("  " , end="")
    print("#" * (i+1), end="")
    print()