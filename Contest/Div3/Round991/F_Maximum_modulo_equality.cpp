#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = gcd(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftGCD = query(2 * node + 1, start, mid, l, r);
        int rightGCD = query(2 * node + 2, mid + 1, end, l, r);
        return gcd(leftGCD, rightGCD);
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> results;

        if (n > 1) {
            vector<int> diff(n - 1);
            for (int i = 0; i < n - 1; i++) {
                diff[i] = abs(a[i + 1] - a[i]);
            }

            SegmentTree segTree(diff);

            while (q--) {
                int l, r;
                cin >> l >> r;
                l--, r--;

                if (l == r) {
                    results.push_back(0);
                } else {
                    results.push_back(segTree.query(l, r - 1));
                }
            }
        } else {
            while (q--) {
                int l, r;
                cin >> l >> r;
                results.push_back(0);
            }
        }

        for (size_t i = 0; i < results.size(); i++) {
            if (i > 0) cout << " ";
            cout << results[i];
        }
        cout << '\n';
    }

    return 0;
}
