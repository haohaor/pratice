class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(),
        n = nums2.size();
    if ((n + m) & 1) {
      return find_kth(nums1, 0, m - 1, nums2, 0, n - 1, (n + m - 1) / 2);
    } else {
      return (find_kth(nums1, 0, m - 1, nums2, 0, n - 1, (n + m) / 2) + 
          find_kth(nums1, 0, m - 1, nums2, 0, n - 1, (n + m) / 2 - 1)) / 2;
    }
  }
  double find_kth(vector<int>& nums1, int s1, int e1, vector<int> &nums2, 
      int s2, int e2, int k) {
    int len1 = e1 - s1 + 1, len2 = e2 - s2 + 1;
    // cout << len1 << " ___ " << len2 << endl;
    if (len1 > len2) return find_kth(nums2, s2, e2, nums1, s1, e1, k);
    if (len1 == 0) return nums2[k];
    if (k == 0) return min(nums1[s1], nums2[s2]);
    int mid1 = min(k/2, len1 - 1), mid2 = k - mid1 - 1;
    cout << mid1 << "  " << mid2 << endl;
    if (nums1[s1 + mid1] > nums2[s2 + mid2]) {
      return find_kth(nums1, s1, e1, nums2, s2 + mid2 + 1, e2, k - mid2 - 1);
    } else if (nums2[s1 + mid1] < nums2[s2 + mid2]) {
      return find_kth(nums1, s1 + mid1 + 1, e1, nums2, s2, e2, k - mid1 - 1);
    } else {
      return nums1[s1 + mid1 - 1];
    }
  }
};