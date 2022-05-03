The tricky part of this problem is that you have to take care of some corner cases, such as an order can only be processed after day S or on day S, cannot be process earlier than that, that's the part that didn't state out in the problem statement.
```
My approach

Basically look for the best number of machines we need, it's just the tester function that is a little tricky.
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
 
bool valid(vector<pi>& a, int mid, int d, int n){
    int day = 1;
    int cur = 0;
    for(auto& i : a){
        if ((day-i.fir) >  d || day > n){
            return false;
        }
        if (i.fir > day){
            day = i.fir;
            cur = 1;
        }else{
            cur++;
        }
        if (cur == mid){
            cur = 0;
            day++;
        }
    }
    return true;
}
 
 
void solve(){
    int n, d, m;
    cin >> n >> d >> m;
 
    vector<pi> a(m);
    for(int i{}; i < m; i++){
        cin >> a[i].fir;
        a[i].sec = i+1;
    }
 
    sort(all(a));
 
    int lo = 1, hi = m;
    while (hi > lo){
        int mid = lo + (hi-lo)/2;
        if (valid(a, mid, d, n)){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }
 
    cout << lo << '\n';
    int p = 0;
    for(int i{}; i < n; i++){
        for(int j{}; j < lo; j++){
            if (p < sz(a) && a[p].fir <= i+1){
                cout << a[p].sec << ' ';
                p++;
            }else break;
        }
        cout << 0 << '\n';
    }
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```