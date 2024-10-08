#ifndef COLLISION_OBJECT_H
#define COLLISION_OBJECT_H

enum CollisionObjectType {
  NONE,
  ENEMY,
  PLAYER,
  BULLET
};

class CollisionObject {
    public:
        virtual void updateVelocity() = 0;
        virtual ~CollisionObject() = default;
        int left = 0;
        int right = 0;
        int top = 0;
        int bottom = 0;
        bool proccessed = false;
        CollisionObjectType type = NONE;
        CollisionObject* collision = NULL;
        SDL_FPoint velocity;
};

#endif