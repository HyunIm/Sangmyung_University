package gov.sandia.jess.example.pricing;

import gov.sandia.jess.example.pricing.model.Offer;
import gov.sandia.jess.example.pricing.model.Order;
import jess.*;

import java.util.Iterator;

public class PricingEngine {
    private Rete engine;
    private WorkingMemoryMarker marker;
    private Database database;

    public PricingEngine(Database aDatabase) throws JessException {
        // Create a Jess rule engine
        engine = new Rete();
        engine.reset();

        // Load the pricing rules
        engine.batch("pricing.clp");

        // Load the catalog data into working memory
        database = aDatabase;
        engine.addAll(database.getCatalogItems());

        // Mark end of catalog data for later
        marker = engine.mark();
    }

    private void loadOrderData(int orderNumber) throws JessException {
        // Retrive the order from the database
    	Order order = database.getOrder(orderNumber);
        
    	if (order != null) {
    		// Add the order and its contents to working memory
    		engine.add(order);
    		engine.add(order.getCustomer());
    		engine.addAll(order.getItems());
    	}
    }

    public Iterator run(int orderNumber) throws JessException {
        // Remove any previous order data, leaving only catalog data
    	engine.resetToMark(marker);
    	
    	// Load data for this order
        loadOrderData(orderNumber);
        
        // Fire the rules that apply to this order
        engine.run();
        
        // Return the list of offers created by the rules
        return engine.getObjects(new Filter.ByClass(Offer.class));
    }
}