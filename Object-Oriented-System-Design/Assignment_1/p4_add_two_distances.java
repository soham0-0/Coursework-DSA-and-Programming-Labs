public class p4_add_two_distances {
    public static void main(String[] args) {
        Distance d1 = new Distance(10), d2 = new  Distance(14.2), dTotal = d1.add(d2);
        System.out.println("Total Distance = " + dTotal.value);
    }
}

class Distance {
    double value;
    Distance(double value) {
        this.value = value;
    }
    Distance add(Distance d){
        return new Distance(this.value + d.value);
    } 
}