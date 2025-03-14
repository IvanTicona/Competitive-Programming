/*
Competitive Programming
A. The Game
Author: Ivan Ticona
Created: 30/12/2024 01:01 AM
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

struct Node {
  int u;
  int parent;
  bool post;
};

void solve(){
  int n; cin >> n;
  vvi adj(n+1, vi());
  FOR(i, 0, n-2){
    int a,b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  vb dp(n+1, false);
  stack<Node> s;
  s.push(Node{1, -1, false});
  while (!s.empty()) {
    Node current = s.top(); s.pop();
    if (!current.post) {
      s.push(Node{current.u, current.parent, true});
      for(auto &v: adj[current.u]){
        if(v != current.parent){
          s.push(Node{v, current.u, false});
        }
      }
    }else{
      if(adj[current.u].size() ==1 && current.u !=1){
        dp[current.u] = false;
      }
      else{
        bool win = false;
        for(auto &v: adj[current.u]){
          if(v != current.parent){
            if(!dp[v]){
              win = true;
              break;
            }
          }
        }
        dp[current.u] = win;
      }
    }
  }
  if(!dp[1]){
    cout << "O\n";
  }
  else{
    cout << "F\n";
  }
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}