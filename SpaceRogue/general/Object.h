#ifndef OBJECT_h
#define OBJECT_h
#include "Field.h"
#include "Coordinates.h"
//#include "Animation.h"

/*!
\brief Класс, реализующий объект
*/
class Object
{
public:
    Object(Coordinates position);
    virtual ~Object();

    Coordinates getPosition();
    void setPosition(Coordinates coord);
    Vector2f getRotation();
	Vector2f getSize();
    //virtual Sprite getSprite();
	Field* getField();
    void resize();
    void setSize(Vector2f size);
	void bind(Field*, Vector2f);
	virtual void calculate(); //!<

protected:
	//Animation* animation = nullptr;
	Object* that; //!<
	Field* field = nullptr; //!<
	//Sprite sprite; //!<
	Vector2f size; //!< размер спрайта
    Coordinates position; //!< положение рыбы в аквариуме
	Vector2f rotation; //!<	
};

#endif //! OBJECT_h