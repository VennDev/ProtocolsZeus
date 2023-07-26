#ifndef PACKET_PLAY_OUT_EXPLOSITION_H
#define PACKET_PLAY_OUT_EXPLOSITION_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayOutExplosion : public Packet
	{
	private:
		float _x;
		float _y;
		float _z;

	public:
		PacketPlayOutExplosion(
			int id,
			std::string origin,
			double timeCurrent,
			float x,
			float y,
			float z
		) : Packet(id, origin, timeCurrent)
		{
			_x = x;
			_y = y;
			_z = z;
		}

		float getX()
		{
			return _x;
		}

		float getY()
		{
			return _y;
		}

		float getZ()
		{
			return _z;
		}
	};
}

#endif