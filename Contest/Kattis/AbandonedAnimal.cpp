#include<bits/stdc++.h>

using namespace std;

bool includes(vector<string> &inventory, string item){
  for(string &i: inventory){
    if(i.compare(item)==0) return true;
  }
  return false;
}

int main(){

  freopen("INPUT.txt", "r", stdin);
  freopen("OUTPUT.txt", "w", stdout);

  int n, k; cin >> n >> k;

  vector< vector<string> > inventory(n);

  for (int i = 0; i < k; i++){
    int store; cin >> store;
    string item; cin >> item;
    inventory[store].push_back(item);
  }

  int m; cin >> m;
  queue<string> q;
  for (int i = 0; i < m; i++){
    string t; cin >> t;
    q.push(t);
  }
  //Unique ONE PATH
  //impossible theres no path

  bool unique = true;
  for (int i = 0; i < n-1; i++){
    string item = q.front(); q.pop();
    if(!includes(inventory[i], item)){
      unique = false;
      break;
    }
  }
  if(unique){
    cout<<"unique"<<endl;
    return 0;
  }else if(!unique){
    cout<<"impossible"<<endl;
  }
  
  //Ambiguous multiple paths
  
  return 0;
}