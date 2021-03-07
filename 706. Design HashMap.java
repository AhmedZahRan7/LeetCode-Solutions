class Element{
    private int key,val;
    Element(){

    }
    Element(int key,int val){
        this.key=key;
        this.val=val;
    }
    public int getKey() {
        return key;
    }
    public int getVal() {
        return val;
    }
    public void setVal(int val) {
        this.val = val;
    }
}
class MyHashMap {

    private int prime = 3499;
    private List<LinkedList<Element>> list;
    private int hashFunction(int x){
        return x%prime;
    }

    public MyHashMap() {
        list = new ArrayList<LinkedList<Element>>(Collections.nCopies(prime, new LinkedList<Element>()));
    }
    
    private Element getElement(int key){
        LinkedList<Element> linkedList = list.get(hashFunction(key));
        for(Element e : linkedList) if(key==e.getKey()) return e;
        return null;
    }

    /** value will always be non-negative. */
    public void put(int key, int value) {
        Element e = getElement(key);
        if(e==null) list.get(hashFunction(key)).add(new Element(key,value));
        else e.setVal(value);
    }

    
    public int get(int key) {
        Element e = getElement(key);
        if(e==null) return -1;
        else return e.getVal();
    }
    

    public void remove(int key) {
        Element e = getElement(key);
        if(e==null) return;
        else list.get(hashFunction(key)).remove(e);
    }
}