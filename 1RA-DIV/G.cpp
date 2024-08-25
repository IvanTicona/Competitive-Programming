#include<bits/stdc++.h>

using namespace std;


int main(){
  int n,k; cin>>n>>k;
  set<int> setA;
  int anguloC;
  for (int i = 0; i < n; i++){
    cin>>anguloC;
    setA.insert(anguloC);
    int z=0,x=0;
    vector<int> values;
    for (int val: setA){
      values.push_back(val+anguloC);
      values.push_back(abs(val-anguloC));
    }
    for (int v: values){
      setA.insert(v);
    }
    values.clear();
  }
  
  int angN = 0;
  for (int i = 0; i < k; i++){
    bool v = false;
    cin>>angN;
    for (auto t: setA){
      angN %= t;
    }
    if(angN == 1){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
  
  return 0;
}