void minimumBribes(vector<int> q) {
    int bribes = 0;
    int n = q.size();
    
    for (int i = n - 1; i >= 0; --i) {
        if ((q[i] - 1) - i > 2) {
            cout << "Too chaotic \n";
            return;
        }
        
        for (int j = max(0, q[i] - 2); j < i; ++j) {
            if (q[j] > q[i]) {
                bribes++;
            }
        }
    }
    
    cout << bribes << endl;
}
