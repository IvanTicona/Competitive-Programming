#include<bits/stdc++.h>

using namespace std;


int dp[20][20];

int pesos = {};
int valores = {};
int capacidad;

// Tod Down
int knapSackTD(int remWeight, int i){
  if(i==capacidad) return 0;
  if (dp[remWeight][i] != -1) return dp[remWeight][i];

  if (pesos[i] <= remWeight) {
    return dp[remWeight][i] = max(valores[i] + knapSackTD(remWeight - pesos[i], i + 1), knapSackTD(remWeight, i + 1));
  } else {
    return dp[remWeight][i] = knapSackTD(remWeight, i + 1);
  }
}

int main(){

  

  return 0;
}