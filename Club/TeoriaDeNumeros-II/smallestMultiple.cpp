// import sys
// import math
// from functools import reduce

// def lcm(a, b):
//     return a * b // math.gcd(a, b)

// def main():
//     for line in sys.stdin:
//         if not line.strip():
//             continue
//         nums = list(map(int, line.split()))
//         result = reduce(lcm, nums, 1)
//         print(result)

// if __name__ == "__main__":
//     main()