/*******************************
 * **Author: Alexandria Marsh
 * **Date: April 25, 2015
 * **Description: This file is teh implication
 *     file for the Item class. This file contains all of
 *     the set and get functions, constructors, and will 
 *     be used in the class Shopping Cart
 ****************************/

#include "Item.hpp"
#include "ClubItem.hpp"
#include <string>

//default constructor
Item::Item()
{
  setName(" ");
  setPrice(0.0);
  setQuantity(0);
  setUnit(" ");
}

//constructor
Item::Item(std::string nameIn, double priceIn, 
	   int quantityIn, std::string unitIn )
{
  setName(nameIn);
  setPrice(priceIn);
  setQuantity(quantityIn);
  setUnit(unitIn);
}
  	
void Item::setName(std::string nameIn)
{
  name = nameIn;
}

void Item::setPrice( double priceIn)
{
  price = priceIn;
}

void Item::setQuantity (int quantityIn)
{
  quantity = quantityIn;
}

void Item::setUnit( std::string unitIn)
{
  unit = unitIn;
}


std::string Item::getName()
{
  return name;
}

double Item::getPrice()
{
  return price;
}

int Item::getQuantity()
{
  return quantity;
} 

std::string Item::getUnit()
{
  return unit;
}
	      
