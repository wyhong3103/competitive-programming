The idea is to basically test if a certain medium can be made or not, the tricky part is about making the function that test it's validity, I am really bad at these for now, gotta work on it! So basically the idea is that , say I want to choose x as a median, to know how much operations I need in order to make it the median, I can do this, first, just start with the original median, and check the difference between it and the desired median, keep doing this until the end of the array, if the total operations needed <= k, then yes, possible.
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
 
bool valid(vi& a, int med, int op){
    ll total = 0;
    int temp = med;
    for(int i{(sz(a)/2)}; i < sz(a); i++){
        if (a[i] - temp >= 0){
        	//When the height of the element is bigger than the median expected, we can straight away determine whether it's possible or no
            return (total <= op);
        }else{
            total += temp - a[i];
        }
    }
    return (total <= op);
}

void solve(){ 
    int n, k;
    cin >> n >> k;

    vi a(n);
    for(auto& i : a) cin >> i;
    sort(all(a));

    ll lo = a[n/2], hi = lo + k;

    while (hi > lo){
        ll mid = lo + (hi-lo+1)/2;
        if (valid(a,mid,k)){
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