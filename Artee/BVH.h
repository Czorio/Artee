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

	Hit intersect() const;
	AABB getBounds() const;
private:
	std::vector<Primitive*> primitives;
	std::vector<BVHNode> nodes;
	std::vector<Uint32> indices;
};