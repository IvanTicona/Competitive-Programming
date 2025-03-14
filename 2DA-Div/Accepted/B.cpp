#include<bits/stdc++.h>

using namespace std;

void getPyramid(int &n){
  int cards=2;
  while (n-cards>=0){
    n-=cards;
    cards+=3;
  }
}

int main(){

  int t; cin>>t;
  while (t--){
    int n; cin>>n;
    int piramids=0;
    while (n>=2){
      piramids++;
      getPyramid(n);
    }
    cout<<piramids<<endl;
  }

  return 0;
}