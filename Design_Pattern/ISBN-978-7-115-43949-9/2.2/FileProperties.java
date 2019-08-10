import java.io.*;
import java.util.Properties;


public class FileProperties implements FileIO {
    private Properties properties;

    public FileProperties() {
        properties = new Properties();
    }
    @Override
    public void readFromFile(String filename) throws IOException {
	properties.load(new FileInputStream(new File("./" + filename)));
    }
    
    @Override
    public void writeToFile(String filename) throws IOException {
	properties.save(new FileOutputStream(new File("./" + filename)), "Comments: Write By WeiYuan");
    }

    @Override
    public void setValue(String key, String value) {
        properties.setProperty(key, value);
    }

    @Override
    public String getValue(String key){
	return properties.getProperty(key);
    }
}
