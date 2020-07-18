class Solution {
public:
    int findKthLargest(vector<int>& nums, int k, int l=0, int r=-1) {
        if (r<0) r = nums.size();
        if (l+1 >= r) return nums[l];
        swap(nums[l], nums[rand() % (r-l) + l]);
        int pivot = nums[l];
        int i = l, j = r;
        while (i<j) {
            while (i < j && nums[--j] <= pivot);
            nums[i] = nums[j];
            while (i < j && nums[++i] >= pivot);
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        if (i == k - 1) return nums[i];
        if (i < k - 1) return findKthLargest(nums, k, i + 1, r);
        else return findKthLargest(nums, k, l, i);
    }
};