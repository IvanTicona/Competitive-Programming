/*
Competitive Programming
C. Christ of Discord
Author: Ivan Ticona
Created: 31/12/2024 07:02 PM
*/
#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;
static const int MAXA = 100000;

vector<int> spf(MAXA+1);
void build_spf(){
    iota(spf.begin(), spf.end(), 0);
    for(int i=2; i*i<=MAXA; i++){
        if(spf[i] == i){
            for(int j=i*i; j<=MAXA; j+=i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<pair<int,int>> factorize(int x){
    vector<pair<int,int>> f;
    while(x>1){
        int p = spf[x];
        int cnt=0;
        while(spf[x] == p){
            x /= p;
            cnt++;
        }
        f.push_back({p, cnt});
    }
    return f;
}

long long modexp(long long base, int exp){
    long long result = 1;
    base %= MOD;
    while(exp>0){
        if(exp & 1) result = (result*base) % MOD;
        base=(base*base) % MOD;
        exp >>= 1;
    }
    return result;
}
long long inv(long long x){
    return modexp(x, MOD-2);
}

struct PrimeData {
    vector<long long> fv, invfv;
};

struct Query {
    int l, r, idx;
};

int BLOCK_SIZE;

bool mo_cmp(const Query &A, const Query &B){
    int blockA = A.l / BLOCK_SIZE;
    int blockB = B.l / BLOCK_SIZE;
    if(blockA != blockB) return blockA < blockB;
    return A.r < B.r;
}

long long currentSigma = 1;
vector<int> expOfPrime;
vector<PrimeData> primeData;
unordered_map<int,int> pIndex;

inline void mulmod(long long &a, long long b){
    a = (a*b) % MOD;
}

void addElement(const vector<vector<pair<int,int>>> &factArr, int pos){
    for(auto &pe : factArr[pos]){
        int p = pe.first, e = pe.second;
        int id = pIndex[p];
        int oldE = expOfPrime[id];
        int newE = oldE + e;

        mulmod(currentSigma, primeData[id].fv[newE]);
        mulmod(currentSigma, primeData[id].invfv[oldE]);

        expOfPrime[id] = newE;
    }
}

void removeElement(const vector<vector<pair<int,int>>> &factArr, int pos){
    for(auto &pe : factArr[pos]){
        int p = pe.first, e = pe.second;
        int id = pIndex[p];
        int oldE = expOfPrime[id];
        int newE = oldE - e;

        mulmod(currentSigma, primeData[id].fv[newE]);
        mulmod(currentSigma, primeData[id].invfv[oldE]);

        expOfPrime[id] = newE;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_spf();

    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<vector<pair<int,int>>> factArr(n);
    unordered_map<int,int> totalExp;
    totalExp.reserve(n*3);

    for(int i=0; i<n; i++){
        auto f = factorize(arr[i]);
        factArr[i] = f;
        for(auto &pe : f){
            totalExp[pe.first] += pe.second;
        }
    }

    pIndex.reserve(totalExp.size());
    primeData.reserve(totalExp.size());
    int idx = 0;
    for(auto &kv : totalExp){
        int p = kv.first;
        pIndex[p] = idx++;
    }
    primeData.resize(idx);

    for(auto &kv : totalExp){
        int p = kv.first;
        int E = kv.second;
        int id = pIndex[p];

        primeData[id].fv.resize(E+1);
        primeData[id].invfv.resize(E+1);

        vector<long long> pot(E+2, 1LL);
        for(int k=1; k<=E+1; k++){
            pot[k] = (pot[k-1]*p) % MOD;
        }
        long long invPminus1 = inv((p-1+MOD)%MOD);

        for(int e=0; e<=E; e++){
            long long numerator = (pot[e+1] + MOD - 1) % MOD;
            long long val = (numerator * invPminus1) % MOD;
            primeData[id].fv[e] = val;
            primeData[id].invfv[e] = inv(val);
        }
    }

    vector<Query> queries(q);
    for(int i=0; i<q; i++){
        int l,r;
        cin >> l >> r;
        --l;
        --r;
        queries[i] = {l, r, i};
    }

    BLOCK_SIZE = (int) floor(sqrt(n));
    sort(queries.begin(), queries.end(), mo_cmp);

    expOfPrime.assign(idx, 0);
    currentSigma = 1;

    vector<long long> ans(q);
    int curL=0, curR=-1;

    for(auto &qv : queries){
        int L = qv.l, R = qv.r;
        while(curR < R) addElement(factArr, ++curR);
        while(curR > R) removeElement(factArr, curR--);
        while(curL < L) removeElement(factArr, curL++);
        while(curL > L) addElement(factArr, --curL);

        ans[qv.idx] = currentSigma;
    }

    for(long long x : ans) cout << x << "\n";
    return 0;
}
