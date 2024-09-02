#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vi findSubset(vi &nums){

  int totalSum = accumulate(nums.begin(), nums.end(), 0);
  if (totalSum % 2 != 0) return {};

  int target = totalSum / 2;
  int n = nums.size();

  // Crear un vector dp de tamaño (target + 1) inicializado a false
  vb dp(target + 1, false);
  dp[0] = true;

  // Crear un mapa para almacenar los elementos que llevan a la suma j
  unordered_map<int, int> parent;

  // Iterar sobre cada número en la lista
  for (int num : nums){
    // Actualizar dp[] desde el final hacia el principio para evitar el uso de un número más de una vez
    for (int j = target; j >= num; j--){
      if (dp[j - num]){
        dp[j] = true;
        parent[j] = num; // Guardar el número que lleva a la suma j
      }
    }
  }

  if (!dp[target]) return {};

  vi subset;
  int sum = target;
  while (sum > 0){
    int num = parent[sum];
    subset.push_back(num);
    sum -= num;
  }

  return subset;
}

int main(){

  // vi nums = {1, 12, 21, 23, 33, 34};
  // vi nums = {1, 2, 2, 3};
  vi nums = {1, 2, 2, 3, 6};
  vi subset = findSubset(nums);

  if(!subset.empty()){
    for (int num: subset) cout<<num<<" ";
  }else{
    cout<< -1<<endl;
  }

  return 0;
}
