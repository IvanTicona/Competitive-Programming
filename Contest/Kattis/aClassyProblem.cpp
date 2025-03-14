#include <bits/stdc++.h>

using namespace std;

map<string, long> m;
vector<string> v;

bool sortNames (string a, string b) {
  long al = m[a];
  long bl = m[b];
  if(al != bl){
    return (m[a]>m[b]);
  } else {
    return a.compare(b) < 0;
  }
}

int main(){

  int t;
  cin >> t;
  for(int i = 0; i < t; ++i){
    v.clear();
    m.clear();
    int n;
    cin >> n;

    for(int j = 0; j < n; ++j){

      string name; cin >> name;
      name = name.substr(0,name.length()-1);

      string class_string; cin >> class_string;
      string throw_away; cin >> throw_away;

      string class_value = "";
      istringstream ss(class_string);
      string token;

      while(getline(ss, token, '-')) {
        if(token.compare("upper") == 0){
          class_value.push_back('3');
        } else if(token.compare("middle") == 0){
          class_value.push_back('2');
        } else if(token.compare("lower") == 0){
          class_value.push_back('1');
        }
      }
      
      class_value = string(class_value.rbegin(), class_value.rend());
      //reverse string to get highest class value first
      
      while(class_value.length() != 10) {
        class_value.push_back('2');
      }

      long value = 0;
      for(auto c: class_value){
        value *= 10;
        value += c-'0';
      }

      m[name] = value;
      v.push_back(name);
    }

    sort(v.begin(), v.end(), sortNames);

    for(auto name: v){
      cout << name << endl;
    }

    cout << "==============================" << endl;
  }
  return 0;
}