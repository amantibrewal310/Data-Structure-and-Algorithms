//?https://leetcode.com/problems/median-of-two-sorted-arrays/
#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

    int lenX = nums1.size();
    int lenY = nums2.size();

    if(lenX > lenY) {
        // We are applying BS on the smaller length array.
        return findMedianSortedArrays(nums2, nums1);
    }

    int low = 0;
    int high = lenX;

    while(low <= high) {
        int partitionX = low + (high - low) / 2;
        int partitionY = (lenX + lenY + 1) / 2;
        partitionY -= partitionX;
        
        // if the partition is at 0 then we need to assign -INF as no element is present on left of it
        // if the partition is at X then we need to assign +INF as no element is present on the right of it
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == lenX) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == lenY) ? INT_MAX : nums2[partitionY];

        if(maxLeftX <= minRightY and maxLeftY <= minRightX) {
            // If are at correct position

            if((lenX + lenY) % 2 == 0) {
                double avg = ( max(maxLeftY, maxLeftX) + min(minRightX, minRightY) ) / 2.0;
                return avg;
            } else {
                return (double)max(maxLeftY, maxLeftX);
            }

        } else if(maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
}