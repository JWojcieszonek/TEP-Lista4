#pragma once
class Zakres
{
public:
	Zakres();
	Zakres(int low, int high,int val);
	~Zakres();

	Zakres operator = (Zakres &cOther);
	void setValue(int val);
	Zakres operator = (int val);
private:
	int i_low;
	int i_high;
	int i_val;
};

