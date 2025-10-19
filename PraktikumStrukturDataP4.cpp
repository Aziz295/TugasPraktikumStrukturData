#include<bits/stdc++.h>
using namespace std; 
#define MAX 1000
class Stack{
	int top;
public:
	int a[MAX];
	Stack(){top=1;}
	bool push(int x);
	int pop();
	int peek();
	bool isEmpety();	
};
bool Stack::push(int x)
{
	if(top>=(MAX-1)){
		cout<<"Stack Overflow";
		return false;
	}
	else{
		a[++top]=x;
		cout<<x<<"didorong kedalam tumpukan\n";
		return true;
	}
}
int Stack::pop()
{
	if(top<0){
		cout<<"stack Underflow";
		return 0;
	}
	else{
		int x =a[top--];
		return x;
	}
}
int Stack::peek()
{
	if (top<0){
		cout<<"Tumpukan Kosong";
		return 0;
	}
else {
	int x = a[top];
	return x;
}
}

bool Stack::isEmpety()
{
	return (top<0);
}

int main()
{
	class Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout<<s.pop()<<"Dikeluarkan dari tumpukan";
	
	return 0;
}
