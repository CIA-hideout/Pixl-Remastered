// Module:			Gameplay Programming
// Assignment 1:	Pixl

// Programming 2D Games
// Copyright (c) 2011 by:
// Charles Kelly
// Chapter 6 constants.h v1.0

#ifndef _CONSTANTS_H            // Prevent multiple definitions if this
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#define PI	3.14159265
#define G	6.67428e-11f

#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <string>
#include <vector>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }
#define TRANSCOLOR  SETCOLOR_ARGB(0,0,0,0)  // transparent color (magenta)

//-----------------------------------------------
//                  Constants
//-----------------------------------------------

// window
const char CLASS_NAME[] = "Pixl";
const char GAME_TITLE[] = "Pixl";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH = 1200;               // width of game in pixels
const UINT GAME_HEIGHT = 1000;               // height of game in pixels

// game
const float FRAME_RATE = 200.0f;                // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f / FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE; // maximum time used in calculations
const float MASS_PLANET = 1.0e14f;
const float MASS_SHIP = 5.0f;

const std::vector<std::string> CREDITS = {"-TEAM-", "Amos Tan", "Elcoms Khang", "Lin Lue", "-IN CHARGE-", "Tan Teck Jin Andrew", "Lee Ching Yun"};
const std::vector<std::string> MENU_OPTIONS = { "[S] tart", "[I] nstructions", "[H] ighscore", "[C] redits" };

// player
const int PLAYER_HEALTH						= 3;						// player starting health
const int PLAYER_MAX_HEALTH					= 10;						// player maximum health
const int PLAYER_START_FRAME				= 0;						// player starts at frame 0
const int PLAYER_END_FRAME					= 3;						// player animation frames 0,1,2,3
const float	PLAYER_SCALING					= 0.25f;					// player sprite scaling		
const int P_DEATH_START_FRAME				= 16;						// player death start frame number
const int P_DEATH_END_FRAME					= 40;						// player death end frame number
const float P_DEATH_SCALING					= 0.5f; 					// player death scaling
const float P_DEATH_ANIMATION_DELAY			= 0.1f;						// player death animation time between frames
const bool P_DEATH_LOOP						= false;					// player death animation loop
const int P_INVUL_START_FRAME				= 8;						// player invul start frame number
const int P_INVUL_END_FRAME					= 15;						// player invul end frame number
const float P_INVUL_SCALE					= 0.25f;					// player invul starting scale
const float P_INVUL_ANIMATION_DELAY			= 0.1f;						// player invul animation time between frames
const bool P_INVUL_LOOP						= true;						// player invul animation loop	
const int P_INVIN_START_FRAME				= 3;						// player invin start frame number
const int P_INVIN_END_FRAME					= 7;						// player invin end frame number
const float P_INVIN_SCALE					= 0.25f;					// player invin starting scale
const float P_INVIN_ANIMATION_DELAY			= 0.1f;						// player invin animation time between frames
const bool P_INVIN_LOOP						= true;						// Player invin animation loop

// GUI
const int INSTRUCTIONS_WIDTH = 512;
const int INSTRUCTIONS_HEIGHT = 512;
const int INSTRUCTIONS_COLS = 4;
const int INSTRUCTIONS_CONTROLS_START_FRAME = 0;
const int INSTRUCTIONS_CONTROLS_END_FRAME = 0;
const int INSTRUCTIONS_HOW_START_FRAME = 1;
const int INSTRUCTIONS_HOW_END_FRAME = 1;
const int INSTRUCTIONS_GOODLUCK_START_FRAME = 2;
const int INSTRUCTIONS_GOODLUCK_END_FRAME = 3;
const float INSTRUCTIONS_ANIMATION_DELAY = 0.2f;


//=================================
//		RESOURCE FILE PATHS
//=================================

// Player
const char PLAYER_TEXTURE[]					= "resources\\images\\player.png";

// Enemy
const char TRIANGLE_TEXTURE[]				= "resources\\images\\triangle.png";
const char CIRCLE_TEXTURE[]					= "resources\\images\\circle.png";
const char BLACKHOLE_TEXTURE[]				= "resources\\images\\blackhole.png";

// Pickups
const char DESTRUCTOR_OBSTRUCTOR_TEXTURE[]	= "resources\\images\\destructor_obstructor.png";
const char MISSILE_TEXTURE[]				= "resources\\images\\missile_animation_spritesheet.png";
const char EXPLOSION_TEXTURE[]				= "resources\\images\\explosion.png";
const char FREEZE_TEXTURE[]					= "resources\\images\\freeze_animation_spritesheet.png";

// GUI
const char FONT_TEXTURE[]					= "resources\\images\\font.png";
const char FONT_TEXTURE_INFO[]				= "resources\\data\\font.dat";
const char HEART_TEXTURE[] 					= "resources\\images\\sprite_hearts.png";
const char INSTRUCTIONS_TEXTURE[]			= "resources\\images\\instructions_animation_spritesheet.png";
const char SELECT_BOX_TEXTURE[]				= "resources\\images\\select_box.png";

// audio file required by audio.cpp
// WAVE_BANK must be the location of the xwb file
const char WAVE_BANK[] = "resources\\sounds\\Win\\Wave Bank.xwb";
// SOUND_BANK must be location of .xsb file
const char SOUND_BANK[] = "resources\\sounds\\Win\\Sound Bank.xsb";
// XGS_FILE must be location of .xgs file.
const char XGS_FILE[] = "resources\\sounds\\Win\\pixl-sound.xgs";

// Sound cues
const char PLAYER_PICKUP_SOUND[] = "pickup_good";			// player pick up a pickup
const char PLAYER_PICKUP_HEART_SOUND[] = "pickup_heart";	// player pickup a heart
const char PLAYER_DAMAGE_SOUND[] = "damage_player";			// player gets damaged
const char PLAYER_SELECT_SOUND[] = "push_button";			// player pushes space or esc
const char PICKUP_EXPLODE_SOUND[] = "explosion";			// explosion pickup, well explodes
const char PLAYER_DEAD_SOUND[] = "player_dead";				// player is killed

const char HIGHSCORE_FILE[]					= "resources\\data\\highscore.dat";


// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY = VK_ESCAPE;       // escape key
const UCHAR ALT_KEY = VK_MENU;         // Alt key
const UCHAR ENTER_KEY = VK_RETURN;       // Enter key
const UCHAR SHIP_ROTATE_LEFT = VK_LEFT;
const UCHAR SHIP_ROTATE_RIGHT = VK_RIGHT;
const UCHAR SHIP_ADD_V = VK_UP;
const UCHAR SHIP_SUBTRACT_V = VK_DOWN;
const UCHAR SPACEBAR = 0x20;

// weapon types
enum WEAPON {
	WEAPON_TRIANGLE,
	WEAPON_CIRCLE,
	WEAPON_BLACKHOLE,
	WEAPON_PLAYER,
	WEAPON_BOSS,
	WEAPON_MISSILE,
	WEAPON_EXPLOSION
};
#endif
