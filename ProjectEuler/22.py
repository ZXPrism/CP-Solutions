with open("./ProjectEuler/names-22.txt") as f:
    names = f.readline()
    names_arr = []
    n = len(names)

    left = 0
    while left < n:
        if not (names[left] >= "A" and names[left] <= "Z"):
            left += 1
            continue
        right = left + 1
        while right < n and names[right] >= "A" and names[right] <= "Z":
            right += 1
        names_arr.append(names[left:right])
        left = right

    names_arr.sort()
    n_names_arr = len(names_arr)
    print(
        sum(
            [
                (i + 1) * sum(map(lambda x: ord(x) & 31, names_arr[i]))
                for i in range(n_names_arr)
            ]
        )
    )
