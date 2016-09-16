#include "Constants.h"
#include <3ds.h>
#include <string.h>
#include "item.h"
#include "palico.h"


class Equipment {
	// Byte 0: Equipment Type
	// Byte 1: Equipment ID
	// Byte 2: ???
	// Byte 3: Level (0 indexed)
	// Bytes 6-7:   Deco 1
	// Bytes 8-9:  Deco 2
	// Bytes 10-11: Deco 3
	// Convert ID to 
	public:
	u8 bytes[36];
	Equipment()
	{
		memset(bytes, 0, 36);
	}
	Equipment(u8 rawData[36])
	{
		for(int i = 0; i < 36; i++)
			bytes[i] = rawData[i];
	}
	Equipment(const Equipment &copy)
	{
		for(int i = 0; i < 36; i++)
			bytes[i] = copy.bytes[i];
	}
	u8 getType()
	{
		return bytes[0];
	}
	void setType(u8 newType)
	{
		bytes[0] = newType;
	}
	u16 getID()
	{
		u16 ID = (u16)(bytes[2] << 8 | bytes[1]);
		return ID;
	}
	void setID(u16 newID)
	{
		bytes[1] = (u8)(newID & 0x00FF);
		bytes[2] = (u8)(newID >> 8);
	}
	u8 getLevel()
	{
		return bytes[3];
	}
	void setLevel(u8 newLevel)
	{
		bytes[3] = newLevel;
	}
	
};

class Character {
	public:
	Character()
	{
		itemBox = NULL;
		itemPouch = NULL;
		equipBox = NULL; //new Equipment[1400];
	}
	u8 name[32];
	u32 playTime;
	s32 funds;
	u16 hunterRank;
	u16 hunterArt1;
	u16 hunterArt2;
	u16 hunterArt3;
	
	u8 voice;
	u8 eyeColor;
	u8 clothing;
	u8 gender;
	u8 huntingStyle;
	u8 hairStyle;
	u8 face;
	u8 features;
	
	u32 skinColorRGBA;
	u32 hairColorRGBA;
	u32 featuresColorRGBA;
	u32 clothingColorRGBA;
	
	s32 hrPoints;
	s32 zenny;
	s32 academyPoints;
	s32 berunaPoints;
	s32 kokotoPoints;
	s32 pokkePoints;
	s32 yukumoPoints;
	
	Item* itemBox;
	Item* itemPouch;
	Equipment* equipBox;
	Palico* palicos;
	Equipment* palicoEquip;
	
	void importItems(u8 buffer[], int type);
	u8* packItems(int type);
};