vector<int> temp(1e7 + 5);
long merge(vector<int> &arr, int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;
    long inv_count = 0;
    while (i <= mid && j <= right){
        if (arr[i] <= arr[j]){
            temp[k++] = arr[i];
            i++;
        }
        else{
            temp[k++] = arr[j];
            j++;
            inv_count += mid - i + 1;
        }
    }
    while (i <= mid){
        temp[k++] = arr[i++];
    }
    while (j <= right){
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++){
        arr[i] = temp[i];
    }
    return inv_count;
}

long solve(vector<int> &arr, int left, int right){
    if (left >= right){
        return 0;
    }
    int mid = (left + right) / 2;
    long inv_count = 0;
    inv_count = solve(arr, left, mid);
    inv_count += solve(arr, mid + 1, right);
    inv_count += merge(arr, left, mid, right);
    return inv_count;
}

long countInversions(vector<int> arr) {
    vector<int> temp(arr.size());
    return solve(arr, 0, arr.size() - 1);
}

