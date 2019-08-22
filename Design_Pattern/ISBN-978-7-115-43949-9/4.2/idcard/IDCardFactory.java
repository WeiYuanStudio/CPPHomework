package idcard;
import framework.*;
import java.util.*;

public class IDCardFactory extends Factory {
	private int serialIndex = 100;
	private List owners = new ArrayList();

	@Override
	protected synchronized Product createProduct(String owner) {
		return new IDCard(owner, serialIndex++);
	}

	@Override
	protected void registerProduct (Product product) {
		owners.add(((IDCard)product).getOwner());
	}

	public List getOwners() {
		return owners;
	}
}
