#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXV = 1e6 + 5;

vector<int> prime_factors[MAXV];
bitset<MAXV> is_composite;

void sieve() {
    for (int i = 2; i < MAXV; i++) {
        if (!is_composite[i]) {
            for (int j = i; j < MAXV; j += i) {
                is_composite[j] = 1;
                prime_factors[j].push_back(i);
            }
        }
    }
}

int mod_pow(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (1LL * result * base) % mod;
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    sieve();

    int N;
    cin >> N;
    vector<int> foods(N);
    unordered_map<int, int> food_count_by_prime;

    for (int i = 0; i < N; i++) {
        cin >> foods[i];
        unordered_set<int> unique_primes(prime_factors[foods[i]].begin(), prime_factors[foods[i]].end());
        for (int p : unique_primes) {
            food_count_by_prime[p]++;
        }
    }

    int total_combinations = mod_pow(2, N, MOD);

    int Q;
    cin >> Q;
    while (Q--) {
        int X;
        cin >> X;

        unordered_set<int> allergy_primes(prime_factors[X].begin(), prime_factors[X].end());

        int invalid_combinations = 0;
        int num_subsets = 1 << allergy_primes.size();
        vector<int> primes(allergy_primes.begin(), allergy_primes.end());

        for (int mask = 1; mask < num_subsets; mask++) {
            int count = 0;
            int lcm_count = N;
            for (int i = 0; i < primes.size(); i++) {
                if (mask & (1 << i)) {
                    lcm_count -= food_count_by_prime[primes[i]];
                    count++;
                }
            }
            int contribution = mod_pow(2, lcm_count, MOD);
            if (count % 2 == 1) {
                invalid_combinations = (invalid_combinations + contribution) % MOD;
            } else {
                invalid_combinations = (invalid_combinations - contribution + MOD) % MOD;
            }
        }

        int safe_combinations = (total_combinations - invalid_combinations + MOD) % MOD;
        cout << safe_combinations << endl;
    }

    return 0;
}
