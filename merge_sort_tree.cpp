
#define lim  200010

//////////////// Merge Sort Tree //////////////////////////

LL arr[lim ];
vector < LL > tree[4 * lim];

void merge_sort(LL node, LL a, LL b) {
	if (a == b) {
		tree[node].pb(arr[a]);
		return;
	}
	LL mid = (a + b) / 2 , left, right;
	left = node * 2 ; right = left + 1;
	merge_sort( left, a, mid);
	merge_sort( right, mid + 1, b);
	merge( tree[left].begin() , tree[left].end() , tree[right].begin(), tree[right].end(), back_inserter(tree[node]));
}

LL BS( LL node, LL val ){
   
   LL l = 0 ,  r = tree[node].size()-1 , m;
   LL ret = 0;
   while(l<=r){
   		m = (l+r)/2;
   		if( tree[node][m] <= val ){
   			ret = m+1;
   			l = m+1;
   		}
   		else r = m-1;
   }
   return tree[node].size()-ret;
}

LL query(LL node, LL a, LL b, LL i, LL j, LL val) {
	
	if ( a > j || b < i ) return 0;
	if ( i <= a && b <= j ) {
		if ( tree[node].size() )
			return BS( node, val );
		return 0;
	}
	LL left = (node<<1) , right = left + 1 , mid = ((a+b)/2);
	return query(left,a,mid,i,j,val) + query( right, mid+1,b,i,j,val );
}


//////////////// Merge Sort Tree END //////////////////////////
