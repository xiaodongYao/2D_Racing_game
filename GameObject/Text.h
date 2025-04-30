#pragma once

class Text
{
public:
    Text();
    ~Text();

    void RenderTextInit();
    void RenderTextStart(unsigned int score, unsigned int FPS, unsigned int level);
    void RenderTextEnd(unsigned int score);
};