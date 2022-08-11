Basically binary search, very standard problem.
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
    string s;
    int n[3];
    int p[3];
    ll r;
    cin >> s;
    cin >> n[0] >> n[1] >> n[2];
    cin >> p[0] >> p[1] >> p[2];
    cin >> r;

    int ingredient[3] = {0,0,0};
    for(auto& i : s){
        switch(i){
            case 'B':
                ingredient[0]++; 
                break;
            case 'S':
                ingredient[1]++; 
                break;
            case 'C':
                ingredient[2]++; 
                break;
        } 
    }

    auto valid = [&](ll mid){
        ll total = 0;
        ll cnt = min({n[0]/max(ingredient[0],1), n[1]/max(ingredient[1],1), n[2]/max(ingredient[2],1)});
        ll temp[3] = {ingredient[0] * (mid-cnt), ingredient[1] * (mid-cnt), ingredient[2] * (mid-cnt)};
        ll cur[3] = {n[0], n[1], n[2]};

        for(int i{}; i < 3; i++){
            cur[i] -= cnt*ingredient[i];
        } 
        for(int i{}; i < 3; i++){
            if (ingredient[i] > 0 && temp[i] > cur[i])
                total += (temp[i] - cur[i]) * p[i];
        }
        
        return (total <= r || cnt >= mid);
    };

    ll lo = 0, hi = 1e15;
    while (hi > lo){
        ll mid = lo + (hi-lo+1)/2;
        if (valid(mid)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }
    cout << lo;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```