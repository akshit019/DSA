#include <bits/stdc++.h>
using namespace std;

//repeated scanning in infix makes it inefficient, postfix or prefix can be evaluated esily using stack
bool isoperand(char operand){
	//cout << ".";
	if(operand >= 'a' && operand <= 'z'){
		return true;
	}
	else
		return false;
}

bool isoperator(char oper){
	if(oper == '+' || oper == '-' || oper == '*' || oper == '/'){
		return true;
	}
	else
		return false;
}

bool hasgreaterprec(char op1, char op2){
	if(op1 == '/'){
		if(op2 == '/')
			return false;
		else
			return true;
	}
	else if(op1 == '*'){
		if(op2 == '/' || op2 == '*')
			return false;
		else
			return true;
	}
	else if(op1 == '+'){
		if(op2 == '*' || op2 == '/' || op2 == '+')
			return false;
		else
			return true;
	}
	else if (op1 == '-'){
		if(op2 == '*' || op2 == '/'|| op2 == '+' || op2 == '-')
			return false;
		else
			return true;
	}
}

void infixtopostfix(){

	string str = "a+b+c";
	stack<char> s;

	for (int i = 0; i < str.length(); i++)
	{
		//cout << ".";
		if(isoperand(str.at(i))){
			cout << str.at(i);
			//cout << ".";
		}

		if(isoperator(str.at(i))){
			
			if(s.empty()){
				//cout << str.at(i) << ".";
				s.push(str.at(i));
			}
			if(!s.empty()){
				char t = s.top();
				//cout << t << ".";
				if(hasgreaterprec(str.at(i),s.top())){
					s.push(str.at(i));
					//cout << str.at(i) << ".";
				}
				else{

					while(!hasgreaterprec(str.at(i),t)){
						t = s.top();
						cout << t;
						s.pop();
					}	
					s.push(str.at(i));
				}
			}
			
		}

		if(str.at(i) == '('){
			s.push(str.at(i));
		}

		if(str.at(i) == ')'){
			while(s.top() != '('){
				char temp = s.top();
				cout << temp;
				s.pop();
			}
			s.pop();
		}
	}

	while(s.empty()){
		char temp1 = s.top();
		cout << temp1;
		s.pop();
	}

}

int main()
{

	infixtopostfix();
	return 0;
}