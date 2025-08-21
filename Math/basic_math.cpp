#include <bits/stdc++.h>
using namespace std;

// // 1 . reverse number 
void reverse_number(int n){
    int rev = 0;
    while(n!=0){
        int digit  = n % 10;
        rev = rev*10 + digit;
        n /= 10;
    }
    cout<<rev<<endl;
}

// // 2. gcd or hcf 


int main()
{
    reverse_number(321);
 return 0;
}