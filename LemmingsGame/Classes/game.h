#pragma once

#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class game : public cocos2d::Scene
{
public:
	//static cocos2d::Scene* createScene();
	void pauseScreen();

	virtual bool init();
	
	static cocos2d::Scene* createScene();

	CREATE_FUNC(game);


private:
	bool pauseMenuOpen = false;
};

