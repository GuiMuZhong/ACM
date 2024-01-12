#include <iostream>
#include <cstdio>
using namespace std;

double Ax, Ay, Bx, By, Cx, Cy, X, Y;

int main()
{
    cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy;
    X = (Bx*Bx*Ay - Cx*Cx*Ay - Ax*Ax*By + Cx*Cx*By - Ay*Ay*By + Ay*By*By + Ax*Ax*Cy - Bx*Bx*Cy + Ay*Ay*Cy - By*By*Cy - Ay*Cy*Cy + By*Cy*Cy) / (2*(Bx*Ay - Cx*Ay - Ax*By + Cx*By - Bx*Cy));
    Y = (-Ax*Ax*Bx + Ax*Bx*Bx + Ax*Ax*Cx - Bx*Bx*Cx - Ax*Cx*Cx + Bx*Cx*Cx - Bx*Ay*Ay + Cx*Ay*Ay + Ax*By*By - Cx*By*By - Ax*Cy*Cy + Bx*Cy*Cy) / (2*(Bx*Ay - Cx*Ay - Ax*By + Cx*By + Ax*Cy + Bx*Cy));
    printf("%.10f\n%.10f\n", X, Y);
    return 0;
}
