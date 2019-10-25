import java.sql.SQLException;

interface DAO {
    abstract public int insertBook(BookBean book) throws SQLException;
    abstract public BookBean getBook(int id) throws SQLException;
    abstract public void deleteBook(int id) throws SQLException;
}
