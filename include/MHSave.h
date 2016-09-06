#include "Character.h"

class MHSave {
	public:
	Character slot[3];
	bool test;
	bool slotUsed(int slot, bool used);
	bool slotUsed(int slot);
	u8* getName(int slot);
	u8* packPouch(int slot);
	u8* packBox(int slot);
	void importPouch(int slot, u8 buffer[]);
	void importBox(int slot, u8 buffer[]);
	Equipment* getEquipment(int saveSlot, int equipSlot);
};