#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <numeric>
// #include "utilities.cpp"
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, x, n) for (int i = x; i < n; i++)
#define forll(i, x, n) for (long long i = x; i < n; i++)
#define vi vector<int>
#define vpp vector<pair<int,int>>
#define vs vector<string>
#define vll vector<long long>
#define ss second
#define ff first


 
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int cnt=0;
        vi v1(m);
        vi v2(n,0);
        forn(i,0,m){
            cin>>v1[i];
        }
        forn(i,0,k){
            int z;
            cin>>z;
            v2[z-1]++;
        }
        forn(i,0,n){
            if(v2[i]==0){
                cnt++;
            }
        }
        if(m<n || cnt>1){
            forn(i,0,m){
                cout<<0;
            }
            cout<<endl;
        }else if(cnt==1){
            forn(i,0,m){
                if(v2[v1[i]-1]==0){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }
            cout<<endl;
        }else{
            forn(i,0,m){
                if(v2[v1[i]-1]==0){
                    cout<<0;
                }else{
                    cout<<1;
                }
            }
            cout<<endl;
        }
    }
}