#ifndef OBJECT_h
#define OBJECT_h
#include "Headers.h"
//#include "Field.h"
//#include "Coordinates.h"
//#include "Animation.h"

/*!
\brief Класс, реализующий объект
*/
class Object
{
public:
    Object();
    //Object(Coordinates position);
    virtual ~Object();

    Vector2f getPosition();
    void setPosition(Vector2f pos);
    /*
    void setPosition(Vector2f coord);
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
    //Field* field = nullptr; //!<
	//Sprite sprite; //!<
	Vector2f size; //!< размер спрайта
    Vector2f position; //!< положение рыбы в аквариуме
	Vector2f rotation; //!<	
    */
private:
    sf::Vector2f position;
    //!< type (Component, item, Alive)
};

#endif //! OBJECT_h
