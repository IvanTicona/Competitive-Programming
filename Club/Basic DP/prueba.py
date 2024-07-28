ops = [' // ', ' * ', ' + ', ' - ']

values = {}

for op1 in ops:
    for op2 in ops:
        for op3 in ops:
            expr = f'4{op1}4{op2}4{op3}4'
            result = eval(expr)
            values[result] = expr.replace('//', '/') + f' = {result}'

t = int(input())

while t > 0:
    t -= 1
    n = int(input())
    
    if n in values:
        print(values[n])
    else:
        print('no solution')
