#include <iostream>
using namespace std;
void midPointCircleDraw(int x_centre, int y_centre, int r)
{
    int x = r, y = 0;
    int P = 1 - r;
    cout << "(" << x + x_centre << ", " << y + y_centre << ") ";
    while (x != y)
    {
        y++;
        if (P <= 0)
        {
            P = P + 2 * y + 1;
        }
        else
        {
            x--;
            P = P + 2 * y - 2 * x + 1;
        }

        if (x < y)
            break;
        cout << "(" << x + x_centre << ", " << y + y_centre << ") ";
    }
}
int main()
{
    midPointCircleDraw(0, 0, 10);
}
