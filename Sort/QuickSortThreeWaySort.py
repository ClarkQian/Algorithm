#!usr/bin/env python
# -*- coding:utf-8 -*-
# __Author : Clark Qian


import timeit
import random

def insertionSort(a, l, r):
    for i in range(l+1, r+1, 1):
        e = a[i]
        j = i
        while i-1 >= 0 and a[i-1] > e:
            a[i] = a[i-1]
            i -= 1
        a[i] = e
    return


def __quickSort(a, l, r):
    if r-l <= 15:
        insertionSort(a, l, r)
        return
    d = random.randint(l,r)
    a[l],a[d] = a[d],a[l]

    lt = l;
    gt = r + 1;
    i = l + 1;
    e = a[l]
    while i < gt :
        if a[i] < e:
            a[i],a[lt+1] = a[lt+1],a[i]
            lt += 1
            i += 1
        elif a[i] > e:
            a[i],a[gt-1] = a[gt-1],a[i]
            gt -= 1
        else:
            i += 1
    a[l],a[lt] = a[lt],a[l]
    __quickSort(a, l, lt - 1)
    __quickSort(a, gt, r)

def quickSort(a):
    __quickSort(a, 0, len(a)-1)
    return


if __name__ == '__main__':
    a = [100-i for i in range(0, 100, 1)]
    print (a)
    quickSort(a)
    print(a)
