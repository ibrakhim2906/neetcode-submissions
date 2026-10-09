class NumMatrix {

    ArrayList<ArrayList<Integer>> perRowPrefixSum;

    public NumMatrix(int[][] matrix) {
        perRowPrefixSum = new ArrayList<>();

        for (int r=0; r<matrix.length; r++) {
            perRowPrefixSum.add(new ArrayList<>());
            int totalPerRow=0;
            for (int c=0; c<matrix[0].length; c++) {
                totalPerRow+=matrix[r][c];
                perRowPrefixSum.get(r).add(totalPerRow);
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1>row2 || col1>col2) {
            return -1;
        }    

        int totalSum = 0;
        
        for (int r=row1; r<=row2; r++) {
            ArrayList<Integer> rowPrefixSum = perRowPrefixSum.get(r);
            totalSum+= col1>0 ? rowPrefixSum.get(col2) - rowPrefixSum.get(col1-1) : rowPrefixSum.get(col2);
        }

        return totalSum;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */