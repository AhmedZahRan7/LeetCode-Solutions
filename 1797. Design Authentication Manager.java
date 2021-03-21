class AuthenticationManager {
    int liveTime;
    HashMap<String,Integer> map;
    public AuthenticationManager(int timeToLive) {
        liveTime = timeToLive;
        map = new HashMap<String,Integer>();
    }
    public void generate(String tokenId, int currentTime) {
        map.put(tokenId, currentTime+liveTime);   
    }
    
    public void renew(String tokenId, int currentTime) {
        if(!map.containsKey(tokenId)) return;
        if(map.get(tokenId)<=currentTime) return;
        map.put(tokenId, currentTime+liveTime);
    }
    
    public int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(Integer i : map.values()){
            if(i>currentTime) count++;
        }
        return count;
    }
}