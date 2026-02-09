#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> str = {"cba", "daf", "ghi"};
    int n = 3;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        char first = str[0][i];
        for (int j = 0; j < 3; j++)
        {
            if (str[j][i] < strs)
            {
                count++;
                break;
            }
        }
    }
    cout << "count : " << count << endl;
    return 0;
}