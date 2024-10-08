#include "engine/entity/render_object/text_object.hpp"

TextObject::TextObject() {

}

TextObject::~TextObject() {

}

void TextObject::setText(std::string text) {
    TTF_SizeText(font, text.c_str(), &width, &height);
    width *= 0.5;
    height *= 0.5;
    this->text = text;
}

void TextObject::setFont(TTF_Font* font) {
    this->font = font;
}

void TextObject::process() {
    if (process_function) {
        process_function();
    }
}

void TextObject::destroy() {
    this->~TextObject();
}

void TextObject::setProcess(std::function<void()> func) {
    process_function = func;
}

void TextObject::setScale(float scale) {
    render_scale = scale;
}

void TextObject::setOffset(int x, int y) {
    offsetX = x;
    offsetY = y;
}

void TextObject::render(SDL_Renderer* renderer) {
    textSurface = TTF_RenderUTF8_Solid(font, text.c_str(), textColor);
    mTexture =  SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textSurface) {
        SDL_Rect bounds = {
            x * render_scale + offsetX * render_scale,
            y * render_scale + offsetY * render_scale,
            textSurface->w * render_scale,
            textSurface->h * render_scale
        };
        SDL_RenderCopy(renderer, mTexture, NULL, &bounds);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(mTexture);
    }
}
