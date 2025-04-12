#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000009

struct func{
    int a,b;
    func(int a, int b){
        this->a = a;
        this->b = b;
    }
};

void fun(vector<int> &v, string &s, int n){
    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            v[i+1] = v[i] + 1;
        }else{
            v[i+1] = v[i] - 1;
        }
    }
}

void solve(){
    int n,x,k;
    cin>>n>>x>>k;
    string s;
    cin>>s;

    vector<int> v(n+1,0);
    fun(v,s,n);
    
    int chk = n+2;
    int i=1;
    while(i<=n){
        if(x+v[i]==0){
            chk = i;
            break;
        }
        i++;
    }
    
    if(!(chk==n+2) and !(chk>k)){
        int chk2 = n+2;
        i=1;
        while(i<=n){
            if(v[i]==0){
                chk2 = i;
                break;
            }
            i++;
        }

        if(chk2==n+2){
            cout<<1<<endl;
            return;
        }

        cout<<1 + (k-chk)/chk2<<endl;
        return;
    }
    cout<<0<<endl;
    return;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}