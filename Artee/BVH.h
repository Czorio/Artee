#pragma once

struct BVHNode
{
	AABB bounds;
	Uint32 count;
	Uint32 leftFirst;
};

class BVH
{
public:
	BVH();
	~BVH();
private:
	std::vector<Primitive*> primitives;
	std::vector<BVHNode> nodes;
	std::vector<Uint32> indices;
};