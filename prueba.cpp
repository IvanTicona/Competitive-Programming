
#include<bits/stdc++.h>

using namespace std;

int main(){
  
  map<int, bool> toys;
  for (int i = 0; i < 5; i++){
    int toy; cin >> toy;
    toys[toy] = !toys[toy]; 
  }
  for (int i = 0; i < 4; i++){
    int toy; cin >> toy;
    toys[toy] = !toys[toy]; 
  }

  for(auto toy: toys){
    if(toy.second){
      cout << toy.first << endl;
      break;
    }
  }

  return 0;
}