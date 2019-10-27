import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;

class NumFile {
    private File numFile; //文件对象
    private String fileString = null; //文件内容
    private ArrayList<Integer> numList = new ArrayList<>(); //取出数组

    /**
     * New NumFile 构造方法
     *
     * @param filePath 文件路径
     */
    NumFile(String filePath) {
        numFile = new File(filePath); //创建文件对象
    }

    /**
     * 从文件系统加载文件
     */
    private void readFile() throws IOException {
        BufferedReader fileBufferedReader = new BufferedReader(new FileReader(numFile));
        fileString = fileBufferedReader.readLine(); //读取一行
        fileBufferedReader.close(); //关闭Reader
    }

    /**
     * 加载文件
     *
     * @throws IOException
     */
    void loadFile() throws IOException {
        readFile(); //读取文件字符串

        if (fileString == null) //检查文件内容是否为空
            throw new RuntimeException("文件为空");

        String[] numStrings = fileString.split(" "); //通过空格分隔字符串
        for (String str : numStrings) {
            numList.add(Integer.valueOf(str)); //转入List<Integer>
        }
    }

    /**
     * 将List写入流
     *
     * @param out
     */
    void splitNumWriter(OutputStream out) {
        PrintStream p = new PrintStream(out) {
            @Override //重写输出方法，加入空格分隔数字
            public void print(Object obj) {
                super.print(obj.toString() + ' ');
            }
        }; //创建Print流
        numList.forEach(p::print);

        //写入后操作
        p.println();
    }

    void sortNumWriter(OutputStream out) {
        PrintStream p = new PrintStream(out) {
            @Override //重写输出方法，加入空格分隔数字
            public void print(Object obj) {
                super.print(obj.toString() + ' ');
            }
        };
        numList.stream()
                .sorted(Comparator.naturalOrder())
                .forEach(p::print);

        //写入后操作
        p.println();
    }
}
