#include <bits/stdc++.h>
using namespace std;

struct vec
{
    int dim[3];
};

int main()
{
    vec A, B;

    for ( int i=0; i<3; ++i)
        cin >> A.dim[i];

    for ( int i=0; i<3; ++i)
        cin >> B.dim[i];

    vector < int > crossProduct(3);

    crossProduct[0] = A.dim[1] * B.dim[2] - A.dim[2] * B.dim[1];
    crossProduct[1] = A.dim[2] * B.dim[0] - A.dim[0] * B.dim[2];
    crossProduct[2] = A.dim[0] * B.dim[1] - A.dim[1] * B.dim[0];


    return 0;
}
