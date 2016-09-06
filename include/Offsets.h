	struct Offsets
	{	
		const u16 FIRST_CHAR_SLOT_USED = 0x04; //Size 1
        const u16 SECOND_CHAR_SLOT_USED = 0x05; //Size 1
        const u16 THIRD_CHAR_SLOT_USED = 0x06; //Size 1
        const u16 FIRST_CHARACTER_OFFSET = 0x10; //Size 4
        const u16 SECOND_CHARACTER_OFFSET = 0x14; //Size 4
        const u16 THIRD_CHARACTER_OFFSET = 0x18; //Size 4

        //Character Offsets [CHARACTER BASE +  CHARACTER OFFSET]
        const u16 NAME_OFFSET = 0x00; //Size 32
        const u16 PLAY_TIME_OFFSET = 0x20; //Size 4
        //const u16 FUNDS_OFFSET = 0x24; //Size 4 ;What it shows on save menu ?
        //const u16 HUNTER_RANK_OFFSET = 0x28; //Size 2 
        //const u16 HUNTER_ART_1_OFFSET = 0x2C; //Size 2
        //const u16 HUNTER_ART_2_OFFSET = 0x2E; //Size 2
        //const u16 HUNTER_ART_3_OFFSET = 0X30; //Size 2
        const u16 EQUIPPED_WEAPON_OFFSET = 0x010C; //Size 48
        const u16 EQUIPPED_HEAD_OFFSET = 0x013C; //Size 48
        const u16 EQUIPPED_CHEST_OFFSET = 0x016C; //Size 48
        const u16 EQUIPPED_ARMS_OFFSET = 0x019c; //Size 48
        const u16 EQUIPPED_WAIST_OFFSET = 0x01CC; //Size 48
        const u16 EQUIPPED_LEG_OFFSET = 0x01FC; //Size 48
        const u16 EQUIPPED_TALISMAN_OFFSET = 0x022C; //Size 48
        const u16 WEAPON_TYPE_OFFSET = 0x025C; //Size 1
        const u32 CHARACTER_VOICE_OFFSET = 0x193BB;
        //const u16 CHARACTER_VOICE_OFFSET = 0x025D; //Size 1
        //const u16 CHARACTER_EYE_COLOR_OFFSET = 0x025E; //Size 1
        //const u16 CHARACTER_CLOTHING_OFFSET = 0x025F; //Size 1
        //const u16 CHARACTER_GENDER_OFFSET = 0x0260;  //Size 1
        //const u16 CHARACTER_HUNTING_STYLE_OFFSET = 0x0261; //Size 1
        //const u16 CHARACTER_HAIRSTYLE_OFFSET = 0x0262; //Size 1
        //const u16 CHARACTER_FACE_OFFSET = 0x0263; //Size 1
        //const u16 CHARACTER_FEATURES_OFFSET = 0x0264; //Size 1
        //const u16 CHEST_ARMOR_PIGMENT_OFFSET = 0x0268; //Size 4
        //const u16 ARMS_ARMOR_PIGMENT_OFFSET = 0x026C; //Size 4 
        //const u16 WAIST_ARMOR_PIGMENT_OFFSET = 0x0270;  //Size 4
        //const u16 LEG_ARMOR_PIGMENT_OFFSET = 0x0274; //Size 4
        //const u16 HEAD_ARMOR_PIGMENT_OFFSET = 0x0278; //Size 4
        //const u16 CHARACTER_SKIN_COLOR_OFFSET = 0x027C; //Size 4 ;This only used in loading screen
        const u32 CHARACTER_SKIN_COLOR_OFFSET = 0x0193DA; //Size 4 
        //const u16 CHARACTER_HAIR_COLOR_OFFSET = 0x0280; //Size 4
        //const u16 CHARACTER_FEATURES_COLOR_OFFSET = 0x0284; //Size 4
        //const u16 CHARACTER_CLOTHING_COLOR_OFFSET = 0x0288; //Size 4
        const u16 ITEM_BOX_OFFSET = 0x0290; //Size 3150 (1400 of them each 18 bits long)
        const u16 EQUIPMENT_BOX_OFFSET = 0x4667; //Size 50415 (1400 of them each 36 bytes long)
        const u16 ITEM_SET_OFFSET = 0x0EDE; //Size 1360 (8 of them each 170 bytes long)
        const u16 POUCH_OFFSET = 0x142E; //Size 72 (32 Items each 18 bits long)

        const u32 STORED_NAME_OFFSET = 0x0193ED; //Size 32
        const u32 STORED_PLAY_TIME_OFFSET = 0x18792; //Size 4

        const u16 HR_POINTS_OFFSET = 0x1476; //Size 4
        //const u16 ZENNY_OFFSET = 0x147A; //Size 4
        //const u16 UNKNOWN_FUNDS_OFFSET = 0x147E; //Size 4
        //const u16 ACADEMY_POINTS_OFFSET = 0x1482; //Size 4
        //const u16 BERUNA_POINTS_OFFSET = 0x1486; //Size 4
        //const u16 KOKOTO_POINTS_OFFSET = 0X148A; //Size 4
        //const u16 POKKE_POINTS_OFFSET = 0x148E; //Size 4
        //const u16 YUKUMO_POINTS_OFFSET = 0x1492; //Size 4
        const u32 PALICO_OFFSET = 0x019426; //Size 19140 (60 of them each 319 bytes long)
        const u32 PALICO_EQUIPMENT_OFFSET = 0x10B47; //Size 25200 (700 of them 36 bytes long)

        const u32 SHOP_OFFSETS = 0x1D76;
        const u32 CRAFTABLE_WEAPONS_OFFSET = 0x20BE;
        const u32 CRAFTABLE_ARMOR_SHOP_OFFSET = 0x2316;
        const u32 CRAFTABLE_PALICO_GEAR_OFFSET = 0x02ABE;

        const u32 PLAYER_GUILD_CARD_OFFSET = 0x09F0FE; //Size 5208

        const u16 UNLOCKED_BOXES_OFFSET = 0x1A22; //Size 8

        const u16 MONSTERHUNT_OFFSETS = 0x42E7; //71 Monsters 2 bytes each
        const u16 MONSTERCAPTURE_OFFSETS = 0x43C7; //71 Monsters 2 bytes each

        const u32 SHOUTOUT_OFFSETS = 0xEAD6E;
        const u32 AUTOMATIC_SHOUTOUT_OFFSETS = 0xEB72E;

        const u16 PALICO_NAME_OFFSET = 0x00; //Size 32
        const u16 PALICO_EXP_OFFSET = 0x20; //Size 4
        const u16 PALICO_LEVEL_OFFSET = 0x24; //Size 1
        const u16 PALICO_FORTE_OFFSET = 0x25; //Size 1
        const u16 PALICO_ENTHUSIASM_OFFSET = 0x26; //Size 1
        const u16 PALICO_TARGET_OFFSET = 0x27; //Size 1
        const u16 PALICO_EQUIPPED_ACTIONS_OFFSET = 0x28; //Size 8 (8 of them 1 byte each)
        const u16 PALICO_EQUIPPED_SKILLS_OFFSET = 0x30; //Size 8 (8 of them 1 byte each)
        const u16 PALICO_LEARNED_ACTIONS_OFFSET = 0x38; //Size 16 (16 of them 1 byte each)
        const u16 PALICO_LEARNED_SKILLS_OFFSET = 0x48; //Size 16 (16 of them 1 byte each)
        const u16 PALICO_LEARNED_ACTION_RNG_OFFSET = 0x54; //Size 2
        const u16 PALICO_LEARNED_SKILL_RNG_OFFSET = 0x56; //Size 2
        const u16 PALICO_GREETING_OFFSET = 0x60; //Size 60
        const u16 PALICO_NAME_GIVER_OFFSET = 0x9C; //Size 32
        const u16 PALICO_PREVIOUS_MASTER_OFFSET = 0xBC; //Size 32
        const u16 PALICO_RGBA_VALUE_OFFSET = 0x011A; //Size 4
    
        const u16 GUILD_CARD_ID_OFFSET = 0x0828; //Size 8
        //Guild Card Offsets by Ukee
        const u16 PLAYTIME_OFFSET = 0x088C; //Size 4
        const u16 VILLAGE_WEAPON_USAGE_OFFSET = 0x0830; //Size 30
        const u16 LOW_HUB_WEAPON_USAGE_OFFSET = 0x084E; //Size 30
        const u16 HUB_WEAPON_USAGE_OFFSET = 0x086C; //Size 30

        const u16 VILLAGE_QUEST_OFFSETS = 0x07DA; //Size 2
        const u16 LOW_HUB_QUEST_OFFSETS = 0x07DC; //Size 2
        const u16 HIGH_HUB_QUEST_OFFSETS = 0x07DE; //Size 2
        const u16 SPECIAL_PERMIT_QUEST_OFFSETS = 0x07e0; //Size 2
        const u16 ARENA_QUEST_OFFSETS = 0x07E2; //Size 2
        const u16 STREET_PASS_OFFSETS = 0x07E8; //Size 2
        const u16 MONSTER_HUNT_OFFSETS = 0x0EE0; //Size 552 (69 Monsters, 8 Bytes Each)
    };