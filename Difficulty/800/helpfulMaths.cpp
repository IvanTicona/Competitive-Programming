#include<bits/stdc++.h>

using namespace std;

vector<char> split(string c){
  vector<char> v;
  for(int i=0;i<c.size();i++){
    if(c[i]!='+'){
      v.push_back(c[i]);
    }
  }
  return v;
}

string orderOp(vector<char> v){
  string correct;
  for (int i = 0; i < v.size(); i++){
    for (int j = 0; j < v.size(); j++){
      if(v[i]<v[j]){
        char aux=v[i];
        v[i]=v[j];
        v[j]=aux;
      }
    }
  }
  for(int i=0;i<v.size();i++){
    correct+=v[i];
    correct+='+';
  }
  correct.pop_back();
  return correct;
}

int main(){

  string op;
  cin>>op;
  cout<<orderOp(split(op))<<endl;

  return 0;
}