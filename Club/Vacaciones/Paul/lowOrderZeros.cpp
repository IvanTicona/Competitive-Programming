#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9;

vector<long long> fact(1e6+10);

void getFactorialWithoutZeros() {
    fact[0]=1;
    fact[1]=1;
    for(long long i = 2; i <= 1e6;i++){
        fact[i] = (fact[i-1]*i)%mod;
       // cout<<fact[i]<<endl;
        while(fact[i]%10 == 0) {
            fact[i]/=10;
        }
        fact[i] = fact[i]%mod;
       //cout<<"after while"<<fact[i]<<" "<<i<<endl;
    }
    //cout<<fact[0];
}

int main() {
    int n;
    getFactorialWithoutZeros();
    while(cin>>n && n) {
        cout<<fact[n]%10<<endl;
    }
    
    return 0;
}