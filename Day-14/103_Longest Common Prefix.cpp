string longestCommonPrefix(vector<string> &arr, int n)
{
    int lcpLen=arr[0].length();
    for(int i=1; i<n; i++){
        string str = arr[i];
        int x = str.length();
        int cnt=0;
        for(int j=0; j<min(x,lcpLen); j++){
            if(arr[0][j]!=str[j])   break;
            cnt++;
        }
        lcpLen = min(lcpLen,cnt);
    }
    return arr[0].substr(0,lcpLen);
}


