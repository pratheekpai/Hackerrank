#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    if(s.size() % 2 == 1)
        return "NO";
     stack<char> char_stack;
     for(int i=0; i<s.size(); ++i){
        if(int(s[i]) == 40 || int(s[i]) == 91 || int(s[i]) == 123)
            char_stack.push(s[i]);
        else if(char_stack.empty())     // if the string has closing brackets at the
            return "NO";                // beginning or after a pair
        else if(int(s[i]) == 41){
            if(int(char_stack.top()) != 40)
                return "NO";
            else{
                char_stack.pop();
                continue;
            }
        }
        else if(int(s[i]) == 93){
            if(int(char_stack.top()) != 91)
                return "NO";
            else{
                char_stack.pop();
                continue;
            }
        }
        else if(int(s[i]) == 125){
            if(int(char_stack.top()) != 123)
                return "NO";
            else{
                char_stack.pop();
                continue;
            }
        }
     }
     if(char_stack.empty()) // if the string has opening brackets at the end 
        return "YES";
     else
        return "NO";
     
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
