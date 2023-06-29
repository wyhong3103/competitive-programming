```
Greedily find the best candidate from the last

Best candidate, c - no c is found before next letter (previous one cus we start from last )/ has the minimal index j amongst other candidates s.t j is maximal and j < i and s[j] = c

Finding the one that has leftmost is good, because we reduce the possibility of having more characters that is suitable for the next letter
 
```
```cpp

#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using ull = unsigned long long;
const double EPS = (1e-6);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    string s;
    cin >> s;
    int n;
    cin >> n;
 
    string l, r;
    cin >> l >> r;
 
    vector<vi> a(10);
    for(int i{}; i < sz(s); i++){
        a[s[i]-'0'].pb(i);
    }
 
    int cur = sz(s);
    for(int i{n-1}; i >= 0; i--){
        //choose the best candidate among everyone we can choose
        //best candidate - doesn't exist or has the left most index (first before cur)
        int temp = cur;
        for(int j{l[i]-'0'}; j <= r[i]-'0'; j++){
            int lo = 0, hi = sz(a[j])-1;
            while (hi > lo){
                int mid = lo + (hi-lo+1)/2;
                if (a[j][mid] < cur){
                    lo = mid;
                }else hi = mid-1;
            }
            if (!sz(a[j]) || a[j][lo] >= cur){
                cout << "YES" << '\n';
                return;
            }else{
                temp = min(temp, a[j][lo]);
            }
        }
        swap(temp,cur);
    }
    cout << "NO" << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

```