#include <string.h>
#include <stdio.h>
#include <3ds.h>
#include "GameConstants.h"
#include "Offsets.h"
#include "MHSave.h"
#include "Constants.h"

int main()
{
	Offsets offsets;
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);
	gfxSetDoubleBuffering(GFX_TOP, false);
	MHSave saveFile;
	memset(&saveFile, 0, sizeof(saveFile));
	//u8* buffer = NULL;
	//gfxSet3D(true); // uncomment if using stereoscopic 3D
	/*u32 low[3];
	low[0] = MEDIATYPE_SD;
	low[1] = 0x00001870;
	low[2] = 0;*/
	
	gspWaitForVBlank();
	for(int i = 0; i < 3; i++)
	{
		saveFile.selectSlot(i);
		saveFile.loadSlot();
	}
	for(int i = 0; i < 3; i++)
	{
		saveFile.selectSlot(i);
		if(saveFile.slotInUse())
		{
			printf("\nSlot %d\n", i + 1);
			printf("\tCharacter Name: %s\n", saveFile.getName());
			printf("\tItem in box slot 1: %s x%lu\n", ItemList[saveFile.getItemBox(0).itemID], saveFile.getItemBox(0).itemAmount);
			printf("\tItem in pouch slot 1: %s x%lu\n", ItemList[saveFile.getItemPouch(0).itemID], saveFile.getItemPouch(0).itemAmount);
			printf("\tItem in equip box slot 1: %s\n\t\t\t\t\t\t\t\t\t\tLvl %hhu\n", AllEquip[saveFile.getEquipment(12).getType()][saveFile.getEquipment(12).getID()], saveFile.getEquipment(12).getLevel() + 1);
			printf("\tFirst Palico: %s  Lvl %hhu\n", saveFile.getPalico(0).name, saveFile.getPalico(0).level + 1);
		}
	}
	gspWaitForVBlank();
	printf("\nPress start to exit...");
	// Your code goes here
		// Example rendering code that displays a white pixel
		// Please note that the 3DS screens are sideways (thus 240x400 and 240x320)
		/*u8* fb = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
		memset(fb, 0, 240*400*3);
		fb[3*(10+10*240)] = 0xFF;
		fb[3*(10+10*240)+1] = 0xFF;
		fb[3*(10+10*240)+2] = 0xFF;*/
		
	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();	
		
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
	}

	gfxExit();
	return 0;
}
