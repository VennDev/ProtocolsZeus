#ifndef PACKET_PLAY_IN_SNEAKING_H
#define PACKET_PLAY_IN_SNEAKING_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayInSneaking : public Packet
	{
	private:
		bool _cancelled;

	public:
		PacketPlayInSneaking(
			int id,
			std::string origin,
			double timeCurrent
		) : Packet(id, origin, timeCurrent)
		{
			_cancelled = false;
		}

		void cancel()
		{
			_cancelled = true;
		}

		bool isCancelled()
		{
			return _cancelled;
		}
	};
}

#endif