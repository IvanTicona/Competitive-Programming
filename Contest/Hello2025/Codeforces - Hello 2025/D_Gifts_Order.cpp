#include <bits/stdc++.h>
using namespace std;

/*
   Opcion C (Zigzag Global):
   - "zz = sum_{i=1..n-1} of max(0, a[i+1]-a[i])"
   - Para cada update a[p] = x, ajustamos localmente zz.

   Se afirma (en la mayoría de editoriales) que "zz" da la 
   conveniencia óptima = max_{l,r}( max-min - (r-l) ).

   Complejidad: O(n) para construir zz, y O(1) por cada cambio.
*/

// Calcula el "zigzag" inicial
long long buildZigzag(const vector<long long> &a, int n) {
    long long zz = 0;
    for(int i = 1; i < n; i++){
        long long diff = a[i+1] - a[i];
        if(diff > 0) zz += diff;
    }
    return zz;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<long long> a(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        // Construimos la suma zigzag
        long long zz = buildZigzag(a, n);

        // Imprimimos la respuesta inicial (zz)
        cout << zz << "\n";

        while(q--){
            int p;
            long long x;
            cin >> p >> x;

            // 1) Quitamos la vieja contribucion de los saltos que involucraban a[p]
            //    Saltos: (p-1 -> p) y (p -> p+1), si existen
            if(p > 1){
                long long diffOld = a[p] - a[p-1];
                if(diffOld > 0) zz -= diffOld;
            }
            if(p < n){
                long long diffOld = a[p+1] - a[p];
                if(diffOld > 0) zz -= diffOld;
            }

            // 2) Actualizamos a[p] = x
            a[p] = x;

            // 3) Sumamos la nueva contribucion
            if(p > 1){
                long long diffNew = a[p] - a[p-1];
                if(diffNew > 0) zz += diffNew;
            }
            if(p < n){
                long long diffNew = a[p+1] - a[p];
                if(diffNew > 0) zz += diffNew;
            }

            // Respuesta tras cada update
            cout << zz << "\n";
        }
    }
    return 0;
}
