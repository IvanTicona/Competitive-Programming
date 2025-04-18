/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define sz(x) (int)x.size()
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<ii> vii;

void solve(){
  string withoutVowels,word;
  cin>>word;
  FOR(i, 0, word.size()-1){
    if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
     word[i] == 'o' || word[i] == 'u' || word[i] == 'y' ||
      word[i] == 'A' || word[i] == 'E' || word[i] == 'I' ||
       word[i] == 'O' || word[i] == 'U' || word[i] == 'Y') continue;
    withoutVowels+='.';
    withoutVowels+=tolower(word[i]);
  }
  cout<<withoutVowels<<endl;
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  // int t; cin >> t;
  // while(t--){
    solve();
  // }

  return 0;
}