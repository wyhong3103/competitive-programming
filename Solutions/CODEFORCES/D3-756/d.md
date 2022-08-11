Struggled a little while doing the question, beacuse I dont know what does the question want! The sum of weight and all, but after a few minutes, I eventually figured it out. Simple BFS, to validate the order given. Then output the index of the order but - parents index.

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

vector<int> adj[1000000];
bool vis[1000000];
int parents[1000000];

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int root;
        for(int i{}; i < n; i++){
            int parent;
            cin >> parent;
            parent--;
            if (i == parent) root = parent;
            adj[parent].push_back(i);
            parents[i] = parent;
        }

        map<int,int> p;
        for(int o{}; o < n; o++){
            int i;
            cin >> i;
            i--;
            p[i] = o;
        }

        queue<int> q;
        q.push(root);
        vis[root] = true;
        bool valid = true;

        while(!q.empty()){
            int s = q.front(); q.pop();

            for(auto& i : adj[s]){
                if (!vis[i]){
                    vis[i] = true;
                    if (p[i] < p[s]){
                        valid = false;
                    }
                    q.push(i);
                }
            }
        }

        if (!valid){
            cout << -1;
        }else{
            for(int i{}; i < n; i++){
                cout << p[i]-p[parents[i]] << ' ';
            }
        }
        cout << '\n';
        memset(vis, 0 , sizeof(vis));
        for(int i{}; i < n; i++){
            vector<int> a;
            swap(adj[i], a);
        }

    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}


```