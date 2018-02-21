#ifndef FIELD_H
#define FIELD_H
#include <vector>
//#include "Headers.h"

class Object;
/*!
\brief Класс, реализующий поле

Поле - содержит характеристики окна, на котором мы рисуемся
*/
class Field
{
protected:
	bool clearOutOfBounds;
	//FloatRect displayedRect;
	std::vector<Object*> objects;
	float scale;
	//Texture* background;
	//Vector2f cameraPosition;
	//Vector2f backSize;
	//RenderWindow* window;
public:
	//Field(float, RenderWindow&, Vector2f = Vector2f(0, 0), bool = false,Texture* = nullptr, Vector2f = Vector2f(0, 0));
	void CalculateDisplayedRect();
	void HandleObjects();
	int GetObjectCount();
	bool AddObject(Object*);
	float GetScale() const;
	void RemoveObject(Object*);
	//Vector2f GetCameraPosition();
	void SetCameraPosition(Vector2f);
	//Vector2f WorldToScreenPoint(Vector2f);
	//Vector2f ScreenToWorldPoint(Vector2f);
	const RenderWindow* GetWindow();
	~Field();
};
//extern Field MAIN_FIELD;
#endif //! FIELD_H
