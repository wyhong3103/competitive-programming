```

Observation

1. We only care about the maximal element that is not taken, we dont care about which food is taken by student.

2. Order of the student dont actually matter. We just need to know which item is taken and which is not.

Idea:

Consider student as -1 and a food as 1, and they are aligned on a number line s.t the position is their value.

type  : 1, 1, -1, -1
value : 1  2   3   4

In the above scenario, one thing we are for sure is that both the students at the back will take 2 of the element.

To generalize, student at x will have food to buy iff there is previous element that has not been taken yet.

3. Maximal element is simply the first element at the back that is not taken, basically the first positive element in suffix sum. 


We can use segment tree, for each node, we store [number of remaining food, number of students that has not taken any food]

At node i, if right child of i has student that hasnt taken any food, then they will take, food on the left child. 

Remainig food on the right child will remian the same, also student on the left child.

How do know which is the first element that hasn't been taken?

We will have a search function that checks if the top node has remaining element, if there is, we will always prioritize going to the right child first, because thats the largest & will not be taken. However, this is only the case, if the nodes will not be taken. Consider such a case

		[1, 2]

	[3, 2]   [0, 2]

[1,2]  [2,0]

In this scenario, in the second layer, the 2 of the 3 reamining on the left child will be taken because 2 needs food on the right child.

So when we go down to the third layer, we know that 2 of them will need to be taken, so instead of exploring [2,0] (because 2 will completely be taken away), we will go to the left node and not worry about taking any node because its already taken on the right child, we repeat the same process until we go to the deepest element.

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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}


struct SegTree{
    int size = 1;
    //{remaining food, student that has not taken}
    vector<pi> val;
    
    void init(){
        while (size < 1e6 + 5) size *= 2;
        val.resize(size * 2, {});
    }

    void build(vi& a, vi& b, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)) val[x] = {max(0, b[lx] - a[lx]), max(0, a[lx] - b[lx])};
            return;
        }

        int m = (lx+rx)/2;
        build(a, b, x*2+1, lx, m);
        build(a, b, x*2+2, m, rx);
        
        val[x].fir = val[x*2+2].fir + max(0, val[x*2+1].fir - val[x*2+2].sec);
        val[x].sec = val[x*2+1].sec + max(0, val[x*2+2].sec - val[x*2+1].fir);
    }

    void build(vi& a, vi& b){
        build(a, b, 0, 0, size);
    }

    void set(pi v, int i, int x, int lx , int rx){
        if (rx-lx == 1){
            val[x] = v;
            return;
        }

        int m = (lx+rx)/2;

        if (i >= m){
            set(v, i,x*2+2, m, rx);
        }else set(v, i,x*2+1, lx, m);
        
        val[x].fir = val[x*2+2].fir + max(0, val[x*2+1].fir - val[x*2+2].sec);
        val[x].sec = val[x*2+1].sec + max(0, val[x*2+2].sec - val[x*2+1].fir);
    }

    void set(pi v, int i){
        set(v, i, 0, 0, size);
    }

    int query(int x, int lx, int rx, int taken){
        if (!val[x].fir) return -1;

        if (rx-lx == 1){
            return lx;
        }

        int m = (lx+rx)/2;

        if (val[x*2+2].fir > taken){
            return query(x*2+2, m, rx, taken);
        }else{
            return query(x*2+1, lx, m, taken - val[x*2+2].fir + min(val[x*2+1].fir, val[x*2+2].sec));
        } 
    }

    int query(){
        return query(0, 0, size, 0);
    }
};

void solve(){
    int n, m;
    cin >> n >> m;

    vi ai(m);
    vi bi(n);
    //student
    vi a(1e6 + 3);
    //food
    vi b(1e6 + 3);

    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        b[x]++;
        bi[i] = x;
    }

    for(int i{}; i < m; i++){
        int x;
        cin >> x;
        a[x]++;
        ai[i] = x;
    }

    SegTree st;
    st.init();
    st.build(a, b);

    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        int i, x;
        cin >> i >> x;
        i--;

        if (t == 1){
            //change food price, b[i]
            b[bi[i]]--;
            st.set({max(0, b[bi[i]]-a[bi[i]]), max(0, a[bi[i]]-b[bi[i]])}, bi[i]);
            b[x]++;
            bi[i] = x;
            st.set({max(0, b[x]-a[x]), max(0, a[x]-b[x])}, x);
        }else{
            a[ai[i]]--;
            st.set({max(0, b[ai[i]]-a[ai[i]]), max(0, a[ai[i]]-b[ai[i]])}, ai[i]);
            a[x]++;
            ai[i] = x;
            st.set({max(0, b[x]-a[x]), max(0, a[x]-b[x])}, x);
        }

        cout << st.query() << '\n';
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