Greedy problem, you always want to select the minimal element you could find, one edge case is when the element at the end of the array is equal to the only element left in the set, if that happens, you simply need to swap the last element with the current element.
```cpp
#include <bits/stdc++.h>
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        set<int> numbers;
        for(int i{1}; i <= n; i++) numbers.insert(i);
        
        vi a(n);
        for(auto& i : a) cin >> i;
 
        if (n == 1){
            cout << -1 << '\n';
            continue;
        }
        
        vi res(n);
        for(int i{}; i < n; i++){
            auto it = numbers.begin();
            if (*it == a[i] && sz(numbers) == 1){
                res[i] = -1;
                break;
            }
            if (*it == a[i]) it++;
            res[i] = *it;
            numbers.erase(*it);
        }
 
        if (res[n-1] == -1 && n >= 2){
            res[n-1] = res[n-2];
            res[n-2] = a[n-1];
        }
 
        for(auto& i : res) cout << i << ' ';
        cout << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```