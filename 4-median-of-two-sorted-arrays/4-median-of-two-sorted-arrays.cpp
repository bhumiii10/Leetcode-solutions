class Solution {
double median(vector<int> v)
	{
		sort(v.begin(), v.end());
		int n = v.size();
		if(n % 2)
		{
		    return v[n/2];
		}
		else
		{
		    return (v[n/2 - 1] + v[n/2])/2.0;
		}
	}
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n == 0 || m == 0)
        {
            return ((n == 0) ? median(nums2): median(nums1));
        }
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        int left = 0;
        int right = m-1;
        int mid;
        while(true)
        {
            mid = floor(left + (right - left) / 2.0);
            int other = (n + m)/2 - mid - 2;
            int left1,left2,right1,right2;
            if(mid >= 0)
            left1 = nums2[mid];
            else
            left1 = INT_MIN + 2;
            if(mid+1 < m)
            right1 = nums2[mid+1];
            else
            right1 = INT_MAX - 2;
            if(other >= 0)
            left2 = nums1[other];
            else
            left2 = INT_MIN + 2;
            if(other+1 < n)
            right2 = nums1[other+1];
            else
            right2 = INT_MAX - 2;
            if(left1 <= right2 && left2 <= right1)
            {
                if((n + m) % 2)
                {
                    return min(right1, right2);
                }
                else
                {
                    return (max(left1, left2) + min(right1, right2))/2.0;
                }
            }
            else 
            {
                if(left1 > right2)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return 0;
    }
};

