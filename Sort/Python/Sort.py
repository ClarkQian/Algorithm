#!usr/bin/env python
# -*- coding:utf-8 -*-
# __Author : Clark Qian


def BubbleSort(arr):
    n = len(arr)
    for i in range(0, n - 1):
        for j in range(0,n-i-1):
            if arr[j] > arr[j+1]:
                arr[j],arr[j+1] = arr[j+1],arr[j]
def insertionSort(arr):
    n = len(arr)
    for i in range(1,n):
        j = i
        e = arr[i]
        while j-1 >= 0 and arr[j-1] > e:
            arr[j] = arr[j - 1]
            j -= 1
        arr[j] = e
        
def mergeSort(arr):
    __mergeSort(arr, 0, len(arr)-1)


def __mergeSort(arr, left, right):
    if left >= right:
        return

    mid = (left+right)//2

    __mergeSort(arr, left, mid)
    __mergeSort(arr, mid+1, right)

    if arr[mid] > arr[mid+1]:
        merge(arr,left, mid, right)

def merge(arr, left, mid, right):
    aux = arr[left:right+1]
    i, j, k = left, mid+1, 0
    n = right - left +1
    while k < n:
        if i <= mid:
            if j <= right:
                if arr[i] < arr[j]:
                    aux[k] = arr[i]
                    i += 1
                else:
                    aux[k] = arr[j]
                    j += 1
            else:
                aux[k] = arr[i]
                i += 1
        else:
            aux[k] = arr[j]
            j += 1
        k += 1
    for i in range(n):
        arr[left+i] = aux[i]

def SelectionSort(arr):
    n = len(arr)
    for i in range(0,n,1):
        index = i
        for j in range(i,n, 1):
            if arr[j] < arr[index]:
                index = j
        arr[i],arr[index] = arr[index],arr[i]
    return arr

def shellSort(arr):
    n = len(arr)
    h = 1
    while h < int(n/3):
        h = 3*h+1

    while h >= 1:
        for i in range(h, n):
            j = i
            e = arr[i]
            while j - h >= 0 and arr[j-h] > e:
                arr[j] = arr[j - h]
                j -= h
            arr[j] = e
        h = int(h/3)

if __name__ == '__main__':
