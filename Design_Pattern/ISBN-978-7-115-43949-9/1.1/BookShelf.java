import java.util.Iterator;
import java.util.ArrayList;

public class BookShelf implements Aggregate{
    private ArrayList<Book> bookList;
    private int last = -1 ; //Index of the last book
    
    /**
     * Set max num of BookShelf
     * @param maxsize
     */
    public BookShelf(){
        //books = new Book[maxsize];	
    	bookList  = new ArrayList<Book>();
    }

    /**
     * Return book by index
     * @param index
     * @return Book on index
     */
    public Book getBookAt(int index){
    	//return books[index];
	return bookList.get(index);
    }

    /**
     * Append a new book
     * @param Book
     */
    public void appendBook(Book newBook){
	last++;
	//books[last] = newbook;
	bookList.add(newBook);
    }

    /**
     * Get Length of BookShelf
     */
    public int getLength() {
        //return last + 1;
	return bookList.size();
    }

    @Override
    public Iterator iterator() {
        return new BookShelfIterator(this);
    }
}
