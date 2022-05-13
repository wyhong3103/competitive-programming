So this problem is simply about recursively looking for the solution, at each state, you will have 6 new states each time. so the time complexity is actually 6^k. We cannot afford that by just simply doing recusion, because it will become really big, but one thing we can do is to not to repeat a certain steps.
```
For example, 

At one point you might have (x,y), with n steps left

At another point you might ends up having the same (x,y), and you might want to skip this, because you have already done the same thing, but one thing to take note of is that, sometimes by revisiting can gives you better result, ONLY when the remaining number of steps , n, is bigger than the last time, so that's exactly what are we going to do, instead of using a bool to decide if we're going to visit a pair of (x,y) again, we store the steps, if the steps is bigger than the first time we visit it, then yes we can do it again, else skip it.
```
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

const int MAX = 102;
int ans = INT_MAX;
int x, y, k, m;
int vis[MAX][MAX];

void dfs(int a, int b, int n){
    //If n < 0, (no more steps), or n is smaller or equal to previous visit
    if (n <= vis[a][b] || n < 0) return;

    vis[a][b] = n;
    ans = min(ans, abs(m - (a+b)));

    //All 6 combinations
    //Filling a
    dfs(x, b, n-1);
    //Filling b
    dfs(a, y, n-1);
    //Emptying a
    dfs(0, b, n-1);
    //Emptying b
    dfs(a, 0, n-1);
    //Pouring b to a, until one is full or one is empty
    dfs(min(x, a+b), b-min(x-a, b), n-1);
    //Pouring a to b, until one is full or one is empty
    dfs(a-min(y-b, a), min(y, a+b), n-1);
}


void solve(){
    cin >> x >> y >> k >> m;
    memset(vis,-1,sizeof(vis));
    //Initialize all as -1, became sometimes the optimal step might be at 0
    dfs(0,0, k);
    cout << ans;
}

int main(){
    setio("pails");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

```