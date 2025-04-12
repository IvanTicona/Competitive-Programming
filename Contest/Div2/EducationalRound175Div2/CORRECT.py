def solve():
    import sys
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    it = iter(input_data)
    t = int(next(it))
    results = []
    for _ in range(t):
        n = int(next(it))
        k = int(next(it))
        s = next(it)
        p = [int(next(it)) for _ in range(n)]
        mx = max(p) if p else 0
        
        lo, hi, ans = 0, mx, mx
        
        def check(lim):
            cnt = 0
            i = 0
            while i < n:
                if s[i] == 'R' and p[i] > lim:
                    i += 1
                    continue
                need = False
                while i < n and not (s[i] == 'R' and p[i] > lim):
                    if s[i] == 'B' and p[i] > lim:
                        need = True
                    i += 1
                if need:
                    cnt += 1
                if cnt > k:
                    return False
            return True
        
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            if check(mid):
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1
        results.append(str(ans))
    
    sys.stdout.write("\n".join(results))

if __name__ == '__main__':
    solve()