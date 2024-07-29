from itertools import product

limit = 99999999
primes=[]
is_prime = [True] * (limit+1)
is_prime[0] = is_prime[1] = False
for i in range(2, limit+1):
    if is_prime[i]:
        primes.append(i)
        for j in range(i*i, limit+1, i):
            is_prime[j] = False


def todos_prefijos_primos(cadena):
    for i in range(1, len(cadena) + 1):
        if int(cadena[:i]) not in primes:
            return False
    return True


def es_superprime_grid(grid):
    n = len(grid)
    m = len(grid[0])

    # Verificar filas
    for fila in grid:
        for i in range(1, m + 1):
            if not todos_prefijos_primos("".join(fila[:i])):
                return False
    
    # Verificar columnas
    for j in range(m):
        for i in range(1, n + 1):
            if not todos_prefijos_primos("".join(grid[k][j] for k in range(i))):
                return False
    
    return True


def contar_superprime_grids(n, m):
    digitos = '0123456789'
    contador = 0
    
    for grid in product(digitos, repeat=n*m):
        grid = [grid[i*m:(i+1)*m] for i in range(n)]
        if es_superprime_grid(grid):
            contador += 1
    
    return contador

print(contar_superprime_grids(3, 2))