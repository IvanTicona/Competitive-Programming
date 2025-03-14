#include<bits/stdc++.h>

using namespace std;

int main(){

  string withoutVowels,word;
  cin>>word;
  for (int i = 0; i < word.size(); i++){
    if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
     word[i] == 'o' || word[i] == 'u' || word[i] == 'y' ||
      word[i] == 'A' || word[i] == 'E' || word[i] == 'I' ||
       word[i] == 'O' || word[i] == 'U' || word[i] == 'Y') continue;
    withoutVowels+='.';
    withoutVowels+=tolower(word[i]);
  }
  cout<<withoutVowels<<endl;

  return 0;
}