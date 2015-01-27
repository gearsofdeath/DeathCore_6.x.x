/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "shadopan_monastery.h"

/* Notes :
Instance : Script 95% 
GuCloudstrike 95% (termin� -- voir spells)
Master Snowdrift 95% (termin� -- voir spells)
Sha of violence 95% (termin� -- voir spells)
TaranZhu 95% (termin� -- voir spells) 
Voir pour les gameobjects comme les coffres (master snowdrift et TaranZhu) et les portes (Au moins GuCloudstrike et MasterSnowdrift, le reste je sais pas...)
*/


class instance_shado_pan_monastery : public InstanceMapScript
{
	public:
		instance_shado_pan_monastery() : InstanceMapScript("instance_shado_pan_monastery", 959) { }

		struct instance_shado_pan_monastery_InstanceMapScript : public InstanceScript
		{
			instance_shado_pan_monastery_InstanceMapScript(Map* map) : InstanceScript(map)
			{
				BossGuCloudstrikeGUID	= 0;
				NpcAzureSerpentGUID		= 0;
				BossMasterSnowdriftGUID	= 0;
				BossShaOfViolenceGUID	= 0;
				BossTaranZhuGUID	    = 0;
			}

			void OnCreatureCreate(Creature* creature)
			{
				switch (creature->GetEntry())
				{
					case BOSS_GU_CLOUDSTRIKE:
						BossGuCloudstrikeGUID = creature->GetGUID();
						break;
					case NPC_AZURE_SERPENT:
						NpcAzureSerpentGUID = creature->GetGUID();
						break;
					case BOSS_MASTER_SNOWDRIFT:
						BossMasterSnowdriftGUID = creature->GetGUID();
						break;
					case BOSS_SHA_OF_VIOLENCE:
						BossShaOfViolenceGUID = creature->GetGUID();
						break;
					case BOSS_TARAN_ZHU:
						BossTaranZhuGUID = creature->GetGUID();
						break;
					default:
						break;
				}
			}
			
			void OnGameObjectCreate(GameObject* go)
            {
                switch (go->GetEntry())
                {
				}
			}
			
			void OnGameObjectRemove(GameObject* go)
            {
                switch (go->GetEntry())
                {
				}
			}

			uint64 GetData64(uint32 id) const
			{
				switch (id)
				{
					case DATA_BOSS_GU_CLOUDSTRIKE:
						return BossGuCloudstrikeGUID;
					case DATA_NPC_AZURE_SERPENT:
						return NpcAzureSerpentGUID;
					case DATA_BOSS_MASTER_SNOWDRIFT:
						return BossMasterSnowdriftGUID;
					case DATA_BOSS_SHA_OF_VIOLENCE:
						return BossShaOfViolenceGUID;
					case DATA_BOSS_TARAN_ZHU:
						return BossTaranZhuGUID;
					default:
						break;
				}

				return 0;
			}

			protected:
				uint64 BossGuCloudstrikeGUID;
				uint64 NpcAzureSerpentGUID;
				uint64 BossMasterSnowdriftGUID;
				uint64 BossShaOfViolenceGUID;
				uint64 BossTaranZhuGUID;
		};

		InstanceScript* GetInstanceScript(InstanceMap* map) const
		{
			return new instance_shado_pan_monastery_InstanceMapScript(map);
		}
};


void AddSC_instance_shado_pan_monastery()
{
   new instance_shado_pan_monastery();
}