# Grafo Bipartito

Un grafo bipartito es un grafo cuyos vértices pueden ser divididos en dos conjuntos disjuntos U y V de tal forma que cada arista conecta un vértice de U con un vértice de V. Es decir, no existen aristas que conecten vértices del mismo conjunto.

```
// inside int main()
int s = 0;
queue<int> q; q.push(s);
vi color(n, INF); color[s] = 0;
bool isBipartite = true; // add a Boolean flag
while (!q.empty() && isBipartite) { // as with original BFS
int u = q.front(); q.pop();
for (auto &v : AL[u]) {
if (color[v] == INF) { // don’t record distances
color[v] = 1-color[u]; // just record two colors
q.push(v);
}
else if (color[v] == color[u]) { // u & v have same color
isBipartite = false; // a coloring conflict :(
break; // optional speedup
}
}
}
```