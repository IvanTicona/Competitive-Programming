#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

  int t, n, m;
  cin>>t;
  while (t--){
    cin>>n>>m;
    int size = n+m+1;
    int a[size];
    int b[size];
    for (int i = 0; i < size; i++){
      cin>>a[i];
    }
    for (int i = 0; i < size; i++){
      cin>>b[i];
    }

    for (int i = 0; i < size; i++){
      int sum=0;

      int n1=n, m1=m; //puestos disponibles

      for (int j = 0; j < size; j++){
        if(j==i) continue;
        
        if(a[j]>b[j] && n1 > 0){
          sum+=a[j];
          n1--;
        }else if(a[j]>b[j] && n1 == 0){
          sum+=b[j];
          m1--;
        }else if(b[j]>a[j] && m1 >0){
          sum +=b[j];
          m1--;
        }else if(b[j]>a[j] && m1 == 0){
          sum += a[j];
          n1--;
        }
      }
      cout<<sum<<" ";
    }
    cout<<endl;
  }

  return 0;
}