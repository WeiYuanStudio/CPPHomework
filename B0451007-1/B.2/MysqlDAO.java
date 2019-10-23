import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

class MysqlDAO implements DAO {

    //数据库操作
    private static final String tableName = "library";

    private static final String DROP_OLD_TABLE = "DROP TABLE IF EXISTS " + tableName;
    private static final String INSERT_NEW_BOOK = "INSERT INTO " + tableName + " VALUES(?, ?, ?, ?, ?, ?)";
    private static final String ID_QUERY_BOOK = "SELECT * FROM " + tableName + " WHERE id=?";
    private static final String ID_DELETE_BOOK = "DELETE FROM " + tableName + " WHERE id=?";

    private String sqlPath; //数据库路径
    private int port; //服务器端口
    private String db_name; //数据库名
    private String user;
    private String password;
    private Connection connection;

    /**
     * Load JDBC Driver and create new table
     */
    MysqlDAO(String sqlPath, int port, String db_name, String user, String password) throws SQLException, ClassNotFoundException {
        this.sqlPath = sqlPath; //设定数据库路径
        this.port = port;
        this.db_name = db_name;
        this.user = user;
        this.password = password;
        sqlLoad();
    }

    /**
     * 通过SQLPropertiesLoader实例化对象
     * @param loader
     * @throws SQLException
     * @throws ClassNotFoundException
     */
    MysqlDAO(SQLPropertyLoader loader) throws SQLException, ClassNotFoundException {
        this.sqlPath = loader.getSQLPath();
        this.port = loader.getPort();
        this.db_name = loader.getDataBaseName();
        this.user = loader.getUser();
        this.password = loader.getPassword();

        sqlLoad();
    }

    /**
     * Insert new book into database
     */
    @Override
    public int insertBook(BookBean book) throws SQLException {
        //TODO: Check if id illegal
        Connection connection = getConnection(sqlPath);

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
     * Get book by id
     * 
     * @param id Book id
     * @return BookBean
     */
    @Override
    public BookBean getBook(int id) throws SQLException {
        Connection connection = getConnection(sqlPath);

        PreparedStatement ps = connection.prepareStatement(ID_QUERY_BOOK);
        ps.setInt(1, id);
        ResultSet set = ps.executeQuery();
        BookBean book = null;
        if(set.next()) {
            book = new BookBean(
                id,
                set.getString("full_title"),
                set.getString("isbn"),
                set.getString("publisher"),
                set.getString("author"),
                set.getInt("publish_year")
            );
        }
        return book;
    }

    @Override
    public void deleteBook(int id) throws SQLException {
        Connection connection = getConnection(sqlPath);

        PreparedStatement ps = connection.prepareStatement(ID_DELETE_BOOK);
        ps.setInt(1, id);
        ps.executeUpdate();
    }

    /**
     * Create a empty table
     * @throws SQLException
     */
    private void createEmptyTable() throws SQLException {
        Connection connection = getConnection(sqlPath);

        Statement statement = connection.createStatement();

        statement.execute(DROP_OLD_TABLE);

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
     * @param sqlPath
     * @return connection
     */
    private Connection getConnection(String sqlPath) throws SQLException {
        System.out.println("jdbc:mysql://" + sqlPath
                + ":" + port
                + "/" + db_name + user + password); //TODO: Println for test
        if(connection == null) {
            connection = DriverManager.getConnection(
                "jdbc:mysql://" + sqlPath
                + ":" + port
                + "/" + db_name,
                user,
                password
            ); //建立数据库连接;
        }
        return connection;
    }

    /**
     * 初始化驱动，新建数据库表
     * @throws ClassNotFoundException
     * @throws SQLException
     */
    private void sqlLoad() throws ClassNotFoundException, SQLException {
        //加载sql驱动
        Class.forName("com.mysql.jdbc.Driver"); //使用forClass加载sqlite-JDBC驱动
        System.out.println("Load MySQL JDBC driver success");

        createEmptyTable();
    }
}
