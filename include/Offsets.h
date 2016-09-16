#pragma once	
	struct Offsets
	{	
		const u16 FIRST_CHAR_SLOT_USED = 0x04; //Size 1
        const u16 SECOND_CHAR_SLOT_USED = 0x05; //Size 1
        const u16 THIRD_CHAR_SLOT_USED = 0x06; //Size 1
        const u16 FIRST_CHARACTER = 0x10; //Size 4
        const u16 SECOND_CHARACTER = 0x14; //Size 4
        const u16 THIRD_CHARACTER = 0x18; //Size 4

        //Character Offsets [CHARACTER BASE +  CHARACTER OFFSET]
        const u16 NAME = 0x00; //Size 32
        const u16 PLAY_TIME = 0x20; //Size 4
        const u16 FUNDS = 0x24; //Size 4 ;What it shows on save menu ?
        const u16 HUNTER_RANK = 0x28; //Size 2 
        const u16 HUNTER_ART_1 = 0x2C; //Size 2
        const u16 HUNTER_ART_2 = 0x2E; //Size 2
        const u16 HUNTER_ART_3 = 0X30; //Size 2
        const u16 EQUIPPED_WEAPON = 0x010C; //Size 48
        const u16 EQUIPPED_HEAD = 0x013C; //Size 48
        const u16 EQUIPPED_CHEST = 0x016C; //Size 48
        const u16 EQUIPPED_ARMS = 0x019c; //Size 48
        const u16 EQUIPPED_WAIST = 0x01CC; //Size 48
        const u16 EQUIPPED_LEG = 0x01FC; //Size 48
        const u16 EQUIPPED_TALISMAN = 0x022C; //Size 48
        const u16 WEAPON_TYPE = 0x025C; //Size 1
        const u32 CHARACTER_VOICE_2 = 0x193BB;
        const u16 CHARACTER_VOICE = 0x025D; //Size 1
        const u16 CHARACTER_EYE_COLOR = 0x025E; //Size 1
        const u16 CHARACTER_CLOTHING = 0x025F; //Size 1
        const u16 CHARACTER_GENDER = 0x0260;  //Size 1
        const u16 CHARACTER_HUNTING_STYLE = 0x0261; //Size 1
        const u16 CHARACTER_HAIRSTYLE = 0x0262; //Size 1
        const u16 CHARACTER_FACE = 0x0263; //Size 1
        const u16 CHARACTER_FEATURES = 0x0264; //Size 1
        //const u16 CHEST_ARMOR_PIGMENT = 0x0268; //Size 4
        //const u16 ARMS_ARMOR_PIGMENT = 0x026C; //Size 4 
        //const u16 WAIST_ARMOR_PIGMENT = 0x0270;  //Size 4
        //const u16 LEG_ARMOR_PIGMENT = 0x0274; //Size 4
        //const u16 HEAD_ARMOR_PIGMENT = 0x0278; //Size 4
        //const u16 CHARACTER_SKIN_COLOR = 0x027C; //Size 4 ;This only used in loading screen
        const u32 CHARACTER_SKIN_COLOR = 0x0193DA; //Size 4 
        const u16 CHARACTER_HAIR_COLOR = 0x0280; //Size 4
        const u16 CHARACTER_FEATURES_COLOR = 0x0284; //Size 4
        const u16 CHARACTER_CLOTHING_COLOR = 0x0288; //Size 4
        const u16 ITEM_BOX = 0x0290; //Size 3150 (1400 of them each 18 bits long)
        const u16 EQUIPMENT_BOX = 0x4667; //Size 50415 (1400 of them each 36 bytes long)
        const u16 ITEM_SET = 0x0EDE; //Size 1360 (8 of them each 170 bytes long)
        const u16 POUCH = 0x142E; //Size 72 (32 Items each 18 bits long)

        const u32 STORED_NAME = 0x0193ED; //Size 32
        const u32 STORED_PLAY_TIME = 0x18792; //Size 4

        const u16 HR_POINTS = 0x1476; //Size 4
        const u16 ZENNY = 0x147A; //Size 4
        //const u16 UNKNOWN_FUNDS = 0x147E; //Size 4
        //const u16 ACADEMY_POINTS = 0x1482; //Size 4
        //const u16 BERUNA_POINTS = 0x1486; //Size 4
        //const u16 KOKOTO_POINTS = 0X148A; //Size 4
        //const u16 POKKE_POINTS = 0x148E; //Size 4
        //const u16 YUKUMO_POINTS = 0x1492; //Size 4
        const u32 PALICO = 0x019426; //Size 19140 (60 of them each 319 bytes long)
        const u32 PALICO_EQUIPMENT = 0x10B47; //Size 25200 (700 of them 36 bytes long)

        const u32 SHOPS = 0x1D76;
        const u32 CRAFTABLE_WEAPONS = 0x20BE;
        const u32 CRAFTABLE_ARMOR_SHOP = 0x2316;
        const u32 CRAFTABLE_PALICO_GEAR = 0x02ABE;

        const u32 PLAYER_GUILD_CARD = 0x09F0FE; //Size 5208

        const u16 UNLOCKED_BOXES = 0x1A22; //Size 8

        const u16 MONSTERHUNTS = 0x42E7; //71 Monsters 2 bytes each
        const u16 MONSTERCAPTURES = 0x43C7; //71 Monsters 2 bytes each

        const u32 SHOUTOUTS = 0xEAD6E;
        const u32 AUTOMATIC_SHOUTOUTS = 0xEB72E;

        const u16 PALICO_NAME = 0x00; //Size 32
        const u16 PALICO_EXP = 0x20; //Size 4
        const u16 PALICO_LEVEL = 0x24; //Size 1
        const u16 PALICO_FORTE = 0x25; //Size 1
        const u16 PALICO_ENTHUSIASM = 0x26; //Size 1
        const u16 PALICO_TARGET = 0x27; //Size 1
        const u16 PALICO_EQUIPPED_ACTIONS = 0x28; //Size 8 (8 of them 1 byte each)
        const u16 PALICO_EQUIPPED_SKILLS = 0x30; //Size 8 (8 of them 1 byte each)
        const u16 PALICO_LEARNED_ACTIONS = 0x38; //Size 16 (16 of them 1 byte each)
        const u16 PALICO_LEARNED_SKILLS = 0x48; //Size 16 (16 of them 1 byte each)
        const u16 PALICO_LEARNED_ACTION_RNG = 0x54; //Size 2
        const u16 PALICO_LEARNED_SKILL_RNG = 0x56; //Size 2
        const u16 PALICO_GREETING = 0x60; //Size 60
        const u16 PALICO_NAME_GIVER = 0x9C; //Size 32
        const u16 PALICO_PREVIOUS_MASTER = 0xBC; //Size 32
        const u16 PALICO_RGBA_VALUE = 0x011A; //Size 4
    
        const u16 GUILD_CARD_ID = 0x0828; //Size 8
        //Guild Card Offsets by Ukee
        const u16 PLAYTIME = 0x088C; //Size 4
        const u16 VILLAGE_WEAPON_USAGE = 0x0830; //Size 30
        const u16 LOW_HUB_WEAPON_USAGE = 0x084E; //Size 30
        const u16 HUB_WEAPON_USAGE = 0x086C; //Size 30

        const u16 VILLAGE_QUESTS = 0x07DA; //Size 2
        const u16 LOW_HUB_QUESTS = 0x07DC; //Size 2
        const u16 HIGH_HUB_QUESTS = 0x07DE; //Size 2
        const u16 SPECIAL_PERMIT_QUESTS = 0x07e0; //Size 2
        const u16 ARENA_QUESTS = 0x07E2; //Size 2
        const u16 STREET_PASSS = 0x07E8; //Size 2
        const u16 MONSTER_HUNTS = 0x0EE0; //Size 552 (69 Monsters, 8 Bytes Each)
    };