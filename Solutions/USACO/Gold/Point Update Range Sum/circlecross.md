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
        return a + b;
    }

    void setHelper(int i, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] = !val[x];
            return;
        }
 
        int m = (lx+rx)/2;
        if (i < m){
            setHelper(i, (x*2)+1, lx, m);
        }else{
            setHelper(i, (x*2)+2, m, rx);
        }
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void set(int i){
        setHelper(i, 0, 0, size);
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


    SegTree st;
    st.init((2*n)+1);

    vi left(n, -1);

    int cnt = 0;
    for(int i{}; i < 2*n; i++){
        int x;
        cin >> x;
        x--;
        if (left[x] == -1){
            st.set(i);
            left[x] = i;
        }
        else{
            cnt += st.query(left[x]+1, i);
            st.set(left[x]);
        }
    }
    
    cout << cnt;
}
 
int main(){
    setio("circlecross");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
 

```