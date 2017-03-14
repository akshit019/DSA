#include<bits/stdc++.h>
using namespace std;

class twostackarray
{
public:
	int top1;
	int top2;
	int maxsize;
	int s[];

	void declare(){
		maxsize = 10;
		top1 = -1;
		top2 = maxsize;
		s[maxsize];
	}

	void push1(int e){
		if(top1<top2-1){
			top1++;
			//cout << ".";
			s[top1] = e;
		}
		else
			cout << "overflow" << endl;
	}
	
	void push2(int e){
		if(top1<top2-1){
			top2--;
			s[top2] = e;
		}
		else
			cout << "overflow" << endl;
	}

	int pop1(){
		if(top1>=0){
			top1--;
			return s[top1+1];
		}
		else
			cout << "underflow" << endl;
	}

	int pop2(){
		if(top2<maxsize){
			top2++;
			return s[top2-1];
		}
		else
			cout << "underflow" << endl;
	}

	int s1size(){
		cout << top1 << " ";
		return top1+1;
	}

	int s2size(){
		cout << top2 << " ";
		return maxsize-top2;
	}

	void prints1(){
		for(int i=top1; i>=0; i--){
			cout << s[i] << " ";
		}
		cout << endl;
	}

	void prints2(){
		for(int i=top2; i<maxsize; i++){
			cout << s[i] << " ";
		}
		cout << endl;
	}

};

int main(int argc, char const *argv[])
{
	twostackarray ss;
	ss.declare();
	ss.push1(1);
	//cout << ".";
	ss.push1(2);
	ss.push1(3);
	ss.push1(4);
	ss.push1(5);

	int size1 = ss.s1size();
	cout << size1 << endl;
	//ss.prints1();

	ss.push2(10);
	ss.push2(9);
	ss.push2(8);
	ss.push2(7);
	ss.push2(6);

	//ss.pop1();
	//size1 = ss.s1size();
	//cout << size1 << endl;
	ss.push1(5);
	ss.push2(5);

	int size2 = ss.s2size();
	cout << size2 << endl;
	//ss.prints2();

	

	return 0;
}