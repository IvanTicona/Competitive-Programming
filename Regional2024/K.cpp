/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int k; string s; cin >> k >> s;

  if(k == 2)
  {
    int aux0 = 0, aux1 = 0; string s0 = "", s1 = "";
    for (int i = 0; i < s.size(); i++)
    {
      if(i%2 == 0){
        s0 += '0';
        s1 += '1';
      }else{
        s0 += '1';
        s1 += '0';
      }
    }
    for (int i = 0; i < s.size(); i++)
    {
      if(s[i] != s0[i]) aux0++;
      if(s[i] != s1[i]) aux1++;
    }
    if(aux0 > aux1){
      cout << aux1 << " " << s1 << endl;

    }else{
      cout << aux0 << " " << s0 << endl;
    }
  }else{
    int consecutivos = 1, ops = 0;
    s+='2';
    for (int i = 1; i < s.size(); i++)
    {
      if(s[i-1] == s[i]) consecutivos++;
      else{
        if(consecutivos >= k)
        {
          int j = i;
          int h = 0;
          while(h+k <= consecutivos){
            int index = j - k + (s[j-k] != s[j-k-1]);
            if(s[index] == '0') s[index] = '1';
            else s[index] = '0';
            ops++;
            h+=k;
            j-=k;
          }
        }
        consecutivos = 1;
      }
    }
    s.pop_back();
    cout << ops << " " << s << endl;
  }

  return 0;
}