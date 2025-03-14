#include <bits/stdc++.h>

using namespace std;

void process(vector<int> &v, vector<int> costs, int order){
  vector<int> ans;
  //Impossible
  if (v[order] == -2){
    cout << "Impossible" << endl;
    return;
  }
  //Ambiguous
  if (v[order] == -1){
    cout << "Ambiguous" << endl;
    return;
  }
  //Orden de items
  while (order > 0){
    ans.push_back(v[order] + 1);
    order -= costs[v[order]];
  }
  //Orden fuera de rango
  if (order < 0){
    cout << "Ambiguous" << endl;
    return;
  }
  //Mostrar items ordenados
  {sort(ans.begin(), ans.end());
  for (auto i : ans){
    cout << i << " ";
  }
  cout << endl;}
}

int main(){
  // DP
  vector<int> v(32000, -2);
  v[0] = 0;
  // items
  int n;
  cin >> n;
  // costos/item
  vector<int> costs(n);
  for(auto &i : costs) cin >> i;
  
  // definir tipo de orden
  for (int i = 0; i < n; i++){
    int cost = costs[i];
    for (int j = 0; j <= 30000; j++){
      if (v[j] >= 0){
        if (v[j + cost] == -2){
          //aceptado
          v[j + cost] = i;
        }else{
          //ambiguo
          v[j + cost] = -1;
        }
      }
      if (v[j] == -1){
        //ambiguo
        v[j + cost] = -1;
      }
    }
  }

  // m
  int q;
  cin >> q;
  // costo de las ordenes
  for (int i = 0; i < q; i++){
    int order;
    cin >> order;
    // ver el tipo de orden
    process(v, costs, order);
  }
}