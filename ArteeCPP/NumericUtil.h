#pragma once

inline bool InRange(const float value, const float rangeStart, const float rangeEnd)
{
	return (value >= rangeStart) && (value <= rangeEnd);
}
