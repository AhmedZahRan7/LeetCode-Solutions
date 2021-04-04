class MyCircularQueue {
    private ArrayList<Integer> arrayList;
    private ArrayList<Boolean> token;
    private int enqueuePointer = 0;
    private int dequeuePointer = 0;
    private int k = 0;
    public MyCircularQueue(int k) {
        arrayList = new ArrayList<> (Collections.nCopies(k, 0));
        token = new ArrayList<> (Collections.nCopies(k, false));
        this.k = k;
    }
    
    public boolean enQueue(int value) {
        if(isFull()) return false;
        token.set(enqueuePointer,true);
        enqueuePointer ++;
        enqueuePointer %= k;
        arrayList.set(enqueuePointer, value);
        return true;
    }
    
    public boolean deQueue() {
        if(isEmpty()) return false;
        token.set(dequeuePointer,false);
        dequeuePointer ++;
        dequeuePointer %= k;
        return true;
    }
    
    public int Front() {
        if(isEmpty()) return -1;
        return arrayList.get((dequeuePointer+1)%k);
    }
    
    public int Rear() {
        if(isEmpty()) return -1;
        return arrayList.get(enqueuePointer);
    }
    
    public boolean isEmpty() {
        return (enqueuePointer == dequeuePointer && !token.get(enqueuePointer));
    }
    
    public boolean isFull() {
        return (enqueuePointer == dequeuePointer && token.get(enqueuePointer));
    }
}
