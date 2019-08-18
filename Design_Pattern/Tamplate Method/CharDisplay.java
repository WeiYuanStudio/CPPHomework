public class CharDisplay extends AbstractDisplay {
    private char ch;
    CharDisplay(char ch) {
    	this.ch = ch;
    }

    @Override
    public void open() {
        System.out.print("<<");
    }

    @Override
    public void print() {
        System.out.print(ch); 
    }

    @Override
    public void close() {
	System.out.print(">>");
    }
}
