#include "game.h"
#define CC_CALLBACK_1

USING_NS_CC;

Scene* game::createScene()
{
    auto gameScene = Scene::create();
    return gameScene;
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


bool game::init()
{






    return true;
}

