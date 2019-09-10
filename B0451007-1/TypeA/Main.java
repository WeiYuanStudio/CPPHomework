import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) throws IOException {
        NumFile inFile = new NumFile("." + File.separatorChar +"data.txt"); //Use File.separatorChar to adapt Win & *nix
        inFile.loadFile(); //Load String to ArrayList
        
        ArrayList<Integer> numList = inFile.getList(); //Get a ArrayList from NumFile
        
        Collections.sort(numList); //Sort ArrayList
        
        NumFile outFile = new NumFile("." + File.separatorChar + "number.txt");
        outFile.loadList(numList);
        inFile.splitNumWriter(System.out); //Print ArrayList to Console
        outFile.saveFile(); //
    }
}