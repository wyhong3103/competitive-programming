```

We're to find the number of connected components, such that there is an edge between i and j iff segment[i:j] forms a balanced bracket sequence.

Let's look at this sequence

()()()

It's a one big connected component. Do you see how?

second bracket sequence can connect to the first one, third can connect to the third one/second one.

First observation, we didn't have to connect to all the bracket sequence (that is valid) before us. We just have to connect to the one that is closest to us. As that bracket sequence is also connected to others that the current bracket sequence could reach.

Second observation, we can only connect our bracket sequence to another bracket sequence that is before us, and is completed in order to form another balanced bracket sequence. 

The proof,

The closest bracket sequence we could connect is the corresponding '(' we must match in the original sequence, and we could only connect to bracket sequence before our matching '(', so any completed sequence before that is valid. There is no way we can ever connect to an incomplete sequence.

Take this for an example,

()(())

sequence [2,5] can match with [0,1]. The closest sequence s[5] can reach is s[2]. We could find this using stack. And also notice that, we cannot go out of the incomplete sequence. For example, [3,4] is a valid bracket sequence but it couldn't connect to [1,2], the reason is that there is a incomplete bracket sequence between them.

So the idea is simply by using stack, we could find our matching '(' and then find the closest bracket sequence before our matching '(' and after the top of the stack '(' (because that's the closest incomplete sequence).

We will use DSU to compute the number of connected components.
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


const int MX = 2e5 + 5;
int comp_sz[MX];
int parent[MX];
    
int dsu_get(int a){
    return parent[a] = (parent[a] == a ? parent[a] : dsu_get(parent[a]));
}

void dsu_union(int a, int b, int& total){
    a = dsu_get(a);
    b = dsu_get(b);
    
    if (a == b) return;

    if (comp_sz[a] > comp_sz[b]){
        parent[b] = a;
        comp_sz[a] += comp_sz[b];
    }else{
        parent[a] = b;
        comp_sz[b] += comp_sz[a];
    }
    total--;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    n *= 2;

    for(int i{}; i < n; i++){
        parent[i] = i;
        comp_sz[i] = 1;
    }

    int total = n;
    stack<int> stck;
    vi completed;
    for(int i{}; i < n; i++){
        if (s[i] == '('){
            stck.push(i);
        }else{
            int cur = stck.top();
            stck.pop();
            dsu_union(i, cur, total);
            
            int lo = (stck.empty() ? 0 : lower_bound(all(completed), stck.top()) - completed.begin()), hi = sz(completed)-1;
            while (hi > lo){
                int mid = lo + (hi-lo+1)/2;
                if (completed[mid] < cur){
                    lo = mid;
                }else hi = mid-1;
            }
            if (sz(completed) && lo < sz(completed) && completed[lo] < cur){
                dsu_union(i, completed[lo], total);
            }
            completed.pb(i);
        }
    }

    cout << total << '\n';
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