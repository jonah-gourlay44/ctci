#pragma once

#include <functional>

template <typename T>
void merge(T arr[], int l, int m, int r)
{
    int merge_ptr = m;
    int idx = m;
    while (merge_ptr <= r)
    {
        idx = merge_ptr;

        while (arr[idx] < arr[idx-1] && idx > l)
        {
            std::swap(arr[idx], arr[idx-1]);
            idx--;
        }

        merge_ptr++;
    }
}

template <typename T>
void mergeSort(T arr[], int l, int r)
{
    if (r <= l)
        return;

    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr, l, m, r);
}

template <typename T>
void mergeSort(std::vector<T>& arr)
{
    mergeSort(&arr[0], 0, arr.size()-1);
}