/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>
#define M_PI 3.14159265358979323846

using namespace std;

struct Point
{
  double inicia;
  int pos;
  Point(double a, int c){
    inicia = a;
    pos = c;
  }
};

bool operator<(Point a, Point b){
  return a.inicia < b.inicia;
}

int main(){

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int grado, n; cin >> grado >> n;
  priority_queue<Point> linea;
  for (int i = 0; i < n; i++)
  {
    int x, h; cin >> x >> h;
    double t = h / tan(((2 * M_PI) * grado) / 360);
    double y = x + t;
    linea.push(Point(x, 1));
    linea.push(Point(y, -1));
  }

  double sum = 0.0;
  int cnt = 0;
  double last = 0.0;
  while (!linea.empty())
  {
    Point p = linea.top(); linea.pop();
    if(cnt == 0) last = p.inicia;
    cnt += p.pos;
    if(cnt == 0) sum += (last - p.inicia);
  }
  cout << sum << endl;

  return 0;
}