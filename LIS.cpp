//complexity: O(nlgn) 
/*
define limit first.
define LIS_SZ = 1 for every test case
define lastVal[] = infinity first
LB(s,e,val) finds the largest index i so that lastVal[i]<=val
genLIS( *a , n ) genarets LIS_SZ for array a[] of length 'n'
*/
#define lim 100010
LL arr[lim];
LL lastVal[lim];
LL LIS_SZ = 1;
LL LB( LL s, LL e , LL val ){
    LL ret = 0 , mid ;
    while( s<=e ){
      mid = ((s+e)/2);
      if( lastVal[mid]<=val ){
        ret = mid;
        s = mid + 1;
      }
      else e = mid - 1;
    }
    return ret;
}

void genLIS( LL *a ,  LL n ){
    FOR(i,1,n) lastVal[i] = 1e18;
    FOR(i,1,n){
       LL upInd = LB( 1,LIS_SZ,a[i] ) + 1;
        lastVal[upInd] = a[i];
        LIS_SZ = max( LIS_SZ , upInd );
    }
}
