public class Main {
    public static void main(String[] args) {
    	AbstractDisplay stringDisplay = new StringDisplay("Hello World!");
	stringDisplay.display();
	
	AbstractDisplay charDisplay = new CharDisplay('A');
	charDisplay.display();
    }
}
