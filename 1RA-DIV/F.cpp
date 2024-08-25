#include<bits/stdc++.h>

using namespace std;

vector<string> palabras;

int main(){

  ios_base:: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin>>n;
  int ops = n-1;
  while(n--){
    string s1; 
    cin>>s1;
    palabras.push_back(s1);
  }
  int a = 1, b;
  while (ops--){
    cin>>a>>b;
    palabras[a-1]+=palabras[b-1];
  }
  cout<<palabras[a-1];

  return 0;
}