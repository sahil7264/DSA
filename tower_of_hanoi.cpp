#include <iostream>
#include <cmath>
using namespace std;

int noOfMoves=0;
void TOH(int n, char src, char mid, char end)
{
    if (n <= 0)
    {
        cout << "No disc" << endl;
    }

    else if (n == 1)
    {
        cout << "Move Disk " << n << " from " << src << " to " << end << endl;
        noOfMoves++;
        // then return
        return;
    }
    else
    {
        TOH(n - 1, src, end, mid);
        cout << "Move Disk " << n << " from " << src << " to " << end << endl;
        noOfMoves++;
        TOH(n - 1, mid, src, end);
    }
}

int main()
{
    int n;
    int steps;

    cout << "Enter no. of disks:";
    cin >> n;

    TOH(n, 'A', 'B', 'C');
    steps = pow(2, n) - 1;
    cout << "No. of steps:" << steps << endl;
    return 0;
}