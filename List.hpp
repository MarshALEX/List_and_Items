/***********************************
 * **Author: Alexandria Marsh
 * **Date: April 25, 2015
 * **Description: This is the specifcation file 
 *     for the List class.  It contains a vector
 *     that uses objects from the Item class.
***********************************/

#ifndef LIST_HPP
#define LIST_HPP

#include "Item.hpp"
#include <string>
#include <vector>

class List 
{
 private:
    std::vector<Item> itemContents;  

 public:
   void addItem(Item);
   void listContents();
   void totalPrice();
   void deleteItem(int);
};
#endif
