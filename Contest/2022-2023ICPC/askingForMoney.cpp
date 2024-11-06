/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

vector<int> grafo[1010];
bool vis[1010];

void dfs(int nodo, int bad, vector<int>& alcance) {
    vis[nodo] = true;
    alcance[nodo]++;
    
    for (int vecino: grafo[nodo]) {
        if (vecino != bad && !vis[vecino]) {
            dfs(vecino, bad, alcance);
        }
    }
}

int main(){

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n; 
    cin >> n;
    
    vector<pair<int, int>> personas(n);
    
    // Leer las conexiones
    for (int i = 0; i < n; i++) {
        int x, y; 
        cin >> x >> y;
        x--, y--;
        personas[i] = {x, y};
        grafo[x].push_back(i);
        grafo[y].push_back(i);
    }

    // Para cada persona evaluamos si pueden perder dinero
    for (int i = 0; i < n; i++) {
        vector<int> alcance(n, 0);
        
        // Evaluamos a las tres personas involucradas: la persona i y sus dos conexiones
        vector<int> chequeo = {i, personas[i].first, personas[i].second};
        
        // Realizamos DFS desde las tres personas
        for (int start : chequeo) {
            memset(vis, false, sizeof(vis));
            dfs(start, i, alcance);
        }
        
        // Si alguna persona es alcanzada 3 veces, indica un ciclo completo
        bool pierde = false;
        for (int j = 0; j < n; j++) {
            if (alcance[j] == 3) {
                pierde = true;
                break;
            }
        }
        
        cout << (pierde ? "Y" : "N");
    }
    
    cout << endl;
    
    return 0;
}
