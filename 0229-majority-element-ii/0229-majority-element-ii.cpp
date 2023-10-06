class Solution {
public:
vector<int> majorityElement(vector<int>& nums) {
int n = nums.size();
vector<int> result;
map<int, int> countMap;

    for (int num : nums) {
        countMap[num]++;
    }

    for (auto& entry : countMap) {
        if (entry.second > n / 3) {
            result.push_back(entry.first);
        }
    }

    return result;
}
};

