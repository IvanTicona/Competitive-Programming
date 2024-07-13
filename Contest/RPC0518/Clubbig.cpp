#include<bits/stdc++.h>

using namespace std;

int main(){

  int n;
  bool membersClub[114];
  bool isInClub[114];
  memset(isInClub,false,sizeof(isInClub));
  memset(membersClub,false,sizeof(membersClub));

  cin>>n;
  int intv=0;
  for (int i = 0; i < n; i++){
    string mem;
    cin>>mem;
    for (int i = 0; i < mem.size(); i++){
      isInClub[mem[i]] = true;
    }
  }
  string schedule;
  cin>>schedule;
  for (int i = 0; i < schedule.size(); i++){
    if(!isInClub[schedule[i]]) continue;
    if(membersClub[schedule[i]]) continue;
    membersClub[schedule[i]] = true;
    intv++;
  }
  cout<<intv-1<<endl;

  return 0;
}