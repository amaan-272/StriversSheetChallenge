//CodeStudio Code
bool valid(vector<int> positions, int n, int c, int dist) {
    int pos {positions[0]}, cnt {1};
	for(int i:positions) {
		if(i-pos >= dist) {
			cnt++;
			pos = i;
		}
		if(cnt == c) return true;
	}
    return false;
}

int chessTournament(vector<int> positions, int n, int c) {
    sort(begin(positions), end(positions));
    int low {1}, high {positions[n-1]-positions[0]}, ans {};
    while(low <= high) {
        int mid {low+(high-low)/2};
        if(valid(positions, n, c, mid)) {
            ans = mid;
            low = mid+1;
        } 
		else high = mid-1;
    }
    return ans;
}
