#include <bits/stdc++.h>
using namespace std;

// // digit concept
void count_digit(int n)
{
    // using log
    // int count = (int) (log10 (n) + 1);
    vector<int> digits;
    while (n != 0)
    {
        int digit = n % 10;
        digits.push_back(digit);
        n = n / 10;
    }
    cout << "digits " << digits.size() << endl;
    for (int i = 0; i < digits.size(); i++)
    {
        cout << digits[i] << " ";
    }
    cout << endl;
}

// // 1 . reverse number
void reverse_number(int n)
{
    int rev = 0;
    while (n != 0)
    {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }
    cout << rev << endl;
}

// // divisors

void divisors(int n)
{
    // for(int i = 1;i<=n;i++){
    //     if(n %  i == 0){
    //        cout<< i << " ";
    //     }
    // }
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (n / i != i)
            {
                cout << n / i << " ";
            }
        }
    }
    cout << endl;
}

bool prime_number(int n)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if ((n / i) != i)
            {
                count++;
            }
        }
    }
    if (count == 2)
        return true;
    else
        return false;
}

// // 2. gcd or hcf **** Ecludean Algorithm****

void gcd(int a, int b)
{

    int gcd = 1;

    // for(int i = 1;i<= min(a,b);i++){
    //     if(a % i == 0 && b % i == 0){
    //         gcd = max(gcd,i);
    //     }
    // }

    // // making more better of  above version ,in worst case both are same

    for (int i = min(a, b); i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
            break;
        }
    }

    // // Ecludean Algo TC :-> log(base phi or Φ) (min(a,b))

    cout << "Ecludean algo check : ";
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        cout << b << endl;
    else
        cout << a << endl;

    cout << "GCD : " << gcd << endl;
}

// // lcm of two number

// int lcm (int a, int b)
// {
    
//     return (a * b) / gcd;
// }


int main()
{
    // count_digit(234324);

    // divisors(36);

    // cout<<"prime : " << prime_number(12)<<endl;

    // // 1.
    // reverse_number(321);

    // // 2.
    gcd(10, 52);

    return 0;
}