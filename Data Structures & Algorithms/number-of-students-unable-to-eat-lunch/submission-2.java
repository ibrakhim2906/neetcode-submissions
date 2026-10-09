class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int n = students.length;
        int res = n;
        
        int[] count = new int[2];

        for (int student : students) {
            count[student]++;
        }

        for (int i = 0; i<n; i++) {
            if (count[sandwiches[i]]>0) {
                res--;
                count[sandwiches[i]]--;
            } else {
                break;
            }
        }

        return res;
    }
}