#include <bits/stdc++.h>
using namespace std;

int n , e, timer, cnt;
vector < vector < int > > adj;
vector < int > tin, low;
vector < bool > visited, ans;

void dfs ( int v , int p )
{
    visited[v] = 1;
    tin[v] = low[v] = ++timer;
    int cnt = 0 ;

    for ( int to : adj[v] )
    {
        if ( to == p ) continue;
        if ( visited[to] )
        {
            low[v] = min ( low[v] , tin[to] );
        }
        else
        {
            dfs ( to , v );
            cnt++;
            low[v] = min ( low[v] , low[to] );
            if ( low[to] >= tin[v] && p != -1 )
                      cout <<v << " is an articulation point\n";
            /** Note that: a single articulation point can be printed more than once
                To avoid that, put them in a set or create a boolean array marking articulation points with 1 **/
        }
    }
    if ( cnt > 1 && p == -1 )
         cout <<v << " is an articulation point\n";



    return;
}


void find_Articulation()
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
        int a , b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find_Articulation();

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
