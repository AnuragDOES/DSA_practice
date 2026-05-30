class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int low = 0;
        int high = matrix.size()*n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int i = mid/n;
            int j = mid%n;
            if(matrix[i][j]==target)return true;
            if(matrix[i][j]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};