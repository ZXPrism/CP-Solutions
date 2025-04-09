import sys, heapq
from bisect import *
from collections import deque, Counter

input = sys.stdin.readline


def solve():
    n = int(input())

    N = 1000000
    primes = []
    spf = [i for i in range(N + 1)]
    for i in range(2, N + 1):
        if spf[i] == i:
            primes.append(i)
        for p in primes:
            if i * p > N:
                break
            spf[i * p] = p
            if i % p == 0:
                break

    ans = 0
    for i, p in enumerate(primes):
        if p**8 > n:
            ans += i
            break

    left, right = 0, len(primes) - 1
    sqr = int(n**0.5)
    while left < right:
        mul = primes[left] * primes[right]
        if mul > sqr:
            right -= 1
        else:
            ans += right - left
            left += 1

    print(ans)


solve()
