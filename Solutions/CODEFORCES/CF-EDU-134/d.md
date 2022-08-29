Working solution, but TLE.
```

The important observation

the final value of the function is the AND of every c[i]. That also implies if one of the number didn't have bit 1 on a certain bit, we can straight up forget about that bit.

We can deal with the bits independently.

And also, we could greedy on the bits. (From larger to smaller)

Only ways to fulfill a bit (every c[i] has 1 on that bit). Is that number of a[i] that has 1 on that bit = the number of b[i] that has 0 on that bit. Because we could easily fulfill it by doing XOR.

Now comes the fun part.

Whenever we start dealing with the first bit, (starting from here when I referred to a[i] it's to that bit)

There are 4 groups in total from initial array a & array b,

a[i] with zeros
a[i] with ones

b[i] with zeros
b[i] with ones

If a[i] with ones == b[i] with zeros that it's valid. So we move on the next stage.

Say we fulfil the first group, now we know there is a certain orders that can fulfill that bit. But on the second order (in search of the second bit), it's different,

because we paired a[i] with ones and b[i] with zeros together. So we sort of have to start pairing our new group among those numbers. Instead of the entire array, and this is going to form a recursive graph.

And i tried to solve it using this approach, but it doesn't work. got TLE & almost MLE.

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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}


void solve(){
    int n;
    cin >> n;

    vll a(n);
    vll b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    ll res = 0;
    vector<vector<vi>> cur_arr;
    
    vector<vi> empty_temp(2);
    vi temp;
    for(int i{}; i < n; i++){
        temp.pb(i);
    }
    empty_temp[0] = temp;
    empty_temp[1] = temp;
    cur_arr.pb(empty_temp);

    for(int i{30}; i >= 0; i--){
        bool ok = 1;
        for(auto& arr : cur_arr){
            bool ok_temp = 1;
            pi cnt = {};
            for(int k{}; k < sz(arr[0]); k++){
                if (a[arr[0][k]] & (1 << i)){
                    cnt.fir++;
                }
                if (!(b[arr[1][k]] & (1 << i))){
                    cnt.sec++;
                }
            }
            if (cnt.fir != cnt.sec){
                ok = 0; 
                break;
            }
        }
        if (ok){
            res += 1 << i;
            
            vector<vector<vi>> temp_cur_arr;

            for(auto& arr : cur_arr){
                vi a_one;
                vi a_zero;
                vi b_one;
                vi b_zero;
                
                for(int k{}; k < sz(arr[0]); k++){
                    if (a[arr[0][k]] & (1 << i)){
                        a_one.pb(arr[0][k]);
                    }else{ 
                        a_zero.pb(arr[0][k]);
                    }
                    if (!(b[arr[1][k]] & (1 << i))){
                        b_zero.pb(arr[1][k]);
                    }else{ 
                        b_one.pb(arr[1][k]);
                    }
                }
                vector<vi> empty;
                empty.pb(a_one);
                empty.pb(b_zero);
                vector<vi> empty1;
                empty1.pb(a_zero);
                empty1.pb(b_one);
                temp_cur_arr.pb(empty);
                temp_cur_arr.pb(empty1);
            }
            cur_arr = temp_cur_arr;
        }
    }

    cout << res << '\n';
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

Same working solution. WTF, was that close...
```

Instead of using vector<vi>, we used pair<vi, vi> in this case. Which boost a little performance.

Most importantly, we don't push empty vectors.

not every situation have both a_zero/a_one. It could be entirely a_one/a_zero, and one would be empty. And if we kept pushing this empty vectors, it will create a lot of unnecessary vectors, and causes TLE.

Because imagine every level you extend for 30 times, there will be 2^30 more unnecessary array say all of them are a perfect a_zero/a_one!
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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}


void solve(){
    int n;
    cin >> n;

    vll a(n);
    vll b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    ll res = 0;
    vector<pair<vi,vi>> cur_arr;
    
    pair<vi,vi> empty_temp;
    vi temp;
    for(int i{}; i < n; i++){
        temp.pb(i);
    }
    empty_temp.fir = temp;
    empty_temp.sec = temp;
    cur_arr.pb(empty_temp);

    for(int i{30}; i >= 0; i--){
        bool ok = 1;
        for(auto& arr : cur_arr){
            pi cnt = {};
            for(int k{}; k < sz(arr.fir); k++){
                if (a[arr.fir[k]] & (1 << i)){
                    cnt.fir++;
                }
                if (!(b[arr.sec[k]] & (1 << i))){
                    cnt.sec++;
                }
            }
            if (cnt.fir != cnt.sec){
                ok = 0; 
                break;
            }
        }
        if (ok){
            res += 1 << i;
            
            vector<pair<vi,vi>> temp_cur_arr;

            for(auto& arr : cur_arr){
                vi a_one;
                vi a_zero;
                vi b_one;
                vi b_zero;
                
                for(int k{}; k < sz(arr.fir); k++){
                    if (a[arr.fir[k]] & (1 << i)){
                        a_one.pb(arr.fir[k]);
                    }else{ 
                        a_zero.pb(arr.fir[k]);
                    }
                    if (!(b[arr.sec[k]] & (1 << i))){
                        b_zero.pb(arr.sec[k]);
                    }else{ 
                        b_one.pb(arr.sec[k]);
                    }
                }
                pair<vi,vi> empty;
                empty.fir = (a_one);
                empty.sec = (b_zero);
                pair<vi,vi> empty1;
                empty1.fir = (a_zero);
                empty1.sec = (b_one);
                if (sz(empty.fir)) temp_cur_arr.pb(empty);
                if (sz(empty1.fir)) temp_cur_arr.pb(empty1);
            }
            cur_arr = temp_cur_arr;
        }
    }

    cout << res << '\n';
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