import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

class LibraryDAO {

    //数据库操作
    private static final String tableName = "library";

    private static final String CHECK_TABLE_SQL = "SELECT name FROM sqlite_master WHERE type='table' AND name=?";
    private static final String INSERT_NEW_BOOK = "INSERT INTO " + tableName + " VALUES(?, ?, ?, ?, ?, ?)";

    private String sqlitePath; //数据库文件路径
    private Connection connection;

    /**
     * Load JDBC Driver and create new table
     */
    LibraryDAO(String sqlitePath) throws SQLException, ClassNotFoundException {
        this.sqlitePath = sqlitePath; //设定数据库路径

        //加载sqlite驱动
        Class.forName("org.sqlite.JDBC"); //使用forClass加载sqlite-JDBC驱动
        System.out.println("Load sqlite JDBC driver success");


        //检查数据库是否已经建表
        boolean tableStatus = checkTable(tableName);
        System.out.println("Check if TABLE <" + tableName + "> exsist");
        if(!tableStatus) {
            System.out.println("TABLE <" + tableName + "> not found, Create TABLE");
            createEmptyTable();
        } else {
            System.out.println("TABLE <" + tableName + "> found");
        }
    }

    /**
     * Insert new book into database
     */
    int insertBook(BookBean book) throws SQLException {
        //TODO: Check if id illegal
        Connection connection = getConnection(sqlitePath);

        PreparedStatement ps = connection.prepareStatement(INSERT_NEW_BOOK);
        ps.setInt(1, book.getId());
        ps.setString(2, book.getTitle());
        ps.setString(3, book.getIsbn());
        ps.setString(4, book.getPublisher());
        ps.setString(5, book.getAuthor());
        ps.setInt(6, book.getPublishYear());
        ps.executeUpdate();
        ps.close();
        return book.getId();
    }

    /**
     * Check table "library" exsist
     * 
     * @param tableName
     * @return If table exsist
     */
    private boolean checkTable(String tableName) throws SQLException {
        Connection connection = getConnection(sqlitePath); //获取数据库连接

        PreparedStatement ps = connection.prepareStatement(CHECK_TABLE_SQL); //设定查询语句模板
        ps.setString(1, tableName); //设定查询参数
        ResultSet set = ps.executeQuery(); //执行查询

        if(set.next()) //查询结果判空
            return true;
        return false;
    }

    private void createEmptyTable() throws SQLException {
        Connection connection = getConnection(sqlitePath);

        Statement statement = connection.createStatement();
        statement.execute(
            "CREATE TABLE library("
            + "id INTEGER PRIMARY KEY,"
            + "full_title TEXT,"
            + "isbn TEXT,"
            + "publisher TEXT,"
            + "author TEXT,"
            + "publish_year INTEGER"
            + ")"
        );
    }

    /**
     * Get connection
     * 
     * @param sqlitePath
     * @return connection
     */
    private Connection getConnection(String sqlitePath) throws SQLException {
        if(connection == null) {
            connection = DriverManager.getConnection("jdbc:sqlite:".concat(sqlitePath)); //建立数据库连接;
        }
        return connection;
    }
}