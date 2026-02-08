#include <bits/stdc++.h>
using namespace std;
  
bool isOperand(char x)
{
   return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9');
}

//	input = "ab*c+";
//	output = "((a*b)+c)";
string getInfix(string exp)
{
    stack<string> s;  
    for (int i=0; exp[i]!='\0'; i++)
    {        
        if (isOperand(exp[i]))
        {
           string op(1, exp[i]);//string with lenth 1, pusing as a single character;
           s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] + op1 + ")");
        }
    }
    return s.top();
}

//	input = "((a*b)+c)";
//	output = "ab*c+";
string getPostfix(string exp)
{
    stack<char> st;
	char t[80],j=0,r=0;  
    for (int i=0; exp[i]; i++)
    {        
        if (isOperand(exp[i])){
			t[j++] = exp[i];		
		}
		else{
			if(exp[i]!=')'){
				st.push(exp[i]);
			}
			else{
				r = st.top();st.pop();
				t[j++] = r;
				r = st.top();st.pop();
			}
		}
    }
    while(!st.empty()){
		r=st.top();st.pop();
		if(r!='('){
			t[j++]=r;
		}
	}
	t[j]='\0';
    return t;
} 

int evaluatePostfix(string S)
{
    stack<int> st;
    int r=0;
    for(int i=0; S[i]; i++){
        if(S[i]>='0' && S[i]<='9'){
            st.push(S[i]%48);
        }
        else{
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();
            switch(S[i]){
                case '+' : r = v1 + v2; break;
                case '-' : r = v1 - v2; break;
                case '*' : r = v1 * v2; break;
                case '/' : r = v1 / v2; break;
            }
            st.push(r);
        }
    }
    r = st.top();
    return r;
}
	 
int main()
{
    string exp = "ab*c+";
    exp = getInfix(exp);
    cout << "infix : " << exp << endl;   
        
//	exp = "((a*b)+c)"; input
    cout << "Postfix : " << getPostfix(exp) << endl;
//	exp = "ab*c+"; output

//	exp = "231*+9-"; input
    exp = "231*+9-";
    cout << "evaluatePostfix : " << evaluatePostfix(exp);
//	exp = "-4"; output
	
    return 0;
}
