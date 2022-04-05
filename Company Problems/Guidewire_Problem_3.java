public class Main{
    public static int solution(int A[],String D[]) {
        int amount=0;
        int cnt[]=new int[13];//keeps track of total number of transaction in a month
        int transaction[]=new int[13];//keeps track of the amount of transaction in a month
        for(int i=0;i<A.length;i++) {
            amount+=A[i];
            String d[]=D[i].split("-");
            int m=Integer.parseInt(d[1]);
            if(A[i]<0) {
                transaction[m]+=Math.abs(A[i]);
                cnt[m]=cnt[m]+1;
            }
        }
        
        for(int i=1;i<13;i++) {
            if(cnt[i]>=3 && transaction[i]>=100) {
                continue;
            }else {
                amount-=5;
            }
        }
        return amount;
    }

    public static void main(String[] args) {
        int A[]= {1,-1, 0,-105, 1};
        String D[]= {"2020-12-31","2020-04-04","2020-04-04","2020-04-14", "2020-07-04"};
        int amount=solution(A, D);
        System.out.println(amount);
    }
}