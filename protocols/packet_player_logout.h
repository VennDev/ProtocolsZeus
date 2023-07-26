#ifndef PACKET_PLAYER_LOGOUT_H
#define PACKET_PLAYER_LOGOUT_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayerLogout : public Packet
	{
	private:
		bool _cancelled;
		std::string _xuid;

	public:
		PacketPlayerLogout(
			int id,
			std::string origin,
			double timeCurrent,
			std::string xuid
		) : Packet(id, origin, timeCurrent)
		{
			_xuid = xuid;
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

		std::string getXuid()
		{
			return _xuid;
		}
	};
}

#endif