#include <bits/stdc++.h>
using namespace std;

struct vec{
    int dim[3];
};

int main()
{
    vec A, B;

    for ( int i=0; i<3; ++i)
        cin >> A.dim[i];

    for ( int i=0; i<3; ++i)
        cin >> B.dim[i];

    int dotProduct = 0;

    for ( int i=0; i<3; ++i)
        dotProduct += A.dim[i]*B.dim[i];


    return 0;
}
