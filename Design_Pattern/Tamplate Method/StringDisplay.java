public class StringDisplay extends AbstractDisplay {
    private String str;
    private int strLength;

    public StringDisplay(String str) {
    	this.str = str;
	strLength = str.length();
    }
    @Override
    public void open() {
        printLine();
    }

    @Override
    public void print() {
        System.out.println("|" + str + "|");
    }

    @Override
    public void close() {
	printLine();
    }

    private void printLine() {
    	System.out.print("+");
	for(int i = 0; i < strLength; i++) {
	    System.out.print("-");
	}
    	System.out.println("+");
    }
}
