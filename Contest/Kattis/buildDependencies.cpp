#include<bits/stdc++.h>

using namespace std;

map<string, vector<string>> grafo;
map<string, bool> vis;

vector<string> tp;

void toposort(string nodo){
  vis[nodo] = true;
  for (string vec: grafo[nodo]){
    if(vis[vec]) continue;
    toposort(vec);
  }
  tp.push_back(nodo);
}

int main(){

  int n; 
  cin>>n;
  string line, item, vec, node;
  
  for(int i=0; i<=n; i++){
    getline(cin,line);
    istringstream tokens(line);
    if(tokens>>item){
      node = item.substr(0,item.size()-1);
    }
    while(tokens>>vec){
      grafo[node].push_back(vec);
      vis[node]=false;
    }
    
  }

  string initialNode; 
  cin>>initialNode;
  toposort(initialNode);

  for(string elm: tp) cout<<elm<<endl;

  return 0;
}