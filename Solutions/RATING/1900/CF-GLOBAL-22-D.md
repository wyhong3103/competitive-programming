```
we're given a permutation a, and a number k

for every ai, 

if ai <= k:
	b[a[i]] = aj, aj = the last j, j < i, s.t aj > k
	else
	b[a[i]] = n+1

else:
	b[a[i]] = aj, aj = the last j, j < i, s.t aj <= k
	else
	b[a[i]] = 0


Observations
1. if b[i] = n+1, k > i, and every number before j, such that a[j] = i, is <= k, same goes to b[i] = 0
3. If b[i] != 0 or b[i] != n+1, if i > b[i], it implied i > k, b[i] <= k. 
4. If b[i] != 0 or b[i] != n+1, if i <=b[i], it implied i <= k, b[i] > k. 
2. every value b[i] holds, means b[i] is before a[j] (s.t a[j] == i), and one of them is bigger than k, another one is lower than k (i.e they in the different region of threshold)
5. With the above, we can try to construct a directed graph, Let's denote every number as '>' and '<' instead. Notice that every neighbours of node i, has different sign! Also, i points to b[i].
6.

Claim : After constructing the graph, we will have one connected component and a ton of isolated nodes.

Proof:

Let there exist 2 connected component, which implied in each component that is at least one '>' and '<'. Notice that if there exist '>' in one component and '<' in another component, then we can merge them together as a single component!

7. 
We will end up having a tree, a special kind of tree. Let's reverse the direction of every edges, 

Claim : notice that for each node, and each children of it, there can only be one children that has grandchildren.

Proof : If there exists two children that have granchildren, for example, let's denote the current node as i,

          '(j) <'---'(k) >'
          / 
         /
'<' --- '> (i)' ---- '(l)<'----'>' 
  

Let's denote pos[i] = position of i in array a.

Notice that if pos[i] < pos[j] < pos[k] < pos[l], then l would rather connect to k instead!!

If pos[l] < pos[k], then k would connect to l instead!

So basically between a given (legal) connection between '>' and '<' such that '<' is pointing to '>', there cannot exist another '>' in between.


Solution

With this observation, we can easily construct the array. The one children that has granchildren will be the last element after connecting to all its children (Which we could achieve using linked list)

We can start constructing the solution from the head of the linked list, node i is a head if it has a children but not a parent.

Any node that dont have parent or children will be placed first. Because a node would have connection to other node, if there is a connected component before it.

To determine k, we can iterate through the '<'/'>' sign of every number, then get the largest that has '<' (it is actually '<=')
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
    vi a(n);
    for(auto& i : a){
        cin >> i;
    }

    //adj[i], sign[i] = permutation number not index
    vector<vi> adj(n+5);
    vi sign(n+5);

    for(int i{}; i < n; i++){
        if (a[i] == 0 || a[i] == n+1){
            sign[i+1] = (a[i] == 0 ? 1 : 0);
            continue;
        }
        if (i+1 > a[i]){
            sign[i+1] = 1;
            sign[a[i]] = 0;
        }else{
            sign[i+1] = 0;
            sign[a[i]] = 1;
        }
        adj[a[i]].pb(i+1);
    }

    vi next(n+5, -1);
    vi prev(n+5, -1);

    
    for(int i{1}; i <= n; i++){
        int cur = i;
        int last = -1;
        for(auto& j : adj[i]){
            if (sz(adj[j])) last = j;
            else{
                prev[j] = cur;
                next[cur] = j;
                cur = j;
            }
        }
        if (last != -1){
            prev[last] = cur;
            next[cur] = last;
        }
    }

    vi res;
    int head = -1;
    for(int i{1}; i <= n; i++){
        if (prev[i] == -1 && next[i] != -1) head = i;
        if (prev[i] == -1 && next[i] == -1) res.pb(i);
    }

    if (head != -1){
        int cur = head;
        while (next[cur] != -1){
            res.pb(cur);
            cur = next[cur];
        }
        res.pb(cur);
    }

    int mx = 0;
    for(int i{1}; i <= n; i++){
        if (sign[i] == 0) mx = i;
    }
    cout << mx << '\n';
    for(auto& i :res) cout << i << ' ';
    cout << '\n';
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