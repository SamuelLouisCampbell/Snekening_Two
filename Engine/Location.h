#pragma once

class Location
{
public:

	Location(int x_in,int y_in);
	Location() = default;
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	bool operator==(const Location& rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}
	bool operator!=(const Location& rhs) const
	{
		return x != rhs.x && y != rhs.y;
	}
	int x = 0;
	int y = 0; 
};