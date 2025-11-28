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

BallObject::BallObject()
	:GameObject(),
	Radius(12.5f),
	Stuck(false)
{

}

BallObject::BallObject(Texture2D sprite, glm::vec2 position, float radius, glm::vec2 velocity)
	:GameObject
	(
			sprite, 
			position,
			glm::vec2(radius * 2.0f, radius * 2.0f),
			glm::vec3(1.0f), 
			velocity
	),

			Radius(radius),
			Stuck(true)
{

}

	

void GameObject::draw(SpriteRenderer& renderer)
{
	renderer.Render(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}

glm::vec2 BallObject::Move(GLfloat dt, unsigned int window_width)
{
	if (!this->Stuck)
	{
	
		this->Position += this->Velocity * dt;

		// Left
		if (this->Position.x <= 0.0f)
		{
			this->Velocity.x = -this->Velocity.x;
			this->Position.x = 0.0f;
		}

		// Right
		if (this->Position.x + this->Size.x >= window_width)
		{
			this->Velocity.x = -this->Velocity.x;
			this->Position.x = window_width - this->Size.x;
		}

		// Top
		if (this->Position.y <= 0.0f)
		{
			this->Velocity.y = -this->Velocity.y;
			this->Position.y = 0.0f;
		}

		//Just for fun
		if (this->Position.y + this->Size.y >= window_width)
		{
			this->Velocity.y = -this->Velocity.y;
			this->Position.y = window_width - this->Size.y;
		}

	}

	/*if (this->Stuck)
	{
		this->Position.y += this->Velocity.y * dt;
	}*/

	return this->Position;
}
