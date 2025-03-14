#include<bits/stdc++.h>

using namespace std;

int main(){

  unsigned int numerator, denominator;
  while (cin>>numerator>>denominator&&numerator!=0&&denominator!=0){
    int entire=0;

    while(numerator>=denominator){
      numerator-=denominator;
      entire++;
    }

    cout<<entire<<" "<<" "<<numerator<<" / "<<denominator<<endl; 
  }

  return 0;
}