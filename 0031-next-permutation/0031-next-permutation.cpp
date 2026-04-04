class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i=len-2;
        //get the break point index
        while(i>=0){
            if(nums[i]>=nums[i+1]) i--;
            else break;
        }
        //swapping logic
        int j=len-1;
        if(i!=-1){
            while(true){
                if(nums[i]>=nums[j]) j--;
                else{
                    swap(nums[i],nums[j]);
                    break;
                }
            }
        }
        //non decreasing order
        j = len-1;
        i++;
        while(i<=j){
            swap(nums[i++],nums[j--]);
        }
    }
};