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
void insert_sort(item_type *pItem, int n,
        int (*pfCompare)(item_type a, item_type b) = compare<item_type>) {
    for (int i = 1; i < n; ++i) {
        item_type key = pItem[i];
        int j;
        for (j = i - 1; j >= 0 && pfCompare(pItem[j], key) > 0; --j) {
            pItem[j + 1] = pItem[j];
        }
        pItem[j + 1] = key;
    }
}
