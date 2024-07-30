#include<bits/stdc++.h>

using namespace std;
int parents[200010];

int Find(int x){
  if(x==parents[x]) return x;
  else return parents[ x ] = Find( parents[ x ] );
}

void Union( int x , int y ){
    int xRoot = Find( x );
    int yRoot = Find( y );
    parents[ xRoot ] = yRoot;
}
bool sameSet( int x , int y ){
    if( Find( x ) == Find( y ) ) return true;
    return false;
}

int main(){

  int n, m;
  cin>>n>>m;
  for (int i = 1; i <= n; i++){
    parents[i]=i;
  }

  for (int i = 0; i < m; i++){
    int a, b;
    cin>>a>>b;
    Union(a,b);
  }

  bool ac = true;
  for (int i = 1; i <= n; i++){
    if(!sameSet(1,i)){
      cout<<i<<endl;
      ac=false;
    }
  }
  if(ac) cout<<"Connected"<<endl;

  return 0;
}