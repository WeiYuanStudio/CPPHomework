import java.sql.SQLException;
import java.util.Scanner;

class Main {
    
    /**
     *  提炼方法，简化插入测试
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

        System.out.println("请依次输入Mysql数据库的远程地址，端口，数据库名，用户名，密码");
        Scanner sc = new Scanner(System.in);

        DAO mysqlLibrary = new MysqlDAO( //TODO: 这里有输入流的问题，可能是Win的问题。使用Properties重构
            sc.nextLine(),
            sc.nextInt(),
            sc.nextLine(),
            sc.nextLine(),
            sc.nextLine()
        );
        sc.close();
        insertLibrary(mysqlLibrary);
    }
}
