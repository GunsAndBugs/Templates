/*
    Time: O(nlgn)
    Space: O(n)
*/

const LL lim = 1e5 + 10;

vector < LL > g[lim];
LL treeSize[lim];
bool isRoot[lim];
LL maxChild[lim];

LL dfs( LL u , LL p ){
	treeSize[u] = 1;
	maxChild[u] = 0;
	for(auto v:g[u] )if(v!=p && isRoot[v]==false){
		LL childSize = dfs(v,u);
		treeSize[u] += childSize;
		maxChild[u] = max( maxChild[u] ,childSize );
	}
	return treeSize[u];
}

LL findRoot( LL u , LL p , LL subTreeSize ){
	maxChild[u] = max(  maxChild[u], subTreeSize - treeSize[u] );
	if( maxChild[u]*2 <= subTreeSize ) return u;
	LL ret = -1;
	
	for(auto v: g[u]) if(v!=p && isRoot[v]==false){
		ret = max( ret , findRoot(v,u,subTreeSize) );
	}
	return ret;
}

char ans[lim];

void F( LL u , char c){
	dfs(u,-1);
	LL root = findRoot(u,-1, treeSize[u]);
	isRoot[root] = true;
	
	ans[root] = c;
	for(auto v: g[root])if( isRoot[v] == false){
		F(v,(char)(c+1));
	}
}
