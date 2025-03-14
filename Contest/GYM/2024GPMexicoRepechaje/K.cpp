#include<bits/stdc++.h>

using namespace std;

int n, m, O;
vector<int> ingredients;
vector<vector<pair<int, int>>> dishes;

bool availableDish(int d){
  vector<pair<int, int>> dish = dishes[d];
  for (auto &[I, q]: dish){
    if(ingredients[I]< q) return false;
    else ingredients[I] -= q;
  }
  return true;
}

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> n >> m >> O;

  ingredients.resize(n + 1);
  dishes.resize(m + 1);

  for(int i = 1; i <= n; i++) cin >> ingredients[i];

  for (int i = 1; i <= m; i++){
    int ni; cin >> ni;
    for (int j = 0; j < ni; j++){
      int I, q; cin >> I >> q;
      dishes[i].push_back({I, q});
    }
  }

  int cnt = 0;

  for (int i = 0; i < O; i++){
    int o; cin >> o;
    for (int j = 0; j < o; j++){
      int d; cin >> d;
      if(!availableDish(d)){
        cout << cnt << endl;
        return 0;
      }
    }
    cnt++;
  }

  cout << cnt << endl;

  return 0;
}