#include<iostream>
using namespace std;
#include<queue>
#include<random>
#include<time.h>
#include "Sanke.h"


Sanke::Sanke(const Point &size)
{
	srand((unsigned int)time(NULL));
	map_size = size;
	Point point;
	point.X = size.X / 2;
	point.Y = size.Y / 2;
	body.push(point);
	length = 1;
	map = new MapStyle[size.X * size.Y];
	for (unsigned int i = 0; i < size.X * size.Y; i++)
		map[i] = Way;
	SetStyle(point, Body);
}


Sanke::~Sanke()	//delete map array
{
	delete[] map;
}

void Sanke::Move(Dire dire)
{
	Point head = body.back();	//head is next head node point
	switch (dire) {
	case Up:head.X--; break;
	case Down:head.X++; break;
	case Left:head.Y--; break;
	case Right:head.Y++; break;
	case None:return;
	default:break;
	}
	if (IsSafe(head)) {
		body.push(head);
		length++;
		if (GetData(head) != Food) {	//if not food   delete the last node
			Point rear = body.front();
			SetStyle(rear, Way);
			body.pop();
			length--;
		}
		else  CreateFood();
		SetStyle(head, Body);
	}
	else
	{
		cout << "Game Over" << endl;
		system("pause");
		exit(0);
		//TODO: //Game Over
	}
}

void Sanke::ShowMap() const
{
	unsigned int i, j;
	Point index;
	system("cls");
	for (i = 0; i < map_size.X; i++) {
		index.X = i;
		for (j = 0; j < map_size.Y; j++) {
			index.Y = j;
			cout << " ";
			switch (GetData(index)) {
			case Way:cout << "."; break;	//Show Way Pic
			case Body:cout << "*"; break;	//Show Body Pic
			case Food:cout << "+"; break;	//Show Food Pic
			default:break;	//no way
			}
		}
		cout << endl;
	}
	cout << "W A S D Move" << endl << "P Pause" << endl;
	cout << "score: " << length-1 << endl;
}


void Sanke::CreateFood()
{
	unsigned int sum_length = map_size.X * map_size.Y - length - 1;
	//length of Way
	unsigned int index = rand() % sum_length;
	unsigned int i;
	for (i = 0; i < map_size.X * map_size.Y; i++) {
		if (map[i] == Way) {
			if (index == 0) {
				map[i] = Food;
				return;
			}
			index--;
		}
	}
}
