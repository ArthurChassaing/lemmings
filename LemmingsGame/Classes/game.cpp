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

   auto visibleSize = Director::getInstance()->getVisibleSize();
   Vec2 origin = Director::getInstance()->getVisibleOrigin();

   cocos2d::Size screenSize = cocos2d::Director::getInstance()->getOpenGLView()->getFrameSize();
   cocos2d::Vec2 centerPos = cocos2d::Vec2(screenSize.width / 2.0f, screenSize.height / 2.0f);

   auto map = TMXTiledMap::create("Map.tmx");
   map->setScale(2.1);
   this->addChild(map);



    // add bomb button
    auto bombButton = ui::Button::create("F:/lemmings/LemmingsGame/Assets/bomb.png", "F:/lemmings/LemmingsGame/Assets/bomb.png", "F:/lemmings/LemmingsGame/Assets/bomb.png");

    bombButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {


        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:

            break;
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });

    if (bombButton == nullptr)
    {
        problemLoading("'bomb.png'");
    }
    else
    {
        // position the sprite on the screen
        bombButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, 50));
        bombButton->setScale(10.0);

        // add the sprite as a child to this layer
        this->addChild(bombButton, 2);
    }

    return true;
}

