#include<bits/stdc++.h>

using namespace std;

string m, n, resp;

int extrai_bit(int &mask){
    int ret = mask % 2;
    mask /= 2;
    return ret;
}

bool verif(int mask){
    int mod = 0;
    for (auto dig: n){
        mod = mod * 2 + (dig=='*'? extrai_bit(mask): dig-'0');
    }
    int resto = 0, bit;
    for (int i = 0; i < m.size(); i++){
        bit = (m[i] == '*')? extrai_bit(mask) : (m[i]-'0');
        resp[i] = bit + '0';
        resto = (resto * 2 + bit) % mod;
    }
    return resto == 0;
}

int main(){

    cin >> m >> n;
    resp = m;
    int cnt = 0;

    for(auto dig: m){
        if(dig == '*'){
            cnt++;
        }
    }
    for(auto dig: n){
        if(dig == '*'){
            cnt++;
        }
    }

    int lim_mask =  1 << cnt;

    for (int mask = 0; mask < lim_mask; mask++){
        if(verif(mask)){
            cout<<resp<<endl;
            break;
        }
    }

    return 0;
}