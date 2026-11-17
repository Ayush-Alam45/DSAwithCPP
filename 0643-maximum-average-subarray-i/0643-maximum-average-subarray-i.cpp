class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long  long  answer=0;
        for(int right=0;right<k;right++){
            answer+=nums[right];
        }
         long long maxsubarray=answer;
        for(int i=k ;i<nums.size();i++){
            answer=answer+nums[i]-nums[i-k];
            maxsubarray= max( maxsubarray,answer);

        }
         

         return (double)maxsubarray/k; 
    }
};