#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx_in)
	:
	gfx(gfx_in)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	gfx.DrawRectPadded(startX + (loc.x * dimension),startY + (loc.y * dimension), dimension,dimension,padding, c);
}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}

int Board::GetStartX() const
{
	return startX;
}

int Board::GetStartY() const
{
	return startY;
}

int Board::GetDimension() const
{
	return dimension;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width &&
		   loc.y >= 0 && loc.y < height;
}
