#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "render_object.hpp"

class TextObject : public RenderObject {
    public:
        TextObject();
        ~TextObject();

        void render(SDL_Renderer* renderer) override;
        void setText(std::string text);
        void setFont(TTF_Font* font);
        void process();
        void setProcess(std::function<void()> func);
        void setScale(float scale);
        void destroy();
        void setOffset(int x, int y);
        SDL_Color textColor = {255,0,0};
        int x = 0;
        int y = 0;
        int width = 0;
        int height = 0;
    private:
        int offsetX = 0;
        int offsetY = 0;
        float render_scale = 0;
        SDL_Texture* mTexture = NULL;
        SDL_Surface* textSurface = NULL;
        TTF_Font* font = NULL;
        std::string text = "";
        std::function<void()> process_function;
};
