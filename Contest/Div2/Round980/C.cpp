#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> arr(n);
        
        // Leer y ordenar cada par
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            arr[i] = {a, b};
        }
        
        // Ordenar todos los pares por el primer elemento
        sort(arr.begin(), arr.end());
        
        // Concatenar los pares y mostrar el resultado
        for (int i = 0; i < n; ++i) {
            cout << arr[i].first << " " << arr[i].second << " ";
        }
        cout << endl;
    }
    
    return 0;
}
