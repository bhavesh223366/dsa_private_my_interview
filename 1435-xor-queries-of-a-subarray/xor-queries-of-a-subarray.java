class Solution {
    public int[] xorQueries(int[] arr, int[][] que) {
        
        int n = arr.length;
        int pre[] =  new int[n];
        int sum =0;
        for(int i =0; i< n;i++){
         sum ^= arr[i];
         pre[i]= sum;
        } 

        int ans[] = new int[que.length];
        int cal =0;
        for(int i =0; i< que.length; i++){
         ans[i]= pre[que[i][1]] ^((que[i][0] -1>=0)? pre[que[i][0] -1]:0);
        }

return ans;
    }
}