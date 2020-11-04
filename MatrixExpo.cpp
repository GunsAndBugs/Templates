/*
    Matrix Expo
    -----------
    Let the matrix has R rows and C columns. 
    1. create matrix machine by:    matExpo machine;
    2. initialize with R,C:         machine.init(R,C);
    3. input A[R][C]                machine.take(i,j,val);
    4. calculate (A[][])^p          machine.expo(p);
                                    or, machine.loop(p);
    
    Space complexity:   O(R*R);
    Time Complexity:    O(R*R*R*lg(p));
*/


const LL mod = 1e9+7;
const LL inf = 2e18;
const LL matSize = 110;
struct matExpo{
	
	LL mat[3][matSize][matSize];
	LL a,res,temp;
	LL r, c;
	
	void init(LL R, LL C){
		r = R, c = C;
		a = 0 , res = 1 , temp = 2;
		FOR(i,1,R)FOR(j,1,C){
			mat[a][i][j] = inf;
			mat[res][i][j] = inf;
		}
	};
	
	void take(LL i, LL j, LL val){ mat[a][i][j] = mat[res][i][j] = val;}
	
	void multiply( LL x, LL y , LL z ){
		FOR(i,1,r)FOR(j,1,c){
			mat[temp][i][j] = inf;
			FOR(k,1,r){
				if( max( mat[x][i][k],mat[y][k][j])<inf  )
				mat[temp][i][j] = min( mat[temp][i][j] , mat[x][i][k] + mat[y][k][j] );
			}
		}
		
		FOR(i,1,r)FOR(j,1,c) mat[z][i][j] = mat[temp][i][j];
	}
	
	void expo(LL p){
		while(p){
			if(p&(1LL)) multiply(a,res,res);
			p = p/2;
			multiply(a,a,a);
		}
	}
	
	void loop( LL p ){
		FOR(i,1,p-1) multiply(a,res,res);
	}

};