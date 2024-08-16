#include<bits/stdc++.h>

using namespace std;

int N;
int memo[1010][35];
int V[1010];
int W[1010];

//Index de objeto, Peso restante
int dp(int id, int remW) {
  if ((id == N) || (remW == 0)) return 0; // two base cases
  int &ans = memo[id][remW];
  if (ans != -1) return ans; // computed before
  if (W[id] > remW) return ans = dp(id+1, remW); // no choice, skip
  return ans = max(dp(id+1, remW), // has choice, skip
    V[id]+dp(id+1, remW-W[id])); // or take
}

int main(){

  int t; cin>>t;

  while (t--){
    memset(memo,-1,sizeof(memo));

    cin>>N; //Number objects
    for (int i = 0; i < N; i++){
      cin>>V[i]>>W[i];
    }
    int g; cin>>g; //People group
    int result=0;
    for (int i = 0; i < g; i++){
      int MG; cin>>MG;
      result+= dp(0,MG);
    }
    cout<<result<<endl;
  }

  return 0;
}