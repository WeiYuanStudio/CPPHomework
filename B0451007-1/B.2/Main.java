import java.sql.SQLException;

class Main {
    
    /**
     *  提炼方法，简化数据库插入测试
     */
    static void insertLibrary(DAO library) {
        System.out.println("插入数据到DAO对象");
        try {
            BookBean book1 = new BookBean(
                1,
                "Thinking In Java",
                "9783827268969",
                "Markt + Technik Verlag",
                "Bruce Eckel",
                2005
            );
            library.insertBook(book1);
            BookBean book2 = new BookBean(
                2,
                "C++ PrimerPlus",
                "978-0321714114",
                "Stanley B. Lippman",
                "Addison-Wesley Professional",
                2005
                );
            library.insertBook(book2);
        } catch(SQLException e) {
            e.printStackTrace();
            System.out.println("数据库插入失败");
        }
    }

    public static void main(String[] args) throws Exception {
        DAO sqlLibrary = new SQLiteDAO("library.db");
        insertLibrary(sqlLibrary);
        System.out.println("sqlite数据库写入完毕");

        System.out.println("读取Mysql配置文件");
        SQLPropertyLoader loader = new SQLPropertyLoader("MySQL.properties");

        DAO mysqlLibrary = new MysqlDAO(
            loader.getSQLPath(),
            loader.getPort(),
            loader.getDataBaseName(),
            loader.getUser(),
            loader.getPassword()
        );
        insertLibrary(mysqlLibrary);
        System.out.println("Mysql写入完毕");
    }

}
