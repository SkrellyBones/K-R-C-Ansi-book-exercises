#include <stdio.h>
/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);
    if (left >= right) /* do nothing if array contains */
        return;
    /* fewer than two elements */
    swap(v, left, (left + right) / 2); /* move partition elem */
    last = left;
    /* to v[0] */
    for (i = left + 1; i <= right; i++) /* partition */
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    /* restore partition elem */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}
/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
int main(){
    int list[] = {10,9,8,7,6,5,4,3,2,1,0};
    int len = sizeof(list) / sizeof(list[0]);
    int i;
    printf("Unsorted: ");
    for (i = 0; i < len; i++)
        printf("%d ", list[i]);
    printf("\n");
    qsort(list,0,len-1);
    printf("  Sorted: ");
    for (i = 0; i < len; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}
