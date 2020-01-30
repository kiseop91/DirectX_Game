#pragma once

class InputClass
{
public:
	InputClass();
	InputClass(const InputClass& _other);
	~InputClass();

	void Initialize();

	void KeyDown(unsigned int);
	void KeyUP(unsigned int);

	bool IsKeyDown(unsigned int);

private:
	bool m_Keys[256];
};

