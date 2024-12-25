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
#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define MOD 1000000007
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define FORP(i, a, b, c) for (int i = a; i <= b; i += c)
#define RFORP(i, a, b, c) for (int i = a; i >= b; i -= c)
#define F first
#define S second
#define all(x) x.begin(), x.end()
// #define sort(x) sort(all(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define rv(x) for (auto &i : x) cin >> i
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

long long S(const vector<int> &p)
{
  int n = p.size();
  long long sum = 0;

  for (int l = 0; l < n; ++l)
  {
    int current_min = p[l];
    for (int r = l; r < n; ++r)
    {
      current_min = min(current_min, p[r]);
      sum += current_min;
    }
  }
  return sum;
}

void solve()
{

  ll n, k;
  cin >> n >> k;

  vector<int> perm(n);
  for (int i = 0; i < n; ++i)
    perm[i] = i + 1;

  vector<pair<long long, vector<int>>> permutations;

  do
  {
    long long S_value = S(perm);
    permutations.push_back({S_value, perm});
  } while (next_permutation(perm.begin(), perm.end()));

  long long max_S = 0;
  for (auto &p : permutations)
  {
    max_S = max(max_S, p.first);
  }

  vector<vector<int>> max_permutations;
  for (auto &p : permutations)
  {
    if (p.first == max_S)
    {
      max_permutations.push_back(p.second);
    }
  }

  sort(max_permutations.begin(), max_permutations.end());

  if (k <= max_permutations.size())
  {
    for (int i = 0; i < n; ++i)
    {
      cout << max_permutations[k - 1][i] << " ";
    }
    cout << endl;
  }
  else
  {
    cout << -1 << endl;
  }
}

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}