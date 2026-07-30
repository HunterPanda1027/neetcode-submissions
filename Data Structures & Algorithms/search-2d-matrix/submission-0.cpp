class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;

            if (matrix[middle][matrix[0].size() - 1] == target || matrix[middle][0] == target) {
                return true;
            } else if (matrix[middle][matrix[0].size() - 1] < target) {
                left = middle + 1;
            } else if (matrix[middle][0] > target) {
                right = middle - 1;
            } else {
                int low = 0;
                int high = matrix[0].size() - 1;

                while (low <= high) {
                    int center = low + (high - low) / 2;

                    if (matrix[middle][center] == target) {
                        return true;
                    } else if (matrix[middle][center] < target) {
                        low = center + 1;
                    } else {
                        high = center - 1;
                    }
                }
                return false;
            }
        }
        
        return false;
    }
};
