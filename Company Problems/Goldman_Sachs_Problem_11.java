// Name - Process Scheduling

public static int minimumTime(List<Integer> ability, long processes) {
    // Write your code here
    int count=0;
    PriorityQueue<Integer> pq= new PriorityQueue<Integer>((i1, i2) -> {
        return i2-i1;
    });
    for(int abi:ability){
        pq.offer(abi);
    }
    while(processes>0){
        int abi=pq.poll();
        processes-=abi;
        pq.offer(abi/2);
        count++;
    }
    return count;
    }
}