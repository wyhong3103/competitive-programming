The problem statement has mentioned that it's always possible to find an X. So, it's actually referring to the number 0, you could literally use the number 0 to swap everything, and meanwhile maintaining the condition, x-sortable. But that's not the optimal answer. Another fact, in order to be X-sortable, every element that has to be swapped need to have X(bitwise). So, a pretty straightfoward solution, just check the bitwise AND of all elements, because that's the common X that those element had.
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
        map<int, int> mp;
        
        vi a(n);
        vi b(n);
        for(int i{}; i < n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(all(b));
 
        int res = -1;
        for(int i{}; i < n; i++){
            if (a[i] != b[i]){
                if (res == -1) res = a[i];
                else res &= a[i];
            }
        }
        cout << res << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```