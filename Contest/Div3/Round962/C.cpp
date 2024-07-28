#include <bits/stdc++.h>

using namespace std;

int diffStrings(const string& a, const string& b, int l, int r) {
    vector<int> count(26, 0);

    for (int i = l; i <= r; ++i) {
        count[a[i] - 'a']++;
        count[b[i] - 'a']--;
    }

    int total_operations = 0;
    for (int i = 0; i < 26; ++i) {
        total_operations += abs(count[i]);
    }

    return total_operations;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            cout << diffStrings(a, b, l - 1, r - 1) / 2 << endl;
        }
    }

    return 0;
}
