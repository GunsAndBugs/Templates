
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
   
   // ............ write here.
  
}

LL query(LL node, LL a, LL b, LL i, LL j, LL val) {
	
	if ( a > j || b < i ) return 0;
	if ( i <= a && b <= j ) {

		if ( tree[node].size() )
			return BS( val, node );
		return 0;

	}
	LL left = (node<<1) , right = left + 1 , mid = ((a+b)>>2);
	return query(left,a,mid,i,j,val) + query( right, mid+1,b,i,j,val );
}


//////////////// Merge Sort Tree END //////////////////////////
