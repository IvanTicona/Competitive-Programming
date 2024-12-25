/*
Author: Ivan Ticona

&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$:::::::::X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&$$++$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&X;::::;++++;::X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&$;;X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&X;;;;;;+xX$$$$;:x&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&X:X&&&&&&&&&&&&&&&&&&&&$X++$&X;;;;;+XX+;;;+;::$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&$+&&&&&&&&&&&&&&&&&&&&&&&&X++;::;;+;::;;+;::+XX+X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&;$&&&$+:::;X$&&&&&&&&&&&&&&$+;:::::::::;+::+&&x$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&X;;;:::::::;;;::;&&&&&&&&$++$+;;:::::::;;:::X$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&X::;:::;xXX$+:::;$$&&&&&x++x+;::;;;:::::+;&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&x$&&&&&&&+:;;+X&+X$$Xx$XXXxXx;:;;::+&&&&&&&&&&&&&&&&&&&&&XXXX&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&x+;+++$&&&&$&$$+;;;;;;;;;::;$&&&&&&&&&&&&&&&&&&&&$X++$&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$$$$$$&&&&x;;;;;;;:::::::;+X&&&&&&&&&&&&&$$$$X+++$&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$++;;+;;;:::::::::::::X$&&&&&&$XxxX$$+++x&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$x+;;;;;:;;:::::::::::::;;;+$$$XXX+++++xx$&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&XxXX++;;::;:::::::::::;;;:;;;;+XXxXx+++x++xX&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&Xxxxx++;;:::::::::::::::;;;+x+;;Xx+++++++++xXX&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$$XxXXx+;;;;;;;:::::::;++;::::::xXx+++++;+xx++$&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$$$$&$$$$$$$$$XX+xX+Xx++++;;+;;;:;++;;;;;;+X+++;;+++XX+;;&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$$$xX$$$$$$$$$XXXXXXXx++x+;::;;;+++;;;:::;++;;+;++xxx;:+&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&XXxxxxxx+X$$$$$$XXX$XXX$$+;++++;;:;;;;;;::::::;;;;;+;++;::x&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&+++++++++++++xXX$XX+xx+++++++;;;;;;:::::::::::::::::;;;;;+;:::;$&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$;;::;;;;;;;;++xxXXXx++++++++;;;;::::::::::::::::::::::;;:::;;::;;x&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&X;::::::::::;;;+x+++;;++++;;;:::::::::::::::::::::::::::;:::::::;+x;X&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$;::::::::::::;;;;;;;;;;;;:::::::::::::::::::::::;::::::;:;;:::;+X+;:;$&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&X;::::::::::::::::::;+;:::::::::::::::::::::::::;+;;+;:;;;:;;:;;;;+::::x&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$++;:::::::::::::::::;;;++;;::::...::::::::::::::::;;++++++;;;:;;;;+;;::::&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&;;;::::::::::::::::::::;:;;;:;:::::::::::::::::::::::;;;++;;;;;;::::::::::x&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&;;;::::::::::::::::::::::::::::::::::::::::::::::::::::;;;;;:::::::::::::::;&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&X;::::::::::::::::::::::::::::::::::::::::::::::::$&X:::::;;;::::::::::::::::&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&$$$$&&&&&X+;;;;;::::::::::::::::::::::::::::::::::::::::::::::::X&&&&&$+;;::::::::::::::::::&&&&&&&&&&&&&
&&&&&&&&&&&&&X;;;;::::+$&&+;;::::::::::::::::::::&&:::::::::::::::::::::;;::::::::X&&&&&&&&&&+:::::::::.:::...$&&&&&&&&&&&&&
&&&&&&&&&&&&x::;:::;:;:+X+;:;;;::::::::::::::::X&&&+:::::::::::::::::::::;:::::::X&&&&&&&&&&&&$::::....:...::;&&&&&&&&&&&&&&
&&&&&&&&&&&X;:;::::;;;;;;;::::::::::::::::::;&&&&&&$;::::::::::;;:::;:::::::::::x&&&&&&&&&x:........:::..:::+&&&&&&&&&&&&&&&
&&&&&&&&&&X;::::::;;::;:+;;;;::::::::::::::$&&&&&&&$;::::::::::::::::;;;::;:::::&&&&&&&&+::::::::::::::...:+&&&&&&&&&&&&&&&&
&&&&&&&&&&X::;:::::::::;;;:::::::::::::::x&&&&&&&&&;::::::::::::;;;;;++::::::::+&&&&X+::::::.:::::::::::::...:x&&&&&&&&&&&&&
&&&&&&&&&&&X::::::::::::;:::::::::::::::+&&&&&&&&&;:::::::::::::;;;;:::::::::;:Xx::::::::.::::::::::::::.:..:...+&&&&&&&&&&&
&&&&&&&&&&&$;.:::::...:::::::::::::::.+&&&&&X;;::::::::::::;;;;;;;;;::::::::::::;;;;;:::::::::::::::...........:::x&&&&&&&&&
&&&&&&&&&&&&&&$::::::::.:::......:;X&&&$&&&+:::.::::::::::::;;;;:;;;;::::::::::;;;;;:;:::;:::::::................::;&&&&&&&&
&&&&&&&&&&&&&$;::::::::::::::::.:.......:++:...::::::::::::::;;++......:::::::;;;;;;:::;;:::::.::.....:.....:.......x&&&&&&&
&&&&&&&&&&$;:.:::::.....::.:::::.............:::::::::::::;::;;:.....::::.:::++X+X++;;;::;:..:::..:...:..............X&&&&&&
&&&&&&&&&X:..:....:::.........:::..........::::::::::::;::::::;:.....:::..:;;+;:+xx;;:::::.:::.:....::....:........:.;&&&&&&
&&&&&&&&+:....::::::::::..:::::.::::.....::::::::::::::;::::::::......:::;:.::::::::::::..:::::.....:..:....:::.:...::&&&&&&
&&&&&&&X:::::...:....:::...............:::::::::::::::;;::::::::...::::::.:::::.:.::::::.........::::...::::::::.....:&&&&&&
&&&&&&&...::.....::............:::....:..::::::::::::+;;:::::::..::.....::::...:.:::::::.......::::::.::::::.........:&&&&&&
&&&&&&;..:....::................:........:::::::::::;;+;:::::::.......::.:.........:::::.....:::::...:::.............+&&&&&&
&&&&&$:..........::.....................::::::::::::;+++::::::.....................:::::............::...............&&&&&&&
&&&&&&+.............::................::::::::::::::;;;+;::::.......................:::::..........::...............;&&&&&&&
&&&&&&&;.........::.....:...........:::::.:::::::;::;;::x+::.........................:::........:...................X&&&&&&&
&&&&&&&$:..................:........::::...::::;;;;:.:;:;:::..........................::::..........:..............:&&&&&&&&
&&&&&&&&$.....................:....::::...............:;::::...........................:...........................X&&&&&&&&
&&&&&&&&&X:.....................:..:::.............::..:::::............................:...........:.............+&&&&&&&&&
&&&&&&&&&&X:.......................::....................:::..........................................:::........;&&&&&&&&&&
&&&&&&&&&&&&;:......................................::::..:::...................................................;&&&&&&&&&&&
&&&&&&&&&&&&&X:.........:................:.............::::.:...::.......:::..::.....::.::..:.............::...+&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&$XX+;;::.....::.................................::...............................:+&&&&&$$&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$:............................:::;:.......:...................X$;.....;&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&X:.........................:...:::....::.............:...;&&&&XX$&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$:........................:::....:....::::::.....::::::$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&X$&&&&$+:...................:....::...........::..::+&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$...................:::.::......x:..::..:&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&X.....;;::...............:...:$&;.....:$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&+:...x&&&;..................X&&x.....+&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&;::.+&&&&+:..............:$&&&X....:&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$;..;&&&&&+::............X&&&&X...:&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$.:;&&&&&&;.::::::::::.$&&&&&X..:$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
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
// #define sort(x) sort(all(x))
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

void solve(){

  int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        vector<int> b(m);
        for(auto &x: b) cin >> x;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        // Find a1
        int a1 = a[0];
        // Compute c_j for all problems
        vector<int> cj;
        for(int j=0; j<m; j++){
            if(b[j] > a1){
                // Number of participants with a_i >= b[j]
                int idx = lower_bound(a.begin(), a.end(), b[j]) - a.begin();
                int cj_val = n - idx;
                cj.push_back(cj_val);
            }
            else{
                cj.push_back(0);
            }
        }
        // Sort c_j in non-decreasing order
        sort(cj.begin(), cj.end());
        // Compute prefix sums
        vector<long long> prefix_sum(m+1, 0);
        for(int j=0; j<m; j++) prefix_sum[j+1] = prefix_sum[j] + (long long)cj[j];
        // For each k=1 to m, compute floor(m/k) and sum_cj_min
        // To optimize, precompute floor(m/k) for all k
        // Note that floor(m/k) decreases as k increases
        // So we can iterate k from1 to m
        // and for each k, compute q= floor(m/k), t=q*k
        // sum_cj_min = prefix_sum[t]
        // Then, sum_ranks[k] = q + sum_cj_min
        // Precompute results
        vector<long long> results(m, 0);
        for(int k=1; k<=m; k++){
            int q = m / k;
            int t = q * k;
            if(t > m) t = m;
            if(t > (int)cj.size()) t = cj.size();
            // Since c_j's are sorted, prefix_sum[t] already accounts for min t c_j's
            long long sum_cj_min = (t <= (int)prefix_sum.size()-1) ? prefix_sum[t] : prefix_sum[prefix_sum.size()-1];
            results[k-1] = (long long)q + sum_cj_min;
        }
        // Output the results
        for(int k=0; k<m; k++) cout << results[k] << (k<m-1 ? ' ' : '\n');

}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}