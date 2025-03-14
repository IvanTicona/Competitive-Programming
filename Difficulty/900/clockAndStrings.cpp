#include <iostream>

using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    cout<<(((c > min(a, b) && c < max(a, b)) != (d > min(a, b) && d < max(a, b))) ? "YES" : "NO")<<endl;
  }
}