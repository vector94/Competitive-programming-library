class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--){
            if (nums[i] < nums[i + 1]){
                pivot = i;
                break;
            }
        }
        if (pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > pivot; i--){
            if (nums[pivot] < nums[i]){
                swap(nums[pivot], nums[i]);
                reverse(nums.begin() + pivot + 1, nums.end());
                return;
            }
        }
    }
};
/*
1. a[i] < a[i + 1]
2. Range (i + 1, n - 1), Find a[j] > a[i];
3. Swap(a[i], a[j])
4. Reverse(i + 1, n)
*/
