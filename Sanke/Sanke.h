#ifndef SANKE_H
#define SANKE_H

namespace snake_enum {
	enum Dire { Up, Left, Down, Right }; //move Direction
	enum MapStyle { Food, Body, Way };
}
using namespace snake_enum;
using  std::queue;
struct Point {
	unsigned int X;
	unsigned int Y;
};

class Sanke
{
private:
	unsigned int length;//the length of sanke
	Point  map_size;	//the size of map
	MapStyle *map;
	queue<Point> body;	//the body node data
protected:
	inline MapStyle & GetData(const Point &point);
	inline MapStyle GetData(Point point) const;
	inline bool IsSafe(const Point &point) const;
	inline void SetStyle(const Point &point, MapStyle style);
public:
	Sanke(const Point &point);
	~Sanke();
	void Move(Dire dire);
	void ShowMap() const;
	void CreateFood();
	void ShowMapNum();
	void Example();
};

MapStyle & Sanke::GetData(const Point &point) 
{
	return map[point.X * map_size.Y + point.Y];
}

MapStyle Sanke::GetData(const Point point) const
{
	return map[point.X * map_size.Y + point.Y];
}

bool Sanke::IsSafe(const Point &point) const
{
	//array overflow
	if (point.X < 0 || point.Y < 0 || point.X >= map_size.X || point.Y >= map_size.Y)
		return false;
	//eat itself
	if (GetData(point) == Body)
		return false;
	//safe
	return true;
}

void Sanke::SetStyle(const Point &point, MapStyle style)
{
	map[point.X*map_size.Y + point.Y] = style;
}


#endif