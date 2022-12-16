#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto startScene = HelloWorld::create();
    return startScene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("LE JEU", "fonts/Marker Felt.ttf", 84);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add start screen background"
    auto sprite = Sprite::create("F:/lemmings/LemmingsGame/title_screen_image_2.png");
    if (sprite == nullptr)
    {
        problemLoading("'title_screen_image_2.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        sprite->setContentSize(Size(1000, 1000));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }



    // add start button
    auto startButton = ui::Button::create("F:/lemmings/LemmingsGame/start_button.png", "F:/lemmings/LemmingsGame/start_button.png", "F:/lemmings/LemmingsGame/start_button.png");

    startButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {

        //add game scene  and game scene background
        auto gameScene = Scene::create();

        auto gameBg = Sprite::create("F:/lemmings/LemmingsGame/Assets/Battleground1.png");
        gameBg->setPosition(Vec2(visibleSize.width + origin.x + 500, visibleSize.height + origin.y + 400));
        gameBg->setContentSize(Size(gameBg->getContentSize()*1.6));

        gameScene->addChild(gameBg);

        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            Director::getInstance()->replaceScene(gameScene);
            break;
        default:
            break;
        }
        });

    if (startButton == nullptr)
    {
        problemLoading("'start_button.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        startButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 4 + origin.y));

        // changer la taille du bouton (ne fonctionne pas)
        auto resize_btn = [](ui::Button* startButton) {

            auto startButton_size = startButton->getCustomSize();
            startButton->setContentSize(Size(startButton_size.width * 0.1f, startButton_size.height * 0.1f));

        };

        // add the sprite as a child to this layer
        this->addChild(startButton, 2);
    }

    CCLOG("coucou : %f", 14.0f);
    return true;

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
