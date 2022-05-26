We can solve it by just using binary search.
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
    int k;
    cin >> k;
    string s;
    getline(cin>>ws, s);

    int lo = 1, hi = s.length();
    while (hi > lo){
        int mid = lo + (hi-lo)/2;

        int cnt = 0;
        int i = 0;
        int prev = -1;
        int cur = 0;
        while (i < s.length()){
            if (cur + 1 <= mid){
                if (s[i] == ' ' || s[i] == '-') prev = i;
                cur++; 
                i++;
            }else{
                if (prev == -1){
                    //Will automatically be evaluated to false
                    cnt = k+1;
                    break;
                }
                i = prev+1;
                cur = 0;
                cnt++;
            }
            if (cnt > k) break;
        }
        if (cur) cnt++;

        if (cnt <= k){
            hi = mid;
        }else{
            lo = mid + 1;
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