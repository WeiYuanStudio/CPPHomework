import java.util.Iterator;

public class BookShelf implements Aggregate{
    private Book[] books;
    private int last = -1 ; //Index of the last book
    
    /**
     * Set max num of BookShelf
     * @param maxsize
     */
    public BookShelf(int maxsize){
        books = new Book[maxsize];
    }

    /**
     * Return book by index
     * @param index
     * @return Book on index
     */
    public Book getBookAt(int index){
    	return books[index];
    }

    /**
     * Append a new book
     * @param Book
     */
    public void appendBook(Book newbook){
	last++;
	books[last] = newbook;
    }

    /**
     * Get Length of BookShelf
     */
    public int getLength() {
        return last + 1;
    }

    @Override
    public Iterator iterator() {
        return new BookShelfIterator(this);
    }
}
