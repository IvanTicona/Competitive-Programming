#include<bits/stdc++.h>

using namespace std;

int main(){

  int n, x = 0;
  cin>>n;
  while (n--){
    string statement;
    cin>>statement;
    if(statement[0] == '+' || statement[statement.size()-1] == '+'){
      x++;
    } else if(statement[0] == '-' || statement[statement.size()-1] == '-'){
      x--;
    }
  }
  cout<<x<<endl;
  return 0;
}