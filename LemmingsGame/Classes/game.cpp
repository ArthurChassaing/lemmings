#include "game.h"
#include "sprite.h"
#define CC_CALLBACK_1

USING_NS_CC;

    Scene* game::createScene()
    {
       CCLOG("loading second scene");
       auto gameScene = game::create();
       Director::getInstance()->replaceScene(gameScene);
       return gameScene;
    }

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


bool game::init()
{
    if (!Scene::init())
    {
        return false;
    }

    CCLOG("in the second scene");

    auto bgSprite = Sprite::create("F:/lemmings/LemmingsGame/Assets/Battleground1.png");

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    cocos2d::Size screenSize = cocos2d::Director::getInstance()->getOpenGLView()->getFrameSize();
    cocos2d::Vec2 centerPos = cocos2d::Vec2(screenSize.width / 2.0f, screenSize.height / 2.0f);

    bgSprite->setContentSize(Size(1200, 800));
    bgSprite->setAnchorPoint(cocos2d::Vec2(0.5f, 0.5f));
    bgSprite->setPosition(cocos2d::Vec2(screenSize.width / 2.0f, screenSize.height / 2.0f));
    bgSprite->setVisible(true);

    this->addChild(bgSprite, 0);

    return true;
}

