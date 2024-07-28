class SegmentTree:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (4 * n)
        self.lazy = [0] * (4 * n)

    def _push(self, v, tl, tr):
        if self.lazy[v] != 0:
            self.tree[v] += self.lazy[v] * (tr - tl + 1)
            if tl != tr:
                self.lazy[2 * v] += self.lazy[v]
                self.lazy[2 * v + 1] += self.lazy[v]
            self.lazy[v] = 0

    def _update_range(self, v, tl, tr, l, r, addend):
        self._push(v, tl, tr)
        if l > r:
            return
        if l == tl and r == tr:
            self.lazy[v] += addend
            self._push(v, tl, tr)
        else:
            tm = (tl + tr) // 2
            self._update_range(v * 2, tl, tm, l, min(r, tm), addend)
            self._update_range(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend)
            self.tree[v] = self.tree[v * 2] + self.tree[v * 2 + 1]

    def update_range(self, l, r, addend):
        self._update_range(1, 0, self.n - 1, l, r, addend)

    def _query(self, v, tl, tr, l, r):
        self._push(v, tl, tr)
        if l > r:
            return 0
        if l <= tl and tr <= r:
            return self.tree[v]
        tm = (tl + tr) // 2
        return self._query(v * 2, tl, tm, l, min(r, tm)) + self._query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)

    def query(self, l, r):
        return self._query(1, 0, self.n - 1, l, r)

def solve_penacony(t, test_cases):
    results = []
    for case in test_cases:
        n, m, friendships = case
        seg_tree = SegmentTree(n)
        seg_tree.update_range(0, n - 1, 1)  # Inicialmente activamos todas las carreteras
        
        events = []
        for a, b in friendships:
            if a > b:
                events.append((a, 1))
                events.append((b, -1))
            else:
                events.append((a, 1))
                events.append((b, -1))
                events.append((0, 1))
                events.append((n - 1, -1))

        events.sort()
        active = 0
        last = 0
        for i in range(len(events)):
            pos, delta = events[i]
            seg_tree.update_range(last, pos - 1, -active)
            active += delta
            last = pos
        
        min_roads = n - seg_tree.query(0, n - 1)
        results.append(min_roads)
    return results

# Lectura de los datos de entrada
t = int(input())
test_cases = []
for _ in range(t):
    n, m = map(int, input().split())
    friendships = [tuple(map(int, input().split())) for _ in range(m)]
    test_cases.append((n, m, friendships))

# Resolución del problema
results = solve_penacony(t, test_cases)

# Impresión de los resultados
for res in results:
    print(res)
