#pragma once
class Coursor
{
public:
	Coursor();
	~Coursor();
	void SetPosition(int x, int y);
	void GetPosition(int &x, int &y);
private:
	int x;
	int y;
};