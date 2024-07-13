#include<bits/stdc++.h>

using namespace std;

int main(){
  int r=0;
  string s1, s2;
  cin>>s1>>s2;
  for (int i = 0; i < s1.size(); i++){
    if(tolower(s1[i])<tolower(s2[i])) {r = -1;break;}
    else if(tolower(s1[i])>tolower(s2[i])) {r = 1; break;};
  }
  cout<<r;
  return 0;
}

//Si el caso se encuentra en el medio del string
// asadasdasd
// asdwasdawd
// -1