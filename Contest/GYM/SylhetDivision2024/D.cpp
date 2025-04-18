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

void solve(){
  int n; cin >> n;
  if(n <= 6){
    cout << 6 << endl;
  }
  else if(n <= 9){
    cout << 9 << endl;
  }
  else if(n <= 66){
    cout << 66 << endl;
  }
  else if(n <= 69){
    cout << 69 << endl;
  }
  else if(n <= 96){
    cout << 96 << endl;
  }
  else{
    cout << 99 << endl;
  }
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}