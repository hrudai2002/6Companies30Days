https://leetcode.com/problems/split-array-largest-sum/
class Solution {
public:
    bool check(int mid, vector<int> a, int m) {
        int count = 0;
        int sum = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] > mid) return false;
            sum += a[i];
            if(sum > mid) {
                count += 1;
                sum = a[i];
            }
        }
        count += 1;
        if(count <= m) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int m) {
        int start = *max_element(nums.begin(), nums.end());
        int end = 0, ans;
        for(auto i : nums) {
            end += i;
        }
        while(start <= end) {
            int mid = (start + end) / 2;
            if(check(mid, nums, m)) {
                ans = mid; 
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
