// variant of Sliding window technique
int longestSubSeg(vector<int> &nums, int n, int k){
    int i = 0, j;
    for (auto it:nums) {
        if(it==0) k--;
        if(k<0){
            int startEle = nums[i];
            if(startEle==0)  k++;
            i++;
        }
    }
    return n - i;
}
