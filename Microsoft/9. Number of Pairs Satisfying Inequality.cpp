#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long c;
    void merge(int start, int end, int mid , vector<int>&v, int d){
        int l = start;
        int r = mid+1;
        while(l<=mid && r<=end){
            if(v[l]<=(v[r]+d)){
                c+=(end-r+1);
                l++;
            }else{
                r++;
            }
        }
        sort(v.begin()+start, v.begin()+end+1);
    }
    void merge_sort(int start, int end , vector<int>&v, int diff){
        if(start == end){
            return;
        }
        int mid = start + (end-start)/2;
        merge_sort(start, mid, v, diff);
        merge_sort(mid+1, end, v, diff);
        merge(start, end, mid, v, diff);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int>vec;
        for(int i = 0 ; i<nums1.size(); i++){
            vec.push_back(nums1[i]-nums2[i]);
        }
        c=0;
        merge_sort(0,nums1.size()-1, vec, diff);
        return c;
    }
};