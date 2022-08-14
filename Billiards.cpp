#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;

    dy = -dy;

    double a = dy - sy;
    double b = sx - dx;
    double c = a*sx + b*sy;

    cout << fixed << setprecision(10) << (double)(c/a);


    return 0;
}
