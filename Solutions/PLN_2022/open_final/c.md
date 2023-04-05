```

I like this problem.

First, let's just observe how we can move the pieces first.

The middle one can always move in and out.

Let's prove that only one between left and right can move. Let d1 = distance between mid and left piece, d2 = distance between mid and right piece. if d1 > d2, the right one gets to move, bc if the left one was to move, it would be at mid + d1, which is over the right piece, and it violates the rule s.t one piece cannot move over 2 piece. If d2 > d1, left gets to move instead. If d1 == d2, none get to move, because they would land on each other.

Some interesting fact about the moves is the invariant,

Notice that, GCD of d1 and d2 would never change no matter how we moves it.

Proof : 

WLOG, let's just think of shrinking the distance between left and right, i.e never move middle piece, we will see why later.

let d1 = 5g, d2 = 3g, g = gcd(d1, d2)

In this situation we can only move the right piece, which would give us

d1 = 5g-3g = 2g
d2 = 3g

If you know gcd well, you will know that gcd(a, b) = gcd(a-b, b)

So basically, no matter how many time do we perform the operation, gcd would stay the same.

What if we allow the moving of middle piece? Would GCD still stay the same?

Yes, because this is essentially a two way operation, we can make it from state x to state y, then we can also make it from state y to state x.

However, with the above, it is not sufficient to solve the given problem.

We would have to model the way we move into a binary tree.

The root of the binary tree is simply the state when d1 = d2.

Each move we make with the middle piece, create a left or right subtree.

And notice that, if you reverse the middle piece move, we're essentially shrinking / going back to the previous state, and by reversing all the middle piece move, we will eventually be led back to the root.

Now, with this, this is not hard to see that, if our intial setting and target setting has the same root then we can always make it from one to the other.

Why is it not possible to make them the same when they have different root? If these two states can be transformed from one to another then they should belong to the same binary tree, and have the same root.

Okay, now this is not sufficient to solve the problem yet.

We would have to find the moves needed to transform the initial state to the final state.

Now this is simply the distance between two node in a tree, which is simply distance from node a to lca  + distance from b to lca 

It's not done yet, we cannot possibly store the entirety of the binary tree, because imagine the case below,

1 2 1e8

1e8-2 1e8-1 1e8

This would take around 1e8 operation to reach! We can't do that!

To tackle this problem, we can do something that is similar to gcd algorithm, if d2 > d1, then we move the left piece d2/d1 times (subtract by 1 if d1 | d2 because we cannot have them overlapped). After that, d1 would > d2, or they would be the same. This operation only takes log n times to get to root (same as euclid gcd algorithm).

To find the LCA, we can do binary lifting. We perform the same algorithm described above, but not move more than the number of times we want to move it upward.

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

pair<ll,vll> findRoot(vll cur){
    ll cnt = 0;
    ll d1 = cur[1]-cur[0], d2 = cur[2]-cur[1];
    while (d1 != d2){
        if (d1 > d2){
            ll steps = d1/d2;
            if (d1 % d2 == 0) steps--;
            cnt += steps;
            cur[1] -= steps * d2; 
            cur[2] -= steps * d2;
        }else{
            ll steps = d2/d1;
            if (d2 % d1 == 0) steps--;
            cnt += steps;
            cur[1] += steps * d1;
            cur[0] += steps * d1;
        }
        d1 = cur[1]-cur[0], d2 = cur[2]-cur[1];
    }

    return make_pair(cnt, cur);
}

vll up(vll cur, ll level){
    ll d1 = cur[1]-cur[0], d2 = cur[2]-cur[1];
    while (level && d1 != d2){
        if (d1 > d2){
            ll steps = d1/d2;
            if (d1 % d2 == 0) steps--;

            if (level < steps) steps = level;

            cur[1] -= steps * d2; 
            cur[2] -= steps * d2;

            level -= steps;
        }else{
            ll steps = d2/d1;
            if (d2 % d1 == 0) steps--;

            if (level < steps) steps = level;

            cur[1] += steps * d1; 
            cur[0] += steps * d1;

            level -= steps;
        }
        d1 = cur[1]-cur[0], d2 = cur[2]-cur[1];
    }

    return cur;
}

vll lca(vll a, ll depa, vll b, ll depb){
    a = up(a, depa - min(depa, depb));
    b = up(b, depb - min(depa, depb));

    if (a == b) return a;

    for(ll i{50}; i >= 0; i--){
        if (up(a, (1LL << i)) != up(b, (1LL << i))){
            a = up(a, (1LL << i));
            b = up(b, (1LL << i));
        }
    }
    return up(a, 1);
}


void solve(){
    vll at(3), lo(3);
    cin >> at[0] >> at[1] >> at[2] >> lo[0]  >> lo[1] >> lo[2];

    sort(all(at));
    sort(all(lo));

    pair<ll, vll> root1 = findRoot(at);
    pair<ll, vll> root2 = findRoot(lo);

    if (root1.sec != root2.sec){
        cout << "NO";
        return;
    }

    vll a = lca(at, root1.fir, lo, root2.fir);

    cout << "YES" << '\n';
    cout << root1.fir + root2.fir - findRoot(a).fir * 2;
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