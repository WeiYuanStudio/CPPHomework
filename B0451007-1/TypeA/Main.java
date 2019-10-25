import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) throws IOException {
        NumFile inFile = new NumFile("." + File.separatorChar + "data.txt"); //Use File.separatorChar to adapt Win & *nix
        inFile.loadFile(); //加载文件

        ArrayList<Integer> numList = inFile.getList(); //获取List

        Collections.sort(numList); //排序List

        NumFile outFile = new NumFile("." + File.separatorChar + "number.txt");
        outFile.loadList(numList);
        inFile.splitNumWriter(System.out); //打印List到CLI
        outFile.saveFile(); //保存文件
    }
}