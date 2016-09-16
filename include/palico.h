#pragma once
#include <3ds.h>

class Palico {
	public:
	Palico();
	//Palico(u8* &palicoData);
	
	u8* rawData[319];
	
	u8 name[32];
	u32 xp = 0;
	u8 level = 0;
	u8 forte = 0;
	u8 enthusiasm = 0;
	u8 target = 0;
	
	u8 equippedActions[8];
	u8 equippedSkills[8];
	u8 learnedActions[16];
	u8 learnedSkills[12];
	u16 learnedActionRNG = 0;
	u16 learnedSkillRNG = 0;
	
	u8 greeting[60];
	u8 nameGiver[32];
	u8 previousMaster[32];
	
	u32 coatRGBAValue = 0;
	u32 leftEyeRGBAValue = 0;
	u32 rightEyeRGBAValue = 0;
	u32 vestRGBAValue = 0;
	u8 voice = 0;
	u8 eyes = 0;
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