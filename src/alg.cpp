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
        else {
            break;
        }
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j <= k; j++)
            if (arr[i] + arr[j] == value) 
                count++;
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int begin = 0, end = len, m, i, count = 0;
    while (begin < end) {
        m = (begin + end) / 2;
        i = 0;
        if (arr[begin] + arr[m] > value) {
            end = m - 1;
            break;
        }
        else {
            i = begin+1;
            while (arr[begin] + arr[i] <= value) {
                if (arr[begin] + arr[i] == value) count++;
                i++;
            }
        }
        begin++;
        end = i;
    }
    return count;
}
