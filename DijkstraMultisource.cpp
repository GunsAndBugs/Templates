
#define lim 200010
vector < ll > graph[lim] , edge[lim];


struct info {
    ll nd ,  cst;
    bool operator <( const info &x )const {
        return cst > x.cst;
    }
};
priority_queue<  info > pq;
ll mindist[lim];
void dijkstra( ll src ) {
    mindist[src] = 0;
    info tmp;
    tmp.nd = src, tmp.cst = 0;
    pq.push(tmp);
    while (!pq.empty()) {
        tmp = pq.top(); pq.pop();
        if ( tmp.cst > mindist[tmp.nd] ) continue;
        for ( ll i = 0 ; i < graph[ tmp.nd ].size() ; i++ ) {
            ll ch = graph[tmp.nd][i];
            ll thiscost =  mindist[ tmp.nd ] + edge[tmp.nd][i];
            if ( mindist[ch] > thiscost ) {
                mindist[ch] = thiscost;
                info ctmp ;
                ctmp.nd = ch;
                ctmp.cst = mindist[ch];
                pq.push(ctmp);
            }
        }
    }
}
