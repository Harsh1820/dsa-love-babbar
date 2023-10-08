// //Bruteforce Approach - O(n^3) time and O(n) space
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         set<vector<int>> s;
//         vector<vector<int>> output;
//         for (int i = 0; i < nums.size(); i++){
//             for(int j = i+1; j < nums.size(); j++){
//                 for(int k = j+1; k < nums.size(); k++){
//                     vector<int> temp;
//                     if(nums[i] + nums[j] + nums[k] == 0){
//                         temp.push_back(nums[i]);
//                         temp.push_back(nums[j]);
//                         temp.push_back(nums[k]);
//                         s.insert(temp);
//                     }
//                 }
//             }
//         }
//         for(auto allTriplets : s)
//             output.push_back(allTriplets);
//         return output;
//     }
// };


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i=0; i<n-2; i++){
            int low = i+1, high = n-1;
            while(low < high){
                if(nums[i] + nums[low] + nums[high] < 0){
                    low++;
                }
                else if(nums[i] + nums[low] + nums[high] > 0){
                    high--;
                }
                else{
                    set.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                }
            }
        }
        for(auto it : set){
            output.push_back(it);
        }
        return output;
    }
};


