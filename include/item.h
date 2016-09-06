#include <3ds.h>

class Item {
	public:
	u32 itemID;
	u32 itemAmount;
	Item(u32 itemID, u32 itemAmount)
	{
		this->itemID = itemID;
		this->itemAmount = itemAmount;
	}
	Item()
	{
		itemID = 0;
		itemAmount = 0;
	}
	Item(const Item &copy)
	{
		this->itemID = copy.itemID;
		this->itemAmount = copy.itemAmount;
	}
};