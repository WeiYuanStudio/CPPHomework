import java.sql.SQLException;

class Main {
    public static void main(String[] args) throws Exception {
        LibraryDAO library = new LibraryDAO("library.db");
        BookBean book = new BookBean(
            1,
            "Thinking In Java",
            "9783827268969",
            "Markt + Technik Verlag",
            "Bruce Eckel",
            2005
        );
        library.insertBook(book);
        BookBean book2 = library.getBook(1);
        book2.printInfo();
    }
}