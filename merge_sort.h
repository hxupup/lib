#include <stdlib.h>
#include <string.h>

template <typename item_type>
void merge(item_type *pItem, int begin, int middle, int end, item_type *pBuf) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (k < (end - middle) && j < (middle - begin + 1)) {
        if (pItem[begin + j] < pItem[middle + 1 + k]) {
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
void merge_sort_(item_type *pItem, int begin, int end, item_type *pBuf) {    
    if (begin < end) {
        int middle = (begin + end) / 2;
        merge_sort_<item_type>(pItem, begin, middle, pBuf);
        merge_sort_<item_type>(pItem, middle + 1, end, pBuf);
        merge<item_type>(pItem, begin, middle, end, pBuf);
    }
}

template <typename item_type>
int merge_sort(item_type *pItem, int begin, int end) {
    item_type *pBuf = (item_type *)malloc(sizeof(item_type) * (end - begin + 1));
    if (NULL == pBuf)
        return -1;
    merge_sort_<item_type>(pItem, begin, end, pBuf);
    free(pBuf);
    return 0;
}
