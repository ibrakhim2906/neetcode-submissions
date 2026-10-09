class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int n = students.length;
        int res = n;
        
        int[] count = new int[2];

        for (int student : students) {
            count[student]++;
        }

        for (int sandwich : sandwiches) {
            if (count[sandwich]>0) {
                res--;
                count[sandwich]--;
            } else {
                break;
            }
        }

        return res;
    }
}