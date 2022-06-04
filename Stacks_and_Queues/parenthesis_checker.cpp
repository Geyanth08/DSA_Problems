// Leetcode link - https://leetcode.com/problems/valid-parentheses/submissions/
// Parenthesis Checker

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
bool ispar(string x);

// Main Function
int main()
{
    string s;
    cin >> s;

    if (ispar(s))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
    return 0;
}

// Comparing closing brackets with top of Stack -> Time Complexity - O(size of String), Space Complexity - O(size of String)
bool ispar(string x)
{

    stack<char> s;

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '{' or x[i] == '[' or x[i] == '(')
        {
            s.push(x[i]);
        }
        else if (x[i] == '}')
        {
            if (!s.empty() and s.top() == '{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        else if (x[i] == ']')
        {
            if (!s.empty() and s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        else if (x[i] == ')')
        {
            if (!s.empty() and s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (!s.empty())
    {
        return false;
    }
    return true;
}
