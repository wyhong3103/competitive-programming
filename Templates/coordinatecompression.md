Check out the problem : https://usaco.guide/silver/sorting-custom?lang=cpp for a better understanding on this technique.
```cpp
int getIndex(int a){
    return lower_bound(all(indices),a) - indices.begin();
}

void removeDup(vector<int>& indices){
    sort(all(indices));
    indices.erase(unique(all(indices)), indices.end());
}

//add all the possible element into indices array, run rmeoveDup, then getIndex
```