/*
Competitive Programming
H. Harmonics with Interference
Author: Ivan Ticona
Created: 30/12/2024 09:28 PM
*/
#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define RFOR(i, a, b) for(int i = a; i >= b; i--)
#define FORP(i, a, b, c) for(int i = a; i <= b; i += c)
#define RFORP(i, a, b, c) for(int i = a; i >= b; i -= c)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define rv(x) for(auto &i: x) cin >> i
#define includes(x, y) x.find(y) != x.end()
#define fill(x, y) memset(x, y, sizeof(x))
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<char, int>> vci;

int compute_mod(const string &M, const int N) {
    int remainder = 0;
    for(const char bit : M){
        remainder = static_cast<int>((static_cast<long long>(remainder) * 2 + (bit - '0')) % N);
    }
    return remainder;
}

void solve(){

    string M_prime, N_prime;
    cin >> M_prime >> N_prime;

    vci star_positions;

    FOR(i, 0, M_prime.size()-1) {
        if(M_prime[i] == '*'){
            star_positions.emplace_back('M', i);
        }
    }

    for(int i = 0; i < N_prime.size(); ++i){
        if(N_prime[i] == '*'){
            star_positions.emplace_back('N', i);
        }
    }

    const size_t K = star_positions.size();

    if(K == 0){
        int N_int = 0;
        bool valid_N = false;
        for(const char c : N_prime){
            if(c != '0' && c != '1'){
                valid_N = false;
                break;
            }
            N_int = (N_int << 1) + (c - '0');
            if(c == '1') valid_N = true;
        }
        if(valid_N && N_int != 0){
            if(compute_mod(M_prime, N_int) == 0){
                cout << M_prime;
                return;
            }
        }
    }

    for(int comb = 0; comb < (1 << K); ++comb){
        string bits;
        for(int  b = static_cast<int>(K)-1; b >=0; --b){
            if(comb & (1 << b)){
                bits += '1';
            }
            else{
                bits += '0';
            }
        }

        string M = M_prime;
        string N = N_prime;

        for(int b = 0; b < K; ++b){
            const char bit = bits[b];
            const char string_id = star_positions[b].first;
            const int pos = star_positions[b].second;
            if(string_id == 'M'){
                M[pos] = bit;
            }
            else{
                N[pos] = bit;
            }
        }

        int N_int = 0;
        bool valid_N = false;
        for(const char c : N){
            if(c != '0' && c != '1'){
                valid_N = false;
                break;
            }
            N_int = (N_int << 1) + (c - '0');
            if(c == '1') valid_N = true;
        }
        if(!valid_N || N_int == 0){
            continue;
        }

        if(compute_mod(M, N_int) == 0){
            cout << M;
            return;
        }
    }
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  // int t; cin >> t;
  // while(t--){
    solve();
  // }

  return 0;
}