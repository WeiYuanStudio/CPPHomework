public class Singleton {
    private static Singleton singleton = new Singleton();
    private Singleton() {
        System.out.println("New Singleton");
    }

    public static Singleton getInstance() {
        return singleton;
    }
}