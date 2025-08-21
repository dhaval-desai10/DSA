#include <bits/stdc++.h>
using namespace std;
// void pattern1(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             cout << " ";
//         }
//         for (int k = 0; k < 2 * i + 1; k++)
//         {
//             cout << "*";
//         }
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             cout << " ";
//         }
//         cout << endl;
//     }
// }

// void pattern2(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             cout << " ";
//         }
//         for (int k = 0; k < 2 * n - 2 * i - 1; k++)
//         {
//             cout << "*";
//         }
//         for (int l = 0; l < i; l++)
//         {
//             cout << " ";
//         }
//         cout << endl;
//     }
// }

// void pattern3(int n)
// {
//     for (int i = 1; i <= (2 * n) - 1; i++)
//     {
//         int stars = i;
//         if (i > n) stars = (2*n)-i;
//             for (int j = 1; j <= stars; j++)
//             {
//                 cout << "* ";
//             }
//         cout << endl;
//     }
// }

// void pattern4(int n)
// {
//     int start = 1;
//     for(int i = 0;i<n;i++)
//     {
//         if(i%2 == 0) start = 1;
//         else start = 0;
//         for(int j = 0;j<=i;j++)
//         {
//             cout<<start<<" ";
//             start = 1-start;
//         }
//         cout<<endl;
//     }
// }

// void pattern5(int n)
// {
//     int space = 2 * (n - 1);
//     for (int i = 1; i <= n; i++)
//     {
//         // number
//         for (int j = 1; j <= i; j++)
//         {
//             cout << j;
//         }
//         // space
//         for (int j = 1; j <= space; j++)
//         {
//             cout << " ";
//         }
//         for (int j = i; j >= 1; j--)
//         {
//             cout << j;
//         }
//         cout << endl;
//         space -= 2;
//     }
// }

// void pattern6(int n)
// {
//     int count = 1;
//     for(int i = 0;i<n;i++)
//     {
//         for(int j = 0;j<=i;j++)
//         {
//             cout<<count++<<" ";
//         }
//         cout<<endl;
//     }
// }

// void pattern7(int n)
// {
//     char ch = 'A';
//     for(int i = 0;i<n;i++)
//     {
//         for(int j= 0;j<=i;j++)
//         {
//             cout<< char(ch + j) << " ";
//         }
//         cout<<endl;
//     }
// }

// void pattern8(int n)
// {
//     char ch = 'A';
//     for(int i = 0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             cout<<char(ch + j - i);
//         }
//         cout<<endl;
//     }
// }

// void pattern9(int n)
// {
//     char ch = 'A';
//     for(int i = 0;i<n;i++)
//     {
//         for(int j=0;j<=i;j++)
//         {
//             cout<<char(ch + i);
//         }
//         cout<<endl;
//     }
// }

// void pattern10(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = i; j <= n; j++)
//         {
//             cout << " ";
//         }
//         char ch = 'A';
//         int breakpoint = (2 * i - 1) / 2;
//         for (int k = 1; k <= 2 * i - 1; k++)
//         {
//             cout << ch;
//             if (k <= breakpoint)
//                 ch++;
//             else
//                 ch--;
//         }
//         for (int j = i; j <= n; j++)
//         {
//             cout << " ";
//         }
//         cout << endl;
//     }
// }

// void pattern11(int n)
// {
//     char ch = 'A' + n;
//     for(int i = 1;i<=n;i++)
//     {
//         // for(int j=0;j<i;j++)
//         // {
//         //     cout<<char(ch + j - i);
//         // }
//         for(char j=ch - i;j<ch;j++)
//         {
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }

// void pattern12(int n)
// {
//     for(int i = 0;i<n;i++)
//     {
//         for(int j = i;j<n;j++)
//         {
//             cout<<"*";
//         }
//         for(int j = 0;j<2*i;j++)
//         {
//             cout<<" ";
//         }
//         for(int j = i;j<n;j++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     for(int i = 0;i<n;i++)
//     {
//         for(int j = 0;j<=i;j++)
//         {
//             cout<<"*";
//         }
//         for(int j = 0;j<2*(n-1 -i);j++)
//         {
//             cout<<" ";
//         }
//         for(int j = 0;j<=i;j++)
//         {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }
// void pattern13(int n)
// {
//     int spaces = 2 * (n - 1);
//     for (int i = 1; i <= 2 * n - 1; i++)  // Fixed: should go to 2*n-1
//     {
//         int stars = i;
//         if (i > n)
//             stars = 2 * n - i;
//         // Left stars
//         for (int j = 1; j <= stars; j++)
//         {
//             cout << "*";
//         }
//         // Middle spaces
//         for (int j = 1; j <= spaces; j++)
//         {
//             cout << " ";
//         }
//         // Right stars
//         for (int j = 1; j <= stars; j++)
//         {
//             cout << "*";
//         }
//         cout << endl;
//         if (i < n)
//             spaces -= 2;  // Fixed: spaces decrease in first half
//         else
//             spaces += 2;  // Fixed: spaces increase in second half
//     }
// }

// void pattern14(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i == 0 || i== n-1 || j==0 || j== n-1)
//                 cout << "*";
//             else
//                 cout << " ";
//         }
//         cout << endl;
//     }
// }

// void pattern15(int n)
// {
//     for(int i = 0;i<2*n -1;i++)
//     {
//         for(int j=0;j<2*n -1;j++)
//         {
//             int top = i;
//             int left = j;
//             int right = (2*n - 2) - j;
//             int down = (2*n - 2) - i;
//             cout<<(n- min(min(top,down),min(left,right)));
//         }
//         cout<<endl;
//     }
// }

void pattern16(int n)
{
    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        int len = n - i;

        // print left side characters
        for (int j = 0; j < len; j++)
        {
            cout << char(ch + j);
        }

        // print middle spaces
        for (int j = 0; j < 2 * i - 1; j++)
        {
            cout << " ";
        }

        // print right side characters (reverse, skip last from left)
        for (int j = len - 1 - (i == 0 ? 1 : 0); j >= 0; j--)
        {
            cout << char(ch + j);
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cout << "number : ";
    cin >> n;
    cout << endl;
    // pattern1(n);
    // pattern2(n);
    // pattern3(n);
    // pattern4(n);
    // pattern5(n);
    // pattern6(n);
    // pattern7(n);
    // pattern7(n);
    // pattern8(n);
    // pattern9(n);
    // pattern10(n);
    // pattern11(n);
    // pattern12(n);
    // pattern13(n);
    // pattern14(n);
    // pattern15(n);
    pattern16(n);

    return 0;
}