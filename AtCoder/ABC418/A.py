n = int(input())
s = input().strip()
if len(s) >= 3 and s[-1] == "a" and s[-2] == "e" and s[-3] == "t":
    print("Yes")
else:
    print("No")
