import java.util.Iterator;

public class main {
	public static void main(String[] args) {
		BookShelf myBookShelf = new BookShelf(4);

		myBookShelf.appendBook(new Book("No Game, No Life"));
		myBookShelf.appendBook(new Book("君の名は"));
        myBookShelf.appendBook(new Book("天気の子"));
        myBookShelf.appendBook(new Book("Thinking In Java"));

        System.out.println("The Length Of BookShelf: "  + myBookShelf.getLength());

        Iterator it = myBookShelf.iterator();
        while(it.hasNext()) {
        	Book nowBook = (Book) it.next();
        	System.out.println(nowBook.getName());
        }
	}
}