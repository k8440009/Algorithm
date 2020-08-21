// Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i < k % nums.size(); i++)
        {
            int end = nums.size() - 1;
            int tmp = nums[end];
            nums.pop_back();
            nums.insert(nums.begin(), tmp);
        }
    }
};