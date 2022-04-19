One way to do this is by using binary search, but we will show two pointers approach
```
So basically, we want to find the minimal distance, the cellular tower need to cover, so that all cities are covered by cellular network

Example,

3 2
-2 2 4
-3 0
// All orders are in non-decreasing order


One key observation is that, every tower can cover every city if needed, but that isn't necessary, because if one tower cover one city and it requires more distance, it can probably be done with less distance with the next tower

So the idea is to use first pointer on the cities, second pointer on the cellular tower

And to compare them

If the distance between the city and the tower the second pointer is pointing at is greater than the distance between the city and the next tower, then we will switch to next tower

That's the gist of it, and also, if the second pointer is pointing at the last tower, there's no more other options , so we will have to stick to the last tower.
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
 
 
void solve(){
    int n, m;
    cin >> n >> m;

    vi a(n);
    for(auto& i : a)cin >> i;
    vi b(m);
    for(auto& i : b)cin >> i;

    int mx = 0;
    int p1 = 0, p2 = 0;
    while (p1 < n){
        if (p2 != m-1){
            if (abs(a[p1] - b[p2]) < abs(a[p1] - b[p2+1])){
                mx = max(mx, abs(a[p1] - b[p2]));
                p1++;
            }else{
                p2++; 
            }
        }else{
                mx = max(mx, abs(a[p1] - b[p2]));
                p1++;
        }
    }

    cout << mx;
}
    
 
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```
