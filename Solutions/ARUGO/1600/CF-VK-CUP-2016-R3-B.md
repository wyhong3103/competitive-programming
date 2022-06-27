Quite an interesting problem.
```
One key main observation is that we only need n+1 roads to make it work, and it will always work

say n = 7,

We will construct such a road,

----------------
a -- c -- random -- d -- random -- random --b
		  -----------------------------------

The path from a to b is always just the start to the end

For c to d, we could always just go from c to a to the middle value between c and d, then to b, then we would reach d by just going backward

One edge cases is when n = 4, no matter how many roads are given , it will always be impossible because remember, there cannot exist a direct path between a/b and c/d

You might be tempted to do this

a -- c -- b -- d

Well, from a to b, you might be tempted to think that maybe we could go from a -> c -> d -> b, but remember c and d cannot contain a road, so it's impossible

```
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
using pdb = pair<double,double>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

const int MAX = 1000+1;

void solve(){
    int n, k;
    cin >> n >> k;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (n == 4 || k < n+1){
        cout << -1;
        return;
    }

    set<int> available;
    for(int i{1}; i <= n; i++){
        if (i == a || i == b || i == c || i ==d) continue;
        available.insert(i);
    }


    vi order(n);
    order[0] = a;
    order[1] = c;
    order[3] = d;
    order[n-1] = b; 

    for(int i{}; i < n; i++){
        if (!order[i]){
            order[i] = *(available.begin());
            available.erase(*(available.begin()));
        }
    }

    //a to b
    for(int i{}; i < n; i++){
        cout << order[i] << ' ';
    }
    cout << '\n';

    //c to d
    for(int i{1}; i >= 0; i--) cout << order[i] << ' ';
    cout << order[2] << ' ';
    for(int i{n-1}; i >= 3; i--) cout << order[i] << ' ';
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