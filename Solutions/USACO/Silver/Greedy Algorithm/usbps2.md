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
    int a, b, c;
    cin >> a >> b >> c;

    int m;
    cin >> m;
    vector<pair<int,string>> arr(m);
    for(auto& i : arr) cin >> i.fir >> i.sec;

    sort(all(arr));

    ll total = 0, count = 0;
    for(auto& i : arr){
        if (i.sec == "USB"){
            if (!a && !c) continue;
            if (a) a--;
            else if (c) c--;
            total += i.fir;
            count++;
        }else{
            if (!b && !c) continue;
            if (b) b--;
            else if (c) c--;
            total += i.fir;
            count++;
        }
    }
    cout << count << ' ' << total;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```