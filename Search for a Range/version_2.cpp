class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {
        int left, right, mid;
        int n = A.size();
        vector<int> ret;
        
        //find lowerbound
        left = 0, right = n - 1;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (A[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        ret.push_back((A[left] == target) ? left : -1);
        
        //find upperbound
        right = n - 1;
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            if (target < A[mid]) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        ret.push_back((A[left] == target) ? left : -1);
        
        return ret;
	}
};