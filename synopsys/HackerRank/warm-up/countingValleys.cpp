int countingValleys(int steps, string path) {
    int count = 0;
    int level = 0;
    for(int i = 0; i < steps; i++){
        if(path[i] == 'D') level--;
        else level++;
        if (level == 0 && path[i] == 'U') count++;
    }
    return count;
}
