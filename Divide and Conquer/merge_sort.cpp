
// C program for implementation of Merge Sort
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("");
}

int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
}

void merge(int arr[], int l, int m, int r)
{
     int tmparr[r-l+1];
     int itrl=l;
     int itr=0;
     int itrr=m+1;
     while(itrl<=m && itrr<=r)
     {
         if(arr[itrl]<arr[itrr]){
             tmparr[itr]=arr[itrl];
             itrl++;itr++;
         }
         else
         {
             tmparr[itr]=arr[itrr];
             itrr++;itr++;
         }
     }
      while(itrr<=r)
     {
             tmparr[itr]=arr[itrr];
             itrr++;itr++;
         
     }
      while(itrl<=m )
     {
         
             tmparr[itr]=arr[itrl];
             itrl++;itr++;
        
     }
     int j=0;
     for(int i=l;i<=r;i++){
         arr[i]=tmparr[j];
         j++;
     }
}
