#include "Input/InputClass.h"



InputClass::InputClass()
{
}

InputClass::InputClass(const InputClass & _other)
{
}


InputClass::~InputClass()
{
}

void InputClass::Initialize()
{
	int i;

	for (i = 0; i < 256; i++)
	{
		m_Keys[i] = false;
	}

	return;
}

void InputClass::KeyDown(unsigned int _input)
{
	m_Keys[_input] = true;
	return;
}

void InputClass::KeyUP(unsigned int _input)
{
	m_Keys[_input] = false;
	return;
}

bool InputClass::IsKeyDown(unsigned int _key)
{
	return m_Keys[_key];
}
