MOD = 10**9 + 7
MAX_V = 10**6

# Criba de Eratóstenes para obtener los factores primos de cada número hasta MAX_V
def sieve_factors(limit):
    factors = [[] for _ in range(limit+1)]
    for i in range(2, limit+1):
        if not factors[i]:
            for j in range(i, limit+1, i):
                factors[j].append(i)
    return factors

# Exponentiation to calculate 2^n % MOD efficiently
def mod_exp(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

# Preprocesar los platos para obtener las combinaciones válidas según factores primos
def preprocess_food_combinations(N, V, factors):
    # Mapa de cada conjunto de factores primos y el número de alimentos que no contienen esos factores
    valid_combinations = {}
    
    # Calcula todas las posibles combinaciones de exclusión de factores
    for mask in range(1, 1 << len(factors)):  # Todas las posibles combinaciones de factores
        excluded_foods = set()
        for i in range(len(V)):
            food = V[i]
            for j in range(len(factors)):
                if (mask >> j) & 1:  # Si el j-ésimo factor está en la máscara
                    if factors[food]:
                        excluded_foods.add(food)
                        break
        
        # Calculamos cuántas combinaciones de alimentos son válidas excluyendo 'excluded_foods'
        valid_combinations[mask] = mod_exp(2, N - len(excluded_foods), MOD)
    
    return valid_combinations

# Consulta por persona, usando el preprocesamiento
def query_allergies(X, Q, valid_combinations, factors):
    results = []
    
    for x in X:
        bad_foods_mask = 0
        bad_ingredients = factors[x]
        
        # Crear una máscara para identificar los factores alérgenos de la persona
        for ingredient in bad_ingredients:
            bad_foods_mask |= (1 << ingredient)
        
        # Obtener el número de combinaciones válidas desde el preprocesamiento
        results.append(valid_combinations.get(bad_foods_mask, 0))
    
    return results

# Input processing
N = int(input())  # Número de alimentos
V = list(map(int, input().split()))  # Valores de los alimentos
Q = int(input())  # Número de consultas
X = [int(input()) for _ in range(Q)]  # Alergias de cada persona

# Preprocesar factores primos de los alimentos
factors = sieve_factors(MAX_V)

# Preprocesar todas las combinaciones posibles de alimentos válidos
valid_combinations = preprocess_food_combinations(N, V, factors)

# Responder consultas
results = query_allergies(X, Q, valid_combinations, factors)

# Imprimir los resultados
for res in results:
    print(res)
