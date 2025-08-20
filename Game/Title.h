/// <summary>
/// �^�C�g�����Ǘ����܂��B
/// </summary>
#pragma once
class Title :public IGameObject
{
public:
	~Title();

private:
	bool Start()override final;
	void Update() override final;
	void Render(RenderContext& rc)override final;

	/// <summary>
	/// �t�H���g�A�j���[�V�������Đ����܂��B
	/// </summary>
	void PlayFontAnimation();

	/// <summary>
	/// �t�H���g�A�j���[�V�����̏�Ԃ��Ǘ����邽�߂̊֐��ł��B
	/// </summary>
	void FontAnimationStateManager();

	/// <summary>
	/// �t�H���g�A�j���[�V�����̃I�v�V������ݒ肵�܂��B
	/// </summary>
	void FontAnimationOption();

	SpriteRender m_spriteRender;
	FontRender m_fontRender;

	Vector4 m_durationColor;		// �F�̌v�Z���ʂ������܂��B
	bool m_isStart = false;			// �C���Q�[���X�^�[�g�̃t���O�B
	float m_gameStartDelay = 0.0f;	// �C���Q�[���J�n�܂ł̗P�\���ԁB

	/// <summary>
	/// �A���t�@��Ԃ�\���񋓌^�ł��B
	/// </summary>
	enum EnAlphaEffectState
	{
		enAlphaEffectState_Up,		// �A���t�@�l�𑝉�������X�e�[�g�B
		enAlphaEffectState_Down		// �A���t�@�l�����ۂ�����X�e�[�g�B
	};

	float elapsedTime = 0.0f;			// �A���t�@�l�𑝌�������X�s�[�h�𑪒肵�܂��B
	int m_alphaState = 0;				// �A���t�@�l�̑����̃X�e�[�g���i�[���܂��B
	float m_alpha = 0.0f;				// �v�Z�����A���t�@�l���i�[���܂��B
	float m_alphaEffectDuration = 0.0f;	// �t�F�[�h�Ɠ_�łɉ����ăA���t�@�l�𑝌�������X�s�[�h���i�[���܂��B
	bool m_isResetElapsedTime = false;	// �A���t�@�l�𑝌������鎞�Ԃ����Z�b�g���܂��B
};
