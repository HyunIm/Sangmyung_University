package gov.sandia.jess.example.pricing.demo;

import gov.sandia.jess.example.pricing.model.CatalogItem;
import gov.sandia.jess.example.pricing.model.Customer;
import gov.sandia.jess.example.pricing.model.Order;
import gov.sandia.jess.example.pricing.model.OrderItem;
import gov.sandia.jess.example.pricing.Database;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

/**
 * A toy implementation of the Database interface with some
 * hard-coded order data.
 */

public class DemoDatabase implements Database {

	private ArrayList items;
	private Map orders;

	public DemoDatabase() {
		createCatalogItems();
		createOrders();
	}
	
	private void createOrders() {
		orders = new HashMap();
		
		Customer customer = new Customer(6);
		ArrayList orderItems = new ArrayList();
		orderItems.add(new OrderItem("CD Writer", 1234, 199.99f, 1));
		orderItems.add(new OrderItem("AA Batteries", 4323, 4.99f, 2));
		orders.put(new Integer(123), new Order(orderItems, customer));
		
		customer = new Customer(1);
		orderItems = new ArrayList();
		orderItems.add(new OrderItem("Gold-tipped cable", 9876, 19.99f, 4));
		orders.put(new Integer(567), new Order(orderItems, customer));
		
		customer = new Customer(1);
		orderItems = new ArrayList();
		orderItems.add(new OrderItem("Incredibles DVD", 222123, 29.99f, 1));
		orders.put(new Integer(666), new Order(orderItems, customer));
	}

	private void createCatalogItems() {
		items = new ArrayList();
		items.add(new CatalogItem("CD Writer", 1234, 199.99f));
		items.add(new CatalogItem("CD-RW Disks", 782321, 5.99f));
		items.add(new CatalogItem("AA Batteries", 4323, 4.99f));
		items.add(new CatalogItem("Gold-tipped cable", 9876, 19.99f));
		items.add(new CatalogItem("Amplifier", 34526, 399.99f));
		items.add(new CatalogItem("Incredibles DVD", 222123, 29.99f));
	}

	public Collection getCatalogItems() {
		return items;
	}

	public Order getOrder(int orderNumber) {
		return (Order) orders.get(new Integer(orderNumber));
	}
}
