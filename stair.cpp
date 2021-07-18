#include<iostream>
#include<climits>

using namespace std;


int minStep(int n,int dp[]){
	if(n==1){
		dp[n]=0;
		return 0;
	}
	if(dp[n-1]==-1){
		dp[n-1] = minStep(n-1,dp);
	}
	int x=INT_MAX,y=INT_MAX;
	if(n%2==0){
		if(dp[n/2]==-1){
			dp[n/2]=minStep(n/2,dp);
		}
		x=dp[n/2];
	}
	if(n%3==0){
		if(dp[n/3]==-1){
			dp[n/3]=minStep(n/3,dp);
		}
		y=dp[n/3];
	}

	dp[n] = 1 +  min(dp[n-1],min(x,y));
	return dp[n];

}

int minStep(int n){
	
	int dp[n+1];
	for(int i=0;i<n+1;i++){
		dp[i]=-1;
	}
	return minStep(n,dp);
	
}

int main(){

	int n;
	cin>>n;
	cout<<minStep(n);
	return 0;

}
