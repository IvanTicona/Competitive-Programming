#include <bits/stdc++.h>

using namespace std;

const int MAX_R = 4;
const int MAX_C = 4;

// Direcciones para moverse en el tablero
int dr4[4] = {0, 1, 0, -1};
int dc4[4] = {1, 0, -1, 0};
int dr8[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dc8[8] = {1, 0, -1, 0, 1, -1, 1, -1};

// Verifica si las coordenadas están dentro de los límites del tablero
bool isValid(int x, int y, int R, int C) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

bool checkPolygon(int R, int C, int p) {
    if (p == 0) return false; // no es un polígono si no hay chocolates

    vector<vector<int>> board(R, vector<int>(C, 0));
    pair<int, int> source = {-1, -1};

    // Llenar el tablero según la máscara p
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if ((1 << (r * C + c)) & p) {
                board[r][c] = 1;
                if (source == make_pair(-1, -1)) {
                    source = {r, c};
                }
            }
        }
    }

    // Verificar si todos los chocolates están en un solo componente conectado
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    q.push(source);
    visited[source.first][source.second] = true;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr4[i];
            int nc = c + dc4[i];
            if (isValid(nr, nc, R, C) && !visited[nr][nc] && board[nr][nc] == 1) {
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (board[r][c] == 1 && !visited[r][c]) {
                return false;
            }
        }
    }

    // Verificar que todas las celdas vacías estén conectadas a los bordes
    q = queue<pair<int, int>>();
    visited = vector<vector<bool>>(R, vector<bool>(C, false));

    for (int r = 0; r < R; ++r) {
        if (board[r][0] == 0) q.push({r, 0});
        if (board[r][C-1] == 0) q.push({r, C-1});
    }
    for (int c = 1; c < C-1; ++c) {
        if (board[0][c] == 0) q.push({0, c});
        if (board[R-1][c] == 0) q.push({R-1, c});
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        visited[r][c] = true;
        for (int i = 0; i < 8; ++i) {
            int nr = r + dr8[i];
            int nc = c + dc8[i];
            if (isValid(nr, nc, R, C) && !visited[nr][nc] && board[nr][nc] == 0) {
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (board[r][c] == 0 && !visited[r][c]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int answer_matrix[MAX_R][MAX_C] = {0};

    for (int h = 1; h <= MAX_R; ++h) {
        for (int w = 1; w <= MAX_C; ++w) {
            for (int p = 1; p < (1 << (h * w)); ++p) {
                if (checkPolygon(h, w, p)) {
                    answer_matrix[h-1][w-1]++;
                }
            }
        }
    }

    for (int h = 1; h <= MAX_R; ++h) {
        for (int w = 1; w <= MAX_C; ++w) {
            cout << "Polygons for " << h << "x" << w << ": " << answer_matrix[h-1][w-1] << endl;
        }
    }

    // Lectura de la entrada
    int h, w;
    cin >> h >> w;
    cout << answer_matrix[h-1][w-1] << endl;

    return 0;
}
