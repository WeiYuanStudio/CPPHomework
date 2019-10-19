import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

class LibraryDAO {

    //数据库操作
    private static final String CHECK_TABLE_SQL = "SELECT name FROM sqlite_master WHERE type='table' AND name=?";


    private String sqlitePath; //数据库文件路径

    private static final String tableName = "library";
    /**
     * Load JDBC Driver and create new table
     */
    LibraryDAO(String sqlitePath) {
        this.sqlitePath = sqlitePath; //设定数据库路径

        //加载sqlite驱动
        try {
            Class.forName("org.sqlite.JDBC"); //使用forClass加载sqlite-JDBC驱动
            System.out.println("Load sqlite JDBC driver success");
        } catch(ClassNotFoundException e) {
            System.out.println("驱动加载失败");
            e.printStackTrace();
            System.exit(-1);
        }

        //检查数据库是否已经建表
        boolean tableStatus = checkTable(tableName);
        System.out.println(tableStatus);

        // Connection connection = null; //数据库连接
        
        // try {
        //     connection = DriverManager.getConnection("jdbc:sqlite:library.db"); //建立数据库连接
        //     Statement statement = connection.createStatement();
        //     statement.setQueryTimeout(3000); //设置超时

        //     // ResultSet set = statement.executeQuery("SELECT name FROM sqlite_master WHERE type='table' AND name='library'");
        //     // System.out.println(set.getString("name"));

        //     statement.executeUpdate("DROP TABLE IF EXISTS library"); //清空表
        //     statement.executeUpdate("CREATE TABLE library(id integer, full_title string, isbn string, pulisher string, author string, publish_date string)");
        // } catch(SQLException e) {
        //     e.printStackTrace();
        // } finally {
        //     try {
        //         if(connection != null)
        //             connection.close();
        //     } catch(SQLException e) {
        //         e.printStackTrace();
        //     }
        // }
    }

    /**
     * Check table "library" exsist
     * @param tableName
     * @return If table exsist
     */
    private boolean checkTable(String tableName) {
        try {
        Connection connection = getConnection(sqlitePath); //获取数据库连接

        PreparedStatement ps = connection.prepareStatement(CHECK_TABLE_SQL); //设定查询语句模板
        ps.setString(1, tableName); //设定查询参数
        ResultSet set = ps.executeQuery(); //执行查询

        if(set.next()) //查询结果判空
            return true;
        else
            return false;
        } catch(SQLException e) {
            e.printStackTrace();
        }
        return false;
    }
    /**
     * Get connection
     */
    private Connection getConnection(String sqlitePath) {
        Connection connection = null;
        try {
            connection = DriverManager.getConnection("jdbc:sqlite:".concat(sqlitePath)); //建立数据库连接
        } catch(SQLException e) {
            e.printStackTrace();
            return null;
        }
        return connection;
    }
}