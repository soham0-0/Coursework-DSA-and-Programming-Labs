public class p3_command_line_arg_search {
    public static void main(String args[]) {
        for(int i = 0; i < args.length; ++i) {
            if(args[i].charAt(0) < 'A' || args[i].charAt(0) > 'Z') {
                System.out.println("Error: \"" + args[i] + "\" does not begin with an uppercase letter.");
                System.exit(1);
            }
        }
        System.out.println("No Errors Found.");
    }
}
