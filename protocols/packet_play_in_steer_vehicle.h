#ifndef PACKET_PLAY_IN_STEER_VEHICLE_H
#define PACKET_PLAY_IN_STEER_VEHICLE_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayInSteerVehicle : public Packet
	{
	private:
		float _strafe;
		float _forward;

	public:
		PacketPlayInSteerVehicle(
			int id,
			std::string origin,
			double timeCurrent,
			float strafe,
			float forward
		) : Packet(id, origin, timeCurrent)
		{
			_strafe = strafe;
			_forward = forward;
		}

		float getStrafe()
		{
			return _strafe;
		}

		float getForward()
		{
			return _forward;
		}
	};
}

#endif