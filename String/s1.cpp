// #include<iostream>
// using namespace std;
// string longestpelistring(string str,int size)
// {
//         int start=0;
//         int maxlength=1;
//         int low,high;
//         for(int i=1;i<size;i++)
//         {
//             low=i-1;
//             high=i;
//             while(low>=0 && high<size && str[low]==str[high])
//             {
//                 if(high-low+1>maxlength)
//                 {
//                     start=low;
//                     maxlength=high-low+1;
//                 }
//                 low--;
//                 high++;
//             }
//             low=i-1;
//             high=i+1;
//             while(low>=0 && high<size && str[low]==str[high])
//             {
//                 if(high-low+1>maxlength)
//                 {
//                     start=low;
//                     maxlength=high-low+1;
//                 }
//                 low--;
//                 high++;
//             }
//         }
//         return str.substr(start,maxlength);

// }
// int main()
// {
//     string str;
//     cin>>str;
//     cout<<longestpelistring(str,str.size());

//  return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// char convertToLower(char ch);

// // string reverse(char name[], int n)
// bool check(char name[], int n)
// {
//     int start = 0;
//     int end = n - 1;
//     while (start < end)
//     {
//         if (convertToLower(name[start]) != convertToLower(name[end]))
//         {
//             return false;
//         }
//         else {
//             start++;
//             end--;
//         }
//     }
//     return true;
// }

// char convertToLower(char ch)
// {
//     if(ch >= 'a' && ch <= 'z')
//     {
//         return ch;
//     }
//     else {
//         return ch - 'A' + 'a';
//     }
// }

// int main()
// {
//     char name[20];
//     cin >> name;
//     if (check(name, strlen(name)))
//     {
//         cout << "its pali"<<endl;
//     }
//     else
//         cout << "no"<<endl;

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;


// string addstr(string s)
// {
//     int n = s.length();
//     string result = "";
//     for(int i = 0;i<n;i++)
//     {
//         if(s[i] != ' ')
//         {
//             result += s[i];
//         }
//         else if(s[i] == ' ')
//         {
//             result += '@';
//             result += '4';
//             result += '0';
//         }
//     }
//     return result;
// }

// int main()
// {
//     string s;
//     cout << "enter string: ";
//     getline(cin, s);
    
//     cout<<addstr(s)<<endl;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    cout<<s<<endl;
    int ans = stoi(s); 
    cout<<ans<<endl;
 return 0;
}