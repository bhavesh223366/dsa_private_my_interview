class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n=arr.size();
        vector<string>vec;
        for(int i=0;i<n;i++){
            int t=0;
            for(int j=0;j<n;j++){
                if(i!=j&&arr[i]==arr[j])break;
                else if (i!=j&&arr[i]!=arr[j])t++;
            }
            if(t==n-1)vec.push_back(arr[i]);
        }
        int m=vec.size();
        if(m<=k-1)return "";
        return vec[k-1];
    }
};