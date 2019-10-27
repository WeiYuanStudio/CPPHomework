import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    private static void usage() { //缺参数提示
        System.out.println("Please input your param for in/output file path");
    }

    public static void main(String[] args) {
        String inFilePath = null; //文件读取路径
        String outFilePath = null; //文件输出路径

        try {
            inFilePath = args[0]; //设定读取路径
            outFilePath = args[1]; //设定输出路径
        } catch (ArrayIndexOutOfBoundsException e) {
            usage();
            System.exit(-1);
        }

        System.out.println("读取文件路径: " + inFilePath);

        NumFile inFile = new NumFile(inFilePath); //创建NumFile实例

        try {
            inFile.loadFile(); //加载文件
            System.out.println("文件读取成功");
            inFile.splitNumWriter(System.out); //输出文件
        } catch (IOException e) {
            System.out.println("File open failed");
            e.printStackTrace();
            System.exit(-1);
        }

        System.out.println("排序输出");
        inFile.sortNumWriter(System.out);

        try {
            System.out.println("保存到文件路径: " + outFilePath);
            FileOutputStream fileOutputStream = new FileOutputStream(new File(outFilePath)); //创建保存文件输出流
            inFile.sortNumWriter(fileOutputStream); //输出排序数字
            System.out.println("保存到文件成功");
        } catch (IOException e) {
            System.out.println("保存失败");
            e.printStackTrace();
            System.exit(-1);
        }
    }
}