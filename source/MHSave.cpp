#include "MHSave.h"
#include <string.h>
#include <stdio.h>


bool MHSave::slotInUse()
{
	return used[currentSlot];
}

bool MHSave::slotInUse(bool used)
{
	this->used[currentSlot] = used;
	return true;
}

u8* MHSave::getName()
{
	return slot[currentSlot].name;
}

u8* MHSave::packPouch()
{
	return slot[currentSlot].packItems(SIZEOF_ITEMPOUCH);
}

u8* MHSave::packBox()
{
	return slot[currentSlot].packItems(SIZEOF_ITEMBOX);
}

Equipment MHSave::getEquipment(int equiactiveSlot)
{
	return slot[currentSlot].equipBox[equiactiveSlot];
}

Item MHSave::getItemBox(int index)
{
	return slot[currentSlot].itemBox[index];
}

Item MHSave::getItemPouch(int index)
{
	return slot[currentSlot].itemPouch[index];
}

void MHSave::setName(u8 buffer[32])
{
	memcpy(slot[currentSlot].name, buffer, 32);
}

void MHSave::selectSlot(int slot)
{
	if (slot < 3)
	{
		currentSlot = slot;
		activeSlot = &(this->slot[currentSlot]);
	}
	else
	{
		currentSlot = 0;
		activeSlot = this->slot;
	}
}

u32 MHSave::updateOffset(u32 &offset, u32 update)
{
	offset += update;
	return offset;
}

Palico MHSave::getPalico(int index)
{
	if(index < TOTAL_PALICOS)
		return activeSlot->palicos[index];
	else
		return Palico();
}

void MHSave::loadSlot()
{	
	Offsets offsets;
	u32 low[3] = {MEDIATYPE_SD, 0x00001870, 0};
	Handle fileHand;
	u32 bytesread;
	bool slotUsed = false;
	printf("S: Attempting to load slot %d\n", currentSlot + 1);
	FS_Path pth = fsMakePath(PATH_ASCII, "/system");
	// Open Save
	Result res = FSUSER_OpenFileDirectly(&fileHand, ARCHIVE_EXTDATA,
			(FS_Path){PATH_BINARY, 0xC, (u8*)low}, pth, FS_OPEN_WRITE, 0);
	if(res)
	{
		FSFILE_Close(fileHand);
		printf("S: Failed to open system\n");
		return /*-1*/;
	}
	printf("S: Opened system\n");
	// Check if currentSlot is in use
	res = FSFILE_Read(fileHand, &bytesread, offsets.FIRST_CHAR_SLOT_USED +
					  currentSlot, &slotUsed, 1);
	if (res)
	{
		slotUsed = false;
		printf("S: Failed to read slot in use data\n");
	}
	slotInUse(slotUsed);
	
	if (slotUsed)
	{
		printf("S: Slot %d in use\n", currentSlot +1);
		u32 charOffset = 0;
		u32 curOffset = 0;
		res = FSFILE_Read(fileHand, &bytesread, offsets.FIRST_CHARACTER + (currentSlot * 4), &charOffset, 4);
		printf("S: Slot %d offset: %08lx\n", currentSlot + 1, charOffset);
		u8* buffer = NULL;
		
		// Player General
		
		curOffset = charOffset + offsets.PLAY_TIME;
		res = FSFILE_Read(fileHand, &bytesread, curOffset, &(activeSlot->playTime), 4);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->funds), 4);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->hunterRank), 2);
		curOffset += 2; //Skip 2 1-byte unknowns (ezapm)
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->hunterArt1), 2);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->hunterArt2), 2);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->hunterArt3), 2);
		curOffset = charOffset + offsets.STORED_NAME;
		res = FSFILE_Read(fileHand, &bytesread, curOffset, activeSlot->name, 32);
		if (res) goto closeFile;
		printf("P%d: General loaded\n", currentSlot + 1);
		
		// Player Details
		
		curOffset = charOffset + offsets.CHARACTER_VOICE;
		res = FSFILE_Read(fileHand, &bytesread, curOffset, &(activeSlot->voice), 1);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->eyeColor), 1);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->clothing), 1);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->gender), 1);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->huntingStyle), 1);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->hairStyle), 1);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->face), 1);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->features), 1);
		if (res) goto closeFile;
		printf("P%d: Details loaded\n", currentSlot + 1);
		
		// Player Colors
		
		curOffset = charOffset + offsets.CHARACTER_SKIN_COLOR;
		res = FSFILE_Read(fileHand, &bytesread, curOffset, &(activeSlot->skinColorRGBA), 4);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->hairColorRGBA), 4);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->featuresColorRGBA), 4);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->clothingColorRGBA), 4);
		if (res) goto closeFile;
		printf("P%d: Colors loaded\n", currentSlot + 1);
		
		// Points
		
		curOffset = charOffset + offsets.HR_POINTS;
		res = FSFILE_Read(fileHand, &bytesread, curOffset, &(activeSlot->hrPoints), 4);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->zenny), 4);
		bytesread += 4; // Skip 4-byte unknown (ezapm)
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->academyPoints), 4);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->berunaPoints), 4);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->kokotoPoints), 4);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->pokkePoints), 4);
		res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(activeSlot->yukumoPoints), 4);
		if (res) goto closeFile;
		printf("P%d: Points loaded\n", currentSlot + 1);
		
		// Item Box
		curOffset = charOffset + offsets.ITEM_BOX;
		buffer = new u8[SIZEOF_ITEMBOX];
		res = FSFILE_Read(fileHand, &bytesread, curOffset, buffer, SIZEOF_ITEMBOX);
		if (res) goto closeFile;
		activeSlot->importItems(buffer, SIZEOF_ITEMBOX);
		printf("P%d: Item Box loaded\n", currentSlot + 1);
		delete [] buffer;
		
		// Pouch
		curOffset = charOffset + offsets.POUCH;
		buffer = new u8[SIZEOF_ITEMPOUCH];
		res = FSFILE_Read(fileHand, &bytesread, curOffset, buffer, SIZEOF_ITEMPOUCH);
		if (res) goto closeFile;
		activeSlot->importItems(buffer, SIZEOF_ITEMPOUCH);
		printf("P%d: Item Pouch loaded\n", currentSlot + 1);
		delete [] buffer;
		
		// Equipment
		curOffset = charOffset + offsets.EQUIPMENT_BOX;
		bytesread = 0;
		Equipment* importEquip = new Equipment[TOTAL_ITEM_BOX_SLOTS];
		for (int i = 0; i < TOTAL_ITEM_BOX_SLOTS; i++)
		{
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &importEquip[i], SIZEOF_EQUIPMENT);
		}
		if (res) goto closeFile;
		activeSlot->equipBox = importEquip;
		printf("P%d: Equipment box loaded\n", currentSlot + 1);
		
		// Palicos
		curOffset = charOffset + offsets.PALICO;
		buffer = new u8[SIZEOF_PALICO];
		Palico* importPalico = new Palico[TOTAL_PALICOS];
		bytesread = 0;
		for (int i = 0; i < TOTAL_PALICOS; i++)
		{
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), importPalico[i].name, SIZEOF_NAME);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].xp), 4);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].level), 1);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].forte), 1);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].enthusiasm), 1);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].target), 1);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), importPalico[i].equippedActions, 8);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), importPalico[i].equippedSkills, 8);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), importPalico[i].learnedActions, 16);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), importPalico[i].learnedSkills, 12);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].learnedActionRNG), 2);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].learnedSkillRNG), 2);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), importPalico[i].unknown1, 8);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), importPalico[i].greeting, 60);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), importPalico[i].nameGiver, 32);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), importPalico[i].previousMaster, 32);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), importPalico[i].unknown2, 51);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].voice), 1);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].eyes), 1);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].clothing), 1);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), importPalico[i].unknown3, 2);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].coat), 1);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].ears), 1);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].tail), 1);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), importPalico[i].unknown4, 3);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].coatRGBAValue), 4);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].leftEyeRGBAValue), 4);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].rightEyeRGBAValue), 4);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &(importPalico[i].vestRGBAValue), 4);
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), importPalico[i].unknown5, 21);
		}
		if (res) goto closeFile;
		activeSlot->palicos = importPalico;
		printf("P%d: Palicos loaded\n", currentSlot + 1);
		
		// Palico Equipment
		curOffset = charOffset + offsets.PALICO_EQUIPMENT;
		bytesread = 0;
		Equipment* palicoEquip = new Equipment[TOTAL_PALICO_EQUIPMENT_SLOTS];
		for (int i = 0; i < TOTAL_PALICO_EQUIPMENT_SLOTS; i++)
		{
			res = FSFILE_Read(fileHand, &bytesread, updateOffset(curOffset, bytesread), &palicoEquip[i], SIZEOF_EQUIPMENT);
		}
		if (res) goto closeFile;
		activeSlot->palicoEquip = palicoEquip;
		printf("P%d: Palico equipment box loaded\n", currentSlot + 1);
		
		// Guild Card
		
		//MonsterKills
		//MonsterCaptures
		
		// Shops
		
		//ArmorShops
		//WeaponShops
		//PalicoShops
		
		// Unlocked Box Data
		
		// Shoutouts
	}
	else
	{
		printf("S: Slot %d not in use\n", currentSlot + 1);
	}
closeFile:
	FSFILE_Close(fileHand);
}