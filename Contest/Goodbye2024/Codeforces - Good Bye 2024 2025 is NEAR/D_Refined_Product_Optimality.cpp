/*
Competitive Programming
D. Refined Product Optimality
Author: Ivan Ticona
Created: 28/12/2024 11:32 AM
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define MOD 998244353
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define RFOR(i, a, b) for(int i = a; i >= b; i--)
#define FORP(i, a, b, c) for(int i = a; i <= b; i += c)
#define RFORP(i, a, b, c) for(int i = a; i >= b; i -= c)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define rv(x) for(auto &i: x) cin >> i
#define includes(x, y) x.find(y) != x.end()
#define fill(x, y) memset(x, y, sizeof(x))
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<ll, ll> pll;

ll modexp(ll base, ll exp){
    ll ans = 1LL;
    base%=MOD;
    while(exp>0){
        if(exp & 1) ans=(ans*base)%MOD;
        base=(base*base)%MOD;
        exp>>=1;
    }
    return ans;
}

ll inv(ll x){
    return modexp(x, MOD-2);
}

struct FenwicksProduct {
    int n;
    vll fenw;

    FenwicksProduct(int n_):n(n_){
        fenw.assign(n+1,1LL);
    }
    void mul(int i, ll factor){
        for(; i<=n; i+=(i & -i)){
            fenw[i] = (fenw[i]*factor) % MOD;
        }
    }
    void update(int i, ll oldVal, ll newVal){
        ll factor = (newVal%MOD) * inv(oldVal%MOD) % MOD;
        mul(i, factor);
    }
    ll query(int i) const {
        ll ret=1LL;
        for(; i>0; i-=(i & -i)){
            ret=(ret*fenw[i])%MOD;
        }
        return ret;
    }
    ll productAll() const {
        return query(n);
    }
    ll getSingle(int i) const {
        ll pref=query(i);
        ll pref1=query(i-1);
        return (pref*inv(pref1))%MOD;
    }
};

template<class T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct ValNeg {
    long long negv;
    int id;
    bool operator<(const ValNeg &o) const {
        return (negv<o.negv) || (negv==o.negv && id<o.id);
    }
};

struct MaxProductMin {
    int n;
    vll A, B;
    vi Apos, Bpos;

    OST<ValNeg> ostA, ostB;
    FenwicksProduct fenwA, fenwB, fenwR;

    MaxProductMin(int n_, const vll &initA, const vll &initB)
    : n(n_), A(initA), B(initB),
      Apos(n_), Bpos(n_),
      fenwA(n_), fenwB(n_), fenwR(n_)
    {
        for(int i=0;i<n;i++){
            ostA.insert({-A[i], i});
            ostB.insert({-B[i], i});
        }
        for(int i=0;i<n;i++){
            int rA= (int)ostA.order_of_key({-A[i], i})+1;
            Apos[i]= rA;
            fenwA.update(rA,1LL,A[i]);
        }
        for(int i=0;i<n;i++){
            int rB= (int)ostB.order_of_key({-B[i], i})+1;
            Bpos[i]= rB;
            fenwB.update(rB,1LL,B[i]);
        }
        for(int r=1;r<=n;r++){
            ll aVal= getAvalueByRank(r);
            ll bVal= getBvalueByRank(r);
            ll ratio=1;
            if(bVal< aVal){
                ratio=(bVal%MOD)*inv(aVal%MOD)%MOD;
            }
            fenwR.update(r,1LL, ratio);
        }
    }
    ll getAvalueByRank(int r){
        if(r<1 || r> (int)ostA.size()) return 0;
        auto it= ostA.find_by_order(r-1);
        if(it==ostA.end()) return 0;
        return -(it->negv);
    }
    ll getBvalueByRank(int r){
        if(r<1 || r>(int)ostB.size()) return 0;
        auto it= ostB.find_by_order(r-1);
        if(it==ostB.end()) return 0;
        return -(it->negv);
    }
    ll getRatioSingle(int r){
        return fenwR.getSingle(r);
    }
    void recalcRatioAt(int r){
        if(r<1|| r>n) return;
        ll oldRatio= getRatioSingle(r);
        ll aVal= getAvalueByRank(r);
        ll bVal= getBvalueByRank(r);
        ll newRatio=1;
        if(bVal<aVal){
            newRatio=(bVal%MOD)*inv(aVal%MOD)%MOD;
        }
        fenwR.update(r, oldRatio, newRatio);
    }

    void incrementA(int x){
        ll oldVal= A[x];
        ll newVal= oldVal+1;
        int r = Apos[x];

        fenwA.update(r, oldVal, 1LL);
        ostA.erase({-oldVal, x});
        A[x]= newVal;
        ostA.insert({-newVal, x});
        int newr= (int)ostA.order_of_key({-newVal,x})+1;
        Apos[x] = newr;
        fenwA.update(newr,1LL,newVal);

        // if(newr < r){
        //     while(r> newr){
        //         localSwapA(r-1, r);
        //         r--;
        //     }
        // } else if(newr> r){
        //     while(r< newr){
        //         localSwapA(r, r+1);
        //         r++;
        //     }
        // }
        for(int r=1;r<=n;r++){
            recalcRatioAt(r);
        }
    }

    void incrementB(int x){
        ll oldVal= B[x];
        ll newVal= oldVal+1;
        int r= Bpos[x];

        fenwB.update(r,oldVal,1LL);
        ostB.erase({-oldVal,x});
        B[x]= newVal;
        ostB.insert({-newVal,x});
        int newr= (int)ostB.order_of_key({-newVal,x})+1;
        Bpos[x]= newr;
        fenwB.update(newr,1LL,newVal);

        // if(newr< r){
        //     while(r> newr){
        //         localSwapB(r-1, r);
        //         r--;
        //     }
        // } else if(newr>r){
        //     while(r< newr){
        //         localSwapB(r, r+1);
        //         r++;
        //     }
        // }
        for(int r=1;r<=n;r++){
            recalcRatioAt(r);
        }
    }

    void localSwapA(int i, int j){
        if(i<1|| j>n) return;
        ll valI= fenwA.getSingle(i);
        ll valJ= fenwA.getSingle(j);

        auto itI= ostA.find_by_order(i-1);
        auto itJ= ostA.find_by_order(j-1);
        if(itI==ostA.end() || itJ==ostA.end()) return;

        int idI= itI->id;
        int idJ= itJ->id;

        fenwA.update(i, valI, valJ);
        fenwA.update(j, valJ, valI);

        Apos[idI]= j;
        Apos[idJ]= i;

        recalcRatioAt(i);
        recalcRatioAt(j);
    }

    void localSwapB(int i, int j){
        if(i<1|| j>n) return;
        ll valI= fenwB.getSingle(i);
        ll valJ= fenwB.getSingle(j);

        auto itI= ostB.find_by_order(i-1);
        auto itJ= ostB.find_by_order(j-1);
        if(itI==ostB.end()|| itJ==ostB.end()) return;

        int idI= itI->id;
        int idJ= itJ->id;

        fenwB.update(i, valI, valJ);
        fenwB.update(j, valJ, valI);

        Bpos[idI]= j;
        Bpos[idJ]= i;

        recalcRatioAt(i);
        recalcRatioAt(j);
    }

    ll getProduct(){
        ll prodA = fenwA.productAll();
        ll prodR = fenwR.productAll();
        return (prodA % MOD) * (prodR % MOD) % MOD;
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vll A(n), B(n); rv(A); rv(B);

    MaxProductMin solver(n, A, B);
    ll ans0 = solver.getProduct();
    cout << ans0;

    while(q--){
        int o, x;
        cin >> o >> x;
        x--;
        if(o == 1){
            solver.incrementA(x);
        } else {
            solver.incrementB(x);
        }
        ll ans = solver.getProduct();
        cout << " " << ans;
    }
    cout << "\n";
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}