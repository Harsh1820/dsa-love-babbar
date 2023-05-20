#include <iostream>

using namespace std;
int josephus(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    int x = josephus(n - 1, k);
    int y = (x + k) % n;

    return y;
}

int main()
{
    int n;
    cout << "Enter the value of n" << endl;

    cin >> n;

    int k;
    cout << "Enter the value of k" << endl;

    cin >> k;

    cout << "The last person alive is :" << josephus(n, k) << endl;

    return 0;
}