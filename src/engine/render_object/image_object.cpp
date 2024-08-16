#include "engine/render_object/image_object.hpp"

ImageObject::ImageObject() {

}

ImageObject::~ImageObject() {
    SDL_DestroyTexture(texture);
}

bool ImageObject::load(SDL_Renderer* renderer, SDL_Surface* imageSurface) {
    texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    width = imageSurface->w;
    height = imageSurface->h;

    if (texture == NULL) {
        std::cout << "Can't create texture from surface: " << SDL_GetError() << std::endl;
    }
    
    return true;
}

void ImageObject::turnLeft() {
    flipType = SDL_FLIP_HORIZONTAL;
}

void ImageObject::turnRight() {
    flipType = SDL_FLIP_NONE;
}

void ImageObject::process() {
    if (process_function) {
        process_function();
    }
}

void ImageObject::setProcess(std::function<void()> func) {
    process_function = func;
}

void ImageObject::render(SDL_Renderer* renderer) {
    SDL_Rect rect1 = {x, y, width * scale, height * scale};
    SDL_RenderCopyEx(renderer, texture, NULL, &rect1, 0, NULL, flipType);
}
