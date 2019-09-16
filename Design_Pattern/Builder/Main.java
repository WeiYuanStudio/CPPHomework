import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        if(args.length != 1) {
            usage();
            System.exit(0);
        } else {
            if(args[0].equals("Plain")) {
                TextBuilder plainBuilder = new TextBuilder();
                Director textDirector = new Director(plainBuilder);
                textDirector.construct();
                System.out.println(plainBuilder.getResult());
                textDirector.saveToFile("text.txt");
            }
            if(args[0].equals("HTML")) {
                HTMLBuilder htmlBuilder = new HTMLBuilder();
                Director textDirector = new Director(htmlBuilder);
                textDirector.construct();
                System.out.println(htmlBuilder.getResult());
                textDirector.saveToFile("index.html");
            }
        }
    }
    private static void usage() {
        System.out.println("Please Input Parameter");
        System.out.println("Use Plain Or HTML");
    }
}