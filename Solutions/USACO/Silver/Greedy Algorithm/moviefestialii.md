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
    int n, k;
    cin >> n >> k;
    
    vector<pi> movies(n);

    for(auto& i : movies) cin >> i.sec >> i.fir;

    sort(all(movies));

    ll total = 0;
    queue<int> q;

    for(auto& i : movies){
        if (sz(q) < k){
            q.push(i.fir); 
            total++;
        }else{
            if (i.sec < q.front()){
                continue;
            }else{
                q.pop();
                q.push(i.fir);
                total++;
            }
        }
    }
    cout << total;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```