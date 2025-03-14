# n = 79999999  # 8 dígitos
# ignore = {1, 4, 6, 8, 9}
#
# primes = []
# is_prime = [True] * (n + 1)
# is_prime[0] = is_prime[1] = False
# for i in range(2, n + 1):
#     if is_prime[i]:
#         if not int(str(i)[0]) in ignore:
#             primes.append(i)
#         for j in range(i * i, n + 1, i):
#             is_prime[j] = False
#
# prime_set = set(primes)
# def is_superprime(num):
#     while num > 0:
#         if not num in prime_set:
#             return False
#         num //= 10
#     return True
#
# superprimes = []
# for prime in primes:
#     if is_superprime(prime):
#         superprimes.append(prime)
# for superprime in superprimes:
#     print(superprime)

#Precalculado
superprimes = [2,
  3,
  5,
  7,
  23,
  29,
  31,
  37,
  53,
  59,
  71,
  73,
  79,
  233,
  239,
  293,
  311,
  313,
  317,
  373,
  379,
  593,
  599,
  719,
  733,
  739,
  797,
  2333,
  2339,
  2393,
  2399,
  2939,
  3119,
  3137,
  3733,
  3739,
  3793,
  3797,
  5939,
  7193,
  7331,
  7333,
  7393,
  23333,
  23339,
  23399,
  23993,
  29399,
  31193,
  31379,
  37337,
  37339,
  37397,
  59393,
  59399,
  71933,
  73331,
  73939,
  233993,
  239933,
  293999,
  373379,
  373393,
  593933,
  593993,
  719333,
  739391,
  739393,
  739397,
  739399,
  2339933,
  2399333,
  2939999,
  3733799,
  5939333,
  7393913,
  7393931,
  7393933,
  23399339,
  29399999,
  37337999,
  59393339,
  73939133]

superprime_set = set(superprimes)

def is_superprime(num):
    return num in superprime_set

# Función para generar todas las cuadrículas posibles utilizando backtracking
def generate_grids(n, m, grid, row, col):
    if row == n:
        return 1  # Cuadrícula completa y válida

    if col == m:
        return generate_grids(n, m, grid, row + 1, 0)  # Moverse a la siguiente fila

    count = 0
    for digit in range(1, 10):  # Dígitos del 1 al 9
        grid[row][col] = digit

        # Construir prefijos de la fila y columna actual
        row_prefix = int(''.join(map(str, grid[row][:col + 1])))
        col_prefix = int(''.join(map(str, [grid[i][col] for i in range(row + 1)])))

        if is_superprime(row_prefix) and is_superprime(col_prefix):
            count += generate_grids(n, m, grid, row, col + 1)  # Moverse a la siguiente columna

        grid[row][col] = 0  # Restaurar el valor

    return count

# Contar superprimos en N x M
def count_superprime_grids(n, m):
    grid = [[0] * m for _ in range(n)]
    return generate_grids(n, m, grid, 0, 0)

# Entrada de datos
n, m = map(int, input().split())
print(count_superprime_grids(n, m))
