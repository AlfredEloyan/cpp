long repeatedString(string s, long n) {
    long count = 0;
    long repetitions = n / s.length();
      for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a') {
            count++;
        }
      }
      count = count * repetitions;
      for(int i = 0; i < n % s.length(); i++) {
        if(s[i] == 'a') {
            count++;
        }
      }
      return count;
}
