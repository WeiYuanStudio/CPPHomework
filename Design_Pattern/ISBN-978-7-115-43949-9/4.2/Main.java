import framework.*;
import idcard.*;

public class Main {
	public static void main(String[] args) {
		Factory factory = new IDCardFactory();
		Product card1 = factory.create("Adam");
		Product card2 = factory.create("Lisa");

		card1.use();
		card2.use();
	}
}
