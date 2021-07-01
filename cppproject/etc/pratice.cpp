#include <bits/stdc++.h>

using namespace std;

void quick(int[] arr, int size, int left, int right){
    if(left >= right)   return;
    int pivot = left, l = left+1,r = right+1;
    while(l<=r){
        while(arr[l]<=arr[pivot] && l<=right)  l++;
        while(arr[r]>=arr[pivot] && r>left)   r--;
        if(l<=r){
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
        }
    }
    int temp = arr[pivot];
    arr[pivot] = arr[r];
    arr[r] = temp;
    quick(arr,size-r,left,r-1);
    quick(arr,size-r,r+1,right);
}

int size,heapArr[10000];

void insert(int data){
    heapArr[size] = data;
    int cur = size;
    while(cur /* && cur의 부모보다 cur가 더 크면*/){
        /*교환하고*/
        cur = (cur-1)/2;
    }
    size++;
}

int remove(){
    ret = heapArr[0];
    heapArr[0] = heapArr[size - 1];
    heapArr[size - 1] = 0;
    size--;
    int cur = 0, next;
    while(1){
        next = cur;
        if(2 * cur + 1 >= size) break; // 왼쪽 자식 노드가 없으면
        //왼쪽 자식 노드가 자신 보다 크면
        next = 2 * cur + 1;
        //오른쪽 자식 노드가 자신 보다 크면
        next = 2 * cur + 2;
        if(next == cur) break;
        else{
            //next <-> cur
            cur = next;
        }
    }
}