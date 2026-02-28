#include <bits/stdc++.h>
using namespace std;

int main()
{
    // char str[] = {'a', 'b', 'c'};
    // char str[] = {'a', 'b', 'c', '\0'};
    // char str[] = "abc";
    // str = "cde" // problem here its not modifiable
    // string str = "dhaval desai"; // dynamically-> runtime resize
    // str = "dd_dhavaldesai";      // it can be modified
    // cout << str << endl;
    // string input;
    // cout << "enter string : " << endl;
    // // cin>>input;
    // getline(cin, input);
    // cout << "string : " << input << endl;

    // // reverse word in the string ==> hey its me --> me its hey
    // //  howt to do reverse first whole string -> yeh sti em then word hey

    string s = "hello world";
    string ans = "";
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";

        while (i < s.length() && s[i] != ' ')
        {
            word += s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if (word.length() > 0)
        {
            ans += " " + word;
        }
    }
    cout << "reverse word string : " << ans.substr(1) << endl;

    return 0;
}