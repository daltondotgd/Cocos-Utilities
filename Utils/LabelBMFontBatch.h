#ifndef __LABEL_BM_FONT_BATCH_H__
#define __LABEL_BM_FONT_BATCH_H__

/*
 * source: http://www.nulldesign.de/2013/05/30/cocos2dx-faster-fonts/
 */

#include "cocos2d.h"

class LabelBMFontBatch : public cocos2d::CCSpriteBatchNode
{

private:
    const char *_fntFile;
    int _lastChildTag;

public:
    LabelBMFontBatch(const char *fntFile);
    ~LabelBMFontBatch();

    static LabelBMFontBatch *create(const char *fileImage, const char *fntFile, unsigned int capacity);

    /* returns a text id. used to identify the text in the batch. use the id with removeTextByID  */
    int addTextAt(const char *text, cocos2d::Vec2 position, float scale);
    void removeTextByID(int textID);
    void removeAllTexts();
};

#endif // __LABEL_BM_FONT_BATCH_H__