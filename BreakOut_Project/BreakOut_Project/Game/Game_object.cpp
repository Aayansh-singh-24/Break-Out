#include"Game_object.h"

// For Default Value:-
GameObject::GameObject()
	:Position(0.0f, 0.0f),
	Size(1.0f, 1.0f),
	Color(1.0f, 1.0f, 1.0f),
	Velocity(0.0f, 0.0f),
	IsDestroyed(false),
	IsSolid(false),
	Rotation(0.0f),
	Sprite()
{

}

GameObject::GameObject(Texture2D sprite, glm::vec2 position, glm::vec2 size, glm::vec3 color, glm::vec2 velocity)
	:Position(position),
	Size(size),
	Color(color),
	Velocity(velocity),
	Sprite(sprite),
	Rotation(0.0f),
	IsDestroyed(false),
	IsSolid(false)
{

}

void GameObject::draw(SpriteRenderer& renderer)
{
	renderer.Render(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}
