Well, this is my first time doing such problem, having to reset the global array and vector. Takes me sometimes to figure out what's going wrong with my code. Pretty cool, although I spent so much time than it should, debugging, debugging and debugging.
<br>
Anyway, let's get into the problem. This problem is basically about finding whether if one of the edge got removed, it would still be a fully connected component, it's just basic brute force, given the time constraint, and the input constraint. So , that's what I did, I am thinking if there's a better way to solve this. But yeah, here's my solution, not much explanation needed i guess


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


const int MXN = 100;

bool visited[MXN];
vector <int> adj[MXN];


void dfs(int node, int start, int end,int& count){
    if (visited[node]) return;

    count++;
    visited[node] = true;
    for(auto& i: adj[node]){
        if ((node == start && i == end) || (node == end && i == start)){
            continue;
        }
        dfs(i, start,end, count);
    }
}


void solve(){
    int p,c;
    while(true){
        cin >> p >> c;
        if (p == 0 && c == 0) break;

        for(int i{}; i < c; i++){
            int to,end;
            cin >> to >> end;
            adj[to].push_back(end);
            adj[end].push_back(to);
        }
        
        

        bool good = true;
        for(int i{}; i < p; i++){
            for(int j{}; j < adj[i].size() ; j++){
                int count{};
                int to{i}, end{adj[i][j]};
                dfs(to, to, end, count);
                fill(visited, visited+p, 0);
                if (count != p){
                    good = false;
                    break;
                }
            }
            if (!good) break;
        }

        cout << (!good ? "Yes" : "No") << '\n';
        for(int i{};i  < p; i++){
            adj[i].clear();
        }

    }
}

int main(){
    //setIO("fenceplan");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
}

```

<br>
After reading the editorial, apparently, there's a better way to do this, to ignore the edges with adjacency matrix, we just have to simply set it to 0. Read the thing below
<br>

Ignoring Edges
The easiest way to ignore edges in a graph is to represent the graph with an
adjacency matrix (we can do this because the number of nodes is very small).
To ignore an edge that connects two nodes $a$ and $b$, we can simply set
adj[a][b] and adj[b][a] to false. Later, when we want to add the edge back,
we can update adj[a][b] and adj[b][a] to true.