/*
Author: Ivan Ticona

::::::::---=========++++**********++*#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%######****+++==-----:::::::::::...
::::-------=======+++++******########%%@@@@@@@@%%############%%@@@@@@@@%%%%%%#######***++===----:::::::::::...
:::---------=======++++*****#########%%@@@@@%#***++*+**********##%%@@@@%%%%%%########***++===----:::::::::::..
::-------------=====++++****########%%%@@@%#*++++++++++***++******###%@%%%%%%########***++===-----:::::::::::.
::-------------======++++****#######%%%%@%#++====++++++++=+++++++++*+=*%%%%%%########***+++==------::::::::::.
::------------======++++*****########%%%%%*=========++=============*+-:-+#%%%#######****+++==------:::::::::::
:::-:::---------=====+++*****########%%%%#+=====================++=+*-:::-=+#######*****+++===----------::::::
::--------------=====++++*****#####%%%%%%#========================-=*#+-::-====*####****+++===------------::::
::---------------=====+++*****#####%%%%%%*-:--===================-::=%%#+::-=#+===*##***+++===-------------:::
::--------------======+++*****#####%%%%%#-:::::-===========---::::::-#%%%*-:-=##*=-=+***+++====------------:::
:-----------=========++++***######%%%%%%%=::::::::::::--::::::::::::-#%%%%*-:-=###+=--=+*++====-----------::::
------------=========+++***##%%%%%%%%%%%%*-:::::::::::::::..:.:::::-+%%%%%%+---*###*=---=+++===----------:::::
=--------===---=====+++**###%%%%%%%%%%%%%%=-:...::::::--:::..::..:-=*%%%##%#=--=#####+---=++===---------::::::
----------====-====++++**##%%%%%%%%%%%%%%%=::........:::::......::-+#%%#####=--=*####*=---=++==---------::::::
------------======++++***##%%%%%%%%%%%%%%%#=::...................:-*%%%###%#+=#*#####*+=--=++===-------:::::::
-------:::----====+++**###%%%%%%%%%%%%%%%%%#=-==-:.....:.....:----*#%%%%%%%#++%#######*=---=+===-------::::::.
::::::::::::---==+++**##%%%%%%%%%%%%%%@%%%%%#==++=-::=##+-:-+++--*%%##%%%%%#++#%######*+=--=++===-----:::::::.
....:::::::::::-----===++*****#%%%%%%%%%%%%%%+-=+++==-:::-=+++=-=#%%%%%%%%#+==#########++==+*++===----::::::::
....::..::::::::---=====+*##*****+++*#%%%%%%%#---==---------=-::+%%%%%%%%*+=+##%%%%###*+++++***++===---:::::::
..:........:::--==++*##%%%%%%%#*+==----=+#%%#=...:-+******+-:..:-+#%@@%*===+####%%%##+--=+*******++===-------:
::::......::::--==+**##%%%%%%%%%%%#**##%##*+=-:...:--==---:....:-++*##%%%##%##%%%%%#+--:=+******#**++=======--
---:::::::::::--=++**#%%%%##%%%@@@%%##*++==-:::......:::.......:-=+****##%%%%%%%%%#*+=-=+******###**+=========
------::::::::--=+**#%%@@@%%%%%%##**++==----:::.:..............::--===++***###%%%%%%%%%%%##**++***++==--======
------::..:::--=+#%%%%%########***+==-------::::-:..........:--:::-----==+++**################***+==----=====-
:::---::.:::-+##############***++++=---===========::.::::.::-=-=======---=====++*******###***####*+=----=-----
..:::-----=*###********####***+===+++**#####***+++-:::-----=+++++++++++====-----==++************##*+=-------::
*/
#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define sz(x) (int)x.size()
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vb;

bool solve(){
  int n; cin >> n;
  vi p(n);
  set<int> nums;
  for(int &i: p){
    cin >> i;
    nums.insert(i);
  }

  if(nums.size() != n || *max_element(all(p)) > n) return false;

  for (int i = 0; i < n; i++)
  {
    if(abs((i+1) - p[i]) > 1) return false;
  }

  return true;
}


int main(){

  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while(t--){
    if(solve()){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }

  return 0;
}