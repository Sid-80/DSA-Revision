//stack is inbuild in c++ and called by adding header file-> #include<stack>
#include<bits/stdc++.h>
using namespace std;

void reverseSentence(string s){
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i]!=' ' && i<s.length())
        {
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    string s = "Hey, how are you doing?";
    cout<<s<<endl;
    reverseSentence(s);
    return 0;
}
