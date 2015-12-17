/******************************
 * **Author: Alexandria Marsh
 * **Date: April 25, 2015
 * **Desription: This is the implementation file 
 *    for teh List class.  It will ask users 
 *    to select options from a menu that include: adding
 *    objects to a lest, listing the contents of the list,
 *    deleting items, or displaying the total price of teh list.
 *********************************/

#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<cctype>
#include<iomanip>
#include<vector>
#include "Item.hpp"
#include "List.hpp"
#include "ClubItem.hpp"


/**********************
 *     addItem
 ***Description:  This function takes a 
      new item given by the user and adds 
      it to the list
**Parameters:  This function takes a new item in 
      from a Item class object.  The function has 
      no returning values.  
***********************/
void List::addItem(Item itemIn)
{
  itemContents.push_back(itemIn);
}

/**************************************
 *             deleteItem
 **Description: this function takes the item
	number and deletes the item from the list
 **Parameters: This function takes a item number
	from the user. The function has no returning vales.             
 * ***********************************/
void List::deleteItem(int listNum)
{
 itemContents.erase(itemContents.begin()+(listNum-1));
 std::cout<<"Item number "<<listNum<<" has been deleted."<<std::endl;
}

/******************************
 * 	listContents
 * **Description: This function lists
 *    all of the items the user has entered,
 *    along with the items price and quantity.
 *
 * **Parameters: This function has no parameters and
 *    no returning values, but uses the methods from 
 *    the Item class.   
 *
 * ****************************/
void List::listContents()
{
 int count; 
 double total = 0;
 for( count=0; count < itemContents.size(); count++)
  {
    std::cout<<"Item number "<<count+1<<": "<<std::endl;
    std::cout<<"Name :"<< itemContents[count].getName()<<std::endl;
    std::cout<<std::fixed<<std::showpoint<<std::setprecision(2)
             <<"Price : $"<< itemContents[count].getPrice()<<std::endl;
    std::cout<<"Unit :"<< itemContents[count].getUnit()<<std::endl;
    std::cout<<"Quantity :"<<itemContents[count].getQuantity()<<std::endl;
 
    double sum = itemContents[count].getPrice() *
		 itemContents[count].getQuantity();
    total =+ sum;
    std::cout<<"Subtotal for Item : $"<<total<<std::endl;
    std::cout<<std::endl;	
  }
  totalPrice();
}

/******************************
 * *      totalPrice
 * **Description:This function calculates the total
 *      price for every item on the list.
 *
 * **Paramaters:This function takes in no parameters 
 *     but uses the methods in the Item class. The function
 *     also does not return any values but prints from the function
 *
 * ******************************/
void List::totalPrice()
{
 
 double total =0;
 std::vector<double> v; 
  for(int index=0; index < itemContents.size(); index++)  
  {
    double sum = itemContents[index].getPrice() *
		 itemContents[index].getQuantity();
      v.push_back(sum);
  }  

	for(int i=0; i< v.size(); i++)
	{
	 total += v[i];
	}
    std::cout<<std::fixed<<std::showpoint<<std::setprecision(2)<<std::endl;
    std::cout<<"Total Price For List:  $"<<total<<std::endl;
    
} 

int main()
{
  int choice;
  int num;
  int quantity;
  std::string name;
  char quantityIn[10];
  char card;	
  char sale;
  double price;
  std::string unit;	

   
  List cart; //declare List object cart 
  ClubItem saleItem; //declare ClubItem object saleItem
 do{
     std::cout<<"********************"<<std::endl;
     std::cout<<"Menu: "<<std::endl;
     std::cout<<"1.) Add an item. "<<std::endl;
     std::cout<<"2.) List Contents. "<<std::endl;
     std::cout<<"3.) Get Total Price. "<<std::endl;
     std::cout<<"4.) Delete an item. "<<std::endl; 
     std::cout<<"5.) Quit. "<<std::endl;
     std::cout<<"Please Enter Your Choice: "<<std::endl;
     std::cin >> choice;  	 	    

     if(choice<1 || choice>5)
      {
	std::cout<<"Please Enter Your Choice Again: "<<std::endl;
      } 
     if(choice == 1)
      {
	std::cout<<"Do you have a "<<std::endl;
	std::cout<<"customer loyalty card? (y/n)"<<std::endl;
	std::cin>>card;
	std::cout<<std::endl;
       
        std::cout<<"Enter item name: "<<std::endl;
	std::cin.ignore();
	std::getline(std::cin, name); 
	std::cout<<std::endl;	
		
	std::cout<<"Enter item price: "<<std::endl;
	std::cin>> price;
	std::cout<<std::endl;

	if(card == 'y')
	{	
	std::cout<<"Is this item a Club item(on sale)?(y/n)"<<std::endl;
	std::cin>> sale;
	std::cout<<std::endl;
	}

	std::cout<<"Enter unit of item: "<<std::endl;
	std::cin.ignore();
	std::getline(std::cin, unit); 
	std::cout<<std::endl;

	std::cout<<"Enter quantity of item: "<<std::endl;
	std::cin>> quantityIn;
	for(int i=0; i< strlen(quantityIn); i++)
	  {
	    if(!isdigit(quantityIn[i]))
	     {
	        std::cout<<"Sorry, that is invalid."<<std::endl;
		std::cout<<"Please enter quantity again: "<<std::endl;
		std::cin>> quantityIn; 
	        std::cout<<std::endl; 
	     }
	   
	  }  	
	quantity = atoi(quantityIn); 

	if((card == 'y') && (sale == 'y'))
	{
	  
          double newPrice; 
	  newPrice = saleItem.salePrice(price);
	  Item newItem(name, newPrice, quantity, unit);	

          //pass new item object in Item class to function in 
          //List class to add
	  cart.addItem(newItem);
	}

	else
	{
	 // create class Item object for new item to be added 
	Item newItem(name, price, quantity, unit);

         //pass new item object in Item class to function in 
         //List class to add
  	 cart.addItem(newItem);       
	}         
     }
     
     else if(choice == 2)
      {
	cart.listContents();
      }
     else if(choice ==3)
      {

        cart.totalPrice();
      }
     else if(choice ==4)
      {
	std::cout<<"Please enter the number of item: "<<std::endl;
	std::cin>> num;
	cart.deleteItem(num);	
      }	 		
       	  
   }while(choice != 5); 



 return 0;
}        
