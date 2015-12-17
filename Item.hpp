/*****************************
 * **Author:Alexandria Marsh
 * **Date: April 25, 2015
 * **Description: This is the specifcation file
 *      for the Item class. this class is used to create
 *      item objects of name, price, and quantity.  The functions
 *      included are get and set methods for each object, along with 
 *      a constructors. 
 *       
 **********************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include<string>   

class Item
{
  protected:
	std::string name;
	double price;
	int quantity;
	std::string unit;
  public:
	Item();
	Item(std::string, double, int, std::string);
	void setName(std::string);
	void setPrice(double);
	void setQuantity(int);
	void setUnit(std::string);
	void setSubTotal();
	std::string getName();
	double getPrice();
	int getQuantity();
	std::string getUnit();
	double getSubTotal();
};
#endif  
