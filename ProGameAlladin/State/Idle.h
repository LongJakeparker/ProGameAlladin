﻿#ifndef __IDLE_H__

#define __IDLE_H__
#include "State.h"

NS_JK_BEGIN
class Idle: public State
{
public:
	Idle(Node* node);
	~Idle() override;
	void onEnter() override;
	void onUpdate() override;
	State* checkTransition() override;
};

NS_JK_END
#endif __IDLE_H__
