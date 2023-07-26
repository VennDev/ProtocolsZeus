#ifndef PACKET_PLAY_OUT_BLOCKS_DOWN_H
#define PACKET_PLAY_OUT_BLOCKS_DOWN_H

#include "../compat/packet.h"

#include <vector>

using namespace Compat;

namespace Protocols
{
	class PacketPlayOutBlocksDown : public Packet
	{
	private:
		 std::vector<int> _blocks;

	public:
		PacketPlayOutBlocksDown(
			int id,
			std::string origin,
			double timeCurrent,
			std::vector<int> blocks
		) : Packet(id, origin, timeCurrent)
		{
			_blocks = blocks;
		}

		std::vector<int> getBlocks()
		{
			return _blocks;
		}
	};
}

#endif