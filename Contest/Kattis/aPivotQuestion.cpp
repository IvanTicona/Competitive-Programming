#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main(){

  ios_base:: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;

  vector<int> a(n+1), maxleft(n+1), minright(n+1);

  for (int i = 0; i < n; i++){
    cin>>a[i];
    if(i >= 1) maxleft[i] = max(a[i], maxleft[i-1]);
    else maxleft[0]=a[0];
  }

  for (int i = n-1; i >= 0; i--){
    if(i==n-1) minright[i]=a[i];
    else minright[i]=min(a[i], minright[i+1]);
  }

  int m=0;
  vector<int> result;
  for (int i = 0; i < n; i++){
    if(maxleft[i]<=a[i] && a[i]<=minright[i]){
      result.push_back(a[i]);
      m++;
    }
  }

  cout<<m<<" ";
  int tmp = m > 100? 100: m;

  for(int p: result) cout<<p<<" ";

  return 0;
}