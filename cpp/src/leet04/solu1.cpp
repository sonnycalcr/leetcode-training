#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> mergedNums = mergeTwoSortedArrays(nums1, nums2);
    int numsLen = mergedNums.size();
    if (numsLen % 2)
      return mergedNums[numsLen / 2];
    int rightP = numsLen / 2;
    int leftP = rightP - 1;
    return (static_cast<double>(mergedNums[leftP]) + static_cast<double>(mergedNums[rightP])) / 2.0;
  }

private:
  vector<int> mergeTwoSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    int nums1Len = nums1.size();
    int nums2Len = nums2.size();
    int nums1P = 0;
    int nums2P = 0;
    while (nums1P < nums1Len && nums2P < nums2Len) {
      if (nums1[nums1P] < nums2[nums2P]) {
        res.push_back(nums1[nums1P]);
        nums1P++;
      } else {
        res.push_back(nums2[nums2P]);
        nums2P++;
      }
    }
    while (nums1P < nums1Len) {
      res.push_back(nums1[nums1P]);
      nums1P++;
    }
    while (nums2P < nums2Len) {
      res.push_back(nums2[nums2P]);
      nums2P++;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution solu;
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};
  double res;
  nums1 = {1, 2};
  nums2 = {3, 4};
  res = solu.findMedianSortedArrays(nums1, nums2);
  cout << res << "\n";
  return 0;
}