#ifndef __APPLEEXPLOSIONSTATE_H__

#define __APPLEEXPLOSIONSTATE_H__

#include "../ItemState.h"

NS_JK_BEGIN

class AppleExplosionState: public ItemState
{
public:
	AppleExplosionState();
	AppleExplosionState(Item* item);
	~AppleExplosionState();

	void onUpdate();
	void onExit();
	ItemState* checkTransition();
};

NS_JK_END

#endif
