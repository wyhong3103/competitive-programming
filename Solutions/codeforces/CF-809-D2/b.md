```
The size of a tower with color c, is the maximum consecutive blocks of c placed vertically

You can only place the block in the order given, and you can place only place at i-1 th block left, above, right, never below it. So for 1,2,3,4 ,it kind of goes like this
    
			   4
  			   3
    3 4  	   2		  3 4	
	2 1   Or   1   Or   1 2

Any pattern literally.

And we are to find the maximum size we could build for towers of each color

Notice that to stack the same color together, the entire towers can only look like below

      1 x
    x 1 x
	x 1

Notice that to stack the blocks together, there will always need to be 2x blocks between them.

So now this lead us to an important observation which is, a block can be stack onto a block, if and only if one is even and one is odd, and that's our job to find the maximum length of consecutive odd to even, vice versa blocks for each color.
```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n;
    cin >> n;
    vector<vi> colors(n);
 
    for(int i{}; i < n; i++){
        int c;
        cin >> c;
        c--;
        colors[c].pb(i);
    }
    
 
 
    vi res(n);
    for(int i{}; i < n; i++){
        if (!sz(colors[i])) continue;
        int cur = -1;
        int cnt = 0;
        for(auto& i : colors[i]){
            if (cur == -1){
                cur = i % 2;
                cnt++;
            }
            else if (i % 2 != cur){
                cur = i % 2;
                cnt++;
            }
        }
        res[i] = cnt;
    }
 
    for(auto& i : res) cout << i << ' ';
    cout << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}
```