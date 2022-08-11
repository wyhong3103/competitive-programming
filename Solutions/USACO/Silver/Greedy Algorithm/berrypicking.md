Problem remained unsolved, failed a lot of test cases, I couldn't figure out the optimal way to collect berries, will get back to it later.
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

    vi b(n);
    for(auto& i : b) cin >> i;

    sort(b.rbegin(), b.rend());

    map<int,int> basket;


    int p = 0;
    for(int i{}; i < k; i++){
        if (p < n){
            if (!basket.count(b[p])) basket[b[p]] = 0;
            basket[b[p]]++;
            p++;
        }else{
            if (!basket.count(0)) basket[0] = 0;
            basket[0]++;
        }
    }

    auto it = --basket.end();

    while (true){
        int mn = basket.begin()->fir;
        if (((it->fir)/ 2) > mn){
            basket[mn]--;
            if (basket[mn] == 0){
                basket.erase(mn);
            }
            if(!basket.count((it->fir)/2)) basket[(it->fir)/2] = 0;
            basket[(it->fir)/2]++;
            if(!basket.count((it->fir)/2) + (it->fir % 2 != 0 ? 1 : 0)) basket[((it->fir)/2) + (it->fir % 2 != 0 ? 1 : 0)] = 0;
            basket[((it->fir)/2) + (it->fir % 2 != 0 ? 1 : 0)]++;
            basket[it->fir]--;
            if (basket[it->fir] == 0){
                int val = it->fir;
                basket.erase(val);
            }
            it = --basket.end();
        }else{
            break;
        }
    }

    
    ll total = 0;
    int count = 0;
    for(auto& i : basket){
        while (i.sec){
            if (count < (k/2)){
               total += i.fir; 
            }
            i.sec--;
            count++;
        }
    }

    cout << total;
    
}
 
int main(){
    //setio("berries");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```