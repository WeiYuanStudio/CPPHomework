import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

class SQLPropertyLoader extends Properties {
    private String filePath;

    SQLPropertyLoader(String filePath) throws IOException {
        this.filePath = filePath;
        load(filePath);
    }

    void load(String filePath) throws IOException {
        this.load(new FileReader(filePath));
    }

    /**
     * 获取Mysql远程地址
     * @return
     */
    String getSQLPath() {
        System.out.println(getProperty("SQLPath"));
        return getProperty("SQLPath");
    }

    /**
     * 获取端口号
     */
    int getPort() {
        return Integer.parseInt(getProperty("Port"));
    }

    /**
     * 获取数据库名
     * @return
     */
    String getDataBaseName() {
        return getProperty("DatabaseName");
    }

    /**
     * 获取用户名
     * @return
     */
    String getUser() {
        return getProperty("User");
    }

    /**
     * 获取用户密码
     * @return
     */
    String getPassword() {
        return getProperty("Password");
    }
}
