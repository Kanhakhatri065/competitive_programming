#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <cmath>
 
#define X first
#define Y second
 
using namespace std;
 
int n, m;
int a[200001];
pair<int, pair<int, int> > Q[200001];
int fen[200001];
int ans[200001];
 
void up(int v, int val){
     while (v <= n){
           fen[v] += val;
           v = (v | (v + 1));
     }
}
 
int get(int v){
    int rez = 0;
    while (v > 0){
          rez += fen[v];
          v = (v & (v + 1)) - 1;
    }
    
    return rez;
}
 
int Next(int v){
        int lo = 0;
        int hi = v;
        while (lo + 1 < hi){
              int c = (lo + hi) / 2;
              if (get(c) == get(v)) hi = c; else lo = c;
        }
        
        return hi;
    
}
 
int main(){   
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d",a + i);
        up(i, 1);
    }
    
    scanf("%d", &m);
    for (int i = 1; i <= m; i++){
        int d, t;
        scanf("%d%d", &t, &d);
        Q[i].X = d;
        Q[i].Y.X = t;
        Q[i].Y.Y = i;
    }
    
    sort(Q + 1, Q + m + 1);
    
    for (int i = 1; i <= m; i++){
        int d = Q[i].X;
        int t = Q[i].Y.X;
        int num = Q[i].Y.Y;
        
        int l = 1;
        int r = n + 1;
        while (l + 1 < r){
              int c = (l + r) / 2;             
              if (a[c] <= t) l = c; else r = c;
        }
                     
        int poz = Next(l);
        
        while (poz > 1){
              if (a[poz] - a[poz - 1] > d) break;
              up(poz, -1);
              poz = Next(poz - 1);
        }
        ans[num] = poz;
    }
    
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    
   // system("pause");
    return 0;
} 
