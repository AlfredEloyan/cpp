int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> count;
    int pairs = 0;
    for(int i = 0; i < n; i++){
        count[ar[i]]++;
        if (count[ar[i]] % 2 == 0) pairs++;
    }
    return pairs;
}
