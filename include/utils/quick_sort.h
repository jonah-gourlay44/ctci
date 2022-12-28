#pragma once

#include <functional>
#include <vector>

template <typename T>
T getPivot(T arr[], int l, int r)
{
    int m = (l + r) / 2;
    if (arr[m] < arr[l])
        std::swap(arr[m], arr[l]);
    if (arr[r] < arr[l])
        std::swap(arr[r], arr[l]);
    if (arr[m] < arr[r])
        std::swap(arr[m], arr[r]);
    return arr[r];
}

template <typename T>
void partition(T arr[], int l, int r, int& lo, int& hi, const T& p)
{
    lo = l;
    hi = r;

    while (lo != hi)
    {
        if (arr[lo] > p) {
            std::swap(arr[lo], arr[hi]);
            while (arr[hi] > p)
                hi--;
        } else if (arr[lo] == p) {
            if (arr[hi] < p)
                std::swap(arr[lo], arr[hi]);
            lo++;
        } else {
            lo++;
        }
    }

    while (arr[lo-1] == p)
        lo--;
}

template <typename T>
void quickSort(T arr[], int l, int r)
{
    if (r <= l)
        return;

    T p = getPivot(arr, l, r);
    int lo, hi;
    partition(arr, l, r, lo, hi, p);
    quickSort(arr, l, lo-1);
    quickSort(arr, hi+1, r);
}

template <typename T>
void quickSort(std::vector<T>& arr)
{
    quickSort(&arr[0], 0, arr.size()-1);
}