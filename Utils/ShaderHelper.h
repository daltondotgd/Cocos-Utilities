#ifndef __SHADER_HELPER_H__
#define __SHADER_HELPER_H__

#include "cocos2d.h"

class ShaderHelper
{
public:
    static cocos2d::GLProgram* loadShader(const GLchar* vertexShader, const GLchar* fragmentShader)
    {
        auto shader = cocos2d::ShaderCache::getInstance()->getGLProgram(fragmentShader);
        if (!shader)
        {
            shader = new cocos2d::GLProgram();
            shader->retain();
            shader->initWithFilenames(vertexShader, fragmentShader);
            shader->bindAttribLocation(cocos2d::GLProgram::ATTRIBUTE_NAME_POSITION, cocos2d::GLProgram::VERTEX_ATTRIB_POSITION);
            shader->bindAttribLocation(cocos2d::GLProgram::ATTRIBUTE_NAME_TEX_COORD, cocos2d::GLProgram::VERTEX_ATTRIB_TEX_COORDS);
            shader->bindAttribLocation(cocos2d::GLProgram::ATTRIBUTE_NAME_COLOR, cocos2d::GLProgram::VERTEX_ATTRIB_COLOR);
            shader->link();
            shader->updateUniforms();
            shader->use();
        }

        return shader;
    }
};

#endif // __SHADER_HELPER_H__