#ifndef __ANIMATED_SPRITE_H__
#define __ANIMATED_SPRITE_H__

#include "cocos2d.h"

class AnimatedSprite : public cocos2d::Sprite
{
public:
    static AnimatedSprite* create(std::string fileName, std::string animationToRun = "", std::function<void()> callback = nullptr);
    void runAnimation(std::string animationToRun = "", std::function<void()> callback = nullptr);

private:
    std::string animationFile;
};

#endif // __ANIMATED_SPRITE_H__