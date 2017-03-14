#include<iostream>
using namespace std;

class stack_array
{
	
private:

	int maxsize;
	int top;
	int s[];
	
public:

	void declare(){
		top = -1;
		maxsize = 10;
		s[maxsize];
	}

	void push(int e){
		if (top > 9)
		{
			cout << "Overflow";
			return;
		}
		top++;
		s[top] = e;
	}

	int pop(){
		if(top >= 0){
			top--;
			return s[top+1];
		}
	}

	int size(){
		return top+1;
	}

	void printstack(){
		for(int i=top; i>=0; i--){
			cout << s[i] << " ";
		}
		cout << endl;
	}

};


int main()
{
	stack_array s1;
	
	s1.declare();
	//cout << "declared";
	s1.push(1);
	//cout << "p1";
	s1.push(2);
	//cout << "p2";
	s1.push(3);
	//cout << "p3";
	int size = s1.size();
	cout << "Current size " << size << endl;
	s1.pop();
	//s1.pop();
	//s1.pop();
	//cout << "pop";
	size = s1.size();
	cout << "Current size " << size << endl;
	s1.printstack();

	return 0;
}