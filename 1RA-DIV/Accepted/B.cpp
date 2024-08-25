#include<bits/stdc++.h>

using namespace std;

int main(){

  int pieza;
  for(int i = 0;i<6;i++){
    cin>> pieza;
    if(i==0){
      if(pieza<0){
        cout<<pieza+1<<" ";
      }else 
        cout<< -pieza+1<<" ";
    }
    if(i==1){
      if(pieza<0){
        cout<<pieza+1<<" ";
      }else 
        cout<< -pieza+1<<" ";
    }
    
    if(i==2){
      if(pieza<0){
        cout<<pieza+2<<" ";
      }else 
        cout<< -pieza+2<<" ";
    }
    
    if(i==3){
      if(pieza<0){
        cout<<pieza+2<<" ";
      }else 
        cout<< -pieza+2<<" ";
    }
    
    if(i==4){
      if(pieza<0){
        cout<<pieza+2<<" ";
      }else 
        cout<< -pieza+2<<" ";
    }
    
    if(i==5){
      if(pieza<0){
        cout<<pieza+8;
      }else 
        cout<< -pieza+8;
    }
  }


  return 0;
}