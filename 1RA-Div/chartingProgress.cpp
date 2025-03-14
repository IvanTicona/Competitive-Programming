#include<bits/stdc++.h>

using namespace std;

int main(){

  string line;
  int j = 0;
  while(true){
    int d = 0;
    getline(cin,line);
    for (int i = 0; i < line.size(); i++){
      if(line[i] == '*'){
        d++;
        line[i] = '.';
      }
    }
    int s = line.size()-1;
    while (d > 0){
      line[s-j] = '*';
      j++;
      d--;
    }
    cout << line << endl;
    
    if(cin.eof()) break;
    if(line.size() == 0) j = 0;
  }

  return 0;
}