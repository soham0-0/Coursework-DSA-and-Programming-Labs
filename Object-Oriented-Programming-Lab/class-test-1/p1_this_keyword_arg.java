public class p1_this_keyword_arg {
    String state = "printing this state";
    void method(p1_this_keyword_arg obj) {
        System.out.println(obj.state);
    }
    void testMethod() {
        method(this);
    }
    public static void main(String[] args) {
        p1_this_keyword_arg t = new p1_this_keyword_arg();
        t.testMethod(); 
    }
}