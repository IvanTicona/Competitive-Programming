#include<bits/stdc++.h>

using namespace std;

int main(){

  string s;
  cin>>s;
  int flag = 0;
  for (int i = 0; i < s.size(); i++){
    for (int j = i+1; j <= i+6; j++){
      if(s[i]!=s[j]) break;
      if (j==i+6) flag = 1;
    }
    if (flag) break;
  }
  flag?cout<<"YES":cout<<"NO";

  return 0;
}

//INSANE CODE
// char a[101],i,s;
// main(){
//   for(gets(a);
//     s^6? a[++i]||puts("NO"):puts("YES");
//     a[i]^a[i-1]? s=0:++s);
// }