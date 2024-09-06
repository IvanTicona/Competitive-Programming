#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

pair<vi, vi> findEqualSubset(const vi &nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % 2 != 0) return {{}, {}};  // Si la suma total es impar, no es posible

    int target = totalSum / 2;
    int n = nums.size();

    vb dp(target + 1, false);
    dp[0] = true;

    unordered_map<int, int> parent;

    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            if (dp[j - num]) {
                dp[j] = true;
                parent[j] = num;
            }
        }
    }

    if (!dp[target]) return {{}, {}};  // No es posible formar dos subconjuntos iguales

    vi subset;
    vi remaining = nums;
    int sum = target;
    while (sum > 0) {
        int num = parent[sum];
        subset.push_back(num);
        sum -= num;
        remaining.erase(find(remaining.begin(), remaining.end(), num));
    }

    return {subset, remaining};
}

int main() {
    int n; cin >> n;
    vi nums(n);
    for (int &v : nums) cin >> v;

    auto [subset, remaining] = findEqualSubset(nums);

    if (subset.empty()) {
        cout << -1 << endl;
        return 0;
    }

    // Verificar que las sumas de los dos subconjuntos son iguales
    sort(subset.begin(), subset.end(), greater<int>());
    sort(remaining.begin(), remaining.end(), greater<int>());

    int sumSubset = accumulate(subset.begin(), subset.end(), 0);
    int sumRemaining = accumulate(remaining.begin(), remaining.end(), 0);

    if (sumSubset != sumRemaining) {
        cout << -1 << endl;
        return 0;
    }

    // Imprimir los elementos en el orden correcto
    while (!subset.empty() || !remaining.empty()) {
        if (!subset.empty()) {
            cout << subset.back() << " ";
            subset.pop_back();
        }
        if (!remaining.empty()) {
            cout << remaining.back() << " ";
            remaining.pop_back();
        }
    }
    cout << endl;

    return 0;
}
