#include <iostream>
#include <stack>
//#include <vector>
//#include <algorithm>

using namespace std;

int operator_precedence(int op)
{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    if(op == '^')
        return 3;
    return -1;
}

string convert_expression(string infix)
{
    string post;
    stack<int> s;
    
    // iterate through expression from left to right
    for(auto c : infix)
    {
        
        // if character is operand
        if(isalpha(c))
            post.push_back(c);
        // if it is operator or brcket
        else
        {
            // if it is bracket
            if(c == '(')
                s.push(c);
            else if(c == ')')
            {
                // pop from stack until empty or ( is popped
                while(!s.empty() && s.top() != '(')
                    // insert into postfix
                    post.push_back(s.top()), s.pop();
                s.pop();
            }
            // if it is operator 
            else
            {
                // repeat until precedence condition
                while(!s.empty() && operator_precedence(c) <= operator_precedence(s.top()))
                    post.push_back(s.top()), s.pop();
                s.push(c);
            }
            
        }
    }
    
    // pop all operator from stack
        while(!s.empty())
            post.push_back(s.top()), s.pop();
    
    return post;
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while( t-- )
    {
        int n;
        cin >> n;
        
        string infix;
        cin >> infix;
        
        cout << convert_expression(infix) << "\n";
    }
    
	return 0;
}

