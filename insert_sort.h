template <typename item_type>
void insert_sort(item_type *pItem, int n) {
    for (int i = 1; i < n; ++i) {
        item_type key = pItem[i];
        int j;
        for (j = i - 1; j >= 0 && key < pItem[j]; --j) {
            pItem[j + 1] = pItem[j];
        }
        pItem[j + 1] = key;
    }
}
