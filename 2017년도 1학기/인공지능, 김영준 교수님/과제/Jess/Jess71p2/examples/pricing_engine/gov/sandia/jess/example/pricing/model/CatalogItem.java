package gov.sandia.jess.example.pricing.model;

public class CatalogItem {
    private String description;
    private int partNumber;
    private float price;

    public CatalogItem(String aDescription, int aPartNumber, float aPrice) {
	description = aDescription;
	partNumber = aPartNumber;
	price = aPrice;
    }

    public int getPartNumber() {
	return partNumber;
    }
	
    public String getDescription() {
	return description;
    }
	
    public float getPrice() {
	return price;
    }
}
