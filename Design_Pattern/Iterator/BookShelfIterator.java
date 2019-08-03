import java.util.Iterator;

public class BookShelfIterator implements Iterator {
    private BookShelf bookShelf;
    private int index = 0;

    public BookShelfIterator(BookShelf bookShelf) {
        this.bookShelf = bookShelf;
    }

    public boolean hasNext() {
    	if (index < bookShelf.getLength()) {
    		return true;
    	} else {
    		return false;
    	}
    }

    public Book next() {
    	Book nowBook = bookShelf.getBookAt(index);
    	index++;
    	return nowBook;
    }
}