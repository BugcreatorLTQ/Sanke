#include<iostream>
#include<Windows.h>
#include<queue>
#include<conio.h>
#include"Sanke.h"
using namespace std;
using namespace snake_enum;


Dire ChangeDire(const char ch,Dire _dire)
{
	Dire dire;
	switch (ch) {
	case 'a':dire = Left; break;
	case 's':dire = Down; break;
	case 'd':dire = Right; break;
	case 'w':dire = Up; break;
	case 'p':return None;
	default:dire = _dire; break;
	}
	if (dire != (_dire + 2) % 4)
		return dire;
	return _dire;
}

Dire Pause(const Dire dire)
{
	char ch;
	Dire temp = dire, result = dire;
	unsigned int i, sum = 10000;
	for (i = 0; i < sum; i++) {
		if (_kbhit()) {
			ch = _getch();
			temp = ChangeDire(ch, dire);
			if (temp != dire) {
				result = temp;
				if (temp == None)
					break;
			}
			//Change Dire
		}
	}
	return result;
}

int main()
{
	Dire dire = None;
	const Point MapSize = { 5,5 };
	Sanke sanke(MapSize);
	sanke.CreateFood();
	while (true) {
		system("cls");
		sanke.ShowMap();
		dire = Pause( dire);
		sanke.Move(dire);
	}
	return 0;
}