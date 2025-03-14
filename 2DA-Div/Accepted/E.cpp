#include<bits/stdc++.h>

using namespace std;

string palabra;
bool vis[100010];
int tam=0;

void countAs(int i){
  tam++;
  vis[i]=true;
  if(palabra[i+1]=='a'&&!vis[i+1]){
    countAs(i+1);
  }
}

int main(){

  int size;
  cin>>size;
  cin>>palabra;

  int result=0;
  for (int i = 0; i < size; i++){
    if(palabra[i]=='a'&&!vis[i]) {
      countAs(i);
      if(tam>=2) result+=tam;
      tam=0;
    }
  }
  
  cout<<result<<endl;

  return 0;
}