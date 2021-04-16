public class NestedIterator implements Iterator<Integer> {
    private ArrayList<Integer> list = new ArrayList<>();
    private int pointer = 0;
    private void initializeList(List<NestedInteger> nestedList){
        for(NestedInteger nested : nestedList){
            if(nested.isInteger()) list.add(nested.getInteger());
            else initializeList(nested.getList());
        }
    }
    public NestedIterator(List<NestedInteger> nestedList) {
        initializeList(nestedList);
    }

    @Override
    public Integer next() {
        if(!hasNext()) return null;
        return list.get(pointer++);
    }

    @Override
    public boolean hasNext() {
        return pointer < list.size();
    }
}