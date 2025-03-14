/*
Competitive Programming
G. Geography of Rivers
Author: Ivan Ticona
Created: 30/12/2024 11:06 PM
*/
#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define MOD 1000000007
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

static const int MAXN = 200000;

struct Node {
    Node* ch[2];
    Node* fa;
    bool rev;
    long long volume;
    int name;
    long long sumVol;
    int bestName;
    long long bestVol;

    long long addLazy;

    Node() {
        ch[0] = ch[1] = fa = nullptr;
        rev = false;
        volume = 0;
        name = 0;
        sumVol = 0;
        bestName = 0;
        bestVol = 0;
        addLazy = 0;
    }
};

Node lct[MAXN+5];

int chooseName(int n1, long long v1, int n2, long long v2) {
    if (v1 > v2) return n1;
    if (v2 > v1) return n2;
    return (n1 < n2 ? n1 : n2);
}

void pushUp(Node* x) {
    x->sumVol = x->volume;
    x->bestVol = x->volume;
    x->bestName = x->name;

    for (int i=0; i<2; i++) {
        Node* c = x->ch[i];
        if (!c) continue;
        x->sumVol += c->sumVol;
        int wName = chooseName(x->bestName, x->bestVol, c->bestName, c->bestVol);
        long long wVol;
        long long cVol = c->bestVol;
        long long xVol = x->bestVol;
        if (wName == x->bestName) {
            wVol = x->bestVol;
        } else {
            wVol = c->bestVol;
        }
        x->bestName = wName;
        x->bestVol  = wVol;
    }
}

void pushRev(Node* x) {
    if(!x) return;
    x->rev ^= true;
    Node* tmp = x->ch[0];
    x->ch[0] = x->ch[1];
    x->ch[1] = tmp;
}

void applyAdd(Node* x, long long val) {
    if(!x) return;
    x->volume += val;
    x->sumVol += val * 1LL;
    x->addLazy += val;
    x->bestVol += val;
}

void pushDown(Node* x) {
    if (!x) return;
    if (x->rev) {
        pushRev(x->ch[0]);
        pushRev(x->ch[1]);
        x->rev = false;
    }
    if (x->addLazy != 0) {
        long long val = x->addLazy;
        if (x->ch[0]) applyAdd(x->ch[0], val);
        if (x->ch[1]) applyAdd(x->ch[1], val);
        x->addLazy = 0;
    }
}

bool isRightChild(Node* x) {
    return x->fa && x->fa->ch[1] == x;
}

void rotate(Node* x) {
    Node* f = x->fa;
    bool rt = isRightChild(x);
    f->ch[rt] = x->ch[!rt];
    if (x->ch[!rt]) x->ch[!rt]->fa = f;
    x->fa = f->fa;
    if (f->fa) {
        if (f->fa->ch[0] == f) f->fa->ch[0] = x;
        if (f->fa->ch[1] == f) f->fa->ch[1] = x;
    }
    x->ch[!rt] = f;
    f->fa = x;
    pushUp(f);
    pushUp(x);
}

void splay(Node* x) {
    static Node* stack[2*MAXN];
    int top = 0;
    stack[++top] = x;
    for (Node* v = x; v->fa; v = v->fa) {
        stack[++top] = v->fa;
    }
    while (top) pushDown(stack[top--]);

    while (x->fa) {
        if (x->fa->fa) {
            if (isRightChild(x) == isRightChild(x->fa)) {
                rotate(x->fa);
            } else {
                rotate(x);
            }
        }
        rotate(x);
    }
}

Node* access(Node* x) {
    Node* last = nullptr;
    for (Node* y = x; y; y = y->fa) {
        splay(y);
        y->ch[1] = last;
        pushUp(y);
        last = y;
    }
    splay(x);
    return last;
}

void makeRoot(Node* x) {
    access(x);
    pushRev(x);
    pushDown(x);
    pushUp(x);
}

void link(Node* x, Node* y) {
    makeRoot(y);
    y->fa = x;
}

void addPath(Node* u, Node* v, long long val) {
    makeRoot(u);
    access(v);
    applyAdd(v, val);
    pushDown(v);
    pushUp(v);
}

int getName(Node* r) {
    splay(r);
    return r->bestName;
}


void solve(){
  int N; cin >> N;
  for (int i=1; i<=2*N-1; i++) {
    lct[i].ch[0] = lct[i].ch[1] = lct[i].fa = nullptr;
    lct[i].rev = false;
    lct[i].volume = 0;
    lct[i].name = i;
    lct[i].sumVol = 0;
    lct[i].bestName = i;
    lct[i].bestVol = 0;
    lct[i].addLazy = 0;
  }

  for (int i=1; i<=N; i++){
    long long vol; cin >> vol;
    lct[i].volume = vol;
    lct[i].sumVol = vol;
    lct[i].bestVol= vol;
  }

  for (int i=1; i<=N-1; i++){
    int a, b; cin >> a >> b;
    int p = N + i;
    long long va = lct[a].volume;
    long long vb = lct[b].volume;
    long long sumAB = va + vb;
    lct[p].volume = sumAB;
    lct[p].sumVol = sumAB;
    lct[p].bestVol= sumAB;
    int nm = chooseName(lct[a].name, va, lct[b].name, vb);
    lct[p].name = nm;
    lct[p].bestName = nm;

    link(&lct[p], &lct[a]);
    link(&lct[p], &lct[b]);
  }
  int root = 2*N - 1;

  cout << getName(&lct[root]) << "\n";

  int Q; cin >> Q;
  while (Q--) {
    int ni; long long qi;
    cin >> ni >> qi;
    addPath(&lct[ni], &lct[root], qi);
    cout << getName(&lct[root]) << "\n";
  }
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  // int t; cin >> t;
  // while(t--){
    solve();
  // }

  return 0;
}