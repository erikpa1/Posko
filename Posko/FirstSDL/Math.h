#pragma once

class vec4
{
public:

	int x;
	int y;
	int z;
	int w;

	vec4 vec4plus(const vec4 & a, const vec4 & b)
	{
		vec4 temp;
		temp.x = a.x + b.x;
		temp.y = a.y + b.y;
		temp.z = a.z + b.z;
		temp.w = a.w + b.w;
		return temp;
	}

	vec4 vec4minus(const vec4 & a, const vec4 & b)
	{
		vec4 temp;
		temp.x = a.x - b.x;
		temp.y = a.y - b.y;
		temp.z = a.z - b.z;
		temp.w = a.w - b.w;
		return temp;
	}
};

