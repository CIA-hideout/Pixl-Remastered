#include "Pickup.h"

Pickup::Pickup() : Entity(){
	spriteData.width = PickupNS::WIDTH;
	spriteData.height = PickupNS::HEIGHT;
	spriteData.rect.bottom = PickupNS::HEIGHT;
	spriteData.rect.right = PickupNS::WIDTH;
	spriteData.scale = PickupNS::SCALING;
	velocity.x = 0;
	velocity.y = 0;
	startFrame = PickupNS::PICKUP_START_FRAME;
	endFrame = PickupNS::PICKUP_END_FRAME;
	currentFrame = 0;
	radius = PickupNS::WIDTH / 2.0f;
	mass = PickupNS::MASS;
	collisionType = entityNS::CIRCLE;
	objectType = OBJECT_TYPE_PICKUP;
	bool destructor = true;
}

bool Pickup::initialize(Game *gamePtr, int width, int height, int ncols, TextureManager *textureM){
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Pickup::draw(){
	Image::draw();
}

void Pickup::update(float deltaTime){

}

void Pickup::spawn(){

	setFrames(startFrame, endFrame);
	setCollisionRadius(getHeight() / 2);
	setVelocity(0, 0);						// powerups don't move;
	setObjectType(OBJECT_TYPE_CIRCLE);
	setScale(0.2f);

	//spawn randomly in window
	int side = rand() % 4;

	switch (side) {
		// left
	case 0: {
				this->setX(0 - rand() % GAME_WIDTH);
				this->setY(rand() % GAME_HEIGHT);
	} break;
		// top
	case 1: {
				this->setX(rand() % GAME_WIDTH);
				this->setY(-(rand() % GAME_HEIGHT));
	} break;
		// right
	case 2: {
				this->setX(GAME_WIDTH + GAME_WIDTH - rand() % GAME_WIDTH);
				this->setY(rand() % GAME_HEIGHT);
	} break;
		// bottom
	case 3: {
				this->setX(rand() % GAME_WIDTH);
				this->setY(GAME_HEIGHT + GAME_HEIGHT - rand() % GAME_HEIGHT);
	} break;
	}

	this->setX(rand() % GAME_WIDTH);
	this->setY(rand() % GAME_HEIGHT);

	this->setScale(0.5);
}

void Pickup::damage(WEAPON weapon){
	switch (weapon)
	{
		case OBJECT_TYPE_PLAYER: {
									 // this->setHealth(0);
		}	break;
	}
}

void Pickup::setPickUpType(){ 			// Calculate whether is an Obstructor or Destructor
	int number = rand() % 100;

	if (number >= 80)			// 20% chance of a Obstructor
		destructor = false;
	else						// 80% chance of a Destructor
		destructor = true;

		calculatePickupType();
}

void Pickup::setPickUpType(PickupType pickupType) {
	this->type = pickupType;
	this->destructor = getPickupType() == PICKUP_DESTRUCTOR_EXPLOSION || getPickupType() == PICKUP_DESTRUCTOR_FREEZE || getPickupType() == PICKUP_DESTRUCTOR_INVULNERABILITY || getPickupType() == PICKUP_DESTRUCTOR_MISSLES;
}

/* ========================================	*/
/*			Private Methods					*/
/* ========================================	*/
//	Calculate the type of Obstrutor or Destructor the pickup is

//	return effects of pickups in a string format
//	enum is not supported in console
//	use for debug purposes
void Pickup::getEffectDebug()
{
	switch (type) {
	case PICKUP_OBSTRUCTOR_INVERT_CONTROLS:	printf("PICKUP_OBSTRUCTOR_INVERT_CONTROLS\n");
		break;
	case PICKUP_OBSTRUCTOR_STUN_PLAYER:		printf("PICKUP_OBSTRUCTOR_STUN_PLAYER\n");
		break;
	case PICKUP_OBSTRUCTOR_SLOW_PLAYER:		printf("PICKUP_OBSTRUCTOR_SLOW_PLAYER\n");
		break;
	case PICKUP_OBSTRUCTOR_ENLARGE_PLAYER:	printf("PICKUP_OBSTRUCTOR_ENLARGE_PLAYER\n");
		break;
	case PICKUP_OBSTRUCTOR_BLACKHOLE:		printf("OBSTRUCTOR_BLACKHOLE\n");
		break;
	case PICKUP_DESTRUCTOR_EXPLOSION:		printf("PICKUP_DESTRUCTOR_EXPLOSION\n");
		break;
	case PICKUP_DESTRUCTOR_MISSLES:			printf("PICKUP_DESTRUCTOR_MISSLES\n");
		break;
	case PICKUP_DESTRUCTOR_FREEZE:			printf("PICKUP_DESTRUCTOR_FREEZE\n");
		break;
	case PICKUP_DESTRUCTOR_INVULNERABILITY:	printf("PICKUP_DESTRUCTOR_INVULNERABILITY\n");
		break;
	case PICKUP_HEALTH:						printf("PICKUP_HEALTH\n");
		break;
	default:							printf("NO PICKUPS\n");
	}
}


//	Calculate the type of Obstrutor or Destructor the pickup is
void Pickup::calculatePickupType(){

	setPickUpType();
	int randNumber;

	// Array containing types of obstructor
	PickupType obstructorArray[] = {
		PICKUP_OBSTRUCTOR_SLOW_PLAYER,
		PICKUP_OBSTRUCTOR_SLOW_PLAYER,

		PICKUP_OBSTRUCTOR_STUN_PLAYER,
		PICKUP_OBSTRUCTOR_STUN_PLAYER,

		PICKUP_OBSTRUCTOR_INVERT_CONTROLS,
		PICKUP_OBSTRUCTOR_INVERT_CONTROLS,

		PICKUP_OBSTRUCTOR_ENLARGE_PLAYER,
		PICKUP_OBSTRUCTOR_ENLARGE_PLAYER,

		PICKUP_OBSTRUCTOR_BLACKHOLE
	};

	//	Array containing types of Destructor
	PickupType destructorArray[] = {
		PICKUP_DESTRUCTOR_EXPLOSION,
		PICKUP_DESTRUCTOR_EXPLOSION,
		PICKUP_DESTRUCTOR_EXPLOSION,

		PICKUP_DESTRUCTOR_MISSLES,
		PICKUP_DESTRUCTOR_MISSLES,
		PICKUP_DESTRUCTOR_MISSLES,

		PICKUP_DESTRUCTOR_FREEZE,
		PICKUP_DESTRUCTOR_FREEZE,

		PICKUP_DESTRUCTOR_INVULNERABILITY,
		PICKUP_DESTRUCTOR_INVULNERABILITY
	};

	if (this->destructor())
	{
		randNumber = rand() % 10;	//Get a number from 0 - 9
		type = destructorArray[randNumber];
	}
	else // is an obstructor
	{
		randNumber = rand() % 9;	//Get a number from 0 - 8
		type = obstructorArray[randNumber];
	}

	if (destructor)
		this->setCurrentFrame(0);
	else
		this->setCurrentFrame(1);
}
