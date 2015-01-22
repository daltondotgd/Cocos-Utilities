#ifndef __ANIMATION_UTILS_H__
#define __ANIMATION_UTILS_H__

#include "cocos2d.h"
#include "Defines.h"

class AnimationUtils
{
public:
    static cocos2d::Action* getAnimationRunningForever(std::string name, int tag = TAG_ANIMATION);
    static cocos2d::Action* getAnimationWithCallback(std::string name, std::function<void()> callback, int tag = TAG_ANIMATION);
};

#endif // __ANIMATION_UTILS_H__