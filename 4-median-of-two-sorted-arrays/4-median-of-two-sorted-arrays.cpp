class Solution {
public:
double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {

    int i = 0, j = 0;
    int m = nums1.size(), n = nums2.size();
    vector<float> v;
    
    while(i < m && j < n)
    {
        if(nums1[i] < nums2[j])
            v.push_back(nums1[i++]);
        else
            v.push_back(nums2[j++]);
    }
    
    while(i < m)
        v.push_back(nums1[i++]);
    
    while(j < n)
        v.push_back(nums2[j++]);
    
    int size = v.size();
    float median = 0;
    
    if(size % 2)
        median = v[size / 2];
    else
        median = (v[size / 2 - 1] + v[size / 2]) / 2;
    
    return median;
}
};

