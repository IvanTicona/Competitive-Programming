#include <bits/stdc++.h>

using namespace std;

void findRoundNumbers(int n){
  vector<int> roundNumbers;

  int placeValue = 1;
  while (n > 0){
    int digit = n % 10;
    if (digit != 0){
      roundNumbers.push_back(digit * placeValue);
    }
    n /= 10;
    placeValue *= 10;
  }
  cout<<roundNumbers.size()<<endl;
  for (int num : roundNumbers){
    cout<<num<<" ";
  }
  cout<<endl;
}

int main(){
  int t;
  cin>>t;
  while (t--){
    int n;
    cin>>n;
    findRoundNumbers(n);
  }
  return 0;
}
