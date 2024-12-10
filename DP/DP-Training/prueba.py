from math import gcd
from collections import defaultdict

def count_valid_pairs(t, test_cases):
    results = []
    
    for n, points in test_cases:
        # Diccionario para conteo por direcciones
        direction_count = defaultdict(int)
        total_pairs = n * (n - 1) // 2  # Total de pares posibles
        
        # Procesar direcciones relativas
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]
                dx, dy = x2 - x1, y2 - y1
                g = gcd(dx, dy)
                dx //= g
                dy //= g
                direction_count[(dx, dy)] += 1

        # Restar pares inválidos
        invalid_pairs = sum(count * (count - 1) // 2 for count in direction_count.values())
        results.append(total_pairs - invalid_pairs)

    return results

# Lectura de entrada y ejecución
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    points = [tuple(map(int, input().split())) for _ in range(n)]
    test_cases.append((n, points))
print("Resultados: ")
# Salida
for result in count_valid_pairs(t, test_cases):
    print(result)
