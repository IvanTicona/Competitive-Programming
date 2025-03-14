# Segment Tree

```
class SegmentTree:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (4 * n)
        self.lazy = [0] * (4 * n)

    def build(self, a):
        def build_tree(node, start, end):
            if start == end:
                self.tree[node] = a[start]
            else:
                mid = (start + end) // 2
                build_tree(2 * node, start, mid)
                build_tree(2 * node + 1, mid + 1, end)
                self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]

        build_tree(1, 0, self.n - 1)

    def update(self, l, r, val):
        def update_tree(node, start, end, l, r, val):
            if self.lazy[node] != 0:
                self.tree[node] += (end - start + 1) * self.lazy[node]
                if start != end:
                    self.lazy[2 * node] += self.lazy[node]
                    self.lazy[2 * node + 1] += self.lazy[node]
                self.lazy[node] = 0

            if start > end or start > r or end < l:
                return

            if start >= l and end <= r:
                self.tree[node] += (end - start + 1) * val
                if start != end:
                    self.lazy[2 * node] += val
                    self.lazy[2 * node + 1] += val
                return

            mid = (start + end) // 2
            update_tree(2 * node, start, mid, l, r, val)
            update_tree(2 * node + 1, mid + 1, end, l, r, val)
            self.tree[node] = self.tree[2 * node] + self.tree[2 * node + 1]

        update_tree(1, 0, self.n - 1, l, r, val)

    def query(self, l, r):
        def query_tree(node, start, end, l, r):
            if start > end or start > r or end < l:
                return 0

            if self.lazy[node] != 0:
                self.tree[node] += (end - start + 1) * self.lazy[node]
                if start != end:
                    self.lazy[2 * node] += self.lazy[node]
                    self.lazy[2 * node + 1] += self.lazy[node]
                self.lazy[node] = 0

            if start >= l and end <= r:
                return self.tree[node]

            mid = (start + end) // 2
            p1 = query_tree(2 * node, start, mid, l, r)
            p2 = query_tree(2 * node + 1, mid + 1, end, l, r)
            return p1 + p2

        return query_tree(1, 0, self.n - 1, l, r)
```
# Usage

```python
a = [1, 3, 5, 7, 9, 11]
n = len(a)
st = SegmentTree(n)
st.build(a)
st.update(0, 2, 10)
print(st.query(0, 2)) # Output: 26
```

# Time Complexity

- `build` operation: O(n)
- `update` operation: O(log n)
- `query` operation: O(log n)

# Space Complexity

- O(n) where n is the number of elements in the input array.