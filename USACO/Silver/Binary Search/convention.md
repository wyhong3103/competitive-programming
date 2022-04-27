The idea is to basically binary search the waiting time, a bus can holds up to C cows, but it didn't mean that we must get C cows onto the bus to get it started. We want to minimize the waiting time, so we will test the waiting time using valid(), basically, if a waiting time is valid, that means, it's feasible, all the cows can still make it into M buses.
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

bool valid(vi& a,int t, int m, int c){
    ll bus = 0;
    ll cur = a[0];
    ll cows = 1;
    for(int i{1}; i < sz(a); i++){
        if (a[i] - cur > t || cows >= c){
            cur = a[i];
            cows = 1;
            bus++;
        }else{
            cows++;
        }
    }
    //Left over
    if (cur) bus++;

    return bus <= m;
}
 
void solve(){ 
    int n, m, c;
    cin >> n >> m >> c;

    vi a(n);
    for(auto& i : a)cin >> i;
    sort(all(a));

    ll lo = 0, hi = a[n-1]-a[0];

    while (hi > lo){
        int mid = lo + (hi-lo)/2;
        if (valid(a,mid,m,c)){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }

    cout << lo;
}
 
int main(){
    setio("convention");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```