This is a quite challenging problem! And it's quite interesting! 
```
Thought process

At first, I thought this is another modular arithmetic problem, but the longer i think the clearer i see that it's not a number theory problem, but a graph problem, more particularly, a functional graph.

We always start at node 0 (box 0), and we would go to node x, where x is the next box. The main observation here is that, at one point there is going to be a cycle in this functional graph. This is solely because the property of a functional graph, if each node has only one child, and there is for sure, will be a cycle. And our job is to find the node where k-th step lands in the graph.

----------------------------------------------------------
First off, let's construct the edge

We can construct the edges using binary search (originally used 2 pointers, but too slow) and also find it's distance to the next node. 

Think of it like this

Say 'i' is our starting node, and we want to gain enough weigh w, (w >= x)

_ _ _ _ i _ _ 

Let's break down this problem in such a way 

_ _ _ _ i -> j

The destination is at j, then we simply need to set j as the neighbour of i, and the distance between j and i as the answer if we are to look for (i-th mod N) box

OR else we keep tracks of the sum,

-> -> -> -> ->

We might need to go for a finite number of cycles after reaching the end (x-cur)/sum of all, also keep track of the sum

-> -> -> j _ _ 

Then finally, we also might need to further look for another value that fulfill the condition.

We can simply binary search on a prefix sum array.

This process runs in O(N log N)

----------------------------------------------------------

Next thing we do is to identify the starting point of the cycle, because any boxes/node before that , we can simply get the answer from the value we computed before. But if it's in the cycle, and k as an arbitary large number which is bigger than the tail, we might need to use MOD to identify which node is k-th box


{   tail  }
O - O - O - O
		  O   O
		 O     O
		  O   O
		  	O

Identify the k-th node, and then print the answer we comptued .


```

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
using pdb = pair<double,double>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}


const int MX = 2e5;
//{distance, dest}
pair<ll,ll> adj[MX];
//steps = i-th box, store the node that is i-th box
int steps[MX];
//node_step stores the box that belongs to i-th node, basically the reverse of steps 
int node_step[MX];
//find the beginning of the cycle
//{starting, length before, length of loop}
int loop[3];

void dfs(int node, int step){
    if (node_step[node] != -1){
        loop[0] = node;
        loop[1] = node_step[node];
        loop[2] = step - loop[1];
        return;
    }
    node_step[node] = step;
    step[steps] = node;
    dfs(adj[node].sec, step+1);
}

int binarysearch(vector<ll>& prefix, ll cur, ll x, int at, int lo, int hi){
    while (hi > lo){
        int mid = lo + (hi-lo)/2;
        if (cur + (prefix[mid]-prefix[at]) >= x){
            hi = mid;
        }else lo = mid+1;
    }
    return lo;
}

void solve(){
    //functional graph
    ll n, q, x;
    cin >> n >> q >> x;

    vector<ll> prefix(n);
    for(int i{}; i < n; i++){
        cin >> prefix[i];
        if (i > 0) prefix[i] += prefix[i-1];
    }
    

    //construct edges using binary search
    for(int i{}; i < n; i++){
    	//current sum
        ll cur = prefix[i] - (!i ? 0 : prefix[i-1]);
        //self
        adj[i].fir = 1;
        if (cur >= x){
            adj[i].sec = (i+1)%n;
            continue;
        }


        int dest = 0;

        //to end
        if (i != n-1){
            dest = binarysearch(prefix, cur, x, i, i+1, n-1);
            adj[i].fir += dest-i;
            if (dest != n && cur + (prefix[dest]-prefix[i]) >= x){
                adj[i].sec = (dest+1)%n;
                continue;
            }else{
                cur += prefix[n-1]-prefix[i];
            }
        }

        //full cycle
        adj[i].fir += ((x-cur)/prefix[n-1]) * n;
        cur += ((x-cur)/prefix[n-1]) * prefix[n-1];

        if (cur >= x){
            adj[i].sec = 0;
            continue;
        }else{
            adj[i].fir++;
            cur += prefix[0];
        }

        if (cur >= x){
            adj[i].sec = 1%n;
            continue;
        }

        //from start
        dest = binarysearch(prefix, cur, x, 0, 1, n-1);
        adj[i].fir += (dest);
        adj[i].sec = (dest+1)%n;
    }


    memset(node_step, -1, sizeof(node_step));


    dfs(0,0);

    while(q--){
        ll k;
        cin >> k;
        if (k <= loop[1]){
            cout << adj[steps[k-1]].fir << '\n';
        }else{
        	//subtract the length of the tail
            k -= loop[1];
            //locate the k-th node, node_step[loop[0]] = box that is the starting point of the cycle
            int from = steps[node_step[loop[0]] + ((k-1)%loop[2])];
            cout << adj[from].fir << '\n';
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