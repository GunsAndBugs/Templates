/*
    Strongly Connected Component
    Time: O(N + M)
    Space: O(N + M)
    dfs(u) is for Topological Sorting
    cnt(u) is to count the size of a SCC.
*/
const LL lim = 1e5+10;
vector < LL > g[lim], rg[lim];
stack < LL > st;
bool vis[lim];

void dfs( LL u ){
	if(vis[u]) return;
	vis[u] = true;
	for(auto v: g[u])dfs(v);
	st.push(u);
}

LL cnt( LL u ){
	if(vis[u]) return 0;
	vis[u] = true;
	LL ret = 1;
	for(auto v: rg[u]) ret+=cnt(v);
	return ret;
}