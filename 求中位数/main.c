#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int n=nums1Size+nums2Size;
    int num[n];
    int i,a=0,b=0;
    int cc;
    for(i=0;i<n;i++)
    {
        if(nums1[a]<nums2[b])
        {
            num[i]=nums1[a];
            a++;
        }
        else
        {
            num[i]=nums2[b];
            b++;
        }
        printf("%3d",num[i]);
    }
    if(n%2==0)
    {
        return (num[(n/2)-1]+num[(n/2)])/2.0;
    }
    else
        return num[(n-1)/2];
}

int main()
{
    double a;
    int b[3]={1,2,3},c[3]={4,5,6};
    printf("\n%f",findMedianSortedArrays(b,3,c,3));
    return 0;
}


