#include "Collisions.h"
#include "Character.h"

Collision* ::Collision::M_Instance = nullptr;

Collision::Collision() 
{
}

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
    float halfWidth1 = rect1.width / 2;
    float halfHeight1 = rect1.height / 2;
    float halfWidth2 = rect2.width / 2;
    float halfHeight2 = rect2.height / 2;

    float centerX1 = rect1.x + halfWidth1;
    float centerY1 = rect1.y + halfHeight1;
    float centerX2 = rect2.x + halfWidth2;
    float centerY2 = rect2.y + halfHeight2;

    bool overlapX = abs(centerX1 - centerX2) < halfWidth1 + halfWidth2;
    bool overlapY = abs(centerY1 - centerY2) < halfHeight1 + halfHeight2;

    return overlapX && overlapY;
}
