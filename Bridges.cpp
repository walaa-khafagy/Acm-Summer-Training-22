#include <bits/stdc++.h>
using namespace std;

int n, e, timer;
vector < vector < int > > adj;
vector < int > tin, low;
vector < bool > visited;

void dfs ( int v, int p )
{
    visited[v] = 1;
    tin[v] = low[v] = ++timer;

    for ( int to : adj[v] )
    {

        if ( to == p || v == to ) continue;
        if ( visited[to] )
        {
            low[v] = min ( low[v], tin[to] );
        }
        else
        {
            dfs ( to, v );
            low[v] = min ( low[v], low[to] );
            if ( low[to] > tin[v] )
                cout <<"Bridge found, form: "<< v << " -> " << to <<"\n";
        }
    }
}

void find_bridges()
{
    tin.resize(n+1, -1);
    low.resize(n+1, -1);
    visited.resize(n+1, 0);

    for ( int i=1; i<=n; ++i)
        if ( !visited[i] )
            dfs(i, -1);

    return;
}

int main()
{
        cin >> n >> e ;
        adj.resize(n+1);

        for ( int i=0; i<e; ++i )
        {
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        find_bridges();

    return 0;
}

/**
8 10
1 2
1 8
1 5
2 3
4 2
3 4
6 3
5 6
6 8
6 7
**/

