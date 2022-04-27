Sorting + Two pointers
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
    int n, m, k;
    cin >> n >> m >> k;

    vi c(n);
    for(auto& i : c) cin >> i;
    
    vi a(m);
    for(auto& i : a) cin >> i;

    sort(all(c));
    sort(all(a));

    int count = 0;
    int p1 = 0, p2 = 0;
    while (p1 < n && p2 < m){
        if (c[p1] - a[p2] < -k){
            p1++; 
        }else if (c[p1] - a[p2] > k){
            p2++;
        }else{
            count++;
            p1++; p2++;
        }
    }
    cout << count;

}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```