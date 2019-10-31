#pragma once

inline bool InRange(const float value, const float rangeStart, const float rangeEnd)
{
	return (value >= rangeStart) && (value <= rangeEnd);
}

inline bool InRange(const int value, const int rangeStart, const int rangeEnd)
{
	return (value >= rangeStart) && (value <= rangeEnd);
}

inline float Clamp(const float hi, const float lo, const float val)
{
	if (InRange(val, lo, hi))
	{
		return val;
	}
	if (val > hi)
	{
		return hi;
	}
	return lo;
}

inline float Clamp(const int hi, const int lo, const int val)
{
	if (InRange(val, lo, hi))
	{
		return val;
	}
	if (val > hi)
	{
		return hi;
	}
	return lo;
}