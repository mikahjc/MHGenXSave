#include "Character.h"

void Character::importItems(u8 buffer[], int type)
{
	unsigned int byteindex = 0;
	unsigned int num1 = 0;
	unsigned int num2 = 0;
	double totalItems = type / 2.25;
	
	Item* itemStorage = new Item[type];
	if(type == SIZEOF_ITEMBOX)
		itemBox = itemStorage;
	else if(type == SIZEOF_ITEMPOUCH)
		itemPouch = itemStorage;
	
	for (int index = 0; index < totalItems; index++)
	{
		u8 num3 = 0;
		while (num2 < 18U)
		{
			num3 = buffer[byteindex++];
			unsigned int num4 = num1 >> 8;
			num1 = (u32)((int)num3 << 24 | (int)num4 & 16777215);
			num2 += 8U;
		}
		if (num2 >= 18U)
		{
			unsigned int num4 = num1 >> 32 - (int)num2 & 262143U;
			num1 = (u32)num3 << 24;
			num2 -= 18U;
			itemStorage[index] = Item(num4 & 2047U, num4 >> 11);
		}
	}	
}

u8* Character::packItems(int type)
{
	int byteIndex = 0;
	u8* newBuffer = new u8[type];
	Item* itemStorage;
	if(type == SIZEOF_ITEMBOX)
		itemStorage = itemBox;
	else if(type == SIZEOF_ITEMPOUCH)
		itemStorage = itemPouch;
	
	unsigned int num1 = 0;
	unsigned int num2 = 0;
	for (int i = 0; i < (int)(type / 2.25); ++i)
	{
		num1 = (itemStorage[i].itemAmount << 11 | itemStorage[i].itemID) << (int)num2 | num1;
		num2 += 18U;
		while (num2 >= 8U)
		{
			newBuffer[byteIndex++] = (u8)num1;
			num1 >>=8;
			num2 -= 8U;
		}
	}
	return newBuffer;
}

