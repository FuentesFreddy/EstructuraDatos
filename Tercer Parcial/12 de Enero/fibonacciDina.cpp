#include <iostream>
#include <vector>
using namespace std;

long long int fibonacci(int n){
	if(n<=1){
		return n;
	}
	
	long long int dp[n+1];
	dp[0]=0;
	dp[1]=1;
	
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int main(){
	long n;
	cin>>n;
	cout<< fibonacci(n);
	for(int i=0;i<=n;i++){
		cout<<fibonacci(i)<<endl;
	}
	return 0;
}
