/// <summary>
/// プレイヤーを管理するクラス。
/// </summary>
#pragma once
class Player :public IGameObject
{
private:
	/// <summary>
	/// アニメーションのクリップを表す列挙型です。
	/// </summary>
	enum EnAnimationClip {
		enAnimationClip_Idle,	// 待機アニメーション。
		enAnimationClip_Walk,	// 歩きアニメーション。
		enAnimationClip_Run,	// 走りアニメーション。
		enAnimationClip_Jump,	// ジャンプアニメーション。
		enAnimationClip_Num,
	};

	/// <summary>
	/// ジャンプ状態を表す列挙型です。
	/// </summary>
	enum EnJumpState {
		NoJump,		// まだジャンプしていない。
		OneJump,	// 一回ジャンプ済み。
		TwoJump		// 二回ジャンプ済み。
	};

public:
	/// <summary>
	/// プレイヤーの座標を取得します。
	/// </summary>
	/// <returns>プレイヤーの現在の座標値（float型）。</returns>
	const Vector3 GetPosition()
	{
		return m_position;
	}

private:
	bool Start()override final;
	void Update()override final;
	void Render(RenderContext& rc)override final;

	/// <summary>
	/// プレイヤーの移動処理。
	/// </summary>
	void Move();

	/// <summary>
	/// 移動速度を設定します。
	/// </summary>
	void SetMoveSpeed();

	/// <summary>
	/// プレイヤーのジャンプの回数を管理します。
	/// </summary>
	void JumpManager();

	/// <summary>
	/// プレイヤーの回転処理。
	/// </summary>
	void Rotation();

	/// <summary>
	/// 重力を発生させます。
	/// </summary>
	void AddGravity();

	/// <summary>
	/// アニメーションクリップを設定します。
	/// </summary>
	void SetAnimationClips();

	/// <summary>
	/// プレイヤーのアニメーションを管理し切り替えます。
	/// </summary>
	void AnimState();

	ModelRender m_modelRender;
	AnimationClip m_animationClips[enAnimationClip_Num];
	CharacterController m_characterController;
	Vector3 m_position = Vector3::Zero;
	Vector3 m_moveSpeed = Vector3::Zero;
	Quaternion m_rotation;

	Vector3 stickL = Vector3::Zero;
	Vector3 forward = Vector3::Zero;
	Vector3 right = Vector3::Zero;

	int m_animState = 0;
	int m_jumpState = 0;
};

