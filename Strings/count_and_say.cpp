// Practice link - https://www.codingninjas.com/codestudio/problems/1090543
// Count and Say

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
string countAndSay(int n);

// Main Function
int main()
{

    int n;
    cin >> n;

    string s = countAndSay(n);
    cout << s << endl;

    return 0;
}

// Compare and count -> Time Complexity - O(N*M), Space Complexity - O(1)
string countAndSay(int n)
{

    if (n == 1)
        return "1";
    if (n == 2)
        return "11";

    string str = "11";

    for (int i = 3; i <= n; i++)
    {

        string temp = "";
        str = str + '$';
        int count = 1;

        for (int j = 1; j < str.length(); j++)
        {

            if (str[j] == str[j - 1])
            {
                count++;
            }
            else
            {
                temp += to_string(count) + str[j - 1];
                count = 1;
            }
        }

        str = temp;
    }

    return str;
}