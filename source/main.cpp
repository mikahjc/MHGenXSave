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
	char slotUsed[3];
	u32 charOffset[3];
	char playerName[3][32];
	u8* buffer = NULL;
	memset(playerName, 0, sizeof(playerName));
	//gfxSet3D(true); // uncomment if using stereoscopic 3D
	u32 low[3];
	low[0] = MEDIATYPE_SD;
	low[1] = 0x00001870;
	low[2] = 0;
	Handle filehand;
	Handle fileWrite;
	FS_Path pth = fsMakePath(PATH_ASCII, "/system");
	Result res = FSUSER_OpenFileDirectly(&filehand, ARCHIVE_EXTDATA, (FS_Path){PATH_BINARY, 0xC, (u8*)low}, pth, FS_OPEN_READ, 0);
	if(res)
	{
		FSFILE_Close(filehand);
		return -1;
	}
	else
	{
		printf("Opened system for reading\n");
		u32 bytesread;
		//res = FSFILE_Write(filehand, &bytesread, offsets.FIRST_CHAR_SLOT_USED, slotUsed, 0x3, FS_WRITE_UPDATE_TIME);
		buffer = new u8[3];
		res = FSFILE_Read(filehand, &bytesread, offsets.FIRST_CHAR_SLOT_USED, buffer, 0x3);
		for (int i = 0; i < 3; i++)
		{
			saveFile.slotUsed(i, buffer[i]);
		}
		printf("Read used slots\n");
		res = FSFILE_Read(filehand, &bytesread, offsets.FIRST_CHARACTER_OFFSET, charOffset, 0xC);
		printf("Read character offsets\n");
		buffer = new u8[SIZEOF_ITEMBOX];
		res = FSFILE_Read(filehand, &bytesread, charOffset[0] + offsets.ITEM_BOX_OFFSET, buffer, 0xC4E);
		if(res)
		{
			printf("Failed to read item box\n");
		}
		saveFile.importBox(0, buffer);
		printf("Read item box\n");
		delete [] buffer;
		buffer = new u8[SIZEOF_ITEMPOUCH];
		res = FSFILE_Read(filehand, &bytesread, charOffset[0] + offsets.POUCH_OFFSET, buffer, 0x48);
		if(res)
		{
			printf("Failed to open item pouch\n");
		}
		saveFile.importPouch(0, buffer);
		printf("Read item pouch\n");
		delete [] buffer;
		buffer = NULL;
		for(int i = 0; i < 3; i++)
		{
			res = FSFILE_Read(filehand, &bytesread, charOffset[i], saveFile.getName(i), 0x20);
		}
		printf("Read char names\n");
		res = FSFILE_Close(filehand);
		res = FSUSER_OpenFileDirectly(&fileWrite, ARCHIVE_EXTDATA, (FS_Path){PATH_BINARY, 0xC, (u8*)low}, pth, FS_OPEN_WRITE, 0);
		if(res)
		{
			printf("Failed to open system for writing\n");
		}
		else
		{
			printf("Opened system for writing\n");
			//saveFile.slot[0].itemPouch[0].itemAmount--;
			buffer = saveFile.packPouch(0);
			res = FSFILE_Write(fileWrite, &bytesread, charOffset[0] + offsets.POUCH_OFFSET, buffer, 0x48, FS_WRITE_FLUSH);
			if(res)
			{
				printf("Failed to write item pouch\n");
				printf("%d\n", res);
			}
			else
			{
				printf("Wrote item pouch\n");
			}
			delete [] buffer;
		}
		res = FSFILE_Close(fileWrite);
	}
	
	//importItems(itemBoxRaw, itemBox);
	
	gspWaitForVBlank();
	printf("Used save slots:\n");
	for(int i = 0; i < 3; i++)
	{
		if(saveFile.slotUsed(i) == true)
		{
			printf("Slot %d: %08x\n", i + 1, charOffset[i]);
			printf("\tCharacter Name: %s\n", saveFile.slot[i].name);
			printf("\tItem in box slot 1: %s\n\tQuantity: %d\n", ItemList[saveFile.slot[i].itemBox[0].itemID], saveFile.slot[i].itemBox[0].itemAmount);
			printf("\tItem in pouch slot 1: %s\n\tQuantity: %d\n", ItemList[saveFile.slot[i].itemPouch[0].itemID], saveFile.slot[i].itemPouch[0].itemAmount);
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
