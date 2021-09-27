#include <bits/stdc++.h>
using namespace std;
int main()
{

    int x;
    int y;
    cin >> x >> y;
    x /= 3;
    y /= 3;
    for (int i = 3 * x; i < 3 * x + 3; i++)
    {
        for (int j = 3 * y; j < 3 * y + 3; j++)
            cout << i << "," << j << " ";
        cout << endl;
    }
}