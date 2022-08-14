#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;

    cin >> x1 >> y1 >> x2 >> y2;   /// line 1
    cin >> x3 >> y3 >> x4 >> y4;   /// line 2


    double deltaXline1 = x1-x2;
    double deltaYline1 = y1-y2;
    double deltaXline2 = x3-x4;
    double deltaYline2 = y3-y4;

    if ( !deltaXline1 && !deltaXline2 )
        cout << "parallel!\n";
    else if ( !deltaXline1 || !deltaXline2 )
        cout <<"not parallel!\n";
    else if (deltaYline1/deltaXline1 - deltaYline2/deltaXline2 == 0.0)
        cout << "parallel!\n";
    else
        cout << "not parallel!\n";

    return 0;
}
