// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         for(int i=2;i<n;i++)
//         {
//             cost[i]+=min(cost[i-1],cost[i-2]);
//         }
//         return min(cost[n-1],cost[n-2]);
//     }
// };



class Solution {
    public:
    int solve(vector<int>& cost,int n)
    {
        int prev2 = cost[0];
        int prev1 = cost[1];
        for(int i =2;i<n;i++)
        {
            int curr = cost[i]+ min(prev1,prev2);
            prev2=prev1;
            prev1=curr;
        }
        return min(prev1,prev2);

    }
    


    int minCostClimbingStairs(vector<int> cost) {
     int n= cost.size();
     return solve(cost, n);   
    }
};


// class Solution {
//     private:
//     int solve(vector<int>& cost, int n){
//         vector<int> dp(n+1);// creation of dp array
//         // bass case analysis 

//         dp[0]= cost[0];
//         dp[1] = cost[1];
//           // step 3
//         for(int i =2; i<n; i++){
//             dp[i] = cost[i] + min(dp[n-1], dp[n-2]);
//         }

//         return min(dp[n-1], dp[n-2]);
// }

// public:
//  int minCostClimbingStairs(vector<int>& cost) {

//      int n = cost.size();

//      return solve(cost, n);

//      }
// };