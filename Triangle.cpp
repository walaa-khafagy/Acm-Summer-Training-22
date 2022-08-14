#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll x[300], y[300];
bool IsAreaNonZero ( ll x1, ll y1, ll x2, ll y2, ll x3, ll y3 )
{
    return (bool)( abs((x1*(y2-y3)+ x2*(y3-y1)+ x3*(y1-y2) )) > 0 ) ;
}
int main()
{
    int n;
    cin >> n;
    for ( int i=0; i<n; ++i )
        cin >> x[i] >> y[i];
    ll noOfTriangles = 0;
    for ( int i=0; i<n; ++i )
        for ( int j=i+1; j<n; ++j )
            for ( int k=j+1; k<n; ++k )
                noOfTriangles += IsAreaNonZero(x[i], y[i], x[j], y[j], x[k], y[k]);


    cout << noOfTriangles <<"\n";
    return 0;
}
