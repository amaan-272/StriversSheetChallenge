//CodeStudio
int minCharsforPalindrome(string str) {
	int ans {}, low {}, high = str.size()-1, posn {high};
	while(low < high) {
		if(str[low] == str[high]) {
			low++;
			high--;
		}
		else {
			ans++;
			low = 0;
			high = --posn;
		}
	}
	return ans;
}
