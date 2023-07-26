#ifndef PACKET_KEEP_ALIVE_H
#define PACKET_KEEP_ALIVE_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketKeepAlive : public Packet
	{
	private:
		bool _cancelled;

	public:
		PacketKeepAlive(
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