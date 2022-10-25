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

struct Node{
    vll freq;
    ll cnt;

    Node(){
        freq.assign(45, 0LL);
        cnt = 0;
    }
};


struct SegTree{
    ll size;
    vector<Node> val;
    
    Node NEUTRAL_ELEMENT;

    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.resize(2*size);
    }
 
    Node merge(Node& a, Node& b){
        Node res;

        for(int i{}; i <= 40; i++){
            res.freq[i] += a.freq[i];
            res.freq[i] += b.freq[i];
            if (res.freq[i]) res.cnt++;
        } 

        return res;
    }

    void buildHelper(vi& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                val[x].freq[a[lx]]++;
                val[x].cnt = 1;
            }
            return;
        }
 
        int m = (lx+rx)/2;
        buildHelper(a, (x*2)+1, lx, m);
        buildHelper(a, (x*2)+2, m, rx);
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void build(vi& a){
        buildHelper(a, 0, 0, size);
    }
 
    void setHelper(int i, ll v, int x, int lx, int rx){
        if (rx-lx == 1){
            Node temp;
            temp.freq[v]++;
            val[x] = temp;
            return;
        }
 
        int m = (lx+rx)/2;
        if (i < m){
            setHelper(i, v, (x*2)+1, lx, m);
        }else{
            setHelper(i, v, (x*2)+2, m, rx);
        }
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void set(int i, int v){
        setHelper(i, v, 0, 0, size);
    }


    // Make sure it runs in O(log N), eliminate the segment that is impossible, return the segment that is fully covered
    Node queryHelper(int l, int r, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            return val[x];
        }
        int m = (lx + rx) / 2;
        Node left = queryHelper(l, r, (x*2)+1, lx, m);
        Node right = queryHelper(l, r, (x*2)+2, m, rx);
        return merge(left ,right);
    }
 
    ll query(int l, int r){
        return queryHelper(l, r, 0, 0, size).cnt;
    }
    
    /*
    void printTree(){
        int cnt = 1;
        for(int i{}; i < size; i++){
            cout << val[i] << ' ';
            if (__lg(i) != cnt){
                cout << '\n';
                cnt = __lg(i);
            }
        }
    }
    */

};


void solve(){
    int n, q;
    cin >> n >> q;

    vi a(n);
    for(auto& i : a) cin >> i;

    SegTree st;
    st.init(n+1);
    st.build(a);
    
    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        u--;
        if (t == 1){
            cout << st.query(u, v) << '\n';
        }else{
            st.set(u, v);
        }
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