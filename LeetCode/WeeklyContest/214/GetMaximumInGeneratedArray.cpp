class Solution {
public:
    int getMaximumGenerated(int n) {
		if(n == 0) {
			return 0;
		}

		int nums[n + 1];
		nums[0] = 0;
		nums[1] = 1;
		for(int i = 2;i <= n;i++) {
			if(i & 1) {
				int p = i -1;
				p /= 2;
				nums[i] = nums[p] + nums[p + 1];
			} else {
				int p = i;
				p /= 2;
				nums[i] = nums[p];
			}
		}

		int mx = 0;
		for(int i = 0;i <= n;i++) {
			if(mx < nums[i]) {
				mx = nums[i];
			}
		}		

		return mx;
    }
};

