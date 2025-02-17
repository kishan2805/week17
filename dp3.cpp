#include<iostream>
#include<vector>
using namespace std;


// edit distance leet 72
/*
class Solution {
public:
int solve(string &a, string &b, int i, int j){
    if(i>=a.length()){
        return b.length()-j;
    }
    if(j>=b.length()){
        return a.length()-i;
    }
    int ans=0;
    if(a[i]==b[j]){
        // match
        ans=0+solve(a,b,i+1,j+1);
    }
    else {
        // remove
        int opt1 =1+solve(a,b,i+1,j);
        // insert
        int opt2=1+solve(a,b,i,j+1);
        // replace
        int opt3=1+solve(a,b,i+1,1+j);
        ans=min(opt1,min(opt2,opt3));
    }
    return ans;
}
    int solvetop(string &a, string &b, int i, int j,vector<vector<int> >&dp){
        if(i>=a.length()){
            return b.length()-j;
        }
        if(j>=b.length()){
            return a.length()-i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;
        if(a[i]==b[j]){
            // match
            ans=0+solvetop(a,b,i+1,j+1,dp);
        }
        else {
            // remove
            int opt1 =1+solvetop(a,b,i+1,j,dp);
            // insert
            int opt2=1+solvetop(a,b,i,j+1,dp);
            // replace
            int opt3=1+solvetop(a,b,i+1,1+j,dp);
            ans=min(opt1,min(opt2,opt3));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int i =0;
        int j=0;
        // int ans=solve(word1 , word2, i,j);
        vector<vector<int> >dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        int ans=solvetop(word1 , word2, i,j,dp);
        return ans;
    }
};
*/

// longest subseq leet 1143
/*
class Solution {
public:
    int solve(string a,string b ,int i, int j){
        // base 
        if (i>=a.length()||j>=b.length()){
            return 0;
        }
        // match case 
        int ans=0;
        if(a[i]==b[j]){
            ans=1+solve(a,b,i+1,j+1);
        }
        // dont match 
        else{
            ans=0+max(solve(a,b,i+1,j),solve(a,b,i,j+1));
        }

        return ans;
    }
    int solvetop(string& a,string& b ,int i, int j,vector< vector<int> >& dp){
        // base 
        if (i>=a.length()||j>=b.length()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // match case 
        int ans=0;
        if(a[i]==b[j]){
            ans=1+solvetop(a,b,i+1,j+1,dp);
        }
        // dont match 
        else{
            ans=0+max(solvetop(a,b,i+1,j,dp),solvetop(a,b,i,j+1,dp));
        }
        dp[i][j]=ans;

        return dp[i][j];
    }
    int solvebottom(string a, string b){
        vector<vector<int> >dp(a.length()+1,vector<int>(b.length()+1,0));
        for (int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                int ans=0;
                if(a[i]==b[j]){
                    ans=1+dp[i+1][j+1];
                }
                // dont match 
                else{
                    ans=0+max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }      
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;

        // int ans=solve(text1,text2,i,j);
        vector<vector<int> >dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        // int ans=solvetop(text1,text2,i,j,dp);
        int ans=solvebottom(text1,text2);
        return ans;
        
    }
};

*/


// longest pallindrome subsequence leet 
/* 
class Solution {
public:
    int solvebottom(string a, string b) {
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));

        for(int i=a.length()-1; i>=0; i--) {
            for(int j=b.length()-1; j>=0; j--) {
                    int ans = 0;
                    if(a[i] == b[j]) {
                        ans = 1 + dp[i+1][j+1];
                    }
                    else {
                        ans = 0 + max(dp[i][j+1],dp[i+1][j]);         
                    }
                    dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string a=s;
        reverse(a.begin(),a.end());
        int ans= solvebottom(s,a);
        return ans;
        
    }
};
*/

int main(){

    
    return 0;
}