#include <iostream>
#include <vector>
using namespace std;

long fibonacci(int n){
	if(n<=1){
		return n;
	}else{
		return fibonacci(n-1)+fibonacci(n-2);
	}
}

int main(){
	long n;
	cin>>n;
	cout<< fibonacci(n);
	return 0;
}
