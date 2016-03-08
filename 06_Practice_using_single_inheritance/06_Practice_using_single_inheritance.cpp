// 06_Practice_using_single_inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
# include "string.h"

 //Create several structs in an inheritance hierarchy to model different assets one might invest in.  
// Call the base Asset and give it data members for id, cost and purchase date (year only).
typedef struct 
{
  int    m_id;
  int    m_purchaseDate;  // year purchased
  double m_cost;
} Asset;


// Derive three structs from Asset: Stock, Bond, and Property.  Give Stock data members for ticker symbol, shares owned, and last quoted price per share.
typedef struct
{

  Asset  base;
  double m_lastPrice;
  int    m_shares;
  char   m_symbol[12];
} Stock;


// Give Bond data members for face value, interest rate, and date of maturity.
typedef struct 
{
  Asset  base;
  double m_faceValue;
  double m_interestRate;
  int    m_dateOfMaturity;
} Bond;


// Give Property a data member for its assessed value.
typedef struct 
{

  Asset base;
  double m_assessment;
} Property;


// Derive two types of property from Property: Land and Building. Give land a data member for number of acres.
typedef struct
{

  Property base;
  double m_acres;
} Land;


// Give building a data member for the number of stories.
typedef struct Building 
{
  Property base;
  int m_stories;
};


// Initialization

// Add a function to initialize each structure type.
void Asset_ctor(Asset* self, int id, int date, double cost)
{
    self->m_id = id;
    self->m_purchaseDate = date;
    self->m_cost = cost;
}


// Have each subclass call the base class initialization function (constuctor).
void Stock_ctor(Stock* self, int id, int date, double cost,

                const char* sym, double price, int shares)
{
    Asset_ctor(&self->base, id, date, cost);
    strcpy(self->m_symbol, sym);
    self->m_lastPrice  = price;
    self->m_shares     = shares;
}

// Do the same for Bond
void Bond_ctor(Bond* self, int id, int date, double cost,
				double value, double intrest, int maturity)
{
    Asset_ctor(&self->base, id, date, cost);
    self->m_faceValue		= value;
    self->m_interestRate	= intrest;
    self->m_dateOfMaturity	= maturity;
}


// Create a function to print out each structure type. 
// Have the subclasses chain to the base class implementation in the same way we did with the constructors.
void Asset_print(Asset* self)
{
    printf("ID: %d\nPurchase Year: %d\nInitial Cost: %lf\n",
           self->m_id, self->m_purchaseDate, self->m_cost);
}


void Stock_print(Stock* self)
{
    Asset_print(&self->base);
	
	printf("Last Price: %f \nShares Owned: %d\nTick Name: %s\n",
		self->m_lastPrice, self->m_shares, self->m_symbol);
}

void Bond_print(Bond* self)
{
    Asset_print(&self->base);
	
	printf("Date of Maturity: %d\nFace Value: %f\nInterest Rate: %f\n",
		self->m_dateOfMaturity, self->m_faceValue, self->m_interestRate);
}

int _tmain(int argc, _TCHAR* argv[])
{
	// Instantiate each asset type and fill in the data members with some values.  For example,
	Stock    microsoft;
	Bond     citicorp;
	
	//microsoft.base.m_id     = 100;

 //   // or you could do the following
	//((Asset *)(&microsoft))->m_id     = 100;

 //   // pretty ugly, the next section has you create initialization functions
 //   microsoft.base.m_cost     = 8000;
 //   microsoft.base.m_purchaseDate = 1994;
 //
 //   strcpy(microsoft.m_symbol, "MSFT");
 //   microsoft.m_shares     = 200;
 //   microsoft.m_lastPrice  = 56;

 //   citicorp.base.m_id       = 200;
 //   citicorp.base.m_cost       = 9400;
 //   citicorp.base.m_purchaseDate   = 1980;

 //   citicorp.m_faceValue    = 10000;
 //   citicorp.m_interestRate   = 6.0;
 //   citicorp.m_dateOfMaturity = 2010;

	// Now the initialization of our variables is much cleaner and we can easily initialize more objects.
	Stock_ctor(&microsoft, 100, 1994, 8000, "MSFT", 56, 200);
	Bond_ctor(&citicorp, 200, 1980, 9400, 10000, 6.0, 2010);

	Stock_print(&microsoft);
	Bond_print(&citicorp);
	
	return 0;
}

