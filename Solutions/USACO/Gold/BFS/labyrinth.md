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
    int h, w;
    cin >> h >> w;
    
    vector<string> grid(h);
    for(auto& i : grid) cin >> i;

    pi a;
    pi b;
    for(int i{}; i < h; i++){
        for(int j{}; j < w; j++){
            if (grid[i][j] == 'A') a = {i,j};
            else if (grid[i][j] == 'B') b = {i,j};
        }
    }


    vector<vi> dir(h, vi (w));
    
    queue<pi> q;
    q.push({a.fir,a.sec});
    dir[a.fir][a.sec] = -1;
    
    while (!q.empty()){
        pi cur = q.front(); q.pop();
        if (cur.fir > 0 && grid[cur.fir-1][cur.sec] != '#' && !dir[cur.fir-1][cur.sec]){
            dir[cur.fir-1][cur.sec] = 1;
            q.push({cur.fir-1,cur.sec});
        }
        if (cur.fir < h-1 && grid[cur.fir+1][cur.sec] != '#' && !dir[cur.fir+1][cur.sec]){
            dir[cur.fir+1][cur.sec] = 3;
            q.push({cur.fir+1,cur.sec});
        }
        if (cur.sec > 0 && grid[cur.fir][cur.sec-1] != '#' && !dir[cur.fir][cur.sec-1]){
            dir[cur.fir][cur.sec-1] = 4;
            q.push({cur.fir,cur.sec-1});
        }
        if (cur.sec < w-1 && grid[cur.fir][cur.sec+1] != '#' && !dir[cur.fir][cur.sec+1]){
            dir[cur.fir][cur.sec+1] = 2;
            q.push({cur.fir,cur.sec+1});
        }
    }

    if (!dir[b.fir][b.sec]){
        cout << "NO";
    }else{
        cout << "YES" << '\n';
        string res = "";
        pi cur = {b.fir,b.sec};
        while (dir[cur.fir][cur.sec] != -1){
            switch(dir[cur.fir][cur.sec]){
                case 1:
                    res += 'U';
                    cur.fir++;
                    break;
                case 2:
                    res += 'R';
                    cur.sec--;
                    break;
                case 3:
                    res += 'D';
                    cur.fir--;
                    break;
                case 4:
                    res += 'L';
                    cur.sec++;
                    break;
            }
        }
        cout << sz(res) << '\n';
        for(int i{sz(res)-1}; i >= 0; i--){
            cout << res[i];
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