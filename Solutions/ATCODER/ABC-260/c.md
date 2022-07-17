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
 
ll memo_red[11];
ll memo_blue[11];
 
//0 = red, 1 = blue
ll recur(int n, int x, int y, bool color){
    if (n < 2) return (color);
    if (color){
        if (memo_blue[n]) return memo_blue[n];
        ll& temp = memo_blue[n];
        temp = recur(n-1,x,y,0) + (y * recur(n-1,x,y,1));
        return temp;
    }else{
        if (memo_red[n]) return memo_red[n];
        ll& temp = memo_red[n];
        temp = recur(n-1,x,y,0) + (x * recur(n,x,y,1));
        return temp;
    }
}
 
void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    cout << recur(n,x,y,0);
 
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