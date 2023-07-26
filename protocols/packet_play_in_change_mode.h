#ifndef PACKET_PLAY_IN_CHANGE_MODE_H
#define PACKET_PLAY_IN_CHANGE_MODE_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayInChangeMode : public Packet
	{
	private:
		unsigned char _mode;

	public:
		const unsigned char SURVIVAL = 0;
		const unsigned char CREATIVE = 1;
		const unsigned char ADVENTURE = 2;
		const unsigned char SPECTATOR = 3;
		const unsigned char OTHER = 4;

		PacketPlayInChangeMode(
			int id,
			std::string origin,
			double timeCurrent,
			unsigned char mode
		) : Packet(id, origin, timeCurrent)
		{
			_mode = mode;
		}

		unsigned char getMode()
		{
			return _mode;
		}
	};
}

#endif