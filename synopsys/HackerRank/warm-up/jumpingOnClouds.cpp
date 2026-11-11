int jumpingOnClouds(vector<int> c) {
    int count = 0;
    int i = 0;
    while (i < c.size() - 1){
        if (i+2 < c.size()){
            if (c[i+2] == 1) i=i+1, count++;
            else  i=i+2, count++;
        }
        else i=i+2, count++;
    }
    return count;
}
