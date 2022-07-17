Number theory.
```
The most notably thing about LCM is 

The power of every terms of the prime factorization of LCM is max of each number.

So, the first approach I did (which i thought it would work, and it turned out pretty slow), is by using suffix and prefix array, which stores the prime factorization of every prefix and suffix, that way we only need to do traversal across the entire array, and find the number of unique prime factorization without the i-th term, but it runs in O(n^2 log n)

Second approach, much faster, and smarter

Notice that because only the number with max terms going to affect LCM, so we only need to know how many numbers out there hold the max terms (only, if others hold the same max term then ignore). One tricky part is we need the numbers that hold the max terms instead of the number of unique max terms, because some number could hold more than one max terms.

And that's the idea.

Another thing is if the number that hold max terms == n, then the answer is n, if it's less than n, then we need to + 1, this is because if not every number hold max terms, we could randomly choose a number that doesn't hold a max term, and the answer would be different.
```
```cpp
#include <bits/stdc++.h>
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
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n;
    cin >> n;

    vector<vector<pll>> a(n);
    for(auto& i : a){
        int m;
        cin >> m;
        while(m--){
            ll p, e;
            cin >> p >> e;
            i.pb({p,e});
        }
    }

    //identify the number of only max terms
    //{prime, {power, number of such terms}};
    map<ll, pair<ll,int>> mp;

    for(int i{}; i < n; i++){
        for(auto& j : a[i]){
            if (!mp.count(j.fir)) mp[j.fir] = {0,0};
            if (j.sec > mp[j.fir].fir){
                mp[j.fir].fir = j.sec;
                mp[j.fir].sec = i;
            }
            else if (j.sec == mp[j.fir].fir){
            	//set it as -1, if there is another number that held the same term
                mp[j.fir].sec = -1; 
            }
        }
    }

    set<int> mx;
    for(auto& i :mp){
        if (i.sec.sec != -1) mx.insert(i.sec.sec);
    }
    //only + 1, if not every term a max term
    cout << (sz(mx) == n ? n : sz(mx)+1);
} 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}

```