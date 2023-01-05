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

    initWithPhysics();

    //this->getPhysicsWorld()->setGravity(Vec2(0, -10));
    

    CCLOG("in the second scene");


   auto visibleSize = Director::getInstance()->getVisibleSize();
   Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
   auto map = TMXTiledMap::create("Map.tmx");
   map->setScale(1.1);
   this->addChild(map);

   auto layer = map->getLayer("Wall");
   sprite* test = new sprite;
   test->setSprite(this);


    // add bomb button
    //auto bombButton = ui::Button::create("F:/lemmings/LemmingsGame/Assets/bomb.png", "F:/lemmings/LemmingsGame/Assets/bomb.png", "F:/lemmings/LemmingsGame/Assets/bomb.png");

    //bombButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {


    //    switch (type)
    //    {
    //    case ui::Widget::TouchEventType::BEGAN:

    //        break;
    //    case ui::Widget::TouchEventType::ENDED:
    //        break;
    //    default:
    //        break;
    //    }
    //    });

    //if (bombButton == nullptr)
    //{
    //    problemLoading("'bomb.png'");
    //}
    //else
    //{
    //    // position the sprite on the screen
    //    bombButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, 50));
    //    bombButton->setScale(10.0);

    //    // add the sprite as a child to this layer
    //    this->addChild(bombButton, 2);
    //}


    return true;
}

