#include "stdafx.h"
#include "Item.h"
#include "Player.h"
#include "SoundManager.h"
#include "Game.h"

namespace
{
	const float ITEM_DELETE_LENGTH = 120.0f;
}

bool Item::Start()
{
	m_modelRender.Init("Assets/modelData/item.tkm");

	m_player = FindGO < Player>("BattleCharacter");

	m_modelRender.SetPosition(m_position);

	return true;
}

void Item::Update()
{
	Rotation();
	m_modelRender.Update();

	DeleteItem();
}

void Item::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}

void Item::Rotation()
{
	m_rotation.AddRotationDegY(2.0f);
	m_modelRender.SetRotation(m_rotation);
}

void Item::DeleteItem()
{
	Vector3 diff = m_player->GetPosition() - m_position;

	if (diff.Length() <= ITEM_DELETE_LENGTH)
	{
		SoundManager* soundManager = FindGO<SoundManager>("soundmanager");
		soundManager->SoundNewGO(enSoundList_StarGetSE);

		Game* game = FindGO<Game>("game");
		game->IncrementItemGetCount();

		DeleteGO(this);
	}
}
