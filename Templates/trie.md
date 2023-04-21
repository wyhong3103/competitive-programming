```cpp
struct Trie{
	//This node's child
    map<char, Trie> c;
    //If it has a mark, then its end of a prefix
    bool mark = false;

    //insert word
    void insert(string& s, int pos){;
        if (pos != sz(s)) c[s[pos]].insert(s, pos+1);
        else mark = true;
    }
    
    //DFS on Trie
    int dfs(){
    	for(auto& i : c){
    		i.sec.dfs()	
    	}
    }
};
```