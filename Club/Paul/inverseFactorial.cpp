#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    long long mod = 1e9 + 7;
    long long ans = 0;

    for (int i = 0; i < s.size(); i++) {
        ans = (ans * 10 + (s[i] - '0')) % mod;
    }

    long long res = 1;
    for (long long i = 1; ; i++) {
        res = (res * i) % mod;
        if (res == ans) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}