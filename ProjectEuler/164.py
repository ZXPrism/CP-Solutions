from functools import cache


@cache
def dfs(kth_digit: int, prev_3_digits: int) -> int:
    if kth_digit == 20:
        return 1
    start = 0 if kth_digit != 0 else 1
    curr_res = 0
    d1 = prev_3_digits // 10 % 10
    d0 = prev_3_digits % 10
    for digit in range(start, 10):
        digit_sum = d0 + d1 + digit
        if digit_sum <= 9:
            curr_res += dfs(kth_digit + 1, d1 * 100 + d0 * 10 + digit)
    return curr_res


print(dfs(0, 0))


# follow up: what if n = 10^12 ?
# matrix exponentiation!
# any linear recurrence can be accelerated using matrix exponentiation!
