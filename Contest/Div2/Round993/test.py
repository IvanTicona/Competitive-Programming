import random

# Generate test cases
n = 200000
m = 200000
q = 50000

# Large alternating values for a and b
a = [random.choice([1, 1000000000]) for _ in range(n)]
b = [random.choice([2, 500000000]) for _ in range(m)]

# Random queries, some achievable, some not
queries = [random.randint(1, 10**9) if i % 2 == 0 else random.randint(-10**9, -1) for i in range(q)]

# Write to file
with open("extreme_test_cases.txt", "w") as f:
    f.write(f"{n} {m} {q}\n")
    f.write(" ".join(map(str, a)) + "\n")
    f.write(" ".join(map(str, b)) + "\n")
    f.write("\n".join(map(str, queries)) + "\n")
