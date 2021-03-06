﻿#ifndef __SIT_H__

#define __SIT_H__

#include "State.h"


NS_JK_BEGIN

class Sit : public State
{
public:
	Sit(Node* node);
	~Sit() override;

	void onEnter() override;
	void onUpdate() override;
	void onExit() override;
	State* checkTransition() override;

};

NS_JK_END

#endif __SIT_H__