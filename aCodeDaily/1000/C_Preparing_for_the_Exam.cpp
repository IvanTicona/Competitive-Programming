/*
Author: Ivan Ticona
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

void solve(){

  ll n, m, k; cin >> n >> m >> k;
  
  vector<ll> ai(m), qi(k); rv(ai); rv(qi);
  ll mcount = n - k;
  string result;
  
  if(mcount == 0) result = string(m, '1'); // Conoce todas las preguntas
  else if(mcount == 1){
    ll no = 0;
    ll yes = 1;
    
    // Buscamos la pregunta que no conoce
    FOR(i, 0, k-1){
      if(qi[i] == yes) yes++;
      else{
        no = yes; // Encontro la pregunta que no conoce
        break;
      }
    }
    if(no == 0) no = n; // Conoce de 1 a n-1 preguntas entonces no conoce la n
    
    result.reserve(m);
    FOR(i, 0, m-1){
      if(ai[i] == no) result += '1';
      else result += '0';
    }
  }
  else result = string(m, '0'); // No conoce 2 o más preguntas
  
  cout << result << "\n";
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}