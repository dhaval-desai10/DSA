#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;
char stack[MAX];
int top = -1;
bool isempty()
{
    return top == -1;
}
bool isfull()
{
    return top == MAX - 1;
}
void push(char c)
{
    if (isfull())
    {
        cout << "Stack overflow\n";
        return;
    }
    stack[top++] = c;
}
char pop()
{
    if (isempty())
    {
        cout << "Stack underflow\n";
        return '\0';
    }
    return stack[top--];
}
char peek()
{
    if (isempty())
    {
        return '\0';
    }
    return stack[top];
}
bool isoperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}
string infixToPostfix(string infix)
{
    string postfix = "";

    for (char &ch : infix)
    {
        if (isalpha(ch) || isdigit(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (!isempty() && peek() != '(')
            {
                postfix += pop();
            }
            pop();
        }
        else
        {
            while (!isempty() && precedence(ch) <= precedence(peek()))
            {
                postfix += pop();
            }
            push(ch);
        }
    }

    while (!isempty())
    {
        postfix += pop();
    }
    return postfix;
}
int main()
{
    string infix;
    cout << "Enter  expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
