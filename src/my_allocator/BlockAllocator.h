#pragma once

#include <list>


struct BlockInfo
{
	void *ptr{ nullptr };
	std::size_t size{ 0 };
	bool busy{ false };

	bool operator==(const BlockInfo &other) const;
};



class BlockAllocator
{
public:
	BlockAllocator();
	~BlockAllocator();

	void *allocate(std::size_t size);
	void deallocate(void *ptr);

	std::size_t blockSize() const;
	void setBlockSize(std::size_t blockSize);

private:
	std::list<BlockInfo> _globalBlocks;
	std::list<BlockInfo> _allocetedBlocks;

	std::size_t _blockSize;

	using BlockInfoIt = std::list<BlockInfo>::iterator;
	void occupyBlock(const BlockInfoIt &it, std::size_t size);
	void releaseBlock(const BlockInfoIt &it);
};
