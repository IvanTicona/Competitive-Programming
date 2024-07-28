#include <bits/stdc++.h>

using namespace std;

// Función para verificar si un número es primo
bool isPrime(int num){
  if (num <= 1)
    return false;
  if (num == 2)
    return true;
  if (num % 2 == 0)
    return false;
  for (int i = 3; i <= sqrt(num); i += 2){
    if (num % i == 0)
      return false;
  }
  return true;
}

// Función para verificar si todos los prefijos de las filas y columnas son primos
bool isSuperprimeGrid(const vector<vector<int>> &grid, int n, int m){

  // Verificar filas
  for (int i = 0; i < n; ++i){
    string num = "";
    for (int j = 0; j < m; ++j){
      num += to_string(grid[i][j]);
      if (!isPrime(stoi(num))){
        return false;
      }
    }
  }

  // Verificar columnas
  for (int j = 0; j < m; ++j){
    string num = "";
    for (int i = 0; i < n; ++i){
      num += to_string(grid[i][j]);
      if (!isPrime(stoi(num))){
        return false;
      }
    }
  }

  return true;
}

void showGrid(vector<vector<int>> &grid){
  cout<<endl;
  for (int i = 0; i < grid.size(); i++){
    for (int j = 0; j < grid[i].size(); j++){
      cout<<grid[i][j]<<" ";
    }
    cout<<endl;
  }
}

// Función recursiva para generar todas las posibles cuadrículas
void generateGrids(vector<vector<int>> &grid, int n, int m, int i, int j, int &count){
  if (i == n){
    if (isSuperprimeGrid(grid, n, m)){
      // showGrid(grid);
      count++;
    }
    return;
  }

  if (j == m){
    generateGrids(grid, n, m, i + 1, 0, count);
    return;
  }

  for (int digit = 0; digit <= 9; ++digit){
    grid[i][j] = digit;
    generateGrids(grid, n, m, i, j + 1, count);
  }
}

int main(){
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m, 0));
  int count = 0;

  generateGrids(grid, n, m, 0, 0, count);

  cout << count << endl;

  return 0;
}
