#include "stdafx.h"
#include "Player.h"
#include "SoundManager.h"

namespace
{
	const char* ANIMATION_FILE_PATH = "Assets/animData/";

	const float DASH_SPEED = 300.0f;
	const float WALK_SPEED = 150.0f;
	const float JUMP_POWER = 240.0f;
	const float GRAVITY_POWER = 3.0f;
	const float INPUT_DEADZONE_THRESHOLD = 0.001f;

	/// <summary>
	/// アニメーションファイルのオプションを管理する構造体です。
	/// </summary>
	struct AnimationOption
	{
		const char* fileName;	// ファイルパス。
		bool is_loop = false;	// リピートするかどうか。（true=する、false=しない）

		std::string GetFullPath() const
		{
			return std::string(ANIMATION_FILE_PATH) + fileName;
		}
	};

	/// <summary>
	/// アニメーションのオプションを定義する定数配列です。
	/// </summary>
	const AnimationOption ANIMATION_OPTIONS[] =
	{
		{"idle.tka",true},
		{"walk.tka",true},
		{"run.tka",true},
		{"jump.tka",false}
	};
}

bool Player::Start()
{
	SetAnimationClips();

	m_modelRender.Init("Assets/modelData/unityChan.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisY);

	m_characterController.Init(25.0f, 75.0f, m_position);

	return true;
}

void Player::Update()
{
	Move();
	Rotation();
	AddGravity();

	AnimState();
	m_modelRender.PlayAnimation(m_animState);

	m_modelRender.Update();
}

void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}

void Player::Move()
{
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	forward = g_camera3D->GetForward();
	right = g_camera3D->GetRight();

	forward.y = 0.0f;
	right.y = 0.0f;

	SetMoveSpeed();

	m_moveSpeed += right + forward;

	JumpManager();

	m_position = m_characterController.Execute(m_moveSpeed, 1.0f / 60.0f);

	m_modelRender.SetPosition(m_position);
}

void Player::SetMoveSpeed()
{
	if (g_pad[0]->IsPress(enButtonB))
	{
		right *= stickL.x * DASH_SPEED;
		forward *= stickL.y * DASH_SPEED;
	}
	else
	{
		right *= stickL.x * WALK_SPEED;
		forward *= stickL.y * WALK_SPEED;
	}
}

void Player::JumpManager()
{
	SoundManager* soundManager = FindGO<SoundManager>("soundmanager");

	switch (m_jumpState)
	{
	case NoJump:
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			m_moveSpeed.y = JUMP_POWER;
			m_jumpState = OneJump;
			soundManager->SoundNewGO(enSoundList_JumpSE);
		}
		break;

	case OneJump:
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			m_moveSpeed.y = 0.0f;
			m_moveSpeed.y = JUMP_POWER;
			m_jumpState = TwoJump;
			soundManager->SoundNewGO(enSoundList_JumpSE);
		}
		if (m_characterController.IsOnGround())
		{
			m_jumpState = NoJump;
		}
		break;

	case TwoJump:
		if (m_characterController.IsOnGround())
		{
			m_jumpState = NoJump;
		}
		break;
	}
}

void Player::Rotation()
{
	if (fabsf(m_moveSpeed.x) >= INPUT_DEADZONE_THRESHOLD || fabsf(m_moveSpeed.z) >= INPUT_DEADZONE_THRESHOLD)
	{
		m_rotation.SetRotationYFromDirectionXZ(m_moveSpeed);
		m_modelRender.SetRotation(m_rotation);
	}
}

void Player::AddGravity()
{
	if (m_characterController.IsOnGround() == false)
	{
		m_moveSpeed.y -= GRAVITY_POWER;
	}
}

void Player::SetAnimationClips()
{
	for (int animKinds = 0; animKinds < enAnimationClip_Num; animKinds++)
	{
		m_animationClips[animKinds].Load(ANIMATION_OPTIONS[animKinds].GetFullPath().c_str());
		m_animationClips[animKinds].SetLoopFlag(ANIMATION_OPTIONS[animKinds].is_loop);
	}
}

void Player::AnimState()
{
	if (m_characterController.IsOnGround() == false)
	{
		m_animState = enAnimationClip_Jump;
	}
	else if (fabsf(m_moveSpeed.x) >= INPUT_DEADZONE_THRESHOLD || fabsf(m_moveSpeed.z) >= INPUT_DEADZONE_THRESHOLD)
	{
		m_animState = enAnimationClip_Walk;

		if (g_pad[0]->IsPress(enButtonB))
		{
			m_animState = enAnimationClip_Run;
		}
	}
	else
	{
		m_animState = enAnimationClip_Idle;
	}
}

