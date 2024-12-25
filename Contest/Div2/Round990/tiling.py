def tiling_3xn(n):
    if n % 2 == 1:  # Si N es impar, no se puede cubrir completamente
        return 0
    
    f = [0] * (n + 1)
    g = [0] * (n + 1)
    
    f[0] = 1  # Caso base
    f[1] = 0  # No es posible cubrir 3x1
    g[0] = 0  # No hay configuraciones parciales para tablero vacío
    
    g[1] = 1 # Correcion

    for i in range(2, n + 1):
        f[i] = f[i - 2] + 2 * g[i - 1]
        # g[i] = f[i - 1] + g[i - 1]
        g[i] = f[i - 1] + g[i - 2] # Correcion
    
    return f[n]

# Ejemplo
n = 6
print(tiling_3xn(n))  # Salida: 41
