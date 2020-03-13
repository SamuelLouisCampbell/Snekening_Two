#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx_in);
	void DrawCell(const Location& loc, Color c);
	int GetWidth() const;
	int GetHeight() const;
	int GetStartX() const;
	int GetStartY() const; 
	int GetDimension() const; 
	bool IsInsideBoard(const Location& loc) const;


private:
	static constexpr int startX = 100;
	static constexpr int startY = 50;
	static constexpr int dimension = 16;
	static constexpr int width = 20;
	static constexpr int height = 30;
	static constexpr int padding = 1; 
	Graphics& gfx; 

};

