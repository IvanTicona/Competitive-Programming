#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
  int t;
  cin >> t;

  while (t--){

    ll n = 0, aux = 0, primero = 0;
    ll acc = 0;
    cin >> n;
    aux = n;
    while (aux--){
      if (aux == (n - 1)){
        cin >> primero;
      }else{
        int x;
        cin >> x;
        acc += x;
      }
    }
    cout<<primero<<" "<<acc<<endl;
    while (primero > acc / n){
      cout << "oaieo" << endl;
      primero--;
      acc++;
      cout << "duaedhnaei" << endl;
    }
    cout << "daedaed" << endl;
    cout << t << ". " << (acc + n - 2) / (n - 1) - primero << endl;
  }
}