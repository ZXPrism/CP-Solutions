w1 = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
w2 = [
    "",
    "ten",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
]
w2_x = [
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
]

w1 = list(map(len, w1))
w2 = list(map(len, w2))
w2_x = list(map(len, w2_x))

ans = 11 + sum(w1) + sum(w2_x)

for i in range(20, 1000):
    if i % 100 < 10:
        ans += w1[i % 100]
    elif i % 100 < 20:
        ans += w2_x[i % 100 - 10]
    else:
        ans += w2[i // 10 % 10] + w1[i % 10]

    if i >= 100:
        ans += 7 + w1[i // 100]
        if i % 100 != 0:
            ans += 3
print(ans)
