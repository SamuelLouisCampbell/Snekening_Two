#include "Snake.h"
#include <assert.h>


Snake::Segment::Segment()
	:
	loc(2,2)
{
	void InitBody();
}

void Snake::Segment::InitHead(const Location& loc_in)
{
	loc = loc_in;
	c = Snake::headCol;
}

void Snake::Segment::InitBody(Color c_in)
{
	c = c_in;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

const Location Snake::Segment::GetLocation() const
{
	return loc;
}

Snake::Snake(const Location& loc_in)
{
	constexpr int nBodyColors = 4; 
	constexpr Color bodyCol[nBodyColors] = 
		{ 
			{200,255,200},{200,255,100},{100,255,100},{200,255,200} 
		};
	for (int i = 0; i < segNo; i++)
	{
		segments[i].InitBody(bodyCol[i % nBodyColors]);
	}

	segments[0].InitHead(loc_in);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for(int i = segIndex - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i-1]);
	}
	segments[0].MoveBy(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;

}

void Snake::Grow()
{
	if (segIndex < segNo)
	{
		segIndex++;
	}
}

void Snake::Draw(Board& brd)
{
	for (int i = 0; i < segNo; i++)
	{
		segments[i].Draw(brd);
	}
}

bool Snake::IsInTileExceptEnd(const Location& target) const 
{
	for (int i = 0; i < segIndex - 1; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false; 
}
bool Snake::IsInTile(const Location& target) const 
{
	for (int i = 0; i < segIndex; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

