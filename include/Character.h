#include "Constants.h"
#include <3ds.h>
#include <string.h>
#include "item.h"


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
	u8 bytes[24];
	Equipment()
	{
		memset(bytes, 0, 24);
	}
	Equipment(u8 rawData[24])
	{
		for(int i = 0; i < 24; i++)
			bytes[i] = rawData[i];
	}
	Equipment(const Equipment &copy)
	{
		for(int i = 0; i < 24; i++)
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

struct Palico {
	u8 name[33];
	u32 xp;
	u8 level;
	u8 forte;
	u8 enthusiasm;
	u8 targe;
	
	u8 equippedActions[8];
	u8 equippedSkills[8];
	u8 learnedActions[16];
	u8 learnedSkills[12];
	u16 learnedActionRNG;
	u16 learnedSkillRNG;
	
	u8 greeting[61];
	u8 nameGiver[33];
	u8 previousMaster[33];
	
	u8 coatRGBAValue[4];
	u8 leftEyeRGBAValue[4];
	u8 rightEyeRGBAValue[4];
	u8 vestRGBAValue[4];
	u8 voice;
	u8 eyes;
	u8 clothing;
	u8 coat;
	u8 ears;
	u8 tail;
	
	u8 unknown1[8];  //Offset 0x58
	u8 unknown2[51]; //Offset 0xDC
	u8 unknown3[2];  //Offset 0x0112
	u8 unknown4[3];  //Offset 0x0117
	u8 unknown5[21]; //Offset 0x012A
};

class Character {
	public:
	bool used;
	Character()
	{
		itemBox = NULL;
		itemPouch = NULL;
		equipBox = NULL; //new Equipment[1400];
		used = false;
	}
	u8 name[32];
	u32 playTime;
	u32 offset;
	int funds;
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
	
	u8 skinColorRGBA[4];
	u8 hairColorRGBA[4];
	u8 featuresColorRGBA[4];
	u8 clothingColorRGBA[4];
	
	int hrPoints;
	int zenny;
	int academyPoints;
	int berunaPoints;
	int kokotoPoints;
	int pokkePoints;
	int yukumoPoints;
	
	Item* itemBox;
	Item* itemPouch;
	Equipment* equipBox;
	//Palico palicos[60];
	
	void importItems(u8 buffer[], int type);
	u8* packItems(int type);
};