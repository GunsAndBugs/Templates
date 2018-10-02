
struct line {
	LL m , c;
	line() {
		m = 0 , c = 0;
	}
	line(LL _m , LL _c) {
		m = _m; c = _c;
	}
	bool operator<(const line &arg )const {
		return m < arg.m;
	}
	LL f(LL x) {
		return m * x + c;
	}
};

#define CLIM 100010
struct CHT {

	line lines[ CLIM ];
	LL sz ;

	CHT() {
		sz = 0;
	}

	bool baad( LL i1, LL i2 , LL i3 = 0 ) {
		return 1.0 * (double)( lines[i2].c - lines[i1].c  ) * ( lines[i1].m - lines[i3].m )
		       > 1.0 * ( lines[i3].c - lines[i1].c  ) * ( lines[i1].m - lines[i2].m );

	}

	void add( LL m , LL c ) {
		lines[0] = line(m, c);
		while ( sz >= 2 && baad(sz - 1, sz) ) sz--;
		lines[sz + 1] = lines[0]; sz++;
	}

	LL query( LL ai ) {
		LL l = 1 , r = sz;
		LL ans = 1e18;
		while (l <= r) {
			LL m1 = l + (r - l) / 3;
			LL m2 = r - (r - l) / 3;
			LL y1 = lines[m1].f(ai);
			LL y2 = lines[m2].f(ai);
			if (y1 <= y2) {
				ans = y1;
				r = m2 - 1;
			}
			else {
				ans = y2;
				l = m1 + 1;
			}
		}
		return ans;
	}

};


#define lim 100010
LL dp[lim], a[lim], b[lim];
