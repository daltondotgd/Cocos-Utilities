#include "AnimatedSprite.h"
#include "AnimationUtils.h"

USING_NS_CC;

AnimatedSprite* AnimatedSprite::create(std::string fileName, std::string animationToRun, std::function<void()> callback)
{
    AnimatedSprite* animatedSprite{ new AnimatedSprite() };
    animatedSprite->animationFile = fileName;

    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile(String::createWithFormat("anims/%s.plist", fileName.c_str())->getCString());

    if (animatedSprite->initWithSpriteFrameName(String::createWithFormat("anims/%s_01.png", fileName.c_str())->getCString()))
    {
        auto cache = AnimationCache::getInstance();
        cache->addAnimationsWithFile(String::createWithFormat("anims/%s.plist", fileName.c_str())->getCString());

        if (animationToRun != "")
        {
            if (callback)
                animatedSprite->runAction(AnimationUtils::getAnimationWithCallback(String::createWithFormat("%s_%s", fileName.c_str(), animationToRun.c_str())->getCString(), callback));
            else
                animatedSprite->runAction(AnimationUtils::getAnimationRunningForever(String::createWithFormat("%s_%s", fileName.c_str(), animationToRun.c_str())->getCString()));
        }

        animatedSprite->autorelease();
        animatedSprite->getTexture()->setAliasTexParameters();
        animatedSprite->init();
        animatedSprite->scheduleUpdate();

        return animatedSprite;
    }

    CC_SAFE_DELETE(animatedSprite);
    return nullptr;
}

void AnimatedSprite::runAnimation(std::string animationToRun, std::function<void()> callback)
{
    if (callback)
        runAction(AnimationUtils::getAnimationWithCallback(String::createWithFormat("%s_%s", animationFile.c_str(), animationToRun.c_str())->getCString(), callback));
    else
        runAction(AnimationUtils::getAnimationRunningForever(String::createWithFormat("%s_%s", animationFile.c_str(), animationToRun.c_str())->getCString()));
}