import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;

class NumFile {
    private String filePath;
    private File numFile;
    private String fileString = null;
    private ArrayList<Integer> numList = new ArrayList<Integer>();

    /**
     * New NumFile
     * @param filePath
     */
    public NumFile(String filePath) {
        this.filePath = filePath;
        numFile = new File(filePath);
    }

    /**
     * Load file from file system to fileString.
     */
    private void readFile() throws IOException {
        BufferedReader fileBufferedReader = new BufferedReader(new FileReader(numFile));
        fileString = fileBufferedReader.readLine();
        fileBufferedReader.close();
    }

    /**
     * Save file from fileString to file system.
     */
    public void saveFile() throws IOException {
        FileOutputStream fileOutputStream= new FileOutputStream(new File(filePath));
        splitNumWriter(fileOutputStream);
    }

    public ArrayList<Integer> loadFile() throws IOException {
        readFile();
        if(fileString == null) {
            throw new RuntimeException("Have nothing to Load");
        }

        String[] numStrings = fileString.split(" "); //Split fileString ready to load in numList
        for(String str : numStrings) {
            numList.add(Integer.valueOf(str));
        }
        return numList;
    }

    /**
     * This Writer can write split num string to OutputStream
     * @param out
     */
    public void splitNumWriter(OutputStream out) {
        PrintStream p = new PrintStream(out);
        Iterator<Integer> numIterator = numList.iterator();
        while(numIterator.hasNext()) {
            p.print(numIterator.next() + " ");
        }
        p.println();
        p.close();
    }

    public void loadList(ArrayList<Integer> numList) {
        this.numList = numList;
    }

    public ArrayList<Integer> getList() {
        return numList;
    }
}