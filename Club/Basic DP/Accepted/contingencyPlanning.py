def factorial(n):
    if n == 0:
        return 1
    result = 1
    for i in range(1, n+1):
        result *= i
    return result

def count_permutations(n):
    if n == 0:
        return 0
    total = 0
    n_factorial = factorial(n)
    for k in range(1, n+1):
        total += n_factorial // factorial(n - k)
        if total > 10**9:
            return "JUST RUN!!"
    return total

n = int(input())
print(count_permutations(n))