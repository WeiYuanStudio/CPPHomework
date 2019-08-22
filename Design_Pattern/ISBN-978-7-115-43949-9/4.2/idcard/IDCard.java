package idcard;
import framework.*;

public class IDCard extends Product {
    private String owner;
	private int serial;

	IDCard(String owner, int serial) {
		System.out.println("Creating A IDCard" + owner + serial);
		this.owner = owner;
		this.serial = serial;
	}

	@Override
	public void use() {
		System.out.println("Use" + owner + "Card" + serial);
	}

	public String getOwner() {
		return owner;
	}
}
