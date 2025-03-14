#include<bits/stdc++.h>

using namespace std;

int main(){

  int n;
  string l1, l2;
  cin>>n;
  cin>>l1;
  cin>>l2;
  
  bool success = true;
  
  if(n%2 == 0){
    for (int i = 0; i < l1.size(); i++){
      if(l1[i] != l2[i]){
        success = false;
        break;
      }
    }
  }else{
    for (int i = 0; i < l1.size(); i++){
      if(l1[i] == l2[i]){
        success = false;
        break;
      }
    }
  }
  
  if(success){
    cout << "Deletion succeeded" << endl;
  }
  else{
    cout << "Deletion failed" << endl;
  }

  return 0;
}