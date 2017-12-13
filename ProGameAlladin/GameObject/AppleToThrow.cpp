﻿#include "AppleToThrow.h"
#include "../Framework/Graphics.h"
US_NS_JK

AppleToThrow::AppleToThrow(const Vec2 & position, const Size & size):GameObject(position,size, APPLES)
{
	_rigid->setBodyType(DYNAMIC);
	_rigid->setDensity(0.5);
	_rigid->setRestitution(0);
	_rigid->setGravityScale(1);
	setPosition(_rigid->getPosition());
	setScale(Vec2(1.8, 1.8));
	_rigid->setTag("appletothrow");

	_isCollision = false;
}

AppleToThrow::~AppleToThrow()
{
}

void AppleToThrow::init()
{
	_textureApple.setName("AppleToThrow.png");
	_textureApple.setSrcFile("Resources/apple1.png");
	Graphics::getInstance()->loadTexture(_textureApple);
}

void AppleToThrow::update()
{
	this->_position = _rigid->getPosition() - _rigid->getOffset();

	const auto collisionWithEnemy = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"enermy");
	const auto collisionWithWall = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"wall");
	const auto collisionWithGround = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"ground");
	const auto collisionWithPlatform = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()),"platform");

	if (collisionWithEnemy == _rigid->getCollidingBodies().end())
		_isCollision = false;
	else if (collisionWithWall == _rigid->getCollidingBodies().end())
		_isCollision = false;
	else if (collisionWithGround == _rigid->getCollidingBodies().end())
		_isCollision = false;
	else if (collisionWithPlatform == _rigid->getCollidingBodies().end())
		_isCollision = false;
	else
		_isCollision = true;

	if(_isCollision)
	{
		//getCurrentScene()->removeNode(this);
	}
}

void AppleToThrow::release()
{
	delete _rigid;
	delete this;
}

void AppleToThrow::render()
{
	Graphics::getInstance()->drawSprite(_textureApple, Vec2(0.3f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), 
		Rect(0, 0, 5, 6), 1);
}

Texture AppleToThrow::getTexture() const
{
	return _textureApple;
}

void AppleToThrow::setVelocity(const Vec2& velocity)
{
	_rigid->setVelocity(velocity);
}

bool AppleToThrow::isCollision() const
{
	return _isCollision;
}
