class Solution {
public:
int countLessOrEqual(const vector<vector<int>>& matrix, int n, int mid) {
        int count = 0;
        int row = n - 1;
        int col = 0;

        // Start from bottom-left corner and move towards top-right
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += (row + 1); // Entire column segment above is <= mid
                col++;              // Move right
            } else {
                row--;              // Move up
            }
        }

        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       int n = matrix.size();
       
       
       
        int i = matrix[0][0], j = matrix[n-1][n-1];
        while(i<j){
            int mid = i+(j-i)/2;
            int count = countLessOrEqual(matrix,n,mid);
            if(count>=k){
                j = mid;
            }else{
                i = mid +1;
            }
        }
       
       
       return i;

    }
};