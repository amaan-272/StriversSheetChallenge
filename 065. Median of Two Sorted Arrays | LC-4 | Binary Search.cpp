//CodeStudio Code
double median(vector<int>& a, vector<int>& b) {
    if(a.size() > b.size()) return median(b, a);
    int n1 = a.size(), n2 = b.size(), low{}, high{n1};
    while(low <= high) {
        int cut1 {low+(high-low)/2}, cut2 {(n1+n2+1)/2-cut1};
        int l1 = cut1? a[cut1-1]:INT_MIN, l2 = cut2? b[cut2-1]:INT_MIN;
		int r1 = (cut1 == n1)? INT_MAX:a[cut1], r2 = (cut2 == n2)? INT_MAX:b[cut2];
        if(l1<=r2 && l2<=r1) {
            if((n1+n2)&1) return max(l1, l2);
            return (max(l1, l2)+min(r1, r2))/2.0;
        }
        else if(l1 > r2) high = cut1-1;
        else low = cut1+1;
    } 
    return 0.0;
}

//LeetCode Code
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> all;
        int i {}, j {}, n1 = size(nums1), n2 = size(nums2);
        while(i < n1 && j < n2) {
            if(nums1[i] <= nums2[j]) {
                all.emplace_back(nums1[i]);
                i++;
            }
            else {
                all.emplace_back(nums2[j]);
                j++;
            }
        }
        while(i < n1) {
            all.emplace_back(nums1[i]);
            i++;
        }
        while(j < n2) {
            all.emplace_back(nums2[j]);
            j++;
        }
        double ans;
        int n = size(all);
        ans = (n%2)?(double)all[n/2]:(double)(all[n/2]+all[n/2-1])/2.0;
        return ans;
    }
};
