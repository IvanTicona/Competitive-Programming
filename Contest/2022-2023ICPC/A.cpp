/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n,h,w; cin >>n>> h>>w ;
  string casa, trabajo;
  for (int i = 0; i < n; i++)
  {
    cin>> casa>>trabajo;
    if(casa == "Y" || !w){
      cout<<"Y"<<" ";
      h--;
      w++;
    }else{
      cout<<"N"<<" ";

    }
    if(trabajo == "Y" || !h){
      cout<<"Y"<<endl;
      w--;
      h++;
    }else{
      cout<<"N"<<endl;
    }
    
  }
  
  return 0;
}