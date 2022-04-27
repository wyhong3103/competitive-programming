The idea is to pick the largest first, if there's any remaining space , only select small element. But , Idk if it's necessary since the gondola has a limit of 2 person, I've only realized that after number of submissions. :|
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
    int n, x;
    cin >> n >> x;
    
    vi a(n);
    for(auto& i : a) cin >> i;
 
    sort(all(a));
    
    int l = 0, r = n-1;
    int count = 0;
    int cur = 0;
    int counton = 0;
    while (l <= r){
        if (counton == 2){
            cur = 0;
            counton = 0;
            count++;
        }
        if (cur + a[r] <= x){
            cur += a[r];
            counton++;
            r--;
        }else{
            if (cur + a[l] <= x){
                cur += a[l];
                counton++;
                l++;
            }else{
                cur = a[r];
                counton = 1;
                r--;
                count++;
            }
        }
    }
    if (cur) count++;
 
    cout << count;
 
 
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```