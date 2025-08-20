#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "SoundManager.h"

namespace
{
	const wchar_t* FONT_TEXT = L"PUSU(A)";
	const Vector3 FONT_POSITION = { 500.0f,0.0f,0.0f };
	const float FONT_SCALE = 1.0f;
	const Vector4 FONT_COLOR = { 0.0f,0.0f,0.0f,1.0f };

	const float ALPHA_MIN = 0.3f;
	const float ALPHA_MAX = 1.0f;

	const float ALPHA_BLINK_DURATION = 0.05f;
	const float ALPHA_FADE_DURATION = 0.5f;
}

Title::~Title()
{
	SoundManager* soundManager = FindGO<SoundManager>("soundmanager");
	soundManager->SoundDeleteGO(enSoundList_TitleBGM);
}

bool Title::Start()
{
	m_spriteRender.Init("Assets/sprite/title.dds", 1920.0f, 1080.0f);

	SoundManager* soundManager = FindGO<SoundManager>("soundmanager");
	soundManager->SoundNewGO(enSoundList_TitleBGM);

	m_durationColor = FONT_COLOR;
	m_fontRender.SetText(FONT_TEXT);
	m_fontRender.SetPosition(FONT_POSITION);
	m_fontRender.SetScale(FONT_SCALE);

	return true;
}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonX))
	{
		m_isStart = true;

		NewGO<Game>(0, "game");
	}

	if (m_isStart)
	{
		m_gameStartDelay += g_gameTime->GetFrameDeltaTime();
		if (m_gameStartDelay > 2.0f)
		{
			DeleteGO(this);
		}
	}

	PlayFontAnimation();
}

void Title::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
	m_fontRender.Draw(rc);
}

void Title::PlayFontAnimation()
{
	if (m_isStart)
	{
		m_alphaEffectDuration = ALPHA_BLINK_DURATION;
	}
	else
	{
		m_alphaEffectDuration = ALPHA_FADE_DURATION;
	}
	m_durationColor.a = m_alpha;
	m_fontRender.SetColor(m_durationColor);
	FontAnimationOption();
}

void Title::FontAnimationOption()
{
	FontAnimationStateManager();

	elapsedTime += g_gameTime->GetFrameDeltaTime();

	switch (m_alphaState)
	{
	case enAlphaEffectState_Up:

		if (m_isResetElapsedTime)
		{
			elapsedTime = 0.0f;
			m_isResetElapsedTime = false;
		}

		m_alpha = ALPHA_MIN + (ALPHA_MAX - ALPHA_MIN) * (elapsedTime / m_alphaEffectDuration);
		break;

	case enAlphaEffectState_Down:

		if (!m_isResetElapsedTime)
		{
			elapsedTime = 0.0f;
			m_isResetElapsedTime = true;
		}

		m_alpha = ALPHA_MAX - (ALPHA_MAX - ALPHA_MIN) * (elapsedTime / m_alphaEffectDuration);
		break;

	default:
		break;
	}
}

void Title::FontAnimationStateManager()
{
	if (m_alpha >= ALPHA_MAX)
	{
		m_alphaState = enAlphaEffectState_Down;
	}
	else if (m_alpha <= ALPHA_MIN)
	{
		m_alphaState = enAlphaEffectState_Up;
	}
}