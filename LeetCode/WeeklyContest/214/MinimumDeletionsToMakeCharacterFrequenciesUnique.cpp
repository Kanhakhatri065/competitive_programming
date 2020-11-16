class Solution {
public:
    int minDeletions(string s) {
		map<char, int> mp;
		for(char c : s) {
			mp[c]++;
		}		

		int N = 1e5 + 5;
		int dp[N];
		memset(dp, 0, sizeof(dp));
		for(auto it : mp) {
			dp[it.second]++;
		}
		
		int cnt = 0;
		for(int i = 100000;i >= 1;i--) {
			if(dp[i] > 1) {
				dp[i - 1] += dp[i] - 1;
				cnt += dp[i] - 1;
			}
		}

		return cnt;
    }
};

