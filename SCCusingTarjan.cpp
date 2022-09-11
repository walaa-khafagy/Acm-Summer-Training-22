#include <bits/stdc++.h>
using namespace std;

int n;
vector< vector<int> > adj, comps;
vector<bool> visited, inStack;
vector<int> tin, low;
stack <int> stk;
int timer;

void dfs (int v)
{
    visited[v] = inStack[v] = 1;
    tin[v] = low[v] = ++timer;
    stk.push(v);

    for ( int to : adj[v] )
    {
        if ( inStack[to] )
        {
            low[v] = min ( low[v], tin[to] );
        }
        else if ( !visited[to] )
        {
            dfs(to);
            low[v] = min( low[v], low[to] );
        }

    }

    if ( tin[v] == low[v] )
    {
        //  cout <<"Here is a SCC: \n";
        comps.push_back(vector <int>());
        int x = -1;
        while ( x != v )
        {
            x = stk.top();
            //  cout <<x << " ";
            comps.back().push_back(x);
            inStack[x] = 0;
            stk.pop();

        }
        //  cout <<"\n";
    }
    return;

}


void find_SCC ()
{
    visited.resize(n+1,0);
    inStack.resize(n+1,0);
    tin.resize(n+1,-1);
    low.resize(n+1,-1);

    for ( int i=1; i<=n; ++i )
        if ( !visited[i] )
            dfs (i);

    return;
}
int main()
{
    int  e;
    cin >> n >> e ;
    adj.resize(n+1);
    while ( e-- )
    {
        int a, b;
        cin >> a >> b ;
        adj[a].push_back(b);
    }
    find_SCC();

    /** to print SCCs using comps **/

    for ( int i=0; i<comps.size(); cout<<"\n", ++i )
    {
            for ( int j : comps[i] )
                cout << j <<" ";
    }



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
5 6
6 3
6 8
6 7
**/


/**
7 9
1 2
2 3
3 4
4 2
1 5
5 6
6 7
7 5
6 2
**/


