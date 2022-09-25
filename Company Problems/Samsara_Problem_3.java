// Problem = Y Matrix
import java.util.*;

class Main {
    private static int sol(int[][] matrix) {
        // null case
        if (matrix == null || matrix.length == 0)
            return 0;

        // y map
        int[] yMap = new int[3];
        // remaining map
        int[] rMap = new int[3];
        int n = matrix.length;
        // go over all the matrix and create map
        // for y and r
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j && i < n / 2) {
                    yMap[matrix[i][j]]++;
                } else if (i + j == n - 1 && j > n / 2) {
                    yMap[matrix[i][j]]++;
                } else if (i >= n / 2 && j == n / 2) {
                    yMap[matrix[i][j]]++;
                } else {
                    rMap[matrix[i][j]]++;
                }
            }

        }

        // number of elements of the y
        int yNum = (n / 2) * 3 + 1;
        int rNum = n * n - yNum;
        int result = Integer.MAX_VALUE;
        // first check y
        int yMax = 0;
        int first = -1;
        for (int i = 0; i < 3; i++) {
            if (yMax <= yMap[i]) {
                yMax = yMap[i];
                first = i;
            }
        }
        // then check remaining
        int rMax = 0;
        int second = -1;
        for (int i = 0; i < 3; i++) {
            if (first != i && rMax <= rMap[i]) {
                rMax = rMap[i];
                second = i;
            }
        }
        result = Math.min(result, (yNum - yMap[first]) + (rNum - rMap[second]));

        // first check remaining
        second = -1;
        rMax = 0;
        for (int i = 0; i < 3; i++) {
            if (rMax <= rMap[i]) {
                rMax = rMap[i];
                second = i;
            }
        }

        yMax = 0;
        first = -1;
        for (int i = 0; i < 3; i++) {
            if (i != second && yMax <= yMap[i]) {
                yMax = yMap[i];
                first = i;
            }
        }
        result = Math.min(result, (yNum - yMap[first]) + (rNum - rMap[second]));
        return result;
    }

    public static void main(String[] args) {
        // int[][] matrix = new int[][] {
        // { 2, 0, 0, 0, 2, 1, 2 },
        // { 0, 2, 1, 0, 0, 2, 1 },
        // { 0, 0, 2, 0, 2, 1, 0 },
        // { 0, 0, 0, 2, 0, 0, 0 },
        // { 0, 0, 0, 2, 0, 1, 0 },
        // { 0, 0, 0, 2, 0, 0, 0 },
        // { 0, 0, 0, 2, 0, 0, 0 },

        // };
        int[][] matrix = new int[][] {
                { 2, 2, 2, 2, 2, 2, 2 },
                { 2, 2, 2, 2, 2, 2, 2 }, 
                { 2, 2, 2, 2, 2, 2, 2 },
                { 2, 2, 2, 2, 2, 2, 2 },
                { 2, 2, 2, 2, 2, 2, 2 },
                { 2, 2, 2, 2, 2, 2, 2 },
                { 2, 2, 2, 2, 2, 2, 2 },
        };
        int res = sol(matrix);
        System.out.println(res);
    }
}