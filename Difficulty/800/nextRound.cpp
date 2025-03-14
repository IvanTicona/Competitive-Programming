#include<bits/stdc++.h>

using namespace std;

vector<int> studens(0);

int main(){

  int n,k,x,count=0;
  cin>>n>>k;
  while(n--){
    cin>>x;
    studens.push_back(x);
  }
  for (int i = 0; i < studens.size(); i++)
  {
    if(studens[i]>=studens[k-1] && studens[i]>0){
      count++;
    }
  }
  cout<<count<<endl;
  return 0;
}