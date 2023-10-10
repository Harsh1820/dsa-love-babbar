class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        
        set<int> st(nums.begin(), nums.end());
        vector<int> uniqueNums;
        for (int num : st) {
            uniqueNums.push_back(num);
        }
        int visited = 0;
        for (int mi = 0; mi < uniqueNums.size(); mi++) {
            while (visited < uniqueNums.size() && uniqueNums[visited] < uniqueNums[mi] + n) {
                visited++;
            }
            
            int subAns = visited - mi;
            ans = min(ans, n - subAns);
        }
        
        return ans;
    }
};
// class Solution {
// public:
//     int minOperations(vector<int>& nums)
//     {
//         int maxi = 0;    // Initialize a variable to store the maximum count of consecutive numbers
//         int count = 0;   // Initialize a variable to keep track of the current count of consecutive numbers
//         int n = nums.size() - 1;  // Calculate the maximum possible difference between numbers
//         int l = 0;       // Initialize a variable to keep track of the modified length of the 'nums' vector

//         sort(nums.begin(), nums.end());  // Sort the input vector 'nums' in ascending order

//         // Remove duplicates in 'nums' and update 'l' with the modified length
//         for(int i = 0; i < nums.size(); i++) {
//             if(i+1 < nums.size() && nums[i] == nums[i+1]) continue;
//             nums[l++] = nums[i];
//         }

//         // Calculate the maximum count of consecutive numbers
//         for(int i = 0, j = 0; i < l; i++) {
//             while(j < l && (nums[j] - nums[i]) <= n) {
//                 count++;
//                 j++;
//             }
//             maxi = max(maxi, count);
//             count--;
//         }

//         // Calculate and return the minimum number of operations needed to make the numbers consecutive
//         return nums.size() - maxi;
//     }
// };