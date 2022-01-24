https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
class Solution {
public:
    bool check(int mid, vector<int> a, int days) {
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
        if(count <= days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = 0, ans;
        for(auto i : weights) {
            end += i;
        }
        while(start <= end) {
            int mid = (start + end) / 2;
            if(check(mid, weights, days)) {
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
