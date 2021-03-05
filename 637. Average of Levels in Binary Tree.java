   class Solution {
       public List<Double> averageOfLevels(TreeNode root) {
           Queue<TreeNode> queue = new LinkedList<>();
           List<Double> list = new ArrayList<>();
           queue.add(root);
           while(queue.size()>0){
               int levelSize = queue.size();
               long accumelator = 0;
               for(int i=0;i<levelSize;i++){
                   TreeNode peek = queue.peek();
                   accumelator+=peek.val;
                   if(peek.left!=null) queue.add(peek.left);
                   if(peek.right!=null) queue.add(peek.right);
                   queue.poll();
               }
               list.add((double)accumelator/levelSize);
           }
           return list;
       }
   }