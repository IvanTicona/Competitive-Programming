#include <bits/stdc++.h>

using namespace std;

int main(){

  int B;
  cin>>B;

  vector<string> digits(B);
  map<string, int> alienToDecimal;

  for (int i = 0; i < B; i++){
    cin>>digits[i];
    alienToDecimal[digits[i]] = i;
  }

  string X;
  cin>>X;

  vector<int> number;
  int pos = 0;

  while (pos < X.size()){
    for (int len = 1; len <= 10; len++){
      string sub = X.substr(pos, len);
      if (alienToDecimal.find(sub) != alienToDecimal.end()){
        number.push_back(alienToDecimal[sub]);
        pos += len;
        break;
      }
    }
  }

  long long result = 0;
  long long basePower = 1;

  for (int i = number.size() - 1; i >= 0; i--){
    result += number[i] * basePower;
    basePower *= B;
  }

  cout<<result<<endl;

  return 0;
}
