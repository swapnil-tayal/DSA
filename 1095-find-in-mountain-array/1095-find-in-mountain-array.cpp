/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n = mountainArr.length();
        int s = 0;
        int e = n-1;
        int peak = -1;
        
        while(s <= e){
            
            int mid = (s+e)/2;
            int midEle = mountainArr.get(mid);
            int midPlus = mountainArr.get(mid+1);
            int midMins = mountainArr.get(mid-1);
            
            if(midPlus < midEle and midEle < midMins) e = mid;
            else if(midPlus > midEle and midEle > midMins) s = mid;
            else{
                peak = mid;
                break;
            }
        }
        // cout<<peak<<' ';
        s = 0;
        e = peak;
        while(s <= e){
            
            int mid = (s+e)/2;
            int midEle = mountainArr.get(mid);
            if(midEle > target) e = mid-1;
            else if(midEle < target) s = mid+1;
            else return mid;
        }
        s = peak;
        e = n-1;
        // cout<<s<<' '<<e<<'\n';
        while(s <= e){
            
            int mid = (s+e)/2;
            int midEle = mountainArr.get(mid);
            if(midEle > target) s = mid+1;
            else if(midEle < target) e = mid-1;
            else return mid;
        }
        return -1;
    }
};