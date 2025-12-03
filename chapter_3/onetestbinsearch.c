/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] one test inside the loop*/ 
#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n){
    int low, high, mid;
    low =0;
    high = n-1;
    if (x < v[0] || x > v[n-1])
        return -1;

    while (low<=high){
        mid = (low+high)/2;
        if (x <= v[mid])
            high = mid -1;
        else
            low = mid +1;
    }
    if (v[low] == x)
        return low;
    else
        return -1;
}
int main(){
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 7;
    int result = binsearch(target, arr, size);
    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in the array.\n");
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}
