from itertools import permutations

def S(p):
    n = len(p)
    S = 0
    for l in range(n):
        current_min = float('inf')
        for r in range(l, n):
            current_min = min(current_min, p[r])
            S += current_min
    return S

def solve(N, k):
    all_permutations = list(permutations(range(1, N + 1)))
    S_values = [(S(p), p) for p in all_permutations]
    max_S = max(S for S, _ in S_values)
    max_permutations = [p for S, p in S_values if S == max_S]
    max_permutations.sort()
    if k <= len(max_permutations):
        return list(max_permutations[k - 1])
    else:
        return -1

t = int(input())
results = []

for _ in range(1, t + 1):
    n, k = map(int, input().split())
    result = solve(n, k)
    if result == -1:
        results.append("-1")
    else:
        results.append(" ".join(map(str, result)))

print("\n".join(results))