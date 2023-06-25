//CodeStudio Code
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
	vector<int> freq(n+1, 0);
	for(int i:arr) freq[i]++;
	freq[0] = 1;
	int missed, repeated;
	for(int i {}; i < n+1; i++) {
		if(!freq[i]) {
			missed = i;
			break;
		}
	} 
	for(int i {}; i < n+1; i++) {
		if(freq[i] == 2) {
			repeated = i;
			break;
		}
	} 
	return {missed, repeated};
}
