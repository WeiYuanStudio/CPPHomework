package framework;
import java.util.*;

public class Manager {
    private HashMap showcase = new HashMap();
    public void register(String name, Product product) {
        showcase.put(name, product);
    }

    public Product creat(String productName) {
        Product product = (Product)showcase.get(productName);
        return product.creatClone();
    }
}