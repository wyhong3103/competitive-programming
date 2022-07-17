Formula.
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
 
double to_rad(double d){
    return (d * acos(-1))/180;
}
 
void solve(){
    double a, b, d;
    cin >> a >> b >> d;
 
 
    cout << setprecision(10) << fixed;
    cout << (a * cos(to_rad(d))) - (b * sin(to_rad(d))) << ' ' << (a * sin(to_rad(d))) + (b * cos(to_rad(d)));
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