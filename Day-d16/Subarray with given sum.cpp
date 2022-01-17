/* Problem - https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1 */
vector<int> subarraySum(int arr[], int n, long long s)
    {
        int e = 0;
        long long sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += arr[i];
            
            while(e < i and sum > s){
                sum -= arr[e];
                e++;
            }
            
            if(sum == s) {
                return {e + 1, i + 1};
            }
        }
        return {-1};
    }
