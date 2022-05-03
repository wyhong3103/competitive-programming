Made some bad assumptions lead to the unnecessary debug. :|
<br>
This problem is basically about modifying the dfs itself, instead of travelling to each node according to the adjacency list, we don't have an adjacency list, so we kind of have to determine which is our neighbour node and which is not , and this happens in the dfs.

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

struct Cow{
    int x,y,p;
};

bool visited[200];
Cow nodes[200];
int ans{};


ll distance(int x1, int y1, int x2, int y2){
    return ceil(sqrt((abs(x1-x2) * abs(x1-x2)) + (abs(y1-y2) * abs(y1-y2))));
}


void dfs(int node,int n, int& count){
    if (visited[node]) return;

    count++;
    visited[node] = true;
    for(int i{}; i < n; i++){
        if (!visited[i] && nodes[node].p >= distance(nodes[i].x, nodes[i].y, nodes[node].x , nodes[node].y)){
            dfs(i, n, count);
        }
    }
}


void solve(){
    int n;
    cin >> n;

    for(int i{}; i < n; i++){
        cin >> nodes[i].x >>nodes[i].y >> nodes[i].p;
    }

    for(int i{}; i < n; i++){
        if (!visited[n]){
            int count{};
            dfs(i, n, count);
            ans = max(ans, count);
        }
        for(int j{}; j < n; j++){
            visited[j] = false;
        }
    }
    cout << ans;
}

int main(){
    setIO("moocast");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
}


```