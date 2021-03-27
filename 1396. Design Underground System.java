class Passenger{
    private Integer id;
    private String startStation;
    private Integer timeArrived;
    Passenger(Integer id,String startStation,Integer timeArrived){
        this.timeArrived = timeArrived;
        this.id = id;
        this.startStation = startStation;
    }
    public Integer getId() {
        return id;
    }
    public String getStartStation() {
        return startStation;
    }
    public Integer getTimeArrived() {
        return timeArrived;
    }
}
class Road{
    private String from,to;
    private Integer numOfTravels;
    private double averageTime;
    public Road(String from, String to) {
        this.from = from;
        this.to = to;
        this.numOfTravels = 0;
        this.averageTime = 0;
    }
    public String getFrom() {
        return from;
    }
    public String getTo() {
        return to;
    }
    public Integer getNumOfTravels() {
        return numOfTravels;
    }
    public void addTravel(double averageTime) {
        //x/n
        //x+t/n+1
        this.averageTime = ((this.averageTime*this.numOfTravels)+averageTime)/(numOfTravels+1);
        this.numOfTravels++;
    }
    public double getAverageTime() {
        return averageTime;
    }
}
class Network{
    private Map<String,Map<String,Road>> map;
    public Network() {
        this.map = new HashMap<String,Map<String,Road>>();
    }
    private void addRoad(String startStation, String endStation){
        if(!map.containsKey(startStation)) map.put(startStation,new HashMap<>());
        if(!map.containsKey(endStation)) map.put(endStation,new HashMap<>());
        if(!map.get(startStation).containsKey(endStation)) map.get(startStation).put(endStation,new Road(startStation,endStation));
        if(!map.get(endStation).containsKey(startStation)) map.get(endStation).put(startStation,new Road(startStation,endStation));
    }
    public Road getRoad(String startStation, String endStation){
        addRoad(startStation, endStation);
        return map.get(startStation).get(endStation);
    }
}
class UndergroundSystem {
    private Map<Integer,Passenger> currentPassengers;
    private Network network;
    public UndergroundSystem() {
        currentPassengers = new HashMap<Integer,Passenger>();
        network = new Network();
    }
    
    public void checkIn(int id, String stationName, int t) {
        if(currentPassengers.containsKey(id)) return;
        currentPassengers.put(id, new Passenger(id, stationName, t));
    }
    
    public void checkOut(int id, String stationName, int t) {
        Passenger outPassenger = currentPassengers.get(id);
        currentPassengers.remove(id);
        Road road1 = network.getRoad(outPassenger.getStartStation(),stationName);
        Road road2 = network.getRoad(stationName,outPassenger.getStartStation());
        road1.addTravel(t-outPassenger.getTimeArrived());
        road2.addTravel(t-outPassenger.getTimeArrived());
    }
    
    public double getAverageTime(String startStation, String endStation) {
        return network.getRoad(startStation, endStation).getAverageTime();
    }
}
