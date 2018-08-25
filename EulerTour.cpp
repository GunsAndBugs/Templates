////// EULER TOUR (print tour) ///////
vector < pair< LL , LL > > graph[1001];
list < pair<LL, LL> > cyc;

void EulerTour( list< pair<LL, LL> >::iterator i , LL u ) {

	for ( LL j = 0 ; j < graph[u].size(); j++ ) {

		pair < LL , LL > &thisEdge = graph[u][j];

		if ( thisEdge.ss ) {

			thisEdge.ss = 0;

			for ( LL k = 0 ; k < graph[ thisEdge.ff ].size() ; k++ ) {

				pair < LL , LL > &BiEdgeChk = graph[ thisEdge.ff ][k];
				
				if ( BiEdgeChk.ff == u && BiEdgeChk.ss ) {
				
					BiEdgeChk.ss = 0;
				
					break;
				
				}

			}

			EulerTour( cyc.insert(i, { u , thisEdge.ff }) , thisEdge.ff );

		}
	}
}
//////////////////// EULER TOUR ENDS ///////////////////
