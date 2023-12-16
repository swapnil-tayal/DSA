class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        
        int n = matrix.length;
        int m = matrix[0].length;
        
        int s = 0;
        int e = n*m - 1;
        
        while(s <= e){
            
            int mid = (s+e)/2;
            // System.out.println(mid);

            int i = mid/m;
            int j = mid%m;
            
            if(matrix[i][j] > target) e = mid-1;
            else if(matrix[i][j] < target) s = mid+1;
            else return true;
        }
        return false;
    }
}