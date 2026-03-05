import java.util.*;

public class CoreProcessor {

    private List<Integer> buffer = new ArrayList<>();
    private Random random = new Random();

    public CoreProcessor() {
        for(int i=0;i<500;i++){
            buffer.add(random.nextInt(10000));
        }
    }

    public int process(){
        int sum = 0;
        for(int v : buffer){
            sum += transform(v);
        }
        return sum;
    }

    private int transform(int x){
        int r = x;
        for(int i=0;i<20;i++){
            r = (r * 31 + i) ^ (r >> 2);
            r = Math.abs(r % 100000);
        }
        return r;
    }

    public void shuffle(){
        Collections.shuffle(buffer);
    }

    public void expand(){
        List<Integer> tmp = new ArrayList<>();
        for(int v : buffer){
            tmp.add(transform(v));
            tmp.add(v ^ random.nextInt());
        }
        buffer.addAll(tmp);
    }
}