class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        Map<Integer, Integer> studentsMap = new HashMap<>();
        for (int student : students) {
            studentsMap.put(student, studentsMap.getOrDefault(student, 0)+1);
        }

        int count = 0;

        for (int sandwich : sandwiches) {
            if (studentsMap.getOrDefault(sandwich, 0).equals(0)) {
                break;
            }
            studentsMap.put(sandwich, studentsMap.get(sandwich)-1);
            count++;
        }

        return students.length-count;
    }
}