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
    
    set<int> a;
    set<int> b;
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        b.insert(x);
    }

    for(int i{1}; i <= 2*n; i++){
        if (!b.count(i)) a.insert(i); 
    }

    int count = 0;
    for(auto& i : b){
        auto it = a.upper_bound(i);
        if (it != a.end()){
            a.erase(*(it));
            count++;
        }
    }
    cout << count;
}
 
int main(){
    setio("highcard");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```