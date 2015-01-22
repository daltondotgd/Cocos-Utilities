#include "GameScene.h"
#include "MenuScene.h"

USING_NS_CC;

bool MenuScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto playItem = MenuItemImage::create(
        "gfx/ui/play-normal.png",
        "gfx/ui/play-selected.png",
        [](Ref* pSender) { Director::getInstance()->replaceScene(GameScene::create()); });

    playItem->setScale(0.5f);

    playItem->setPosition(Vec2(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height / 2));

    auto play = Menu::create(playItem, NULL);
    play->setPosition(Vec2::ZERO);
    this->addChild(play, 1);

    auto backListener = EventListenerKeyboard::create();
    backListener->onKeyReleased = [](EventKeyboard::KeyCode key, Event* event) {
        if (key == EventKeyboard::KeyCode::KEY_BACK) Director::getInstance()->end();
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(backListener, this);

    return true;
}