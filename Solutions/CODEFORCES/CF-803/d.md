If an interval has an odd number of element that exist in that range, that means there is one element is fixed. And we just need to binary search to find that element.
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
using pdb = pair<double,double>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n;
    cin >> n;
 
    int lo = 1 , hi = n;
    while(hi > lo){
        int mid = lo + (hi-lo)/2;
        cout << "? " << lo << ' ' << mid << '\n';
        cout.flush();
        
        int cnt = 0;
        for(int i{lo}; i <= mid; i++){
            int x;
            cin >> x;
            if (x >= lo && x <= mid) cnt++;
        }
        cout.flush();
 
        if (cnt % 2){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }
 
    cout << "? " << lo << ' ' << lo << '\n';
    cout.flush();
    int x;
    cin >> x;
    cout << "! " << x << '\n' ;
    cout.flush();
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