/*
Convex Hull Trick
Basic Problem: Given N lines(y = mx + c). Slopes are given in an order(increasing or decreasing).
for any given value of x, find the min/max y. 
CHT machine( _decSlope, _askMin )
machine.add( M,C ) where y = Mx + C
machine.query( x )
*/

const LL inf = 1e18;
struct CHT{
	vector < LL > m,c;
	bool decSlope, askMin;
	CHT(bool _decSlope , bool _askMin ){
		decSlope = _decSlope;
		askMin = _askMin;
	}
	
	bool throwLine( LL l1,LL l2,LL l3 ){
		if(decSlope) {
			if( askMin )
				return (c[l2] - c[l1])*(m[l1] - m[l3]) >= (c[l3] - c[l1])*(m[l1]-m[l2]);
			else return (c[l2] - c[l1])*(m[l1] - m[l3]) <= (c[l3] - c[l1])*(m[l1]-m[l2]);
			
		}
		else{
			if(!askMin)
				return (c[l2] - c[l1])*(m[l1] - m[l3]) >= (c[l3] - c[l1])*(m[l1]-m[l2]);
			else return (c[l2] - c[l1])*(m[l1] - m[l3]) <= (c[l3] - c[l1])*(m[l1]-m[l2]);
		}
	}
	
	void add( LL M , LL C ){
		m.pb(M); c.pb(C);
		while( sz(m) >= 3 && throwLine(sz(m)-3,sz(m)-2,sz(m)-1)){
			m.erase(m.end() - 2);
			c.erase(c.end() - 2);
		}
	}
	
	LL f(LL i,LL x){
		return m[i]*x + c[i];
	} 
	
	LL query( LL x ){
		LL l = 0 ,r = sz(m)-1, ret;
		if(askMin) ret = inf;
		else ret = -inf;
		while(l<=r){
			LL m1 = l + (r-l)/3;
			LL m2 = r - (r-l)/3;
			if( f(m1,x)==f(m2,x) ){
				ret = f(m1,x);
				r = m2 - 1;
				l = m1 + 1;
			}
			else if(f(m1,x)<f(m2,x)){
				if(askMin){
					ret = f(m1,x);
					r = m2 - 1;
				}
				else{
					ret = f(m2,x);
					l = m1 + 1;
				}
			}
			else{
				if(askMin){
					ret = f(m2,x);
					l = m1 + 1;
				}
				else{
					ret = f(m1,x);
					r = m2 - 1;
				}
			}
		}
		return ret;
	}
};