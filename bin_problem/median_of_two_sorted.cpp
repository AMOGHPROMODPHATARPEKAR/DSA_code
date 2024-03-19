double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}
//optimal log(min(n1,n2))
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

       if(nums1.size()<nums2.size()) return findMedianSortedArrays(nums2,nums1);


        int n1=nums1.size();
        int n2=nums2.size();
        int low=0;
        int high=n1;
        while(low<=high)
        {
        int cut1=(low+high) >> 1;
        int cut2=(n1+n2+1)/2 - cut1;

        int l1=cut1==0 ? INT_MIN : nums1[cut1-1];
        int l2=cut2==0 ? INT_MIN : nums2[cut2-1];

        int r1=cut1==n1 ? INT_MAX : nums1[cut1];
        int r2=cut2==n2 ? INT_MAX : nums2[cut2];

        if(l1<=r2 && l2<= r1)
        {
            if((n1+n2)%2 == 0)
                return (max(l1,l2)+min(r1,r2))/2.0;
            else
                return max(l1,l2);
        }else if(l1>r2)
                high=cut1-1;
            else
                low=cut1+1;

        }

        return 0.0;
    }