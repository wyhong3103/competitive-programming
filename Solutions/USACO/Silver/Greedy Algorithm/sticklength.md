Basically finding the median
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
    int n;
    cin >> n;
    
    vi a(n);
    for(auto& i : a) cin >> i;

    sort(all(a));

    int number = a[(n/2)];

    ll count = 0;
    for(int i{}; i < n; i++){
        count += abs(a[i] - number);
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