/*
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
6 6 6 6 6 6
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i=1;
    int x=1;
    while(i<=n)
    {
        int j=1;
        while(j<=i)
        {
            cout << x << " ";
            j++;
        }
        i++;
        x++;
        cout << endl;
    }
    return 0;
}
