#include <bits/stdc++.h>

using namespace std;

// CoinPos, DiffGoingintoit
int numCoins;
int lowestDiff[100][100 * 500];
int coins[100];

int GetBest(int coin, int diff){
  if (coin == numCoins)
    return diff;

  int &bestDiff = lowestDiff[coin][diff];

  if (bestDiff == -1){
    bestDiff = min(GetBest(coin + 1, diff + coins[coin]),
                   GetBest(coin + 1, abs(diff - coins[coin])));
  }

  return bestDiff;
}

int main(){
  
  int t;
  cin>>t;
  
  while (t--){
    cin>>numCoins;
    int maxSum = 500 * numCoins;
    
    for (int i = 0; i < numCoins; i++){
      for (int j = 0; j < maxSum; j++){
        lowestDiff[i][j] = -1;
      }
    }
    
    cout<<GetBest(0, 0)<<endl;
  }
}