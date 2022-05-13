This is a pretty length solution, again, I uses floyd algorithm for this problem. The number of teleportations for node in a cycle is the length of the cycle, we can easily find this using floyd's algorithm. Answer for nodes that aren't in a cycle can be found recursively, and it's shown below.
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);

void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

const int MAX = 2e5 + 5;
int next_node[MAX];
int ans[MAX];
bool in_cycle[MAX];

int fill(int i){
    if (in_cycle[i]) return ans[i];
    ans[i] = fill(next_node[i])+1;
    return ans[i];
}

void floyd(int i){
    if (ans[next_node[i]]){
    	//If the next node is already being processed, the answer is just the answer for the next node + 1, the reason we can do this is because there might be some unprocessed node, and we don't want to redo everything.
        ans[i] = ans[next_node[i]]+1; 
        return;
    }

    //Floyd Algorithm
    int p1 = next_node[i];
    int p2 = next_node[next_node[i]];
    while (p1 != p2){
        p1 = next_node[p1];
        p2 = next_node[next_node[p2]];
    }

    p1 = i;
    while (p1 != p2){
        p1 = next_node[p1];
        p2 = next_node[p2];
    }
    
    int length = 1;
    in_cycle[p2] = 1;
    p1 = next_node[p2];
    while (p1 != p2){
        p1 = next_node[p1];
        in_cycle[p1] = 1;
        length++;
    }

    //Fill in the length for nodes in the cycle
    p1 = next_node[p2];
    while (p1 != p2){
        ans[p1] = length;
        p1 = next_node[p1];
    }
    ans[p2] = length;
    //Fill in the length for nodes that aren't in a cycle
    fill(i);
}

void solve(){
    int n;
    cin >> n;
    for(int i{}; i < n; i++){
        int t;
        cin >> t;
        next_node[i] = t-1;
    }
    
    for(int i{}; i < n; i++){
        if (!ans[i]){
            floyd(i);
        }
    }

    for(int i{}; i < n; i++){
        cout << ans[i] << ' ';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```