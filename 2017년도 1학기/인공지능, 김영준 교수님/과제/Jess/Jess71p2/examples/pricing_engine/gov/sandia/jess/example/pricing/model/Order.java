package gov.sandia.jess.example.pricing.model;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;

public class Order {
    private List items;
    private float total;
    private Customer customer;
    
    public Order(Collection theItems, Customer aCustomer) {
	items = new ArrayList(theItems);
	for (Iterator it = items.iterator(); it.hasNext();) {
	    OrderItem item = (OrderItem) it.next();
	    total += item.getTotal();
	}
	customer = aCustomer;
    }
    
    public Iterator getItems() {
        return items.iterator();
    }
    
    public float getTotal() {
    	return total;
    }
    
    public Customer getCustomer() {
	return customer;
    }
}