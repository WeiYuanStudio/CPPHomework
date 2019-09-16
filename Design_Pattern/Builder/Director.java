import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

public class Director {
    private Builder builder;

    public Director(Builder builder) {
        this.builder = builder;
    }

    public void construct() {
        builder.makeTitle("Hello World! Hello Java!");
        builder.makeString("This Page construct By Java");
        builder.makeItems(new String[] {
            "VSCode",
            "Sublime-Text",
            "Atom",
            "Notepad++"
        });
    }

    public void saveToFile(String fileName) throws IOException {
        System.out.println("HI");
        PrintWriter out = null;
        try {
            out = new PrintWriter(new File(fileName));
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.println(builder.getResult());
        out.flush();
        out.close();
    }
}