class Solution {

    public boolean canFinish(int numc, int[][] prereq) {
        List<List<Integer>> li = new ArrayList<>();
        int degree[] = new int[numc];
        List<Integer> bfs = new ArrayList<>();

        for(int i=0;i<numc;i++){
            li.add(new ArrayList<>());
        }

        for(int i=0;i<prereq.length;i++){
            degree[prereq[i][0]]++;
            li.get(prereq[i][1]).add(prereq[i][0]);
        }

        for(int i=0;i<numc;i++){
            if(degree[i]==0){bfs.add(i);}
        }

        for(int i=0;i<bfs.size();i++){
            int ind = bfs.get(i);
            for(int num: li.get(ind)){
                degree[num]--;
                if(degree[num]==0){bfs.add(num);}
            }
        }
        return bfs.size()==numc;
    }
}