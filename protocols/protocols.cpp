#include "protocols.h"

#include <vector>

namespace Protocols
{

	Packet* Protocol::processDataPacket(nlohmann::json data)
	{
		int id = static_cast<int>(data["id"]);
		std::string origin = static_cast<std::string>(data["origin"]);
		double timeCurrent = static_cast<double>(data["timeCurrent"]);

		Packet* packet = nullptr;

		if (id == PACKET_KEEP_ALIVE)
		{
			Packet packet = PacketKeepAlive(id, origin, timeCurrent);
		}
		else if (id == PACKET_PLAY_IN_CHANGE_MODE)
		{
			unsigned char mode = static_cast<unsigned char>(data["mode"]);

			Packet packet = PacketPlayInChangeMode(id, origin, timeCurrent, mode);
		}
		else if (id == PACKET_PLAY_IN_CLOSE_WINDOW)
		{
			Packet packet = PacketPlayInCloseWindow(id, origin, timeCurrent);
		}
		else if (id == PACKET_PLAY_IN_DEATH)
		{
			float x = static_cast<float>(data["x"]);
			float y = static_cast<float>(data["y"]);
			float z = static_cast<float>(data["z"]);

			Packet packet = PacketPlayInDeath(id, origin, timeCurrent, x, y, z);
		}
		else if (id == PACKET_PLAY_IN_HELD_ITEM_SLOT)
		{
			int idi = static_cast<int>(data["idi"]);
			int meta = static_cast<int>(data["meta"]);
			int slot = static_cast<int>(data["slot"]);
			std::string name = static_cast<std::string>(data["name"]);
			std::string lore = static_cast<std::string>(data["lore"]);

			Packet packet = PacketPlayInHeldItemSlot(id, origin, timeCurrent, idi, meta, slot, name, lore);
		}
		else if (id == PACKET_PLAY_IN_OPEN_WINDOW)
		{
			Packet packet = PacketPlayInOpenWindow(id, origin, timeCurrent);
		}
		else if (id == PACKET_PLAY_IN_ROTATION)
		{
			float yaw = static_cast<float>(data["yaw"]);
			float pitch = static_cast<float>(data["pitch"]);

			Packet packet = PacketPlayInRotation(id, origin, timeCurrent, yaw, pitch);
		}
		else if (id == PACKET_PLAY_IN_SNEAKING)
		{
			Packet packet = PacketPlayInSprinting(id, origin, timeCurrent);
		}
		else if (id == PACKET_PLAY_IN_SPRINTING)
		{
			Packet packet = PacketPlayInSprinting(id, origin, timeCurrent);
		}
		else if (id == PACKET_PLAY_IN_STEER_VEHICLE)
		{
			float strafe = static_cast<float>(data["strafe"]);
			float forward = static_cast<float>(data["forwart"]);

			Packet packet = PacketPlayInSteerVehicle(id, origin, timeCurrent, strafe, forward);
		}
		else if (id == PACKET_PLAY_IN_TRANSACTION)
		{
			int sourceType = static_cast<int>(data["sourceType"]);
			int sourceFlags = static_cast<int>(data["sourceFlags"]);
			unsigned char slot = static_cast<unsigned char>(data["slot"]);

			Packet packet = PacketPlayInTransaction(id, origin, timeCurrent, sourceType, sourceFlags, slot);
		}
		else if (id == PACKET_PLAY_IN_USE_ENTITY)
		{
			float originX = static_cast<float>(data["originX"]);
			float originY = static_cast<float>(data["originY"]);
			float originZ = static_cast<float>(data["originZ"]);
			float originYaw = static_cast<float>(data["originYaw"]);
			float originPitch = static_cast<float>(data["originPitch"]);
			float targetX = static_cast<float>(data["targetX"]);
			float targetY = static_cast<float>(data["targetY"]);
			float targetZ = static_cast<float>(data["targetZ"]);
			float targetYaw = static_cast<float>(data["targetYaw"]);
			float targetPitch = static_cast<float>(data["targetPitch"]);

			Packet packet = PacketPlayInUseEntity(id, origin, timeCurrent, originX, originY, originZ, originYaw, originPitch, targetX, targetY, targetZ, targetYaw, targetPitch);
		}
		else if (id == PACKET_PLAY_OUT_BLOCKS_DOWN)
		{
			std::vector<int> blocks = data["blocks"];

			Packet packet = PacketPlayOutBlocksDown(id, origin, timeCurrent, blocks);
		}
		else if (id == PACKET_PLAY_OUT_ENTITY_EFFECT)
		{
			unsigned char effectId = static_cast<unsigned char>(data["effectId"]);
			float amplifier = static_cast<float>(data["amplifier"]);
			float duration = static_cast<float>(data["duration"]);
			unsigned char flags = static_cast<unsigned char>(data["flags"]);

			Packet packet = PacketPlayOutEntityEffect(id, origin, timeCurrent, effectId, amplifier, duration, flags);
		}
		else if (id == PACKET_PLAY_OUT_ENTITY_TELEPORT)
		{
			float x = static_cast<float>(data["x"]);
			float y = static_cast<float>(data["y"]);
			float z = static_cast<float>(data["z"]);

			Packet packet = PacketPlayOutEntityTeleport(id, origin, timeCurrent, x, y, z);
		}
		else if (id == PACKET_PLAY_OUT_EXPLOSION)
		{
			float x = static_cast<float>(data["x"]);
			float y = static_cast<float>(data["y"]);
			float z = static_cast<float>(data["z"]);

			Packet packet = PacketPlayOutExplosion(id, origin, timeCurrent, x, y, z);
		}
		else if (id == PACKET_PLAY_OUT_RESPAWN)
		{
			float x = static_cast<float>(data["x"]);
			float y = static_cast<float>(data["y"]);
			float z = static_cast<float>(data["z"]);

			Packet packet = PacketPlayOutRespawn(id, origin, timeCurrent, x, y, z);
		}
		else if (id == PACKET_PLAY_OUT_TRANSACTION)
		{
			int sourceType = static_cast<int>(data["sourceType"]);
			int sourceFlags = static_cast<int>(data["sourceFlags"]);
			unsigned char slot = static_cast<unsigned char>(data["slot"]);

			Packet packet = PacketPlayOutTransaction(id, origin, timeCurrent, sourceType, sourceFlags, slot);
		}
		else if (id == PACKET_PLAYER_ARM_ANIMATION)
		{ 
			Packet packet = PacketPlayerArmAnimation(id, origin, timeCurrent);
		}
		else if (id == PACKET_PLAYER_BREAK_BLOCK)
		{
			float x = static_cast<float>(data["x"]);
			float y = static_cast<float>(data["y"]);
			float z = static_cast<float>(data["z"]);

			Packet packet = PacketPlayerBreakBlock(id, origin, timeCurrent, x, y, z);
		}
		else if (id == PACKET_PLAYER_LOGIN)
		{
			std::string xuid = static_cast<std::string>(data["xuid"]);

			Packet packet = PacketPlayerLogin(id, origin, timeCurrent, xuid);
		}
		else if (id == PACKET_PLAYER_LOGOUT)
		{
			std::string xuid = static_cast<std::string>(data["xuid"]);

			Packet packet = PacketPlayerLogout(id, origin, timeCurrent, xuid);
		}
		else if (id == PACKET_PLAYER_PLACE_BLOCK)
		{
			float x = static_cast<float>(data["x"]);
			float y = static_cast<float>(data["y"]);
			float z = static_cast<float>(data["z"]);

			Packet packet = PacketPlayerPlaceBlock(id, origin, timeCurrent, x, y, z);
		}
		else if (id == PACKET_PLAYER_POSITION)
		{
			float x = static_cast<float>(data["x"]);
			float y = static_cast<float>(data["y"]);
			float z = static_cast<float>(data["z"]);
			float yaw = static_cast<float>(data["yaw"]);
			float pitch = static_cast<float>(data["pitch"]);
			bool onGround = static_cast<bool>(data["onGround"]);

			Packet packet = PacketPlayerPosition(id, origin, timeCurrent, x, y, z, yaw, pitch, onGround);
		}

		return packet;
	}

}