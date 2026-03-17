class Solution {
public:
    void reverse(vector<int>& v, int fromIndex, int uptoIndex){
        int s=fromIndex;
        int e=uptoIndex;
        while(s<e){
            swap(v[s++],v[e--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};