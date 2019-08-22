package framework;

public interface Product extends Cloneable {
    public abstract void use(String info);
    public abstract Product creatClone();
}