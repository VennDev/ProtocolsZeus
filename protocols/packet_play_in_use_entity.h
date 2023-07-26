#ifndef PACKET_PLAY_IN_USE_ENTITY_H
#define PACKET_PLAY_IN_USE_ENTITY_H

#include "../compat/packet.h"

using namespace Compat;

namespace Protocols
{
	class PacketPlayInUseEntity : public Packet
	{
	private:
		float _originX;
		float _originY;
		float _originZ;
		float _originYaw;
		float _originPitch;
		float _targetX;
		float _targetY;
		float _targetZ;
		float _targetYaw;
		float _targetPitch;

	public:
		PacketPlayInUseEntity(
			int id,
			std::string origin,
			double timeCurrent,
			float originX,
			float originY,
			float originZ,
			float originYaw,
			float originPitch,
			float targetX,
			float targetY,
			float targetZ,
			float targetYaw,
			float targetPitch
		) : Packet(id, origin, timeCurrent)
		{
			_originX = originX;
			_originY = originY;
			_originZ = originZ;
			_originYaw = originYaw;
			_originPitch = originPitch;
			_targetX = targetX;
			_targetY = targetY;
			_targetZ = targetZ;
			_targetYaw = targetYaw;
			_targetPitch = targetPitch;
		}

		float getOriginX()
		{
			return _originX;
		}

		float getOriginY()
		{
			return _originY;
		}

		float getOriginZ()
		{
			return _originZ;
		}

		float getOriginYaw()
		{
			return _originYaw;
		}

		float getOriginPitch()
		{
			return _originPitch;
		}

		float getTargetX()
		{
			return _targetX;
		}

		float getTargetY()
		{
			return _targetY;
		}

		float getTargetZ()
		{
			return _targetZ;
		}

		float getTargetYaw()
		{
			return _targetYaw;
		}

		float getTargetPitch()
		{
			return _targetPitch;
		}
	};
}

#endif