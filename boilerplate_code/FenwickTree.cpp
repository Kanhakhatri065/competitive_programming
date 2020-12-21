struct FenwickTree {
    //use 0-index while passing argument for range function
    vector<int> bit_tree;

    int get(int index) {
        int ans = 0;
        index++;

        while(index > 0) {
            ans ^= bit_tree[index];
            index -= index & (-index);
        }

        return ans;
    }

public:
    void update(int index, int val) {
        index++;
        while(index < sz(bit_tree)) {
            bit_tree[index] ^= val;
            index += index & (-index);
        }
    }

    FenwickTree(vector<int> arr, int n) {
        bit_tree.assign(n + 1, 0);

        for(int i = 0;i < n;i++) {
            update(i, arr[i]);
        }
    }

    int range(int l, int r) {
        return get(r) ^ get(l - 1);
    }
};

