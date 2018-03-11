package gov.sandia.jess.example.pricing.model;

import java.text.DecimalFormat;

public class Offer {
    private final float amount;
    private final String description;
    private static DecimalFormat formatter = new DecimalFormat("-$0.00");

    public Offer(String aDescription, float anAmount) {
	description = aDescription;
	amount = anAmount;		
    }

    public float getAmount() {
	return amount;
    }

    public String getDescription() {
	return description;
    }

    public String toString() {
	return description + ": " + formatter.format(amount);
    }
	
	
}