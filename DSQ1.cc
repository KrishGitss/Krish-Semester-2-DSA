//DS Q1.
#include <iostream>

using namespace std;

int main()
{
    int n[] = {1, 2, 4, 9, 7, 6, 5};
    int size = sizeof(n) / sizeof(n[0]);
    int count = 0;
    int max;

    for(int i = 0; i < size; i++)
    {
        if(n[i] < n[i + 1])
        {
            continue;
        }
        else if(n[i] > n[i + 1])
        {
            max = n[i];
            break;
        }
        count++;
    }

    cout << max << endl;

    return 0;
}