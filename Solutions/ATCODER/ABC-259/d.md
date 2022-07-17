A graph problem, the only problem is to determine how the circle intersects. Also, one tricky thing, it's always better to deal with integer rather than floating point!!!!! FLOATING POINT PROBLEM COST ME AN HOUR+++
```
One fact

Two circles intersect if and only if

r1-r2 <= dist of center points <= r1+r2

OR 

My own formula

Two circles intersect iff

* = circumferrence
x = center points

one circle is not inside of another, and distance <= r1+r2

**    **
x-*--*-x
**    **


one circle is inside of another, and distance >= abs(r1-r2)
This formula is derrived from, distance+r2 >= r1

  *    *    *
 *       d  r*
*      x---x--* 
 *           *
  *    *    *

In order to intersect, the sum of distance between center points and radius 2 (the inner circle's radius) must be greater or equal than the outer radius


```
```cpp
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MAX = 3000;
vi adj[MAX];
bool vis[MAX];
 
struct Circle{
    ll x, y, r;
};
 
ll distance(Circle c1, Circle c2){
    return ((c1.x-c2.x)*(c1.x-c2.x)) + ((c1.y-c2.y)*(c1.y-c2.y));
}
 
bool reachable(Circle& c1, Circle& c2){
    ll dist = distance(c1,c2);
 
    return ((c1.r-c2.r) * (c1.r-c2.r) <= dist && dist <= abs(c1.r+c2.r) * abs(c1.r+c2.r));
}
 
/* Other Way of determining whether two circles intersect
bool reachable(Circle& c1, Circle& c2){
    ll dist = distance(c1,c2);

    if (dist >= c1.r * c1.r && dist >= c2.r * c2.r){
        return (dist <= (c1.r + c2.r) * (c1.r+c2.r));
    }else{
        return (dist >= (c1.r-c2.r)*(c1.r-c2.r));
    }
}

*/
void dfs(int node, bool& found, int tlo){
    if (vis[node]) return;
    if (node == tlo){
        found = 1;
        return;
    }
 
    vis[node] = 1;
    for(auto& i :adj[node]){
       dfs(i, found, tlo);
    }
}
 
void solve(){
    int n;
    cin >> n;
 
    pll f, t;
    cin >> f.fir >> f.sec >> t.fir >> t.sec;
 
    int flo = -1, tlo = -1;
    vector<Circle> circles(n);
    for(int i{}; i < n; i++){
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
        if (distance(circles[i], {f.fir, f.sec, 0}) == circles[i].r * circles[i].r) flo = i;
        if (distance(circles[i], {t.fir, t.sec, 0}) == circles[i].r * circles[i].r) tlo = i;
    }
 
 
    if (flo == -1 || tlo == -1){
        cout << "No";
        return;
    }
 
    //construct edges
    for(int i{}; i < n; i++){
        for(int j{i+1}; j < n; j++){
            if (reachable(circles[i], circles[j])){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
 
    bool found = 0;
    dfs(flo, found, tlo);
 
    cout << (found ? "Yes" : "No");
 
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}
```