class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        // Ensure A is the smaller array to prevent out-of-bounds on B
        if (A.size() > B.size()) {
            return findMedianSortedArrays(B, A);
        }

        int m = A.size();
        int n = B.size();
        int total = m + n;
        int half = (total + 1) / 2; // Size of the left partition

        int left = 0;
        int right = m;

        while (left <= right) {
            int i = left + (right - left) / 2; // Number of elements from A
            int j = half - i;                 // Number of elements from B

            // Boundary checks: use INT_MIN/INT_MAX when partition hits an edge
            int A_left  = (i == 0) ? INT_MIN : A[i - 1];
            int A_right = (i == m) ? INT_MAX : A[i];
            int B_left  = (j == 0) ? INT_MIN : B[j - 1];
            int B_right = (j == n) ? INT_MAX : B[j];

            // Check if partition is valid
            if (A_left <= B_right && B_left <= A_right) {
                // Odd total elements: median is max of left side
                if (total % 2 != 0) {
                    return max(A_left, B_left);
                }
                // Even total elements: median is average of middle two
                return (max(A_left, B_left) + min(A_right, B_right)) / 2.0;
            } 
            else if (A_left > B_right) {
                // A is contributing too many large numbers to left half
                right = i - 1;
            } 
            else {
                // A is contributing too few numbers to left half
                left = i + 1;
            }
        }

        return 0.0;
    }
};




