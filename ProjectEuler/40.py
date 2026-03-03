ans = 1
offset = 1
curr_upper_bound = 0
curr_digit_cnt = 0
total_digit_length = lambda x: x * 9 * 10 ** (x - 1)

while offset <= 1000000:
    while offset > curr_upper_bound:
        curr_digit_cnt += 1
        curr_upper_bound += total_digit_length(curr_digit_cnt)
    curr_lower_bound = curr_upper_bound - total_digit_length(curr_digit_cnt) + 1

    digit_offset = offset - curr_lower_bound
    num_offset = digit_offset // curr_digit_cnt
    num = 10 ** (curr_digit_cnt - 1) + num_offset
    digit = int(str(num)[digit_offset - num_offset * curr_digit_cnt])
    ans *= digit
    print(f"digit is {digit}")

    offset *= 10

print(ans)
