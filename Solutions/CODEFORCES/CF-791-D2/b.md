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
    int n, q;
    cin >> n >> q;
    ll sm = 0;
    //We can actually use an array here, and it's much more efficient, Idk why am i using map in the first place lol
    map<int, pi> mp;
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        // {number of query, value}
        mp[i] = {0, x};
        sm += x;
    }
 
    pi cur{-1,-1};
    for(int i{1}; i <= q; i++){
        int t;
        cin >> t;
        if (t == 1){
            int index, x;
            cin >> index >> x;
            index--;
            //If the query that set the new value of index-th is before cur.fir, that means cur.fir has taken over the new values, and set all the values into x, so we must deduct cur.sec , which is the new value of every number, and to add x
            if (cur.fir > mp[index].fir){
                sm -= cur.sec;
            }else{
                sm -= mp[index].sec;
            }
            mp[index].fir = i;
            mp[index].sec = x;
            sm += x;
        }else{
            int x;
            cin >> x;
            cur = {i, x};
            sm = (ll)cur.sec * n;
        }
        cout << sm << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```

Using array
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
    int n, q;
    cin >> n >> q;
    ll sm = 0;
    vector<pi> a(n);
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        a[i] = {0, x};
        sm += x;
    }
 
    pi cur{-1,-1};
    for(int i{1}; i <= q; i++){
        int t;
        cin >> t;
        if (t == 1){
            int index, x;
            cin >> index >> x;
            index--;
            if (cur.fir > a[index].fir){
                sm -= cur.sec;
            }else{
                sm -= a[index].sec;
            }
            a[index].fir = i;
            a[index].sec = x;
            sm += x;
        }else{
            int x;
            cin >> x;
            cur = {i, x};
            sm = (ll)cur.sec * n;
        }
        cout << sm << '\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}


```