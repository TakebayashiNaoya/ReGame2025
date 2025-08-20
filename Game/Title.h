/// <summary>
/// タイトルを管理します。
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
	/// フォントアニメーションを再生します。
	/// </summary>
	void PlayFontAnimation();

	/// <summary>
	/// フォントアニメーションの状態を管理するための関数です。
	/// </summary>
	void FontAnimationStateManager();

	/// <summary>
	/// フォントアニメーションのオプションを設定します。
	/// </summary>
	void FontAnimationOption();

	SpriteRender m_spriteRender;
	FontRender m_fontRender;

	Vector4 m_durationColor;		// 色の計算結果を代入します。
	bool m_isStart = false;			// インゲームスタートのフラグ。
	float m_gameStartDelay = 0.0f;	// インゲーム開始までの猶予時間。

	/// <summary>
	/// アルファ状態を表す列挙型です。
	/// </summary>
	enum EnAlphaEffectState
	{
		enAlphaEffectState_Up,		// アルファ値を増加させるステート。
		enAlphaEffectState_Down		// アルファ値を現象させるステート。
	};

	float elapsedTime = 0.0f;			// アルファ値を増減させるスピードを測定します。
	int m_alphaState = 0;				// アルファ値の増減のステートを格納します。
	float m_alpha = 0.0f;				// 計算したアルファ値を格納します。
	float m_alphaEffectDuration = 0.0f;	// フェードと点滅に応じてアルファ値を増減させるスピードを格納します。
	bool m_isResetElapsedTime = false;	// アルファ値を増減させる時間をリセットします。
};
