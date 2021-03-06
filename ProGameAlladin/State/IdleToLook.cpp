﻿#include "IdleToLook.h"
#include "HeadUp.h"
#include "../Framework/Input.h"
#include "Jump.h"
#include "HeadUpAndSlash.h"
#include "Throw.h"
#include "Idle.h"
#include "../GameObject/Aladdin.h"

US_NS_JK

IdleToLook::IdleToLook(Node* node):State(node)
{

}

IdleToLook::~IdleToLook()
{
}

void IdleToLook::onEnter()
{
	auto aladdin = static_cast<Aladdin*>(_node);
	aladdin->setActionName("IdleToLook");
}


State* IdleToLook::checkTransition()
{
	const auto aladdin = static_cast<Aladdin*>(_node);
	if (Input::getInstance()->getKey(KEY_D))
		return new Jump(_node);
	/*if (Input::getInstance()->getKey(KEY_DOWN_ARROW) && Input::getInstance()->isAnyKeyDown())
	return new Sit(_node);*/
	if (Input::getInstance()->getKey(KEY_S))
		return new HeadUpAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_A) && aladdin->getNumApple() > 0)
		return new Throw(_node);
	if (Input::getInstance()->isKeyUp(KEY_UP_ARROW))
		return new Idle(_node);
	if (Input::getInstance()->getKey(KEY_UP_ARROW) && !Input::getInstance()->isKeyUp(KEY_UP_ARROW)&& aladdin->isOnTheGround())
		return new HeadUp(_node);
	return nullptr;
}
