//DS Q2.
#include <iostream>

using namespace std;

int main()
{
    int n, A[n], inversion = 0;

    cout << "Enter the number of distinct integers: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i < j)
            {
                if(A[i] > A[j])
                {
                    inversion++;
                }
            }
        }
    }

    cout << inversion << endl;

    return 0;
}