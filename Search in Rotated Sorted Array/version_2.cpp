class Solution {
public:
    int search(vector<int>& A, int target) {
        int len = A.size();
        if(!len)
            return -1;
        int left = 0, right = len - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (A[mid] == target) {
                return mid;
            }
            if (A[mid] < A[right]) {
                if (A[mid] < target && target <= A[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (A[mid] > A[right]) {
                if (A[left] <= target && target < A[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                right--;
            }
        }
        return -1;
    }
};