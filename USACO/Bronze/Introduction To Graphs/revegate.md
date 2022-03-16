This was quite a good problem for me who just started out in graph! <br>
This problem is about not letting the neighbour of a node to have the same type of seed, which I denoted using n_grass in this solution.
<br>
Explanation :
- First, I used adjacency list to store all the nodes, with its neighbours
- Then, I travel from the first node to the last node, 
- During each iteration, I iterate through i-th node neighbours, and look for the minimum type of seed I need. Eg (3 neighbours node, 0 0 3), 0 = uninitialized, I need to use 1 in this situation. This thing is quite tricky tho, I know there is a way to find the number between it, but I've just decided to use an ordered_set to get the number I want. (by removing every type during the iteration through its neighbour), and just set the n_grass\[i\] to the first element in the ordered_set.

<br><br>
Link to problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=916

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
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> n_grass(n);
    for(int i{}; i < m; i++){
        int to, end;
        cin >> to >> end;
        to--;
        end--;
        adj[to].push_back(end);
        adj[end].push_back(to);
    }

    for(int i{}; i < n; i++){
        set<int> s = {1,2,3,4};
        for(int j{}; j < adj[i].size(); j++){
            if (n_grass[adj[i][j]] != 0){
                s.erase(n_grass[adj[i][j]]);
            }
        }
        n_grass[i] = *s.begin();
    }

    for(auto& i: n_grass){
        cout << i;
    }
}

int main(){
    setIO("revegetate");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
}


```