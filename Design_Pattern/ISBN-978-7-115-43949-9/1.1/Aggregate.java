import java.util.Iterator;

public interface Aggregate {
    /**
     * 该方法生成一个用于遍历集合的迭代器
     * @return Iterator
     */
    public abstract Iterator iterator();
}
