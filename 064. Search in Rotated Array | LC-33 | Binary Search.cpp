//CodeStudio Code
int search(int* arr, int n, int key) {
    int low {}, high {n-1};
    while(low < high){
        int mid {low+(high-low)/2};
        if(arr[mid] > arr[high]) low = mid+1;
        else high = mid;
    }
    int rotated {low};
    low = 0;
    high = n-1;
    while(low <= high){
        int mid {low+(high-low)/2}, middle {(mid+rotated)%n};
        if(arr[middle] == key) return middle;
        if(arr[middle] < key) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

//LeetCode Code
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i {}; i < size(nums); i++) if(nums[i] == target) return i;
        return -1;
    }   
};
