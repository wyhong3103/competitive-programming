A math way of solving it, pretty dumb. I just don't see how we can apply binary search on this problem. 
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
    int t;
    cin >> t;
    while(t--){
        int h, c, t;
        cin >> h >> c >> t;
 
        double val = ((t - c)/(double)((2*t) - h - c));
        //This formula is derrived from the average formula
        long double diff = abs(t- (((h * ceil(val)) + (c * (ceil(val)-1)))/(long double)((ceil(val)*2)-1)));
        long double diff1 = abs(t- (((h * floor(val)) + (c * (floor(val)-1)))/(long double)((floor(val)*2)-1)));
        int ans = (diff >= diff1 ? floor(val) : ceil(val));
        diff = (diff > diff1 ? diff1 : diff);
        cout << (ans <= 0 || ((2*t)-h-c == 0) || abs(t - ((h+c)/1.0)) < diff ? 2 : (ans*2)-1) << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```