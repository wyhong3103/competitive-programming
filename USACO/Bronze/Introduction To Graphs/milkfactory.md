This problem is about finding whether there's a node, where each node can travel through, either directly or through any other nodes, the constraint for this problem is 1 <= N <= 100. So i've decided to use a little complete search in here.
<br>
Explanation:
- One key observation in here is, this is a tree, and it's directed, so one node can only have one neighbour, the highest degree is 1, so one thing we can do is, to travel from one neighbour to another, if we hit -1, that means we have reach our final destination. And we will add 1, to the map that stores how many variable that reaches the final destination.
- If there's one node as final destination and value is n-1, that means it is the node that we're looking for, if no , we cout -1

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


void solve(){
    int n;
    cin >> n ;
    vector<int> adj(n);
    fill(all(adj), -1);
    map<int, int> m;

    for(int i{}; i < n-1; i++){
        int to, end;
        cin >> to >> end;
        to--; end--;
        adj[to] = end;
    }

    for(int i{}; i < n; i++){
        int to = adj[i];
        while (to != -1){
            if(!m.count(to)){
                m[to]= 0;
            }
            m[to]++;
            to = adj[to];
        }
    }

    pair<int,int> ans{};
    for(auto& i: m){
        if (i.sec > ans.sec){
            ans = {i.fir, i.sec};
        }
    }

    cout << (ans.sec == n-1 ? ans.fir+1 : -1);
}

int main(){
    setIO("factory");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
}


```