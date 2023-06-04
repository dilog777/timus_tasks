#include <algorithm>

#include "BlockAllocator.h"



static const std::size_t DEFAULT_ALLOCATED_BLOCK_SIZE = 1024;



bool BlockInfo::operator==(const BlockInfo &other) const
{
	return ptr == other.ptr
		&& size == other.size
		&& busy == other.busy;
}



BlockAllocator::BlockAllocator()
	: _blockSize{ DEFAULT_ALLOCATED_BLOCK_SIZE }
{
}



BlockAllocator::~BlockAllocator()
{
	for (const auto &bi : _globalBlocks)
		::operator delete(bi.ptr);
}



void *BlockAllocator::allocate(std::size_t size)
{
	auto choiseFunc = [size](const BlockInfo &bi) { return !(bi.busy || bi.size < size); };
	auto it = std::find_if(_allocetedBlocks.begin(), _allocetedBlocks.end(), choiseFunc);
	if (it == _allocetedBlocks.end())
	{
		auto memoryPtr = ::operator new(_blockSize);
		if (!memoryPtr)
			throw std::bad_alloc();

		_globalBlocks.push_back(BlockInfo{ memoryPtr, _blockSize });
		_allocetedBlocks.push_back(BlockInfo{ memoryPtr, _blockSize });
		it = --_allocetedBlocks.end();
	}

	occupyBlock(it, size);
	return it->ptr;
}



void BlockAllocator::deallocate(void *ptr)
{
	for (auto it = _allocetedBlocks.begin(); it != _allocetedBlocks.end(); ++it)
	{
		if (it->ptr == ptr)
		{
			releaseBlock(it);
			break;
		}
	}
}



std::size_t BlockAllocator::blockSize() const
{
	return _blockSize;
}



void BlockAllocator::setBlockSize(std::size_t blockSize)
{
	_blockSize = blockSize;
}



void BlockAllocator::occupyBlock(const BlockInfoIt &it, std::size_t size)
{
	if (it->size > size)
	{
		BlockInfo freeBlock;
		freeBlock.ptr = static_cast<char *>(it->ptr) + size;
		freeBlock.size = it->size - size;
		_allocetedBlocks.insert(std::next(it), freeBlock);

		it->size = size;
	}

	it->busy = true;
}



void BlockAllocator::releaseBlock(const BlockInfoIt &it)
{
	it->busy = false;
	
	if (it != _allocetedBlocks.end())
	{
		auto nextIt = std::next(it);
		if (!nextIt->busy)
		{
			it->size += nextIt->size;
			_allocetedBlocks.erase(nextIt);
		}
	}

	if (it != _allocetedBlocks.begin())
	{
		auto prevIt = std::prev(it);
		if (!prevIt->busy)
		{
			prevIt->size += it->size;
			_allocetedBlocks.erase(it);
		}
	}
}
