#include<iostream>
#include<vector>
using namespace std;

// // painting the fence 
// // solving using recurssion
// int solverec(int n, int k){
//     if(n==1)    return k;
//     if(n==2)    return (k+k*(k-1));

//     int ans=(solverec(n-1,k)+solverec(n-2,k))*(k-1);
//     return ans;
// }

// int solvetop(int n,int k, vector<int>&dp){
//     if(n==1)    return k;
//     if(n==2)    return (k+k*(k-1));

//     if(dp[n]!=-1){
//         return dp[n];
//     }

//     dp[n]=(solvetop(n-1,k,dp)+solvetop(n-2,k,dp))*(k-1);
//     return dp[n];

// }

// int solvebottom(int n, int k){
    
//     vector<int>dp(n+1,-1);
//     dp[0]=0;  // invalid case with 0 poles to paint 
//     dp[1]=k;
//     dp[2]=k + k*(k-1);

//     for(int i=3;i<=n;i++){
//         dp[i]=(dp[i-1]+dp[i-2])*(k-1);
//     }

//     return dp[n];
// }

// int solveso(int n,int k){
//     // vector<int>dp(4,-1);
//     if(n==1)    return k;
//     if(n==2)    return (k+k*(k-1));
//     int pre=k;
//     int cur=k + k*(k-1);
//     int next;

//     for(int i=3;i<=n;i++){
//         // dp[i]=(dp[i-1]+dp[i-2])*(k-1);
//         next=(pre+cur)*(k-1);
//         pre=cur;
//         cur=next;

//     }
//     return next;
// }

// int main(){
//     int n=3;
//     int k=2;

//     vector<int>dp(n+1,-1);

//     // int ans=solverec(n,k);
//     // int ans=solvetop(n,k,dp);
//     // int ans=solvebottom(n,k);
//     int ans=solveso(n,k);
//     cout<<"the ans is : "<<ans;

//     return 0;
// }


// 0/1 knapsack
int solve(int capacity,int wt[],int profit[],int i,int n){

    // base 
    if(i>=n){
        return 0;
    }

    // include & exclude
    int include=0;
    if(wt[i]<=capacity){
        include=profit[i]+solve(capacity-wt[i],wt,profit,i+1,n);
    }
    int exclude=0+solve(capacity,wt,profit,i+1,n);

    return max(include,exclude);

}

int solvetop(int capacity,int wt[],int profit[],int index,int n,vector<vector<int> >&dp){
    //base case
	if(index >=n) {
		return 0;
	}

	//already exists
	if(dp[capacity][index] != -1){
		return dp[capacity][index];
	}

	//inc / exc
	int include = 0;
	if(wt[index] <= capacity) {
		include = profit[index] + solvetop(capacity-wt[index], wt, profit, index+1, n, dp);
	}
	int exclude = 0 + solvetop(capacity, wt, profit, index+1, n, dp);
	dp[capacity][index] = max(include, exclude);
	return dp[capacity][index];
}

int solvebottom(int capacity, int wt[], int profit[], int n){
    // creating a 2d vector to store values 
    vector<vector<int> >dp(capacity+1,vector<int>(n+1,-1));
    // here the row represents the capacity of bag at that iteration of i 
    // and j is the item 

    // filling the last column the out of bound one with 0
    for(int i=0;i<=capacity;i++){
        dp[i][n]=0;
    }

    for(int i=0;i<=capacity;i++){
        for(int j=n-1;j>=0;j--){
            int include=0;
            if(wt[j]<=i){
                include=profit[j]+dp[i-wt[j]][j+1];
            }
            int exclude=0+dp[i][j+1];
            dp[i][j]=max(include,exclude);
        }
        
    }
    return dp[capacity][0];

}

int solveso(int capacity, int wt[], int profit[], int n){
    vector<int> next(capacity+1, 0);
	vector<int> curr(capacity+1, -1);


	for(int j=n-1; j>=0; j--) {
		for(int i=0; i<=capacity; i++) {
			int include = 0;
			if(wt[j] <= i) {
				include = profit[j] + next[i-wt[j]];
			}
			int exclude = 0 + next[i];
			curr[i] = max(include, exclude);
		}
		//shifting
		next = curr;
	}
	return curr[capacity];
}


int main(){
    int capacity = 6;
	int wt[] = {1,2,3};
	int profit[] = {10,15,40};
    int i = 0;
	int n = 3;

    // int ans=solve(capacity,wt,profit,i,n);
    // int ans=solvebottom(capacity,wt,profit,n);
    int ans = solveso(capacity,wt, profit, n);
    cout<<"the ans is : "<<ans;

}
