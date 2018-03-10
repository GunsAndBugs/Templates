//Finding nodes in circle: 
#define lim 100010
ll ens[ lim ]; //koyta circle ekhane shuru hoise
bool iscycle[lim]; //node ta ki cycle er moddhe pore ?
ll color[lim]; // kaj shuru , shesh naki choltese

vector <ll> graph[lim];

ll nCycle = 0;

bool dfs( ll node , ll parent ) {

    if ( color[node] == 1 ) {
        // cout<<node<<' '<<parent<<endl;

        nCycle++;
        ens[node]++;
        return true;
    }
    //if( color[node] == 2 ) return false;
    color[node] = 1;

    ll prev = nCycle;
    for ( ll i = 0 ; i < graph[node].size() ; i++ ) {
        if ( parent == graph[node][i] || color[graph[node][i]] == 2  ) continue;
        bool cycle =  dfs( graph[node][i], node );

        if ( cycle ) {
            if ( nCycle > 0 ) iscycle[node] = true;
            if ( ens[node] > 0 ) {
                nCycle -= ens[node];
                ens[node] = 0;
            }

        }

    }

    color[node] = 2;
    //if(node==8) printf("8 = %lld\n", nCycle);

    if ( nCycle > prev ) return true;
    else return false;

}

int main() {
    // freopen("in.txt","r",stdin);
    ll n, m;
    sl(n); sl(m);
    for ( ll i = 0 ; i < m ; i++ ) {
        ll u, v;
        sl(u); sl(v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    nCycle = 0;
    memset( color, 0, sizeof color );
    memset( ens, 0, sizeof ens );
    memset( iscycle, false, sizeof iscycle );

    for ( ll i = 1 ; i <= n ; i++ ) {
        if ( color[i] == 0 ) {
            nCycle = 0;
            dfs(i, 0);
        }
    }
    ll ans = 0;
    for ( ll i = 1 ; i <= n ; i++ ) {
        if ( iscycle[i] == false ) {
            ans++;
            printf("%lld\n", i);
        }
    }

    return 0;
}
