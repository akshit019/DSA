#include<bits/stdc++.h>
using namespace std;

void spop(queue<int> &q1){
	int s = q1.size();
	for(int i=1; i<=s-1; i++){
		int temp1 = q1.front();
		q1.pop();
		//cout << temp1 << " " << endl;
		q1.push(temp1);
	}
	q1.pop();
	cout << "Stack pop done..." << endl;
	cout << "stack size after pop " << q1.size() << endl;
}

int main(int argc, char const *argv[])
{
	queue<int> q;

	for(int i=1; i<=5; i++){
		q.push(i);
	}

	cout << "Current size " << q.size() << endl;

	while(q.size() > 0){
		int temp = q.front();
		cout << temp << " ";
		q.pop();
	}

	cout << endl;
	cout << "Current size " << q.size() << endl;

	for(int i=1; i<=5; i++){
		q.push(i);
	}

	cout << "Current size " << q.size() << endl;

	spop(q);

	//cout << q.size();
	while(q.size() > 0){
		int temp = q.front();
		cout << temp << " ";
		q.pop();
	}
	

	return 0;
}