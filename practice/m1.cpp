#include<iostream>
using namespace std;
// int fact(int n){
//     if(n<=1)
//     {
//         return 1;

//     }
//    return n*fact(n-1);
// }
// int fibo(int n)
// {
//     if(n==1 || n==2)
//     {
//         return 1;
//     }
//     return fibo(n-1)+fibo(n-2);
  
// }


int fibo_iterative(int n) {
    if (n == 1 || n == 0) {
        return 1;   
    }
    int a = 1, b = 1, c;

    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main()
{

    int n;
    cout<<"enter number"<<endl;
    cin>>n;
//   for (int i = 1; i <= n; i++) {
//         cout << fibo(i) << " ";
//     }
    // cout << endl;
      cout << "Fibonacci sequence up to " << n << " terms:" << endl;
      cout<<"0"<<" ";
    for (int i = 1; i < n; i++) {
        cout << fibo_iterative(i) << " ";
    }
    cout << endl;




    // int fact = 1;
    // for(int i=1;i<=n;i++)
    // {
    //     fact = fact * i;
    // }

    // cout<<fact<<endl;
 return 0;
}