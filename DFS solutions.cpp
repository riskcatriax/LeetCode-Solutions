public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> list = new LinkedList<>();
        backtrack(nums,list,new LinkedList<Integer>(),0);
        return list;
    }
    private void backtrack(int[]nums,List<List<Integer>> list, List<Integer>tempList,int level){
        list.add(new LinkedList<>(tempList));
        for(int i = level;i<nums.length;i++){
            if(i!= level && i>0 && nums[i] == nums[i-1]) continue;
            tempList.add(nums[i]);
            backtrack(nums,list,tempList,i+1);
            tempList.remove(tempList.size()-1);
        }
    }
