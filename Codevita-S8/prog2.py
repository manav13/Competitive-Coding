def int_to_Roman(num):
    val = [
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4,
        1
    ]
    syb = [
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV",
        "I"
    ]
    roman_num = ''
    i = 0
    while num > 0:
        for _ in range(num // val[i]):
            roman_num += syb[i]
            num -= val[i]
        i += 1
    return roman_num


num = int(input())
if(num>=1 and num<=3999):
    while(num>=1 and num<=3999):
        roman = str(int_to_Roman(num))
        max=ord(roman[0])
        for i in range(len(roman)):
            if(max<ord(roman[i])):
                max = ord(roman[i])
        base = max - ord('A') + 11
        new_num = 0
        for i in range(len(roman)):
            r = roman[len(roman)-i-1]
            n1 = ord(roman[len(roman)-i-1]) - ord('A') + 10
            new_num = new_num + (n1*(base**i))
        num = new_num
    print(num)
else:
    print(num)