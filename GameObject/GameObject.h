#pragma once

#include "../Utility/Renderer.h"


class GameObject 
{
	GameObject();
	~GameObject();


	virtual void Draw(Renderer& renderer);
};
