#include "Collisions.h"
#include "Character.h"

Collision* ::Collision::M_Instance = nullptr;

Collision::~Collision()
{
	M_Instance = nullptr;
}

Collision* Collision::Instance()
{
	if (!M_Instance)
	{
		M_Instance = new Collision;
	}
	return M_Instance;
}

bool Collision::Circle(Character* Mario, Character* Luigi)
{
	Vector2D vec = Vector2D((Mario->GetPosition().x - Luigi->GetPosition().x), (Mario->GetPosition().y - Luigi->GetPosition().y));
	double distance = sqrt((vec.x * vec.x) + (vec.y * vec.y));
	double Combined_Distance = (Mario->GetCollisionRadius() + Luigi->GetCollisionRadius());
	return distance < Combined_Distance;
}

bool Collision::Box(Rect2D rect1, Rect2D rect2)
{
	if (rect1.x + (rect1.width / 2) > rect2.x && rect1.x + (rect1.width / 2) < rect2 + rect2.width && rect1.y(rect1.height / 2) > rect2.y && rect1.y + (rect1.height / 2) < rect2.y + rect2.height)
	{
		return true;
	}
	return false;
}
