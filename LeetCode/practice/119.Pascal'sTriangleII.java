import java.util.*;

class Solution {
    public List<Integer> getRow(int rowIndex) {
        var ans = new ArrayList<Integer>();

        var temp = new ArrayList<Integer>();
        temp.add(1);

        if(rowIndex == 0) {
            return temp;
        }

        temp.add(1);

        if(rowIndex == 1) {
            return temp;
        }

        int index = 1;
        while(index < rowIndex) {
            index++;
            ans.clear();
            ans.add(1);
            for(int i = 1;i < temp.size();i++) {
                ans.add(temp.get(i - 1) + temp.get(i));
            }
            ans.add(1);
            temp = (ArrayList<Integer>)ans.clone();
        }

        return ans;
    }

    public static void main(String[] args) {
        var sol = new Solution();
        var ans = sol.getRow(3);  

        System.out.println(ans);
    }
}