Another way of solving this problem, and two pointers is definitely faster! So my approach is literally getting the distance of the closest cellular tower to a city. And get the maximum of the distance.
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
    for(auto& i : a) cin >> i;
    
    set<int> b;
    for(int i{}; i < m; i++){
        int x;
        cin >> x;
        b.insert(x);
    }

    int ans = 0;
    for(int i{}; i < n; i++){
        auto it = b.lower_bound(a[i]);
        int dist = abs(a[i] - *(it));
        if (it == b.end()) dist = numeric_limits<int>::max();
        if (it != b.begin()){
             dist = min(dist, abs(a[i] - *(--it)));
        }
        ans = max(ans, dist);
    }
    cout << ans;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```