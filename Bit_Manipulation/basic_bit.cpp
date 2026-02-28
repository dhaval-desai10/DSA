#include <bits/stdc++.h>
using namespace std;

// // 1. decimal to binary
string convert_decimal2_binary(int n)
{
    string binary = "";
    while (n > 0)
    {
        // if(n % 2 == 1){
        //     binary += '1';
        // }
        // else {
        //     binary += '0';
        // }
        binary += (n % 2) ? '1' : '0';
        n = n / 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

// // 2. binary to decimal
void binary2_decimal(string s)
{
    int decimal = 0;
    int base = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            decimal += base;
        }
        base *= 2;
    }
    cout << "Decimal : " << decimal << endl;
}

// // 3. swaping of two number using bit-manuplation
void swap_number(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "a : " << a << ", b : " << b << endl;
}

// //  4. set the ith bit
void set_ith_bit(int n, int i)
{
    int result = n | (1 << i);
    cout << "Number after setting bit " << i << ": " << result << endl;
}

// // 5. toggle the ith bit
void toggle_ith_bit(int n, int i)
{
    int result = n ^ (1 << i);
    cout << "Number after toggling bit " << i << ": " << result << endl;
}

// // 6. remove the last set bit (rightmost)
void rightmost_bit(int n)
{
    int result = n & (n - 1);
    cout << "removing the last set bit (rightmost bit) : " << result << endl;
}

// // 7. count the number of set bit // mean number of 1 in bs
void no_of_set_bit(int n)
{
    int count = 1;
    while (n != 1)
    {
        // if (n % 2 == 1)
        if (n & 1)
            count++;
        n = n / 2;
    }
    cout << "count : " << count << endl;
}

// // 8. xor of numbers in given range // finding the xor of all the numbers
int xor_of_numbers(int n)
{

    // for(int i = 0;i<n;i++){
    //     xorr ^=  i;
    // }
    // ans is ---->> xorr;
    // return xorr
    // // there is pattern ,in divsion of 4 goroups
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    if (n % 4 == 3)
        return 0;
    if (n % 4 == 0)
        return 0;
}


int main()
{
    // // 1.
    // int n = 10;
    // string binary = convert_decimal2_binary(n);
    // cout << binary << endl;

    // // 2.
    // string binary = "1111";
    // binary2_decimal(binary);

    // // 3.
    // swap_number(3,2);

    // // 4.
    // set_ith_bit(5, 1); // Example: set 1st bit of 5 (0101), result should be 7 (0111)

    // // 5.
    // toggle_ith_bit(5, 1); // Example: toggle 1st bit of 5 (0101), result should be 7 (0111)

    // // 6.
    // rightmost_bit(18);    // 1010 -> removing 1 which is last second --> 1000

    // // 7.
    // no_of_set_bit(27); // 1111

    // // 8.
    // cout << xor_of_numbers(10) << endl;
    return 0;
}