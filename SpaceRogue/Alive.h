#pragma once
#include "Object.h"

/*! ����� �����: ����� ������, ���������, ������� � ���������� ������ ������
    6. ����� (�������, ������� ����� ���������):
        a) ������� ��������
        b) �����
*/
class Alive abstract
    : public Object
{
public:
    Alive();
    virtual ~Alive();
};

