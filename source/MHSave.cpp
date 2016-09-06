#include "MHSave.h"

bool MHSave::slotUsed(int slot)
{
	return this->slot[slot].used;
}

bool MHSave::slotUsed(int slot, bool used)
{
	this->slot[slot].used = used;
	return true;
}

u8* MHSave::getName(int slot)
{
	return this->slot[slot].name;
}

u8* MHSave::packPouch(int slot)
{
	return this->slot[slot].packItems(ITEMPOUCH);
}

u8* MHSave::packBox(int slot)
{
	return this->slot[slot].packItems(ITEMBOX);
}

void MHSave::importPouch(int slot, u8 buffer[])
{
	this->slot[slot].importItems(buffer, ITEMPOUCH);
}
void MHSave::importBox(int slot, u8 buffer[])
{
	this->slot[slot].importItems(buffer, ITEMBOX);
}

Equipment* MHSave::getEquipment(int saveSlot, int equipSlot)
{
	return &(slot[saveSlot].equipBox[equipSlot]);
}