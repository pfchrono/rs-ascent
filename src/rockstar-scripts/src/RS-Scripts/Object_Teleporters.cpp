/*
	 Scripted for the RockStar FunServer Egari, T0aST, Midnight
	 http://www.fishstik.ca Please do not use these scripts for any other server
	 than the RockStar Funserver(http://fishstik.ca) as they were specially
	 scripted/modded for the server in question.
 */
#include "StdAfx.h"
#include "Setup.h"
#ifdef WIN32
#pragma warning(disable : 4305) /* warning C4305: 'argument' : truncation from 'double' to 'float' */
#endif

#define TELEPORTERS_USE_DATABASE

#ifndef TELEPORTERS_USE_DATABASE
class RSNationPortal :
	public GameObjectAIScript
{
public:
	RSNationPortal(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}

	void OnActivate(Player *pPlayer)
	{
		pPlayer->SafeTeleport(30, 0, 23.982540, -298.187042, 14.389221, 0); /* RockStar Nation */
		//pPlayer->SafeTeleport(1, 0, -8522.118164, 2014.756836, 105.604131, 3.514657); /* RockStar Twisting Neither */
	}

	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new RSNationPortal(GO);
	}
};
GameObjectAIScript *create_go(GameObject *GO)
{
	return new RSNationPortal(GO);
}

class FPSAreaPortal :
	public GameObjectAIScript
{
public:
	FPSAreaPortal(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}

	void OnActivate(Player *pPlayer)
	{
		if( pPlayer->getLevel() >= 90 /*|| pPlayer->RS_getAccess() >= RS_UBERVIP*/ )
		{
			pPlayer->SafeTeleport(269, 0, -1542.1, 7109.6, 32.8, 0);
		}
		else
		{
			sChatHandler.SystemMessage(pPlayer->GetSession(), "You are not prepared");
		}
	}

	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new FPSAreaPortal(GO);
	}
};
GameObjectAIScript *create_go2(GameObject *GO)
{
	return new FPSAreaPortal(GO);
}

class BaalDomainPortal :
	public GameObjectAIScript
{
public:
	BaalDomainPortal(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}

	void OnActivate(Player *pPlayer)
	{
		if(pPlayer->getLevel() >= 90)
		{
			pPlayer->SafeTeleport(1, 0, 1806.04, -4403.54, -16.57, 0);
		}
		else
		{
			sChatHandler.SystemMessage(pPlayer->GetSession(), "You need to be level 90 to advance.");
		}
	}

	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new BaalDomainPortal(GO);
	}
};
GameObjectAIScript *create_go3(GameObject *GO)
{
	return new BaalDomainPortal(GO);
}

class AllianceSCPortal :
	public GameObjectAIScript
{
public:
	AllianceSCPortal(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}

	void OnActivate(Player *pPlayer)
	{
		if(pPlayer->GetTeam() == 0)
		{
			pPlayer->SafeTeleport(0, 0, -4637.501953, -1691.715332, 505.284424, 0);
		}
		else
		{
			sChatHandler.SystemMessage(pPlayer->GetSession(), "Only Alliance is to be allowed through this portal");
		}
	}

	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new AllianceSCPortal(GO);
	}
};
GameObjectAIScript *create_go4(GameObject *GO)
{
	return new AllianceSCPortal(GO);
}

class HordeSCPortal :
	public GameObjectAIScript
{
public:
	HordeSCPortal(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}

	void OnActivate(Player *pPlayer)
	{
		if(pPlayer->GetTeam() == 1)
		{
			pPlayer->SafeTeleport(1, 0, 7422.44, -1579.46, 180.53, 6.06);
		}
		else
		{
			sChatHandler.SystemMessage(pPlayer->GetSession(), "Only Horde is to be allowed through this portal");
		}
	}

	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new HordeSCPortal(GO);
	}
};
GameObjectAIScript *create_go5(GameObject *GO)
{
	return new HordeSCPortal(GO);
}

class DoMMazePortal :
	public GameObjectAIScript
{
public:
	DoMMazePortal(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}

	void OnActivate(Player *pPlayer)
	{
		pPlayer->SafeTeleport(0, 0, -895.799988, 1564.099976, 41.820267, 0);
		pPlayer->GetSession()->SendNotification("Welcome to the Maze! *evil grin*");
	}

	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new DoMMazePortal(GO);
	}
};
GameObjectAIScript *create_go6(GameObject *GO)
{
	return new DoMMazePortal(GO);
}

class ShadowMancerTP :
	public GameObjectAIScript
{
public:
	ShadowMancerTP(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}

	void OnActivate(Player *pPlayer)
	{
		pPlayer->SafeTeleport(530, 0, -363.34, 3159.77, -95.95, 0);
	}

	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new ShadowMancerTP(GO);
	}
};
GameObjectAIScript *create_go7(GameObject *GO)
{
	return new ShadowMancerTP(GO);
}

class DemonHuntersTP :
	public GameObjectAIScript
{
public:
	DemonHuntersTP(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}

	void OnActivate(Player *pPlayer)
	{
		pPlayer->SafeTeleport(1, 0, -10745.00, 2422.51, 7.41, 0);
	}

	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new DemonHuntersTP(GO);
	}
};
GameObjectAIScript *create_go8(GameObject *GO)
{
	return new DemonHuntersTP(GO);
}

class PVPArenaPortal :
	public GameObjectAIScript
{
public:
	PVPArenaPortal(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}

	void OnActivate(Player *pPlayer)
	{
		pPlayer->SafeTeleport(0, 0, -13226.20, 231.99, 33.29, 0.98);
	}

	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new PVPArenaPortal(GO);
	}
};
GameObjectAIScript *create_go9(GameObject *GO)
{
	return new PVPArenaPortal(GO);
}

class HoradricCube :
	public GameObjectAIScript
{
public:
	HoradricCube(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}

	void OnActivate(Player *pPlayer)
	{
		pPlayer->SafeTeleport(37, 0, -618.95, -283.428, 353, 0.98);
	}

	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new HoradricCube(GO);
	}
};
GameObjectAIScript *create_go10(GameObject *GO)
{
	return new HoradricCube(GO);
}

class QuelDanas :
	public GameObjectAIScript
{
public:
	QuelDanas(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}

	void OnActivate(Player *pPlayer)
	{
		if(pPlayer->GetSession()->HasFlag(ACCOUNT_FLAG_XPACK_01))
		{
			pPlayer->SafeTeleport(530, 0, 12933.332031, -6906.653320, 5.269564, 3.537247);
		}
		else
		{
			sChatHandler.SystemMessage(pPlayer->GetSession(), "You are not prepared! (Req TBC)");
		}
	}

	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new QuelDanas(GO);
	}
};
GameObjectAIScript *create_go13(GameObject *GO)
{
	return new QuelDanas(GO);
}

class AV_TRAVELHUB :
	public GameObjectAIScript
{
public:
	AV_TRAVELHUB(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}

	void OnActivate(Player *pPlayer)
	{
		pPlayer->SafeTeleport(30, 0, 30.956919, -302.919708, 15.692127, 6.196788);
	}

	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new AV_TRAVELHUB(GO);
	}
};
GameObjectAIScript *create_go14(GameObject *GO)
{
	return new AV_TRAVELHUB(GO);
}
#endif
class GM_GATE :
	public GameObjectAIScript
{
public:
	GM_GATE(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}

	void OnActivate(Player *pPlayer)
	{
		if(!pPlayer || !pPlayer->GetSession()) return;
		if( pPlayer->RS_getAccess() < RS_GAMEMASTER)
		{
			pPlayer->GetSession()->SendNotification("You can't use that right now.");
			return;
		}
		float distX = _gameobject->GetPositionX() - pPlayer->GetPositionX();
		float distY = _gameobject->GetPositionY() - pPlayer->GetPositionY();;
		float X = pPlayer->GetPositionX() + (2 * distX);
		float Y = pPlayer->GetPositionY() + (2 * distY);
		float Z = (pPlayer->GetPositionZ() + 0.5);
		float O = pPlayer->GetOrientation();
		pPlayer->SafeTeleport(pPlayer->GetMapId(), pPlayer->GetMapMgr()->GetInstanceID(), X, Y, Z, O);
	}

	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new GM_GATE(GO);
	}
};
GameObjectAIScript *create_go15(GameObject *GO)
{
	return new GM_GATE(GO);
}

#ifdef TELEPORTERS_USE_DATABASE

class SQLTeleport :
	public GameObjectAIScript
{
public:
	SQLTeleport(GameObject *goinstance) :	GameObjectAIScript(goinstance){	}

	void OnActivate(Player *pPlayer)
	{
		if(pPlayer == NULL || pPlayer->GetSession() == NULL)
			return;

		std::stringstream select;
		select << "SELECT * FROM gameobject_tele WHERE entry = '" << _gameobject->GetEntry() << "'";
		QueryResult * result = WorldDatabase.Query( select.str().c_str() );
		if( result )
		{
			do{
				Field * fld			= result->Fetch();
				uint32	map			= fld[1].GetUInt32();
				float	x			= fld[2].GetFloat();
				float	y			= fld[3].GetFloat();
				float	z			= fld[4].GetFloat();
				float	o			= fld[5].GetFloat();
				string	welcomeMsg	= fld[6].GetString();
				string	errorMsg	= fld[7].GetString();
				uint32	reqlevel	= fld[8].GetUInt32();
				int		reqfaction	= fld[9].GetInt32();
				uint32	reqaccess	= fld[10].GetUInt32();
				uint32	reqtbc		= fld[11].GetUInt32();

				if( ( reqaccess == 0 || pPlayer->RS_getAccess() >= reqaccess ) 
					&& ( reqlevel == 0 || pPlayer->getLevel() >= reqlevel ) 
					&& ( reqfaction == -1 || (pPlayer->GetTeam()) == (uint32)reqfaction ) 
					&& ( reqtbc == 0 || ( reqtbc == 1 && pPlayer->GetSession()->HasFlag(ACCOUNT_FLAG_XPACK_01) ) )
					)
				{
					LocationVector LV(x, y, z, o);
					pPlayer->SafeTeleport(map, 0, LV);

					if( !(welcomeMsg.empty()) && welcomeMsg.length() > 3 )
						sChatHandler.SystemMessage(pPlayer->GetSession(), welcomeMsg.c_str());
				}
				else
				{
					if( !(errorMsg.empty()) && errorMsg.length() > 3 )
						sChatHandler.RedSystemMessage(pPlayer->GetSession(), errorMsg.c_str());
				}
			}while( result->NextRow() );
			WorldDatabase.FreeQueryResult( result );
		}
	}
	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new SQLTeleport(GO);
	}
};
GameObjectAIScript *create_go11(GameObject *GO)
{
	return new SQLTeleport(GO);
}

void Setup_Portals(ScriptMgr *mgr)
{
	std::stringstream registr;
	registr << "SELECT entry FROM gameobject_tele";
	QueryResult * reslt = WorldDatabase.Query( registr.str().c_str() );
	if( reslt )
	{
		do{
			uint32 entry = reslt->Fetch()[0].GetUInt32();
			mgr->register_gameobject_script(entry, &SQLTeleport::Create);
		}while( reslt->NextRow() );
		WorldDatabase.FreeQueryResult( reslt );
	}
#else

	mgr->register_gameobject_script(740005, &RSNationPortal::Create);		/* Twisting Nether Portal */
	mgr->register_gameobject_script(820004, &FPSAreaPortal::Create);		/* FPS Area Portal */
	mgr->register_gameobject_script(820047, &BaalDomainPortal::Create);		/* BaalsDomainOfDestruction Portal */
	mgr->register_gameobject_script(700021, &AllianceSCPortal::Create);		/* Portal to Alliance SC */
	mgr->register_gameobject_script(700020, &HordeSCPortal::Create);		/* Portal to Horde SC */
	mgr->register_gameobject_script(820011, &DoMMazePortal::Create);		/* Portal to DoM's Maze */
	mgr->register_gameobject_script(610000, &ShadowMancerTP::Create);		/* Portal to Shadowmancers */
	mgr->register_gameobject_script(700010, &DemonHuntersTP::Create);		/* Portal to Cove of the Demonhunters */
	mgr->register_gameobject_script(740008, &PVPArenaPortal::Create);		/* Portal to PVP Arena */
	mgr->register_gameobject_script(74000001, &HoradricCube::Create);		/* Portal to Horadric Area */
	mgr->register_gameobject_script(700152, &QuelDanas::Create);			/* Portal to Quel'Danas' */
	mgr->register_gameobject_script(700154, &AV_TRAVELHUB::Create);			/* AV_TRAVELHUB */
#endif
	mgr->register_gameobject_script(700129, &GM_GATE::Create);				/* GM GATE */
	/*============================================================================================================*/
}
