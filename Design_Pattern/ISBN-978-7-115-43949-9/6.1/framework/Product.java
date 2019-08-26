package framework;

public abstract class Product implements Cloneable {
    public abstract void use(String info);

    public Product creatClone() {
        Product p = null;
        try {
            p = (Product)this.clone();
        } catch (CloneNotSupportedException e) {
            System.out.print(e);
        }
        return p;
    }
}