class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {

        int n = tickets.length;

        Queue<Integer> que = new LinkedList<>();

        for(int i = 0; i<n; i++){
            que.offer(i);
        }

        int countSeconds = 0;

        while(!que.isEmpty()){

            int topIdx = que.poll();
            tickets[topIdx]--;
            countSeconds++;

            if(tickets[topIdx] != 0) que.offer(topIdx);
            else if(topIdx == k) return countSeconds;
        }


        return -1;        
    }
}