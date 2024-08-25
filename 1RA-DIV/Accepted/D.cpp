#include<bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin>>n;

  string l1, l2;
  cin>>l1;
  cin>>l2;
  
  bool sonIguales = true;
  if(n%2==0){
    for (int i = 0; i < l1.size()&&sonIguales; i++){
      if(l1[i]!=l2[i]){
        sonIguales=false;
      }
    }
    if(sonIguales){
      cout<<"Deletion succeeded";
    }
    else{
      cout<<"Deletion failed";
    }
  }
  bool sonDistintos = true;


  if(n%2!=0){
    for (int i = 0; i < l1.size()&&sonDistintos; i++){
      if(l1[i]==l2[i]){
        sonDistintos=false;
      }
    }
    if(sonDistintos){
      cout<<"Deletion succeeded";
    }else{ 
      cout<<"Deletion failed";
    }
  }

  return 0;
}