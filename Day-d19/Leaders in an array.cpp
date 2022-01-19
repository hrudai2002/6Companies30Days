/* https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/#  */
 vector<int> leaders(int a[], int n){
        int mx = a[n - 1];
        vector<int> ans;
        for(int i = n - 1; i >= 0; --i) {
            if(a[i] > mx) {
                mx = a[i];
            }
            if(a[i] >= mx) ans.push_back(a[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
  }
