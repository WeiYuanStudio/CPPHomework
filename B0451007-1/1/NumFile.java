import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;

class NumFile {
    private String filePath; //文件路径
    private File numFile; //文件对象
    private String fileString = null; //文件内容
    private ArrayList<Integer> numList = new ArrayList<>(); //取出数组

    /**
     * New NumFile 构造方法
     *
     * @param filePath 文件路径
     */
    NumFile(String filePath) {
        this.filePath = filePath; //设定文件路径
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
     * 保存文件到文件系统
     */
    void saveFile() throws IOException {
        FileOutputStream fileOutputStream = new FileOutputStream(new File(filePath)); //创建保存文件输出流
        splitNumWriter(fileOutputStream); //写入流
    }

    /**
     * 加载文件
     *
     * @throws IOException
     */
    void loadFile() throws IOException {
        readFile();
        if (fileString == null) {
            throw new RuntimeException("File path is null");
        }

        String[] numStrings = fileString.split(" "); //通过空格分隔
        for (String str : numStrings) {
            numList.add(Integer.valueOf(str));
        }
    }

    /**
     * 将List写入流
     *
     * @param out
     */
    void splitNumWriter(OutputStream out) {
        PrintStream p = new PrintStream(out); //创建Print流

        Iterator<Integer> numIterator = numList.iterator(); //获取迭代器
        while (numIterator.hasNext()) { //遍历写入
            p.print(numIterator.next() + " ");
        }

        //写入后操作
        p.println();
        p.close();
    }

    void loadList(ArrayList<Integer> numList) {
        this.numList = numList;
    }

    ArrayList<Integer> getList() {
        return numList;
    }
}
