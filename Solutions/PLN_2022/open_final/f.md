```

P(i,j) = p.b for player to win if he is at j-th position of the queue (i-th position is the first of the queue for our setting) when there are i total players in the queue


If j is the last position

P(i,j) = P(i,(j+1) % i) * 1/2 + 1/6

The idea is at the last position we can either directly win the game or back to the beginning of the queue

else

P(i,j) = P(i,(j+1) % i) * 1/2 + P(i-1, j) * 2/6

The idea is we either go in front of the queue, because the first person went back to the back of the queue, or get eliminated

P(i, 0) = 1


Now it is an infinite loop, so we need to apply some algebera

Notice that, 

P(i,j) = P(i, (j+1) % i) * 1/2 + ...

(ignore the rest of the eq first)

This will eventually lead back to P(i,j)

Basically at the end we can let P(i,j) be x, at some point we will loop back to x, and then we need to return back to the original equation where we can do algebra on x.

x = (xa + c) * 1/2 + ...

x = xa * 1/2 + ...

x - xa/2 = ...

x (1 - a/2) = ...

x = .../(1 - a/2)

This is tricky implementation in the code,

We need to keep track of the equation we started s.t with no dependency on others.

P(i,j) = P(i, (j+1) % i) * 1/2

P(i, (j+1) % i) is dependent on P(i,j) because eventually we will loop back to this eq, so we need to know exactly what equation are we dependet on and then only we can tell that we have a parent recursive function that has the same P(i,j) that we can solve with algebra.

You might be wondering about the other part of the equation

P(i,j) = P(i, (j+1) % i) * 1/2 + P(i-1, j) * 2/6

Well for P(i-1,j) will never loop back to P(i,j), because there just isnt a need to do that, whenever P(i-1,j) return, it will be a constant, it basically has no dependency on P(i, j), so we only have to worry about P(i, (j+1) % i)

We only store P(i,j) in dp state if we manage to get the equation as a constant or else we are never storing it.

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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

const int MX = 1005;
double dp[MX][MX];

// db.first is always a constant
// i and j is where we came from
pdb recur(int n, int m, int i, int j){ 
    if (n == 1 && m == 0){
        return {1, 0};
    }

    if (dp[n][m] != -1) return {dp[n][m], 0};

    pdb ret;  
    if (i == -1 && j == -1){
        if (n == m+1){
            ret.fir = (double)1/6;
            pdb res;
            res = recur(n, (m+1) % n, n, m);
            ret.fir += res.fir * 0.5;
            ret.fir /= 1-(res.sec * 0.5);
            dp[n][m] = ret.fir; 
            return ret;
        }
        else{
            pdb res1, res2;


            //costant + unknown
            res1 = recur(n, (m+1) % n, n, m);
            //only constant left
            res2 = recur(n-1, m, -1, -1);

            ret.fir = res2.fir * (double)2/6;            
            ret.fir += res1.fir * 0.5;
            ret.fir /= 1-(res1.sec * 0.5);
            dp[n][m] = ret.fir;
            return ret;
        }
    }else{
        if (n == m+1){
            pdb res;
            // if n == i && m+1 % n == j, do something
            if (n == i && (m+1) % n == j) res = {0, 1};
            else res = recur(n, (m+1) % n, i, j);
            ret.fir = (double)1/6;
            ret.fir += res.fir * 0.5;
            ret.sec = res.sec * 0.5;
            return ret;
        }
        else{
            pdb res1, res2;

            //costant + unknown
            if (n == i && (m+1) % n == j) res1 = {0, 1};
            else res1 = recur(n, (m+1) % n, i, j);
            //only constant left
            res2 = recur(n-1, m, -1, -1);

            ret.fir = res2.fir * (double)2/6;            
            ret.fir += res1.fir * 0.5;
            ret.sec = res1.sec * 0.5;
            return ret;
        }
    }
}


void solve(){
    int n, m;
    cin >> n >> m;
    
    // flip the queue, make 1st position the last in the queue
    m = n-m;

    for(int i{}; i <= n; i++){
        for(int j{}; j <= n; j++){
            dp[i][j] = -1;
        }
    }

    cout << setprecision(9) << fixed;
    cout << recur(n, m, -1, -1).fir;
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