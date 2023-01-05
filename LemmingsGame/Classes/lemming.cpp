#include "lemming.h"
#include "HelloWorldScene.h"

USING_NS_CC;

lemming::lemming()
{
    
}

lemming::~lemming()
{
}

void lemming::setSprite(game* scene)
{
    auto spriteCache = SpriteFrameCache::getInstance();
    spriteCache->addSpriteFramesWithFile("idle/idle.plist");

    Vector<SpriteFrame*> frames;
    frames.pushBack(spriteCache->getSpriteFrameByName("1.png"));
    //frames.pushBack(spriteCache->getSpriteFrameByName("2.png"));
    //frames.pushBack(spriteCache->getSpriteFrameByName("3.png"));
    //frames.pushBack(spriteCache->getSpriteFrameByName("4.png"));
    auto animation = Animation::createWithSpriteFrames(frames);
    animation->setDelayPerUnit(0.2);
    animation->setLoops(-1);
    auto action = Animate::create(animation);

    auto sprite = Sprite::createWithSpriteFrame(frames.front());
    sprite->setPosition(200, 200);
    sprite->setScale(2);
    sprite->runAction(action);

    auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0, 1, 0));
    physicsBody->setDynamic(true);
    physicsBody->setCollisionBitmask(-1);
    sprite->setPhysicsBody(physicsBody);
    

    physicsBody->setGravityEnable(true);
    //sprite->addComponent(physicsBody);  
    sprite->getPhysicsBody()->setVelocity(Vec2(50, 0));

    scene->addChild(sprite, 0, 1);
}

