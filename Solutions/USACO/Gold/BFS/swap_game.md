```

The idea is to simulate every moves of the game with BFS.

At each distance (in BFS), represent the number of moves we have used so far.


The initial idea is to pure BFS without any specific trick.

And this would form a really big tree, which grows in O(12^x) (not really 12, considering some repeated state won't get visited at all)

why 12? 

For each column/row, we can swap (1,2), (2,3), there are 3 columns/rows in total : 2*(3*2) = 12

We could keep generating the game state with next moves, and output the answer if we found a game of state where a[i][j] = (i*3) + (j+1), for each 0 <= i < 3, 0 <= j < 3

But this will eventually get us TLE. As the BFS tree is just way too big.


To optimise this, we have to take advantage of the fact that we know the final game state. So we could kind of use the meet in the midle technique to solve this problem. Have each game state (initial game state with the completed game state) generate the game states until they meet each other. This will have much better time complexity, you can think of the initial method as a big growing tree, but now, with the completed state of game, there will be 2 trees with lesser distance, which significantly improved the time complexity.

But this wasn't enough, using a map<vector<vi>, int> to store our visited states and its distance is too slow, we need to use a hash map to do it instead, and we can accomplish this with our custom hash function.

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

struct VectorHasher {
    int operator()(const vector<vi> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            for(auto& j : i){
                hash ^= j + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
        }
        return hash;
    }
};

void solve(){
    vector<vi> board (3, vi (3));
    for(int i{}; i < 3; i++){
        for(int j{}; j < 3; j++){
            cin >> board[i][j];
        }
    }

    vector<vi> initial (3, vi (3));
    for(int i{}; i < 3; i++){
        for(int j{}; j < 3; j++){
            initial[i][j] = (i*3) + (j+1);
        }
    }

    unordered_map<vector<vi>, int, VectorHasher> dist1;
    unordered_map<vector<vi>, int, VectorHasher> dist2;

    queue< vector<vi> > q1;
    queue< vector<vi> > q2;
    q1.push(board);
    q2.push(initial);
    dist1[board] = 0;
    dist2[initial] = 0;
    while (true){
        vector<vi> cur = q1.front(); q1.pop();
        int cur_dist = dist1[cur];

        if (dist2.count(cur)){
            cout << dist2[cur]+cur_dist;
            return;
        }
        
        for(int i{}; i < 3; i++){
            for(int j{}; j < 2; j++){
                swap(cur[i][j], cur[i][j+1]);
                if (!dist1.count(cur)){
                    dist1[cur] = cur_dist+1;
                    q1.push(cur);
                }
                swap(cur[i][j], cur[i][j+1]);
            }
        }

        for(int i{}; i < 3; i++){
            for(int j{}; j < 2; j++){
                swap(cur[j][i], cur[j+1][i]);
                if (!dist1.count(cur)){
                    dist1[cur] = cur_dist+1;
                    q1.push(cur);
                }
                swap(cur[j][i], cur[j+1][i]);
            }
        }

        cur = q2.front(); q2.pop();
        cur_dist = dist2[cur];
        
        for(int i{}; i < 3; i++){
            for(int j{}; j < 2; j++){
                swap(cur[i][j], cur[i][j+1]);
                if (!dist2.count(cur)){
                    dist2[cur] = cur_dist+1;
                    q2.push(cur);
                }
                swap(cur[i][j], cur[i][j+1]);
            }
        }

        for(int i{}; i < 3; i++){
            for(int j{}; j < 2; j++){
                swap(cur[j][i], cur[j+1][i]);
                if (!dist2.count(cur)){
                    dist2[cur] = cur_dist+1;
                    q2.push(cur);
                }
                swap(cur[j][i], cur[j+1][i]);
            }
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

Okay turned out, this is dumb. There is only 9! game states (which I have thought of it, but never really sure with the ideas), and for each game state we find the number of moves needed to reach the state.(which is a little vague for now) For a better understanding on this approach, [USACO Guide Editorial](https://usaco.guide/problems/cses-1670-swap-game/solution). It's really creative indeed, using a base 9 numbers to represent the state of the game.