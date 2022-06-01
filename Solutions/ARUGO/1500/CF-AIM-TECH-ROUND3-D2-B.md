This is honestly a stupid problem. You basically have to identify the edge cases, and it's either not visiting the first cell or last cell. And also the way you travels matter as well, it's either you go to the second cell and then back to your initial position , which needs to * 2, then go the last cell, or goes in the opposite direction, we need this because , in some cases, it's better to make a U-turn from one side than another. And then the last case, travels from first cell to the second last cell.
```cpp
#include <bits/stdc++.h>
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
    int n, a;
    cin >> n >> a;

    vi x(n);
    for(auto& i : x) cin >> i;
    sort(all(x));

    if (n <= 2) cout << min(abs(x[0]-a), (n > 1 ? abs(x[1]-a) : 0));
    else cout << min({(abs(x[n-1]-a)*(x[1] < a ? 2 : 1)) + (x[1] < a ? abs(x[1]-a) : 0), (abs(x[1]-a)*(x[n-1] > a ? 2 : 1)) + (x[n-1] > a ? abs(x[n-1]-a) : 0),(abs(x[n-2]-a)*(x[0] < a ? 2 : 1)) + (x[0] < a ? abs(x[0]-a) : 0), (abs(x[0]-a)*(x[n-2] > a ? 2 : 1)) + (x[n-2] > a ? abs(x[n-2]-a) : 0)});
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```