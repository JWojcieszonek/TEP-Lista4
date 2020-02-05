#include "Zakres.h"
#include <iostream>
using namespace std;



Zakres::Zakres()
{
	i_low = 0;
	i_high = 0;
	i_val = 0;
}

Zakres::Zakres(int iLow, int iHigh, int iVal)
{
	try
	{
		if (iLow <= iHigh && iVal >= iLow && iVal <= iHigh)
		{
			i_low = iLow;
			i_high = iHigh;
			i_val = iVal;
		}
		else
			throw  0;
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}
}


Zakres::~Zakres()
{
}

Zakres Zakres::operator=(Zakres &cOther)
{
	try
	{
		if (this != &cOther)
		{
			if(cOther.i_low <= cOther.i_high && cOther.i_val >= cOther.i_low && cOther.i_val <= cOther.i_high)
			{
				i_low = cOther.i_low;
				i_high = cOther.i_high;
				i_val = cOther.i_val;
			}
			else throw 2;
			
		}
		else return *this;
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}
	return *this;
}

void Zakres::setValue(int iVal)
{
	try
	{
		if (iVal >= i_low && iVal <= i_high)
		{
			i_val = iVal;
		}
		else
		{
			throw 1;
		}
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}
	
}

Zakres Zakres::operator=(int iVal)
{
	try
	{
		if (iVal >= i_low && iVal <= i_high)
		{
			i_val = iVal;
			return *this;
		}
		else
			throw 3;
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}
	
}
