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
    vector<pi> a(n);

    for(auto& i : a){
        cin >> i.fir >> i.sec;
    }

    sort(all(a), [](pi a,pi b){
        return a.sec < b.sec;
    });
    
    int end = 0;
    int count = 0;
    for(auto& i : a){
        if (i.fir >= end){
            end = i.sec;
            count++;
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