#pragma once
#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		Segment();
		void InitHead(const Location& loc_in);
		void InitBody(Color c_in);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd);
		const Location GetLocation() const;

	private:
		Location loc; 
		Color c; 
	};
public: 
	Snake(const Location& loc_in);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& brd);
	bool IsInTileExceptEnd(const Location& target) const;
	bool IsInTile(const Location& target) const;
	

private: 
	static constexpr Color headCol = Colors::Yellow;
	static constexpr int segNo = 200; 
	int segIndex = 1; 
	Segment segments[segNo];

};

