
		#include <iostream>
		#include <string>
		#include <set>
		#include <map>
		#include <stack>
		#include <queue>
		#include <vector>
		#include <utility>
		#include <iomanip>
		#include <sstream>
		#include <bitset>
		#include <cstdlib>
		#include <iterator>
		#include <algorithm>
		#include <cstdio>
		#include <cctype>
		#include <cmath>
		#include <math.h>
		#include <ctime>
		#include <cstring>

		#define ll long long 
		#define lf double 
		
		#define sl(n) scanf("%lld", &n)
		#define sf(n) scanf("%lf", &n)

		#define PI 2*acos(0.0)
		#define INFP ((ll)1<<62)
		#define INFN (0-(ll)1<<62)

		#define pb push_back
		#define mp make_pair
		#define ff first
		#define ss second
		#define srt(v) sort(v.begin(), v.end()) 

		using namespace std;


		int main(){
				
				ll n,m;
				sl(n); sl(m);
				bool col = false;
				scanf(" ");
				for( ll i = 1 ; i<=n ; i++ ){
					for( ll j = 1 ; j<=m ; j++ ){
						char c;
						scanf("%c", &c);
						scanf(" ");
						//cout<<c<<endl;
						if(c=='C' || c=='M' || c=='Y')  col = true;
					}
				}
				if(col) printf("#Color\n");
				else printf("#Black&White\n");

		return 0;}
