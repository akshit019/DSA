#include<bits/stdc++.h>
using namespace std;

class queue_array
{
	
private:

	int maxsize;
	int f;
	int r;
	int q[];
	
public:

	void declare(){
		f = 0;
		r = -1;
		maxsize = 10;
		q[maxsize];
	}

	void enqueue(int e){
		if (r > 9)
		{
			cout << "Overflow";
			return;
		}
		r++;
		q[r] = e;
		cout << "inserted" << endl;
	}

	int dequeue(){
		if(f==r){
			cout << "underflow" << endl;
			f=0;
			r=-1;
			return 0;
		}
		else if(r==-1){
			return 0;
		}

		f++;
		return q[f];	
	}

	int size(){
		//cout << f;
		//cout << r;
		return r-f+1;

	}

	void printqueue(){
		for(int i=f; i<=r; i++){
			cout << q[i] << " ";
		}
		cout << endl;
	}

};


int main()
{
	queue_array q1;
	
	
	q1.declare();
	q1.dequeue();
	//cout << "declared";
	q1.enqueue(1);
	//cout << "p1";
	q1.enqueue(2);
	//cout << "p2";
	q1.enqueue(3);
	//cout << "p3";
	int size = q1.size();
	cout << "Current size " << size << endl;
	q1.dequeue();
	//q1.dequeue();
	//q1.dequeue();
	//s1.pop();
	//s1.pop();
	//cout << "pop";
	size = q1.size();
	cout << "Current size " << size << endl;
	q1.printqueue();

	return 0;
}