#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("output.txt", "w", stdout);
    
    int T = 10000;       // Número de casos de prueba
    int n = 30, k = 0;   // Para cada caso: n = 30, k = 0
    cout << T << "\n";
    
    // La cadena s: 30 veces 'B'
    string s(n, 'B');
    
    // Para cada caso de prueba, imprimimos:
    // 1) La línea con n y k.
    // 2) La cadena s.
    // 3) Una línea con 30 números (todos 1000000000).
    for (int t = 0; t < T; t++){
        cout << n << " " << k << "\n";
        cout << s << "\n";
        for (int i = 0; i < n; i++){
            cout << 1000000000 << (i == n - 1 ? "\n" : " ");
        }
    }
    
    return 0;
}
