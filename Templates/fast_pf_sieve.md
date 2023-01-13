```cpp


const int MX = 1e7 + 5;
int sieve[MX];

void gen_sieve(){
    for(int i{2}; i < MX; i++){
        if (sieve[i]) continue;
        for(int j{2*i}; j < MX; j+=i){
            sieve[j] = i;
        }
    }
}

/*

Prime factorization in O(log n)

map<int,int> pf;
while (sieve[x]){
    pf[sieve[x]]++;
    x /= sieve[x];
}
pf[x]++;

*/

```