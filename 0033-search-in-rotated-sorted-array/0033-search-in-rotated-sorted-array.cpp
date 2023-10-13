// We have to find the target in the array, so brute force could be going in a linear way i.e. traversing the array and checking for each element and returning if found This is a O(N) solution. But we are asked for more optimized i.e. O(logN). So we can think of binary search. Why? because we know with binary search we optimize the serach space. So we can think of binary serach, if we will divide the array into 2 than one half will be sorted always and based on those conditions we can apply binary search.

//Lineaar Search
// class Solution{
//     public:
//         int search(vector<int> &nums,int target){
//             for(int i=0;i<nums.size();i++){
//                 if(nums[i]==target){
//                     return i;
//                 }
//             }
//             return -1;
//         }
// };

// Binary Search


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[low]<=nums[mid]){//Left half is sorted
                if(nums[low]<=target && nums[mid]>=target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{//Right half is sorted
                if(nums[mid]<=target && nums[high]>=target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};