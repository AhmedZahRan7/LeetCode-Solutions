public class Codec {
    private String myDomain = "MyDomain/";
    private int numOfChacatersInDomain = 7;
    private ArrayList<Character> possibleChars;
    private int numOfPossibleChars;
    private HashMap<String,String> map;
    Codec(){
        map = new HashMap<>();
        possibleChars = new ArrayList<Character>();
        for(int i=0;i<=9;i++) possibleChars.add(Integer.toString(i).charAt(0));
        for(char c='a';c<='z';c++) possibleChars.add(c);
        for(char c='A';c<='Z';c++) possibleChars.add(c);
        numOfPossibleChars = possibleChars.size();
    }
    private String getRandomString(){
        String str = "";
        Random random = new Random();
        for(int i=0;i<7;i++){
            int randIdx = random.nextInt(numOfPossibleChars);
            str = str.concat(possibleChars.get(randIdx).toString());
        }
        return str;
    }
    public String encode(String longUrl) {
        String str = getRandomString();
        while(map.containsKey(str)) str = getRandomString();
        map.put(str, longUrl);
        return myDomain.concat(str);
    }

    public String decode(String shortUrl) {
        if (shortUrl.substring(0,myDomain.length()).compareTo(myDomain)!=0) return null;
        String key = shortUrl.substring(myDomain.length());
        if(!map.containsKey(key)) return null;
        return map.get(key);
    }
}