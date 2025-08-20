/// <summary>
/// �v���C���[���Ǘ�����N���X�B
/// </summary>
#pragma once
class Player :public IGameObject
{
private:
	/// <summary>
	/// �A�j���[�V�����̃N���b�v��\���񋓌^�ł��B
	/// </summary>
	enum EnAnimationClip {
		enAnimationClip_Idle,	// �ҋ@�A�j���[�V�����B
		enAnimationClip_Walk,	// �����A�j���[�V�����B
		enAnimationClip_Run,	// ����A�j���[�V�����B
		enAnimationClip_Jump,	// �W�����v�A�j���[�V�����B
		enAnimationClip_Num,
	};

	/// <summary>
	/// �W�����v��Ԃ�\���񋓌^�ł��B
	/// </summary>
	enum EnJumpState {
		NoJump,		// �܂��W�����v���Ă��Ȃ��B
		OneJump,	// ���W�����v�ς݁B
		TwoJump		// ���W�����v�ς݁B
	};

public:
	/// <summary>
	/// �v���C���[�̍��W���擾���܂��B
	/// </summary>
	/// <returns>�v���C���[�̌��݂̍��W�l�ifloat�^�j�B</returns>
	const Vector3 GetPosition()
	{
		return m_position;
	}

private:
	bool Start()override final;
	void Update()override final;
	void Render(RenderContext& rc)override final;

	/// <summary>
	/// �v���C���[�̈ړ������B
	/// </summary>
	void Move();

	/// <summary>
	/// �ړ����x��ݒ肵�܂��B
	/// </summary>
	void SetMoveSpeed();

	/// <summary>
	/// �v���C���[�̃W�����v�̉񐔂��Ǘ����܂��B
	/// </summary>
	void JumpManager();

	/// <summary>
	/// �v���C���[�̉�]�����B
	/// </summary>
	void Rotation();

	/// <summary>
	/// �d�͂𔭐������܂��B
	/// </summary>
	void AddGravity();

	/// <summary>
	/// �A�j���[�V�����N���b�v��ݒ肵�܂��B
	/// </summary>
	void SetAnimationClips();

	/// <summary>
	/// �v���C���[�̃A�j���[�V�������Ǘ����؂�ւ��܂��B
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

