package gov.sandia.jess.example.pricing.demo;

import java.util.Iterator;
import gov.sandia.jess.example.pricing.Database;
import gov.sandia.jess.example.pricing.PricingEngine;

import jess.JessException;

public class Demo {

	public static void main(String[] args) {
		try {
			DemoDatabase database = new DemoDatabase();
			PricingEngine engine = new PricingEngine(database);
	
			processOrder(database, engine, 123);
			processOrder(database, engine, 567);
			processOrder(database, engine, 666);

		} catch (JessException e) {
			e.printStackTrace();
		}

	}

	private static void processOrder(DemoDatabase database, PricingEngine engine, int orderNumber) throws JessException {
		Iterator items;
		Iterator offers;
		System.out.println("Items for order " + orderNumber + ":");
		items = database.getOrder(orderNumber).getItems();
		while (items.hasNext()) {
			System.out.println("   " + items.next());
		}			
		
		offers = engine.run(orderNumber);
		System.out.println("Offers for order " + orderNumber + ":");
		while (offers.hasNext()) {
			System.out.println("   " + offers.next());
		}
		System.out.println();
	}

}
