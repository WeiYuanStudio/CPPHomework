import framework.*;

public class Main {
    public static void main(String[] args) {
        Manager manager = new Manager();

        Product underLinePen = new UnderLinePen('-');
        Product messageBox = new MessageBox('*');

        manager.register("ulLine", underLinePen);
        manager.register("mb", messageBox);

        Product p1 = manager.creat("ulLine");
        p1.use("Hello World");

        Product p2 = manager.creat("mb");
        p2.use("Hello World");
    }
}