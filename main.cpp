#include <iostream>
#include <Windows.h>
#include "termcolor.hpp"

using namespace std;

enum Hadokentype
{
	AIR_HADOKEN,
	FIRE_HADOKEN,
	METSU_HADOKEN
};

void throwHadoken(Hadokentype type = AIR_HADOKEN)
{
	switch (type)
	{
	case AIR_HADOKEN:
		cout << "\tAIR HADOKEN!! " << termcolor::white << termcolor::on_blue << "~~~~*O}\n\n" << termcolor::reset;
		break;
	case FIRE_HADOKEN:
		cout << "\tFIRE HADOKEN!! " << termcolor::yellow << termcolor::on_red << "~~~~33}}\n\n" << termcolor::reset;
		break;
	case METSU_HADOKEN:
		cout << "\tMETSU HADOKEN!! " << termcolor::magenta << termcolor::on_cyan << "~~~~DD}}}\n\n" << termcolor::reset;
		break;
		return;
	}
}

//void throwHadoken(Hadokentype type = AIR_HADOKEN); //A function we use each time someone exe. a hadoken

int main()
{
	cout << termcolor::reset << "\n\n\tPress A for air Hadoken, F for fire hadoken, M for metsu Hadoken Q for quit. \n\n";

	//Variables to keep track of the state of keyboard presses

	bool userHasQuit = false;
	bool aIsHeld = false;
	bool fIsHeld = false;
	bool mIsHeld = false;

	while (!userHasQuit)
	{
		//The 0x8000 thing is a flag windows uses to represent key state. The single & joins the two using binary and
		if (GetKeyState('A') & 0x8000)
		{
			if (!aIsHeld)
			{
				aIsHeld = true;
				throwHadoken(AIR_HADOKEN);
			}
		}
		else {
			if (aIsHeld) aIsHeld = false;
		}

		if (GetKeyState('F') & 0x8000)
		{
			if (!fIsHeld)
			{
				fIsHeld = true;
				throwHadoken(FIRE_HADOKEN);
			}
		}
		else {
			if (fIsHeld) fIsHeld = false;
		}

		if (GetKeyState('M') & 0x8000)
		{
			if (!mIsHeld)
			{
				mIsHeld = true;
				throwHadoken(METSU_HADOKEN);
			}
		}
		else {
			if (mIsHeld) mIsHeld = false;
		}

		if (GetKeyState('Q') & 0x8000)
		{
			userHasQuit = true;
		}
	}
	return 0;
}

