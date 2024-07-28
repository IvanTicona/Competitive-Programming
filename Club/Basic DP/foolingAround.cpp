/* Kattis - foolingaround
Whoever said precomputable problems were fast to solve?? One needs some skill to actually precompute in a reasonable
time.

Observation 0:
    Checking each n from 1 to 1e9 naively by checking all possible games is very very very obviously gonna take too long.
    We need to at least try to use brain to make our complete search viable

Observation 1:
    Notice there are many overlapping sub problems:
        if there exist p-1 such that that a loses (n-(p-1)), it means that a can win a since he will pick p-1 and 
        because the first player loses (n-(p-1)), b will lose once he starts his round with n-(p-1), allowing a to win.

        Thus solving the problem for n-(p-1) allows us to solve for n
    
    As such, we can use dynamic programming to memorise solutions for each n

Observation 2:
    If we try to apply the above directly, trying each value of p < n for all n, 
    we will quickly realise its still way too slow... 

    this is because actually a wins for most values of n (b only wins 0.0000379% of the time), making it hard to
    determine a value n-(p-1) that b loses. This can be deduced from the fact that a gets to choose what to pick first, allowing it a much bigger advantage rather than b which
    is already 1 step behind. Some of you might note how the first player in normal games of Nim also have a big advantage
    and generalise this to this variant.

Idea 1:
    We draw inspiration from the sieve of eratosthenes. For each n that a loses, a will win all n+(p-1). So we 
    process n upwards from 1, whenever a loses, we set a to win n+(p-1) for all p with n+(p-1) < 1e9.

    This way, we only perform O(number of times b wins * number of p < 1e9) operations rather than O(number of times a
    wins * number of p < 1e9) which is much (much) faster

    Doing so results in a managable completion time of the program (about 5 mins)

Time: O(1), Mem: O(1)
*/ 


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
ll _sieve_size;
bitset<1000000010> bs; // 10^7 is the rough limit
vll p;
vector<int> v_b_w;

bitset<1000000010> a_wins;

void sieve(ll upperbound)
{                                 // range = [0..upperbound]
    _sieve_size = upperbound + 1; // to include upperbound
    bs.set();                     // all 1s
    bs[0] = bs[1] = 0;            // except index 0+1
    for (ll i = 2; i < _sieve_size; ++i)
        if (bs[i])
        {
            // cross out multiples of i starting from i*i
            for (ll j = i * i; j < _sieve_size; j += i)
                bs[j] = 0;
            p.push_back(i); // add prime i to the list
        }
}

int main()
{
    
    ll upperbound = 1e9;
    sieve(upperbound);
    printf("Finished sieving\n");
    a_wins[1] = 1;
    a_wins[2] = 1;
    
    for (int i=0;i<=upperbound;i++){
        if (a_wins[i])continue;

        for (auto prime:p){
            ll candidate = i + prime - 1; // 1 less than prime;
            if (candidate <= upperbound){
                a_wins[candidate] = 1;
            }
            else break;
        }

        v_b_w.emplace_back(i);
        cout << "b wins: " << i << endl;
    }
    
    cout << " LIST OF B WINS \n";
    for (auto i: v_b_w){
        cout << i << endl;
    }

    cout << "Number of B wins: " << v_b_w.size() << endl;
    

    // int b_win_arr[379] = { 3,
    //                          8,
    //                          11,
    //                          32,
    //                          35,
    //                          56,
    //                          59,
    //                          64,
    //                          67,
    //                          118,
    //                          121,
    //                          208,
    //                          211,
    //                          216,
    //                          219,
    //                          622,
    //                          625,
    //                          712,
    //                          715,
    //                          720,
    //                          723,
    //                          744,
    //                          747,
    //                          896,
    //                          899,
    //                          986,
    //                          989,
    //                          2560,
    //                          2563,
    //                          2778,
    //                          2781,
    //                          3806,
    //                          3809,
    //                          3890,
    //                          3893,
    //                          4198,
    //                          4201,
    //                          4584,
    //                          4587,
    //                          5338,
    //                          5341,
    //                          5458,
    //                          5461,
    //                          5962,
    //                          5965,
    //                          8642,
    //                          8645,
    //                          12084,
    //                          12087,
    //                          12772,
    //                          12775,
    //                          13602,
    //                          13605,
    //                          14012,
    //                          14015,
    //                          17336,
    //                          17339,
    //                          18016,
    //                          18019,
    //                          19310,
    //                          19313,
    //                          20940,
    //                          20943,
    //                          26374,
    //                          26377,
    //                          29320,
    //                          29323,
    //                          38154,
    //                          38157,
    //                          42662,
    //                          42665,
    //                          43502,
    //                          43505,
    //                          45930,
    //                          45933,
    //                          49686,
    //                          49689,
    //                          60066,
    //                          60069,
    //                          64476,
    //                          64479,
    //                          72448,
    //                          72451,
    //                          83956,
    //                          83959,
    //                          91046,
    //                          91049,
    //                          93740,
    //                          93743,
    //                          96310,
    //                          96313,
    //                          118766,
    //                          118769,
    //                          123806,
    //                          123809,
    //                          143434,
    //                          143437,
    //                          147712,
    //                          147715,
    //                          154866,
    //                          154869,
    //                          170090,
    //                          170093,
    //                          187820,
    //                          187823,
    //                          209752,
    //                          209755,
    //                          244800,
    //                          244803,
    //                          273474,
    //                          273477,
    //                          347428,
    //                          347431,
    //                          382530,
    //                          382533,
    //                          402720,
    //                          402723,
    //                          467274,
    //                          467277,
    //                          543812,
    //                          543815,
    //                          561334,
    //                          561337,
    //                          580884,
    //                          580887,
    //                          607694,
    //                          607697,
    //                          665034,
    //                          665037,
    //                          686696,
    //                          686699,
    //                          693306,
    //                          693309,
    //                          816300,
    //                          816303,
    //                          960620,
    //                          960623,
    //                          960964,
    //                          960967,
    //                          1024258,
    //                          1024261,
    //                          1157516,
    //                          1157519,
    //                          1340720,
    //                          1340723,
    //                          1377504,
    //                          1377507,
    //                          1412330,
    //                          1412333,
    //                          1454878,
    //                          1454881,
    //                          1488314,
    //                          1488317,
    //                          1608896,
    //                          1608899,
    //                          1907342,
    //                          1907345,
    //                          1915204,
    //                          1915207,
    //                          1953088,
    //                          1953091,
    //                          2011552,
    //                          2011555,
    //                          2053088,
    //                          2053091,
    //                          2218520,
    //                          2218523,
    //                          2439860,
    //                          2439863,
    //                          2506800,
    //                          2506803,
    //                          2792760,
    //                          2792763,
    //                          2818000,
    //                          2818003,
    //                          3058974,
    //                          3058977,
    //                          3692938,
    //                          3692941,
    //                          3810186,
    //                          3810189,
    //                          3850764,
    //                          3850767,
    //                          4240946,
    //                          4240949,
    //                          5380204,
    //                          5380207,
    //                          5484644,
    //                          5484647,
    //                          5632196,
    //                          5632199,
    //                          6136490,
    //                          6136493,
    //                          6929080,
    //                          6929083,
    //                          7019280,
    //                          7019283,
    //                          7163844,
    //                          7163847,
    //                          7339412,
    //                          7339415,
    //                          8299624,
    //                          8299627,
    //                          9702450,
    //                          9702453,
    //                          10000910,
    //                          10000913,
    //                          11404634,
    //                          11404637,
    //                          13368688,
    //                          13368691,
    //                          13509604,
    //                          13509607,
    //                          13750138,
    //                          13750141,
    //                          15095790,
    //                          15095793,
    //                          16166924,
    //                          16166927,
    //                          16409144,
    //                          16409147,
    //                          17105420,
    //                          17105423,
    //                          17412348,
    //                          17412351,
    //                          17820008,
    //                          17820011,
    //                          20007958,
    //                          20007961,
    //                          20693774,
    //                          20693777,
    //                          22045460,
    //                          22045463,
    //                          23380094,
    //                          23380097,
    //                          24789334,
    //                          24789337,
    //                          25126678,
    //                          25126681,
    //                          26647980,
    //                          26647983,
    //                          27683252,
    //                          27683255,
    //                          27781826,
    //                          27781829,
    //                          28640628,
    //                          28640631,
    //                          33645474,
    //                          33645477,
    //                          36104218,
    //                          36104221,
    //                          36190982,
    //                          36190985,
    //                          36607498,
    //                          36607501,
    //                          36830424,
    //                          36830427,
    //                          38880354,
    //                          38880357,
    //                          40010700,
    //                          40010703,
    //                          42600652,
    //                          42600655,
    //                          46883338,
    //                          46883341,
    //                          47261042,
    //                          47261045,
    //                          50441582,
    //                          50441585,
    //                          50806108,
    //                          50806111,
    //                          51326550,
    //                          51326553,
    //                          63270628,
    //                          63270631,
    //                          73376298,
    //                          73376301,
    //                          79246954,
    //                          79246957,
    //                          85507614,
    //                          85507617,
    //                          86494788,
    //                          86494791,
    //                          87659372,
    //                          87659375,
    //                          93188572,
    //                          93188575,
    //                          102490320,
    //                          102490323,
    //                          111387292,
    //                          111387295,
    //                          117666362,
    //                          117666365,
    //                          125481924,
    //                          125481927,
    //                          125946452,
    //                          125946455,
    //                          129257606,
    //                          129257609,
    //                          131533502,
    //                          131533505,
    //                          148061544,
    //                          148061547,
    //                          154708884,
    //                          154708887,
    //                          156257698,
    //                          156257701,
    //                          164235208,
    //                          164235211,
    //                          174422902,
    //                          174422905,
    //                          177543326,
    //                          177543329,
    //                          200688798,
    //                          200688801,
    //                          203517204,
    //                          203517207,
    //                          227993998,
    //                          227994001,
    //                          235532762,
    //                          235532765,
    //                          239063820,
    //                          239063823,
    //                          241476986,
    //                          241476989,
    //                          251732672,
    //                          251732675,
    //                          279478702,
    //                          279478705,
    //                          281430472,
    //                          281430475,
    //                          294129388,
    //                          294129391,
    //                          300664758,
    //                          300664761,
    //                          309796952,
    //                          309796955,
    //                          315713182,
    //                          315713185,
    //                          343273582,
    //                          343273585,
    //                          364007276,
    //                          364007279,
    //                          367324042,
    //                          367324045,
    //                          373016576,
    //                          373016579,
    //                          385477086,
    //                          385477089,
    //                          405738568,
    //                          405738571,
    //                          442967366,
    //                          442967369,
    //                          480451560,
    //                          480451563,
    //                          519983304,
    //                          519983307,
    //                          536597756,
    //                          536597759,
    //                          629403140,
    //                          629403143,
    //                          713858034,
    //                          713858037,
    //                          739002982,
    //                          739002985,
    //                          809065744,
    //                          809065747,
    //                          813583138,
    //                          813583141,
    //                          822228058,
    //                          822228061,
    //                          830259270,
    //                          830259273,
    //                          834828324,
    //                          834828327,
    //                          916215504,
    //                          916215507,
    //                          978364206,
    //                          978364209,
    // };

    // int n, q;
    // cin >> q;
    // for (int i=0;i<q;i++){
    //     cin >> n;
    //     bool b_win = false;
    //     for (int j=0;j<379;j++){
    //         if (b_win_arr[j] == n){
    //             b_win = true;
    //         }
    //     }

    //     if (b_win){
    //         cout << "Bob\n";
    //     }
    //     else cout << "Alice\n";
    // }


    return 0;
}