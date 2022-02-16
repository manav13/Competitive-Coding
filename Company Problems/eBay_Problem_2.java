public static StringBuilder booleanDeqeue(int n, String op, StringBuilder sb) {
    if(op.equals("L")) {
        for(int i=0; i<sb.length(); i++) {
            if(sb.charAt(i) == '0'){
                sb.setCharAt(i, '1');
                break;
            }
        }
    }
    else {
        String nm = op.replaceAll("[^0-9]", "");
        sb.setCharAt(Integer, parseInt(nm), '0');
    }
    return sb;
}

String solution(int n, String[] operations) {
    String str = new String();
    for(int i=0; i<n; i++) {
        str+=0;
    }

    int m = operations.length;
    StringBuilder sb = new StringBuilder(str);
    StringBuilder sbCatch = new StringBuilder();

    for(int i=0; i<m; i++) {
        sbCatch = booleanDeqeue(n, operations[i], sb);
    }

    return sbCatch.toString();
}