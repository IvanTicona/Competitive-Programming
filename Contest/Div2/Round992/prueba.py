from itertools import permutations

def calculate_S(p):
    n = len(p)
    S = 0
    for l in range(n):
        current_min = float('inf')
        for r in range(l, n):
            current_min = min(current_min, p[r])
            S += current_min
    return S

def find_kth_permutation_with_max_S(N, k):
    # Generar todas las permutaciones de [1, 2, ..., N]
    all_permutations = list(permutations(range(1, N + 1)))
    
    # Calcular S(p) para cada permutación
    S_values = [(calculate_S(p), p) for p in all_permutations]
    
    # Encontrar el valor máximo de S(p)
    max_S = max(S for S, _ in S_values)
    
    # Filtrar las permutaciones con S(p) == max_S
    max_permutations = [p for S, p in S_values if S == max_S]
    
    # Ordenar lexicográficamente las permutaciones con S(p) máximo
    max_permutations.sort()
    
    # Devolver la k-ésima permutación (1-based index), o -1 si no hay suficientes
    if k <= len(max_permutations):
        return list(max_permutations[k - 1])  # Convertir de tupla a lista para la salida
    else:
        return -1

# Ejemplo de uso:
N = 4
k = 6
print(find_kth_permutation_with_max_S(N, k))
