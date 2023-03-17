// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (arr[i] + arr[j] == value)
                count++;
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0, k = 0;
    for (int i = 1; i < len; i++)
        if (arr[0] + arr[i] <= value) k++;
        else
            break;
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j <= k; j++)
            if (arr[i] + arr[j] == value)
                count++;
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0, m = 0, l = 0;
    for (int i = 0; i < len-1; i++) {
        int begin = i+1, end = len - 1;
        while (begin < end) {
            m = (begin + end) / 2;
            if (arr[m] + arr[i] > value)
                end = m;
            if (arr[m] + arr[i] < value)
                begin = m + 1;
            if (arr[m] + arr[i] == value) {
                l = m;
                while ((m <= end) && (arr[m] + arr[i] == value)) {
                    count++;
                    m++;
                }
                end = l-1;
            }
        }
        if ((begin == end) && (arr[i] + arr[begin] == value)) count++;
    }
    return count;
}
