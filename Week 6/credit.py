def get_int():
    while True:
        try:
            return int(input("Number: "))
        except ValueError:
            pass


def check(num):
    digits = [int(digit) for digit in str(num)]
    count = 1
    sum1 = 0
    sum2 = 0
    for i in reversed(digits):
        if count % 2 == 0:
            doubled_digit = i * 2
            sum2 += doubled_digit // 10 + doubled_digit % 10
        else:
            sum1 += i
        count += 1
    total_sum = sum1 + sum2
    if len(digits) in [15, 16, 13]:
        if total_sum % 10 == 0:
            return True
    return False


x = get_int()
if check(x):
    if str(x)[:2] in ['34', '37']:
        print("AMEX")
    elif str(x)[0] == '4':
        print("VISA")
    elif 51 <= int(str(x)[:2]) <= 55:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")