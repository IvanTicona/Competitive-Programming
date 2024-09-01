#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi transformBits(vi &nums){
  
  vi result(nums.size(), 0);

  // Iteramos por cada bit (asumiendo que trabajamos con enteros de 32 bits)
  for (int bit = 0; bit < 32; ++bit){
    int bitCount = 0;

    // Contamos los bits en la posición actual para todos los números
    for (int num : nums){
      if (num & (1 << bit)){
        ++bitCount;
      }
    }

    // Colocamos el bit en el resultado correspondiente a la posición del bit
    for (int i = 0; i < nums.size(); ++i){
      if (bitCount > 0){
        result[i] |= (1 << bit);
        --bitCount;
      }
    }
  }

  return result;
}

int main(){
  
  int N; cin>>N;
  vi nums(N);
  for (int &v: nums) cin>>v;

  vi result = transformBits(nums);
  for (int num : result) cout<<num<<" ";

  return 0;
}