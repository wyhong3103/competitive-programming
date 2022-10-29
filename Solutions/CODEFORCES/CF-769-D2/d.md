```

Abridged statement

we have n classes, each class has a[i] value

a subarray is boring if there exist a l and r such that gcd(a[l]...a[r]) = r-l+1

during an operation we can replace one of the a[i]'s value with any value

we have to find the total number of operation needed such that for every non empty prefix to not be boring


Observations

1. 

It's easy to see that if there exist a prime number that is larger than 1e9, the subarray will never be r-l+1, but be 1 instead, because of the fact that a prime number is co prime with every number smaller than it and that is >= 2.

So that's what we will do for each operation.

2.

Claim : for each l, there exists only a r that will makes it gcd(a[l]...a[r]) == r-l+1

Axiom : gcd(l, x) will only be smaller if x was to increase!

say there exist a r such that gcd(a[l]...a[r]) == r-l+1, if we are to increase r to r1 that will make gcd(a[l]...a[r1]) == r1-l+1. We can see that this is contradicting the fact that gcd(l,x) will be smaller when x increased. So that proved our claim.

3.

For each l, we can binary search the R! along with segment tree for range GCD operation.

if gcd(l,mid) >= mid-l+1, we should increase lower boundary

(if the expected size (gcd) is bigger than the current size, we should increase the current size, expected size can become smaller if we are to increase the current size, if that happens, we would keep doing the same thing)

else we decrease higher boundary
(if the expected size (gcd) is smaller than the current size, we should decrease the current size to match it with expected size)

4.

After determining every l & r, how do we determine the minimal operation needed for each prefix??


Let the intersected segment be one segment, the minimal number of operation needed for a prefix is simply the number of non intersected segments.

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


ll gcd(ll a, ll b){
    return (!b ? a : gcd(b, a % b));
}

struct SegTree{
    ll size;
    vll val;
    
    ll NEUTRAL_ELEMENT = 0;

    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.assign(2*size, 0LL);
    }
 
    ll merge(ll a, ll b){
        return gcd((a == 0 ? b : a), (b == 0 ? a : b));
    }

    void buildHelper(vll& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                val[x] = a[lx];
            }
            return;
        }
 
        int m = (lx+rx)/2;
        buildHelper(a, (x*2)+1, lx, m);
        buildHelper(a, (x*2)+2, m, rx);
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void build(vll& a){
        buildHelper(a, 0, 0, size);
    }

    // Make sure it runs in O(log N), eliminate the segment that is impossible, return the segment that is fully covered
    ll queryHelper(int l, int r, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            return val[x];
        }
        int m = (lx + rx) / 2;
        return merge(queryHelper(l, r, (x*2)+1, lx, m), queryHelper(l, r, (x*2)+2, m, rx));
    }
 
    ll query(int l, int r){
        return queryHelper(l, r, 0, 0, size);
    }

    void printTree(){
        int cnt = -1;
        for(int i{}; i < size*2; i++){
            if (__lg(i+1) != cnt){
                cout << '\n';
                cnt = __lg(i+1);
            }
            cout << val[i] << ' ';
        }
    }
};

void solve(){
    int n;
    cin >> n;

    vll a(n);
    for(auto& i : a) cin >> i;

    SegTree st;
    st.init(n+1);
    st.build(a);
    
    vi left(n, -1);
    vi right(n, -1);
    
    for(int i{}; i < n; i++){
        int lo = i, hi = n-1;
        while (hi > lo){
            int mid = lo + (hi-lo+1)/2;
            if (st.query(i, mid+1) >= mid-i+1){
                lo = mid;
            }else hi = mid-1;
        }
        if (st.query(i, lo+1) == lo-i+1){
            left[i] = i;
            right[lo] = i;
        }
    }

    vi res(n);
    int in = -1;
    for(int i{}; i < n; i++){
        if (in == -1 && left[i] != -1){
            in = left[i];
        }
        if (in == right[i] && in != -1){
            res[i]++;
            in = -1;
        }
    }

    int cnt = 0;
    for(int i{}; i < n; i++){
        cnt += res[i];
        cout << cnt << ' ';
    }

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