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

void solve(){

  string n; cin >> n;

  int sum = 0;
  int count_2 = 0, count_3 = 0;

  for (char c : n) {
    int digit = c - '0';
    sum += digit;
    if (digit == 2) count_2++;
    if (digit == 3) count_3++;
  }

  if (sum % 9 == 0) {
    cout << "YES\n";
    return;
  }

  bool possible = false;
  for (int use_2 = 0; use_2 <= count_2; ++use_2) {
    for (int use_3 = 0; use_3 <= count_3; ++use_3) {
      int extra = use_2 * 2 + use_3 * 6;
      if ((sum + extra) % 9 == 0) {
        possible = true;
        break;
      }
    }
    if (possible) break;
  }

  cout << (possible ? "YES" : "NO") << "\n";
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