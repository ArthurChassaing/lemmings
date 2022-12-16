#include "sprite.h"
#include "HelloWorldScene.h"

USING_NS_CC;

sprite::sprite()
{
}

sprite::~sprite()
{
}

void sprite::setSprite(game* scene)
{
    auto spriteCache = SpriteFrameCache::getInstance();
    spriteCache->addSpriteFramesWithFile("idle/idle.plist");

    Vector<SpriteFrame*> frames;
    frames.pushBack(spriteCache->getSpriteFrameByName("1.png"));
    frames.pushBack(spriteCache->getSpriteFrameByName("2.png"));
    frames.pushBack(spriteCache->getSpriteFrameByName("3.png"));
    frames.pushBack(spriteCache->getSpriteFrameByName("4.png"));
    auto animation = Animation::createWithSpriteFrames(frames);
    animation->setDelayPerUnit(0.2);
    animation->setLoops(-1);
    auto action = Animate::create(animation);

    auto sprite = Sprite::createWithSpriteFrame(frames.front());
    sprite->setPosition(500, 500);
    sprite->runAction(action);
    scene->addChild(sprite, 0, 1);


}
