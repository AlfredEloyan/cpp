long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<int> arr (n,0);
    for(size_t i = 0; i < queries.size(); i++){
        for(size_t j = queries[i][0] ; j <= queries[i][1]; j++ ){
            arr[j] += queries[i][2];
        }
    }
    long max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}
