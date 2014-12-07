#include <stdlib.h>
#include <string.h>

template <typename item_type>
int compare(item_type a, item_type b) {
    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    } else {
        return 0;
    }
}

template <typename item_type>
void merge(item_type *pItem, int begin, int middle, int end, item_type *pBuf,
        int (*pfCompare)(item_type a, item_type b)) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (k < (end - middle) && j < (middle - begin + 1)) {
        if (pfCompare(pItem[begin + j], pItem[middle + 1 + k]) < 0) {
            pBuf[i] = pItem[begin + j];
            ++j;
        } else {
            pBuf[i] = pItem[middle + 1 + k];
            ++k;
        }
        ++i;
    }
    while (k < (end - middle)) {
        pBuf[i] = pItem[middle + 1 + k];
        ++k;
        ++i;
    }
    while (j < (middle - begin + 1)) {
        pBuf[i] = pItem[begin + j];
        ++j;
        ++i;
    }
    memcpy(pItem + begin, pBuf, sizeof(item_type) * (end - begin + 1));
}

template <typename item_type>
void merge_sort_(item_type *pItem, int begin, int end, item_type *pBuf,
        int (*pfCompare)(item_type a, item_type b)) {    
    if (begin < end) {
        int middle = (begin + end) / 2;
        merge_sort_<item_type>(pItem, begin, middle, pBuf, pfCompare);
        merge_sort_<item_type>(pItem, middle + 1, end, pBuf, pfCompare);
        merge<item_type>(pItem, begin, middle, end, pBuf, pfCompare);
    }
}

template <typename item_type>
int merge_sort(item_type *pItem, int begin, int end,
        int (*pfCompare)(item_type a, item_type b) = compare<item_type>) {
    item_type *pBuf = (item_type *)malloc(sizeof(item_type) * (end - begin + 1));
    if (NULL == pBuf)
        return -1;
    merge_sort_<item_type>(pItem, begin, end, pBuf, pfCompare);
    free(pBuf);
    return 0;
}
