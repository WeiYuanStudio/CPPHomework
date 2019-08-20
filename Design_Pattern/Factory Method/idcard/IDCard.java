package idcard;
import framework.*;

public class IDCard extends Product {
    private String owner;
	IDCard(String owner) {
		System.out.println("Creating A IDCard" + owner);
		this.owner = owner;
	} 

	@Override
	public void use() {
		System.out.println("Use" + owner + "Card");
	}

	public String getOwner() {
		return owner;
	}
}
