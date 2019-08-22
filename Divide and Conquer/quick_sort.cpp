#include <bits/stdc++.h>
using namespace std;
int partition (int arr[], int low, int high);

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition(arr, low, high);
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("
");
}

int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
}

int partition (int arr[], int low, int high)
{
   int base=arr[high];
   int itr=low;
   for(int i=low;i<=high;i++)
   {
       if(arr[i]<base)
       {
           int a=arr[itr];
           arr[itr]=arr[i];
           arr[i]=a;
           itr++;
       }
       
   }
   int tmp=arr[itr];
   arr[itr]=arr[high];
   arr[high]=tmp;
   return itr;
}
