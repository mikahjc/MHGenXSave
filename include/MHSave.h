#include "Character.h"
#include <3ds.h>
#include <Offsets.h>

class MHSave {
	private:
	Character slot[3];
	Character* activeSlot;
	bool used[3];
	bool test;
	u8 currentSlot = 0;
	u32 updateOffset(u32 &offset, u32 update);
	public:
	MHSave()
	{
		currentSlot = 0;
		activeSlot = NULL;
	}
	void loadSlot();
	void selectSlot(int slot);
	bool slotInUse(bool used);
	bool slotInUse();
	u8* getName();
	void setName(u8 buffer[32]);
	void loadOffsets();
	u32 getOffset();
	u8* packPouch();
	u8* packBox();
	Equipment getEquipment(int equipSlot);
	Item getItemBox(int index);
	Item getItemPouch(int index);
	Palico getPalico(int index);
};