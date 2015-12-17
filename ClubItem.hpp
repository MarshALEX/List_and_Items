/*******************************************
 * *Author: Alex Marsh
 * *Date: April 25, 2015
 * *Description: This is teh specification file
 * 	for the ClubItem class. 
 * *****************************************/

#ifndef CLUBITEM_HPP
#define CLUBITEM_HPP

class Item;  //forward declarations

class ClubItem 
{

	
 public:
	double salePrice(double priceIn)
	{ return (priceIn * .1);}


};
#endif	 
