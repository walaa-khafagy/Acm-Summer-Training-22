#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x, y;
};

int dis ( point a, point b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int orientation ( point a, point b, point c)
{
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; /// clockwise
    if (v > 0) return +1; /// counter-clockwise
    return 0;
}

int main()
{

    int n;
    cin >> n;

    vector < point > a(n);

    for ( int i=0; i<n; ++i )
        cin >> a[i].x >> a[i].y;

    point p0 = a[0];           /// extreme point

    for ( int i=1; i<n; ++i )
    {
        if ( a[i].y < p0.y || ( a[i].y == p0.y && a[i].x < p0.x ) )
                p0 = a[i];
    }

    sort ( a.begin(), a.end(), [&p0]( const point& a, const point& b )
    {
        int o = orientation( p0, a, b );

        if ( o == 0 )
        {
            return dis(p0,a) < dis(p0,b);
        }

        return o > 0;

    }
         );

    vector < point > st;

    for (int i=0; i<a.size(); ++i) {
        while (st.size() > 1 && orientation(st[st.size()-2], st.back(), a[i]) < 0 )
            st.pop_back();
        st.push_back(a[i]);
    }

    cout <<"Convex Hull: \n";
   for ( int i=0; i<st.size(); ++i )
        cout << st[i].x << " " << st[i].y <<"\n";

    return 0;
}

