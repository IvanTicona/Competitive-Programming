#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("extreme_test_cases.txt", "r", stdin);
  int n, m, q;
  cin >> n >> m >> q;
  vector<bool> has_a(2 * n + 1);
  vector<int64_t> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    has_a[a[i] + n] = true;
  }
  vector<bool> has_b(2 * m + 1);
  vector<int64_t> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    has_b[b[i] + m] = true;
  }
  auto sa = accumulate(a.begin(), a.end(), int64_t(0));
  auto sb = accumulate(b.begin(), b.end(), int64_t(0));
  while (q--) {
    bool found = false;
    auto Test = [&](int64_t x, int64_t y) {
      auto need_a = sa - x + n;
      auto need_b = sb - y + m;
      if (0 <= need_a && need_a <= 2 * n && has_a[need_a]) {
        if (0 <= need_b && need_b <= 2 * m && has_b[need_b]) {
          found = true;
        }
      }
    };
    int64_t x;
    cin >> x;
    for (int64_t d = 1; d * d <= abs(x); d++) {
      if (x % d == 0) {
        Test(d, x / d);
        Test(-d, -(x / d));
        Test(x / d, d);
        Test(-(x / d), -d);
      }
    }
    cout << (found ? "YES" : "NO") << '\n';
  }
  return 0;
}
