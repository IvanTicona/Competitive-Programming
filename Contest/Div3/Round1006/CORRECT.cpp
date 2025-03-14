#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
 
template<class T>
using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
#define int long long
#define double long double
#define i28 __int128
#define inf (int)1e18
#define pl(s) cout << s << "\n"
#define ps(a) for(int ele : a) cout << ele << " "; cout << "\n"
#define vi vector<int>
#define vvi vector<vi> 
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vs vector<string>
#define mi map<int, int>
#define vc vector<char>
#define vvc vector<vc>
#define pi pair<int, int>
#define vpi vector<pi>
#define si set<int>
#define init(a, val) memset(a, val, sizeof(a))
#define yes cout << "Yes" << "\n"
#define no cout << "No" << "\n"
 
int mod = (int)1e9 + 7;
 
inline int add(int a, int b) { return ((a % mod) + (b % mod)) % mod; }
inline int sub(int a, int b) { return (((a + mod) % mod) + ((-b + mod) % mod)) % mod; }
inline int mul(int a, int b) { return ((a % mod) * (b % mod)) % mod; }
inline int binpow(int a, int b) { a %= mod; int res = 1; while (b > 0) { if (b & 1) res = mul(res, a); a = mul(a, a); b /= 2; } return res; }
inline int inv(int x) { return binpow(x, mod - 2); }
inline int divi(int x, int y) { return mul(x, inv(y)); }
inline int gcd(int a, int b) { return __gcd(a, b); }
inline int lcm(int a, int b) { return (a * b) / __gcd(a, b); }
inline int ceil(int a, int b) { return (a + b - 1) / b; }
inline bool isSet(int x, int bit) { return ((x >> bit) & 1LL) == 1LL; }
 
string substring(string &s, int i, int j) {int length = j - i;return s.substr(i, length);}
 
int floor(vector<int> &a, int value) {int start = 0;int end = (int)a.size() - 1;int ans = -1;while(start <= end) {int mid = (start + end) / 2;if(a[mid] <= value) {ans = max(ans, mid);start = mid + 1;}else end = mid - 1;}return ans;}
int ceiling(vector<int> &a, int value) {int start = 0;int end = (int)a.size() - 1;int ans = (int)a.size();while(start <= end) {int mid = (start + end) / 2;if(a[mid] >= value) {ans = min(ans, mid);end = mid - 1;}else start = mid + 1;}if(ans == a.size()) ans = -1;return ans;}
int floor(vector<double> &a, double value) {int start = 0, end = (int)a.size() - 1, ans = -1; while(start <= end) {int mid = (start + end) / 2; if(a[mid] <= value) {ans = max(ans, mid); start = mid + 1;} else end = mid - 1;} return ans;}
int ceiling(vector<double> &a, double value) {int start = 0, end = (int)a.size() - 1, ans = (int)a.size(); while(start <= end) {int mid = (start + end) / 2; if(a[mid] >= value) {ans = min(ans, mid); end = mid - 1;} else start = mid + 1;} return ans == a.size() ? -1 : ans;}
int floor(set<int> &st, int value) {auto it = st.upper_bound(value);if (it != st.begin()) {it--;return *it;}return -1;}
int ceiling(set<int> &st, int value) {auto it = st.lower_bound(value);if (it != st.end()) {return *it;}return -1;}
template <typename V> int floor(map<int, V>& mp, int value) {auto it = mp.upper_bound(value);if (it != mp.begin()) {it--;return it->first;}return -1;}
template <typename V> int ceiling(map<int, V>& mp, int value) {auto it = mp.lower_bound(value);if (it != mp.end()) {return it->first;}return -1;}
 
void fill(map<int, int> &mp, int value) {mp[value]++;}
void remove(map<int, int> &mp, int value) {mp[value]--;if(mp[value] == 0) mp.erase(value);}
void fillmap(map<int, int> &mp, vector<int> &a) {for(int i=0;i<a.size();i++) fill(mp, a[i]);}

vi in(int n) {vi a(n);for(int i=0;i<n;i++) cin >> a[i];return a;}

class DSU {public:int components;vector<int> parent, rank, sizes;DSU(int n) {parent.resize(n + 1);rank.resize(n + 1, 1);sizes.resize(n + 1, 1);for (int i = 0; i <= n; i++) parent[i] = i;components = n;}int find(int x) {if (parent[x] != x) {parent[x] = find(parent[x]);}return parent[x];}void unite(int x, int y) {int rootX = find(x);int rootY = find(y);if (rootX != rootY) {if (rank[rootX] < rank[rootY]) {parent[rootX] = rootY;sizes[rootY] += sizes[rootX];} else if (rank[rootX] > rank[rootY]) {parent[rootY] = rootX;sizes[rootX] += sizes[rootY];} else {parent[rootY] = rootX;rank[rootX]++;sizes[rootX] += sizes[rootY];}components--;}}int size(int x) {return sizes[find(x)];}bool same(int x, int y) {return find(x) == find(y);}}; 
class PrefixSum {public:vector<int> psum;PrefixSum(vector<int> &a) {int n = a.size();psum.resize(n, 0);psum[0] = a[0];for(int i=1;i<n;i++) psum[i] = psum[i-1] + a[i];}int query(int l, int r) {if(l > r) return 0;if(l < 0) l = 0;if(r >= psum.size()) r = psum.size() - 1;int sum = psum[r];if(l - 1 >= 0) sum -= psum[l-1];return sum;}};
struct chash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RAnDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RAnDOM);}}; 
#define um(data) unordered_map<int, data, chash>

int query(pbds<pair<int, int>> &st, int l, int r) {int ans = st.order_of_key({r, inf});ans -= st.order_of_key({l - 1, inf});return ans;} 

vi spf, mob;
void mobius(int n) {mob.resize(n + 5, 0);mob[1] = -1;for(int i = 1;i <= n;i++) {if(mob[i]) {mob[i] = -mob[i];for(int j = 2 * i;j <= n;j += i) mob[j] += mob[i];}}}
void sieve(int n) {spf.resize(n + 5, 0);for (int i = 0; i <= n; i++) spf[i] = i; for (int i = 2; i * i <= n; i++) {if (spf[i] == i) {for (int j = i * i; j <= n; j += i) {if (spf[j] == j) spf[j] = i; }}}}
vector<int> prime(int x) {vector<int> ret;while (x != 1) { ret.push_back(spf[x]);x = x / spf[x];}return ret;}

class SparseTableMax {public:vector<vector<int>> table;vector<int> logTable;vector<int> arr;SparseTableMax(const vector<int>& arr) : arr(arr) {int n = arr.size();int logn = (int) (log2(n)) + 1;table.resize(n, vector<int>(logn));logTable.resize(n + 1);buildSparseTable();}void buildSparseTable() {int n = arr.size();for (int i = 2; i <= n; i++) {logTable[i] = logTable[i / 2] + 1;}for (int i = 0; i < n; i++) {table[i][0] = arr[i];}for (int j = 1; (1 << j) <= n; j++) {for (int i = 0; i + (1 << j) <= n; i++) {int leftVal = table[i][j - 1];int rightVal = table[i + (1 << (j - 1))][j - 1];table[i][j] = max(leftVal, rightVal);}}} int query(int l, int r) {int k = logTable[r - l + 1];int leftVal = table[l][k];int rightVal = table[r - (1 << k) + 1][k];return max(leftVal, rightVal);}};
class SparseTableMin {public:vector<vector<int>> table;vector<int> logTable;vector<int> arr;SparseTableMin(const vector<int>& arr) : arr(arr) {int n = arr.size();int logn = (int) (log2(n)) + 1;table.resize(n, vector<int>(logn));logTable.resize(n + 1);buildSparseTable();}void buildSparseTable() {int n = arr.size();for (int i = 2; i <= n; i++) {logTable[i] = logTable[i / 2] + 1;}for (int i = 0; i < n; i++) {table[i][0] = arr[i];}for (int j = 1; (1 << j) <= n; j++) {for (int i = 0; i + (1 << j) <= n; i++) {int leftVal = table[i][j - 1];int rightVal = table[i + (1 << (j - 1))][j - 1];table[i][j] = min(leftVal, rightVal);}}} int query(int l, int r) {int k = logTable[r - l + 1];int leftVal = table[l][k];int rightVal = table[r - (1 << k) + 1][k];return min(leftVal, rightVal);}};

class FenwickTree {public:vector<int> tree;int n;public:FenwickTree(int size) : tree(size + 1, 0), n(size) {}void update(int index, int delta) {for (; index <= n; index += index & -index) {tree[index] += delta;}}int query(int index) {int sum = 0;for (; index > 0; index -= index & -index) {sum += tree[index];}return sum;}int query(int left, int right) {return query(right) - query(left - 1);}};
class RangeQueries {public :int *BITTree1, *BITTree2;int n;RangeQueries(int n) {this->n = n;BITTree1 = constructBITree(n);BITTree2 = constructBITree(n);}int getSum(int BITree[], int index) {int sum = 0;index = index + 1;while (index > 0) {sum += BITree[index];index -= index & (-index);}return sum;}void updateBIT(int BITree[], int n, int index, int val) {index = index + 1;while (index <= n) {BITree[index] += val;index += index & (-index);}}int sum(int x, int BITTree1[], int BITTree2[]) {return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);}void update(int l, int r, int val) {updateRange(BITTree1, BITTree2, n, val, l, r);}int query(int l, int r) {return rangeSum(l, r, BITTree1, BITTree2);}void updateRange(int BITTree1[], int BITTree2[], int n, int val, int l, int r) {updateBIT(BITTree1, n, l, val);updateBIT(BITTree1, n, r + 1, -val);updateBIT(BITTree2, n, l, val * (l - 1));updateBIT(BITTree2, n, r + 1, -val * r);}int rangeSum(int l, int r, int BITTree1[], int BITTree2[]) {return sum(r, BITTree1, BITTree2) - sum(l - 1, BITTree1, BITTree2);}int* constructBITree(int n) {int* BITree = new int[n + 1];for (int i = 1; i <= n; i++) BITree[i] = 0;return BITree;}};

struct compare {
    bool operator()(vector<int> &a, vector<int> &b) {
        return a[0] > b[0];
    }
};

void solve() {
	int n, x;
	cin >> n >> x;
	vi a(n);
	int OR = 0;
	for(int i=0;i<n;i++) {
		if((i | x) == x) {
			a[i] = i;
			OR |= i;
		}
	}
	if(OR != x) a[n - 1] = x;
	ps(a);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
	cin >> t;
    for(int i=0;i<t;i++) solve();
}