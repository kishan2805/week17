



// FIBO Using DP

// class Solution {
// public:
//     int solve(int n , vector<int>& dp){
//         if(n==0||n==1)
//             return n;
        
//         // step 3: 
//         // use the stored value 
//         if(dp[n]!=-1)
//             return(dp[n]);

//         // store the values 
//         dp[n]=solve(n-1,dp)+solve(n-2,dp);
//         return dp[n];
//     }

//     int bottomup(int n){
//         // step 1 : create dp array 
//         vector<int> dp(n+1,-1);
//         // step 2 : fill the values that you know 
//         dp[0]=0;
//         // base case check 
//         if(n==0){
//             return 0;
//         }
//         dp[1]=1;
//         // step 3 : use logic to fill remaining
//         // we need to fill 0->n
//         // already known 0,1
//         // left 2 to n
//         for(int i=2;i<=n;i++){
//             dp[i]=dp[i-1]+dp[i-2];
//         }

//         return dp[n];

//     }

//     int spaceopt(int n ){
//         if(n==0|| n== 1 )
//             return n;
//         int pre=0;
//         int cur=1;
//         int ans;
//         for(int i=2;i<=n;i++){
//             ans=cur+pre;
//             pre=cur;
//             cur=ans;
//         }
//         return ans;
//     }


//     int fib(int n) {

//         // // using recurssion
//         // if(n==0|| n==1)
//         //     return n;

//         // int ans=fib(n-1)+fib(n-2);
//         // return ans;

//         // DP
//         // top down approach => rec+memo

//         // // step1 : create array to store the values 
//         // vector<int>dp(n+1,-1);
//         // return solve(n,dp);


//         // Bottom Up Approach
        
//         // return bottomup(n);

//         // space opt : doesnt apply on all . only if a pattern is found 
//         // different steps  for diff questions 
//         // we will focus on space opt later 
//         return spaceopt(n);
//     }
// };


// // House Robber Using DP
// class Solution {
// public:
//     int solverec (vector<int>&nums, int i){

//         // using rec
//         if(i>=nums.size()){
//             return 0;
//         }
//         // chori nahi hue
//         int opt1=0+solverec(nums,i+1);
//         // chori hue 
//         int opt2=nums[i]+solverec(nums,i+2);

//         return max(opt1,opt2);

//     }
//     int solvetop(vector<int>&dp,vector<int>&nums, int i){
//         // base case 
//         if(i>=nums.size()){
//             return 0;
//         }
//         // step 3 : check for repeate values 
//         if(dp[i]!=-1){
//             return dp[i];
//         }

//         // step 2 : enter the new values in the dp

//         int opt1=0+solvetop(dp,nums,i+1);
//         // chori hue 
//         int opt2=nums[i]+solvetop(dp,nums,i+2);
//         dp[i]=max(opt1,opt2);

//         return dp[i];
//     }
//     int solvebot(vector<int>&nums, int i){

//     }
//     //tabulation
//     int solveUsingTabulation(vector<int>& nums) {
//         int n = nums.size();
//         //step1
//         vector<int> dp(n, -1);
//         //step2
//         dp[n-1] = nums[n-1];
//         for(int index = n-2; index>=0; index--) {
//             int tempAns = 0;
//             if(index + 2 < n) {
//                 tempAns = dp[index+2];
//             }
//             int include = nums[index] + tempAns;
//             int exclude = 0 + dp[index+1];
//             dp[index] = max(include, exclude);
//         }
//         return dp[0];
//     }

//      int solveUsingTabulationSO(vector<int>& nums) {
//         int n = nums.size();
//         int prev = nums[n-1];
//         int next = 0;
//         int curr;

//         for(int index = n-2; index>=0; index--) {
//             int tempAns = 0;
//             if(index + 2 < n) {
//                 tempAns = next;
//             }
//             int include = nums[index] + tempAns;
//             int exclude = 0 + prev;
//             curr = max(include, exclude);

//             //bhul jata hu
//             next = prev;
//             prev = curr;
//         }
//         return prev;
//     }


//     int rob(vector<int>& nums) {

//         // int ans=solverec(nums,0);
//         // return ans;

//         // Using DP (top down )
//         // step 1: storing the value
//         // vector<int>dp(nums.size(),-1);
//         // return solvetop(dp,nums,0);

//         // bottom up
//         int ans = solveUsingTabulationSO(nums);
//         return ans;


//     }
// };

// Coin Change Dp

// class Solution {
// public:
//     int solve(vector<int>& coins, int amount){
//         // base case
//         if(amount == 0){
//             return 0;
//         }
//         // recurssion
//         int mini=INT_MAX;
//         for(int i=0;i<coins.size();i++){
//             // find ans for valid values i.e amount>=0
//             if(amount-coins[i]>=0){
//                 int recans=solve(coins,amount-coins[i]);
//                 // if we are getting a valid ans then only proced
//                 if(recans!=INT_MAX){
//                     // now consider the ith coin
//                     int ans=1+recans;
//                     mini=min(mini,ans);
//                 }
//             }
//         }
//         return mini;
//     }
//     int topdown(vector<int>& coins, int amount,vector<int>& dp){
//         // base case
//         if(amount == 0){
//             return 0;
//         }
//         // step 3 use existing value
//         if(dp[amount]!=-1){
//             return dp[amount];
//         }
//         // recurssion
//         int mini=INT_MAX;
//         for(int i=0;i<coins.size();i++){
//             // find ans for valid values i.e amount>=0
//             if(amount-coins[i]>=0){
//                 int recans=topdown(coins,amount-coins[i],dp);
//                 // if we are getting a valid ans then only proced
//                 if(recans!=INT_MAX){
//                     // now consider the ith coin
//                     int ans=1+recans;
//                     mini=min(mini,ans);
//                 }
//             }
//         }
//         // step 2 
//         dp[amount]=mini;
//         return dp[amount];
//     }
//     int solveUsingTabulation(vector<int>& coins, int amount) {
//         //step1: done
//         int n = amount;
//         vector<int> dp(n+1, INT_MAX);
//         //step2: base case analyse
//         dp[0] = 0;
//         //for loop
//         for( int value = 1; value<=amount; value++) {
//             int mini = INT_MAX;
//             for(int i=0; i<coins.size(); i++) {
            
//                 if(value - coins[i] >= 0) {
//                     int recursionKaAns = dp[value - coins[i] ];
                    
//                     if(recursionKaAns != INT_MAX) {
                        
//                         int ans = 1 + recursionKaAns;
//                         mini  = min(mini, ans);
//                     }
//                 }
//             }
//             dp[value] = mini;
//         }
//         return dp[amount];
    
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         // int ans= solve(coins,amount);
//         // if(ans!=INT_MAX){
//         //     return ans;
//         // }
//         // else{
//         //     return -1;
//         // }

//         // // Using Dp (TopDown)
//         // int n=amount;
//         // vector<int>dp(n+1,-1);
//         // int ans= topdown(coins,amount,dp);
//         // if(ans!=INT_MAX){
//         //     return ans;
//         // }
//         // else{
//         //     return -1;
//         // }

//         int ans = solveUsingTabulation(coins, amount);
//         if(ans == INT_MAX)
//             return -1;
//         else {
//             return ans;
//         }

//     }
// };

